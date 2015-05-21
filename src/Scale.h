#ifndef SCALE_H
#define SCALE_H

#include <Arduino.h>
#include "LoadSensor.h"

class Scale
{
private:
    LoadSensor *sensor;

    int zero = 0;
    int max = 1024;

public:
    Scale(int pinNumber);
    ~Scale();

    void tare();
    void maximum();

    int getPinNumber();

    int getZero();
    bool setZero(int newZero);
    int getMax();
    bool setMax(int newMax);


    int getWeight();
    float getPercentMax();

    String print();
};

#endif