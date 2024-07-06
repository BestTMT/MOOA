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
    
def PSRR(freq_var, frequencyResponse):
    """
    freq_var: in Hz,  frequencyResponse: complex list
    Calculate the 1/Amplitude Response at 1 kHz, return as real number in dB
    """
    amplitudeResponse = np.abs(frequencyResponse)
    try:
        oneOverVout = 1/np.abs(np.interp(1000, freq_var, amplitudeResponse))
        psrr = oneOverVout
        return psrr    
    except:
        return 0.0
    
def phaseMargin(freq_var, frequencyResponse):
        """
        freq_var: in Hz,  frequencyResponse: complex list
        Calculate the phase margin in degree
        """
        phaseResponse =  np.angle(np.array(frequencyResponse), deg=True)
        ugf = unityGainFrequency(freq_var, frequencyResponse)
        while np.sum(phaseResponse>0.0):
            phaseResponse[np.where(phaseResponse > 0.0)] -= 360.0
        try:
            phaseAtUnityGain = np.interp(ugf, freq_var, phaseResponse)
            pm = phaseAtUnityGain + 180.0
            return float(pm)
        except:
            return 0.0
    
def CMRR(freq_var, frequencyResponse):
    """
    freq_var: in Hz,  frequencyResponse: complex list
    Calculate the 1 / Amplitude Response at 1 kHz, return as real number in dB
    """
    amplitudeResponse = np.abs(frequencyResponse)
    try:
        oneOverVout = 1/np.abs(np.interp(1000, freq_var, amplitudeResponse))
        cmrr = oneOverVout
        return cmrr    
    except:
        return 0.0
    
def OCMR(sweep_var, vout_dc):
    """
    sweep_var: in V,  vout_dc: 1-D list
    Calculate the OCMR [V]
    ideal gain of the testbench is -10X
    """
    diff_vout_dc_list = []
    try:
        for i in range(len(sweep_var)-1):
            diff_vout = (vout_dc[i+1] - vout_dc[i]) / (sweep_var[i+1] - sweep_var[i])
            diff_vout_dc_list.append(diff_vout)
            
        firstIndexSlopeNeg10 = np.min(np.where(np.array(diff_vout_dc_list) <= -9))
        lastIndexSlopeNeg10 = np.max(np.where(np.array(diff_vout_dc_list) <= -9))
        ocmr = vout_dc[lastIndexSlopeNeg10] - vout_dc[firstIndexSlopeNeg10]
        return abs(ocmr)    
    except:
        return 0.0