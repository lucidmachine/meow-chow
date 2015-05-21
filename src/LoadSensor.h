#ifndef LOAD_SENSOR_H
#define LOAD_SENSOR_H

class LoadSensor
{
private:
    int pinNumber;
    int voltage;
    
    bool setPinNumber(int newPinNumber);

public:
    LoadSensor(int pinNumber);

    int getPinNumber();

    int getVoltage();
};

#endif