#include <Arduino.h>
#include "Scale.h"


Scale scales[] = {Scale(0), Scale(0)};

int     serialByte      = 0;
char    serialCharacter = '\0';


void setup ()
{
    // Start serial communication
    Serial.begin(9600);
}

void loop ()
{
    outputScaleReadings();
    handleInput();
    delay(1000);
}

void outputScaleReadings ()
{
    Serial.print('\r');
    Serial.print("                                ");
    Serial.print('\r');
    Serial.print(scales[0].print() + "\t" + scales[1].print());
    Serial.print('\r');
}

void handleInput ()
{
    if (Serial.available())
    {
        // Get serial input
        serialByte = Serial.read();
        serialCharacter = (char)serialByte;

        switch (serialCharacter)
        {
            case 't':
                tareScale(0);
                break;
            case 'y':
                tareScale(1);
                break;
            case 'm':
                maxScale(0);
                break;
            case ',':
                maxScale(1);
                break;
        }
    }
}

void tareScale(int scaleIndex)
{
    Serial.print('\n');
    Serial.print('\r');
    Serial.println("Tare " + (String)scaleIndex + ": " + (String)scales[scaleIndex].getWeight());
    scales[scaleIndex].tare();
}

void maxScale(int scaleIndex)
{
    Serial.print('\n');
    Serial.print('\r');
    Serial.println("Max " + (String)scaleIndex + ": " + (String)scales[scaleIndex].getWeight());
    scales[scaleIndex].maximum();
}