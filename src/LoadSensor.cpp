#include <Arduino.h>
#include "LoadSensor.h"

LoadSensor::LoadSensor (int pinNumber)
{
    // Set pin
    this->setPinNumber(pinNumber);
}

int LoadSensor::getPinNumber ()
{
    return this->pinNumber;
}

bool LoadSensor::setPinNumber (int newPinNumber)
{
    if (newPinNumber >= 0 && newPinNumber <= 5)
    {
        this->pinNumber = newPinNumber;
        return true;
    }

    return false;
}

int LoadSensor::getVoltage ()
{
    return analogRead(this->pinNumber);
}