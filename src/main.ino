#include <Arduino.h>
#include "LoadSensor.h"

LoadSensor loadSensor(0);

int     zero            = 0;
int     max             = 1024;
int     currentVoltage  = 0;
int     zeroedVoltage   = 0;
float   percentMax      = 0.0;
int     serialByte      = 0;
char    serialCharacter = '\0';

void setup ()
{
    // Start serial communication
    Serial.begin(9600);
}

void loop ()
{
    // Get current voltage
    currentVoltage = loadSensor.getVoltage();

    // Compute zeroed voltage and percent of maximum voltage
    zeroedVoltage = currentVoltage - zero;
    percentMax = (float)zeroedVoltage / (float)(max - zero) * 100;

    // Output zeroed voltage
    Serial.print('\r');
    Serial.print("             ");
    Serial.print('\r');
    Serial.print("Read: " + (String)zeroedVoltage + "(");
    Serial.print(percentMax, 0);
    Serial.print("%)");
    Serial.print('\r');

    // Check for tare signal
    if (Serial.available())
    {
        serialByte = Serial.read();
        serialCharacter = (char)serialByte;

        if (serialCharacter == 't')
        {
            Serial.print('\n');
            Serial.print('\r');
            Serial.println("Tare: "+(String)currentVoltage);
            zero = currentVoltage;
        }
        if (serialCharacter == 'm')
        {
            Serial.print('\n');
            Serial.print('\r');
            Serial.println("Max: "+(String)zeroedVoltage);
            max = currentVoltage;
        }
    }

    delay(1000);
}