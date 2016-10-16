
import operator
import pickle
import os
import numpy as np
from sklearn.mixture import GMM

class GMMSet(object):

    def __init__(self, gmm_order = 32):
        self.gmms = []
        self.gmm_order = gmm_order
        self.y = []

    def fit_new(self, x, label):
        self.y.append(label)
        gmm = GMM(self.gmm_order)
        gmm.fit(x)
        self.gmms.append(gmm)
        #self.dump('gmms/')

    def gmm_score(self, gmm, x):
        return np.sum(gmm.score(x))

    def before_pickle(self):
        pass

    def after_pickle(self):
        pass

    def predict_one(self, x):
        scores = [self.gmm_score(gmm, x) / len(x) for gmm in self.gmms]
        #print(scores)
        p = sorted(enumerate(scores), key=operator.itemgetter(1), reverse=True)
        p = [(str(self.y[i]), y, p[0][1] - y) for i, y in p]
        result = [(self.y[index], value) for (index, value) in enumerate(scores)]
        p = max(result, key=operator.itemgetter(1))
        return p[0]

    def dump(self, path): 
        for gmm,name in zip(self.gmms,self.y):
            fname=str(path)+str(name)+'.model'
            with open (fname,"wb") as f:
                pickle.dump(gmm,f,-1)
            
    def load(self, path,label):
        with open(path, 'rb') as f:
            R = pickle.load(f)
        self.gmms.append(R)
        self.y.append(label)
        
