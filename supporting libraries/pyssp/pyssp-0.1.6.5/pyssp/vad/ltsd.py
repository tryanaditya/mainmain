#!/usr/bin/env python
# -*- coding: utf-8 -*-
import scipy as sp
import sys
from pyssp.util import read_signal, get_frame

WINSIZE=2048

    
class LTSD():
    def __init__(self,winsize,window,order,e0=200,e1=300,lambda0=40,lambda1=50):
        self._winsize = winsize
        self._window = window
        self._order = order
        self._amplitude = {}
        #calcurate parameters from datasets
        self._e0 = e0;
        self._e1 = e1;
        self._lambda0 = lambda0;
        self._lambda1 = lambda1;

    def _get_amplitude(self,signal,l):
        if l in self._amplitude.keys():
            return self._amplitude[l]
        else:
            amp = sp.absolute(sp.fft(get_frame(signal, self._winsize,l) * self._window))
            self._amplitude[l] = amp
            return amp

    def _compute_noise_avgspectrum(self,nsignal):
        windownum = int(len(nsignal)/(self._winsize/2) - 1)
        avgamp = sp.zeros(self._winsize)
        for l in range(windownum):
            avgamp += sp.absolute(sp.fft(get_frame(nsignal, self._winsize,l) * self._window))
        return avgamp/float(windownum)

    def _is_signal(self,signal,ltsd,l):
        e = self._calc_power(signal,l)
        if e < self._e0:
            if ltsd > self._lambda0:
                return True
            else:
                return False
        elif e > self._e1:
            if ltsd > self._lambda1:
                return True
            else:
                return False
        else:
            lamb = (self._lambda0-self._lambda1)/(self._e0/self._e1)*e + self._lambda0 - (self._lambda0-self._lambda1)/(1.0-(self._e0/self._e1))
            if ltsd > lamb:
                return True
            else:
                return False

    def _calc_power(self,signal,l):
        amp=self._get_amplitude(signal,l)
        avg = 10.0*sp.log10(sp.sum(amp**2)/float(len(signal)))
        return avg
    
    def compute_without_noise(self,signal,size):
        self._windownum = int(len(signal)/(self._winsize/2) - 1)
        #Calcurate the average noise spectrum amplitude based　on first 'size' bytes in the head part of input signal.
        self._avgnoise = self._compute_noise_avgspectrum(signal[0:size])**2
        return self._compute(signal)
    
    def compute_with_noise(self,signal,noise):
        self._windownum = int(len(signal)/(self._winsize/2) - 1)
        self._avgnoise = self._compute_noise_avgspectrum(noise)**2
        return self._compute(signal)

    def _compute(self,signal):
        ltsds = sp.zeros(self._windownum)
        prev = 0
        pair = None
        result = []
        for l in range(self._windownum):
            ltsd = self._ltsd(signal,l)
            ltsds[l]=ltsd
            x = self._is_signal(signal,ltsd,l)
            if x:# signal
                if prev == 0:#start signal segment
                    pair = [l]
                prev = 1
            else:#noise
                if prev == 1:#end signal segment
                    pair.append(l-1)
                    result.append(pair)
                    pair = None
                prev = 0
        return result,ltsds

    def _ltse(self,signal,l):
        maxamp = sp.zeros(self._winsize)
        for idx in range(l-self._order,l+self._order+1):
            amp = self._get_amplitude(signal,idx)
            maxamp = sp.maximum(maxamp,amp)
        return maxamp

    def _ltsd(self,signal,l):
        if l < self._order or l+self._order >= self._windownum:
            return 0
        return 10.0*sp.log10(sp.sum(self._ltse(signal,l)**2/self._avgnoise)/float(len(self._avgnoise)))


class AdaptiveLTSD(LTSD):
    def __init__(self,winsize,window,order,ratio=0.95,e0=200,e1=300,lambda0=40,lambda1=50):
        self._ratio = ratio
        LTSD.__init__(self,winsize,window,order,e0,e1,lambda0,lambda1)

    def _update_noise_spectrum(self,signal,l):
        avgamp = sp.zeros(self._winsize)
        for idx in range(l-self._order,l+self._order+1):
            avgamp += self._get_amplitude(signal,idx)
        avgamp = avgamp / float(self._order*2 + 1)
        self._avgnoise = self._avgnoise * self._ratio + (avgamp**2)*(1.0-self._ratio)
    
    def _compute(self,signal):
        ltsds = sp.zeros(self._windownum)
        prev = 0
        pair = None
        result = []
        for l in range(self._windownum):
            ltsd = self._ltsd(signal,l)
            ltsds[l]=ltsd
            x = self._is_signal(signal,ltsd,l)
            if x:# signal
                if prev == 0:#start signal segment
                    pair = [l]
                prev = 1
            else:#noise
                if prev == 1:#end signal segment
                    pair.append(l-1)
                    result.append(pair)
                    self._update_noise_spectrum(signal,l)
                    pair = None
                prev = 0
        return result,ltsds

if __name__ == "__main__":

    signal,params = read_signal(sys.argv[1],WINSIZE)
    window = sp.hanning(WINSIZE)
    
    ltsd = LTSD(WINSIZE,window,5)
    res,ltsds =  ltsd.compute_without_noise(signal,WINSIZE*int(params[2] /float(WINSIZE)/3.0))
    print(ltsds)
    import matplotlib.pyplot as plt
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(ltsds)
    plt.show()
    print (res)
