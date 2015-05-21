#include "Scale.h"

Scale::Scale (int pinNumber)
{
    // Create sensor
    this->sensor = new LoadSensor(pinNumber);
}

Scale::~Scale ()
{
    delete this->sensor;
    this->sensor = NULL;
}

void Scale::tare ()
{
    this->setZero(this->sensor->getVoltage());
}

void Scale::maximum ()
{
    this->setMax(this->sensor->getVoltage());
}

int Scale::getPinNumber ()
{
    return this->sensor->getPinNumber();
}

int Scale::getZero ()
{
    return this->zero;
}

bool Scale::setZero (int newZero)
{
    if (newZero >= 0 && newZero <=1024)
    {
        this->zero = newZero;
        return true;
    }

    return false;
}

int Scale::getMax ()
{
    return this->max;
}

bool Scale::setMax (int newMax)
{
    if (newMax >= 0 && newMax <= 1024 && newMax > this->getZero())
    {
        this->max = newMax;
        return true;
    }

    return false;
}

int Scale::getWeight ()
{
    return this->sensor->getVoltage() - this->zero;
}

float Scale::getPercentMax ()
{
    return (float)this->getWeight() / (float)(this->getMax() - this->getZero()) * 100;
}

String Scale::print ()
{
    return "Scale " + (String)this->getPinNumber() + ": " + (String)this->getWeight() + " (" + (String)(long)this->getPercentMax() + "%)";
}