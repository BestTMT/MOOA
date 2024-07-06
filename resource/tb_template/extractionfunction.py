# -*- coding: utf-8 -*-

# please convert the rawdata into two lists before using these functions 


import numpy as np
import scipy

def dcGain_dB(freq_var, frequencyResponse):
    """
    freq_var: in Hz,  frequencyResponse: complex list
    Calculate the gain at 1 Hz, return as real number in dB
    """
    try:
        dc_gain = 20.0*np.log10(np.abs(np.interp(1.0, freq_var, frequencyResponse)))
        return float(dc_gain)    
    except:
        return 0.0


def unityGainFrequency(freq_var, frequencyResponse):
    """
    freq_var : 1-D ndarray
        Frequency points in Hz
    frequencyResponse : 1-D ndarray
        Frequency response points, given as an array of complex numbers
    """
    amplitudeResponse = np.abs(frequencyResponse)
    try:
        firstBelowUnityIndex = np.min(np.where(amplitudeResponse < 1))
        initialGuess = freq_var[firstBelowUnityIndex - 1]
        return scipy.optimize.root(lambda x: np.interp(x,
                                                       freq_var[firstBelowUnityIndex -
                                                                          1: firstBelowUnityIndex + 1],
                                                       amplitudeResponse[firstBelowUnityIndex -
                                                                         1: firstBelowUnityIndex + 1],
                                                       left=np.nan, right=np.nan) - 1, initialGuess).x[0]
    except:
        return 0.0


def slewRate(time_var, wave):
    """Calculate the slew rate 
    time_var: in second
    wave: in voltage
    """
    initialValue = np.min(wave)
    finalValue = np.max(wave)
    precentHigh = 0.6*(finalValue-initialValue)+initialValue
    precentLow = 0.1*(finalValue-initialValue)+initialValue
    firstIndexPrecentHgih = np.min(np.where(wave >= precentHigh))
    firstIndexPrecentLow = np.min(np.where(wave >= precentLow))
    if time_var[firstIndexPrecentHgih] <= time_var[firstIndexPrecentLow]:
        return 0.0
    else:
        slewRateInVPerSecond = (precentHigh-precentLow) / (time_var[firstIndexPrecentHgih]-time_var[firstIndexPrecentLow])
        #return np.max(np.abs(np.diff(wave) / np.diff(time_var)))
        return float(slewRateInVPerSecond)