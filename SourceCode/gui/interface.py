import time
import os
import sys
from collections import defaultdict
from scipy.io import wavfile
import numpy as np
import pickle
import traceback as tb

from feature import mix_feature
from filters.VAD import VAD
from .skgmm import GMMSet, GMM
CHECK_ACTIVE_INTERVAL = 1       # seconds
class ModelInterface(object):

    UBM_MODEL_FILE = 'model/ubm.mixture-32.utt-300.model'

    def __init__(self):
        self.features = defaultdict(list)
        self.gmmset = GMMSet()
        self.vad = VAD()

    def init_noise(self, fs, signal):
        """
        init vad from environment noise
        """
        self.vad.init_noise(fs, signal)

    def filter(self, fs, signal):
        """
        use VAD (voice activity detection) to filter out silence part of a signal
        """
        ret, intervals = self.vad.filter(fs, signal)
        orig_len = len(signal)

        if len(ret) > orig_len / 3:
            # signal is filtered by VAD
            return ret
        return np.array([])

    def enroll(self, name, fs, signal):
        """
        add the signal to this person's training dataset
        name: person's name
        """
        feat = mix_feature((fs, signal))
        self.features[name].extend(feat)

    def _get_gmm_set(self):
        if os.path.isfile(self.UBM_MODEL_FILE):
            return GMMSet()
        return GMMSet()

    def train(self):
        self.gmmset = self._get_gmm_set()
        start = time.time()
        print ("Start training...")
        for name, feats in self.features.items():
            self.gmmset.fit_new(feats, name)
        print (time.time() - start, " seconds")

    def predict(self, fs, signal):
        """
        return a label (name)
        """
        try:
            feat = mix_feature((fs, signal))
        except Exception as e:
            print (tb.format_exc())
            return None
        return self.gmmset.predict_one(feat)

    def dump(self, fname):
        """ dump all models to file"""
        self.gmmset.before_pickle()
        self.gmmset.dump(fname)
        self.gmmset.after_pickle()

    #@staticmethod
    def load(self,fname,label):
        """ load from a dumped model file"""
        self.gmmset.load(fname,label)

        # with open(fname, 'rb') as f:
        #     R = pickle.load(f)
        #     R.gmmset.after_pickle()
        #     return R

if __name__ == "__main__":
    """ some testing"""
    m = ModelInterface()
    fs, signal = wavfile.read("../corpus.silence-removed/Style_Reading/f_001_03.wav")
    m.enroll('h', fs, signal[:80000])
    fs, signal = wavfile.read("../corpus.silence-removed/Style_Reading/f_003_03.wav")
    m.enroll('a', fs, signal[:80000])
    m.train()
    print (m.predict(fs, signal[:80000]))
