import sys
from . import MFCC
from . import LPC
import numpy as np

def get_extractor(extract_func, **kwargs):
    def f(tup):
        return extract_func(*tup, **kwargs)
    return f

def mix_feature(tup):
    mfcc = MFCC.extract(tup)
    lpc = LPC.extract(tup)
    if len(mfcc) == 0:
        print( sys.stderr, "ERROR.. failed to extract mfcc feature:", len(tup[1]))
    return np.concatenate((mfcc, lpc), axis=1)
