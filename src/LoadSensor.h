#ifndef LOAD_SENSOR_H
#define LOAD_SENSOR_H

class LoadSensor
{
private:
    int pinNumber;
    int voltage;

public:
    LoadSensor(int pinNumber);

    int getPinNumber();
    bool setPinNumber(int newPinNumber);

    int getVoltage();
};

#endif