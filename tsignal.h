#ifndef TSIGNAL_H
#define TSIGNAL_H

#include <vector>
#include "qvector.h"
#include <iostream>

using namespace std;

template <class T>
class TSignal
{
private:
    QVector<T> signal;
    int maxSignalSise;
public:
    TSignal(int signalSize);
    void addPoint(T point);
    QVector<T> getVector();
    int getSignalSize();
    void setMaxSignalSize(int);
    void resetSignal();
};

template <class T>
TSignal<T>::TSignal(int signalSize)
{   
   signal.fill(0, signalSize);
   this->maxSignalSise = signalSize;
}

template <class T>
void TSignal<T>::addPoint(T point)
{
    signal.removeLast();
    signal.insert(0, point);
}

template <class T>
QVector<T> TSignal<T>::getVector()
{
    return signal;
}

template <class T>
int TSignal<T>::getSignalSize()
{
    return this->maxSignalSise;
}

template <class T>
void TSignal<T>::setMaxSignalSize(int size)
{
    this->maxSignalSise = size;
    signal.fill(0, this->maxSignalSise);
}

template <class T>
void TSignal<T>::resetSignal()
{
    signal.fill(0, this->maxSignalSise);
}

#endif
