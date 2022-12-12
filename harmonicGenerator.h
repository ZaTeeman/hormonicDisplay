#ifndef HARMONICGENERATOR_H
#define HARMONICGENERATOR_H

#include "tsignal.h"
#include <cmath>

extern TSignal<double> signal1;

template <class T1, class T2, class T3, class T4>
class HarmonicGenerator
{
private:
    T1 amplitude;           //Амплитуда
    T2 frequency;           //Частота сигнала
    T3 phase;               //Начальная фаза сигнала
    T4 samplingFrequency;   //Частота дескретизации
    int pointCounter = 0;   //индекс последней сгенерированной точки
public:
    HarmonicGenerator( T1 amplitude, T2 frequency, T3 phase, T4 frequencyOfDescretisation);
    T1 generatePoint ();
    T1 getAmp();
    void setAmp(T1);
    void setFreq(T2);
    void setPhase (T3);
    void setSamplingFreq (T4);
};

template <class T1, class T2, class T3, class T4>
HarmonicGenerator<T1, T2, T3, T4>::HarmonicGenerator(T1 amplitude, T2 frequency, T3 phase, T4 samplingFrequency)
{
    this->amplitude = amplitude;
    this->frequency = frequency;
    this->phase = phase;
    this->samplingFrequency = samplingFrequency;
}

template <class T1, class T2, class T3, class T4>
T1 HarmonicGenerator<T1, T2, T3, T4>::generatePoint()
{
    float val = this->amplitude * sin(2 * M_PI * this->pointCounter * this->frequency / this->samplingFrequency + this->phase); //= A sin (ωt + φ), ω=2 πf
    this->pointCounter++;
    if (this->pointCounter > (int)signal1.getSignalSize() )
    {
        this->pointCounter = 0;
        signal1.resetSignal();
        val = 0;
    }
    return val;
}

template <class T1, class T2, class T3, class T4>
T1 HarmonicGenerator<T1, T2, T3, T4>::getAmp()
{
    return this->amplitude;
}

template <class T1, class T2, class T3, class T4>
void HarmonicGenerator<T1, T2, T3, T4>::setAmp(T1 amp)
{
    this->amplitude = amp;
}

template <class T1, class T2, class T3, class T4>
void HarmonicGenerator<T1, T2, T3, T4>::setFreq(T2 freq)
{
    this->frequency = freq;
}

template <class T1, class T2, class T3, class T4>
void HarmonicGenerator<T1, T2, T3, T4>::setPhase(T3 ph)
{
    this->phase = ph;
}

template <class T1, class T2, class T3, class T4>
void HarmonicGenerator<T1, T2, T3, T4>::setSamplingFreq(T4 sFreq)
{
    this->samplingFrequency = sFreq;
}

#endif
