#include "Arduino.h"

int EncoderPinA = 3;
int EncoderPinB = 4;
int EncoderPos = 0;
int EncoderLast = LOW;
int EncoderCurrent = LOW;

void setup()
{
  pinMode(EncoderPinA, INPUT);
  pinMode(EncoderPinB, INPUT);
  Serial.begin(9600);
}

void loop()
{
  EncoderCurrent = digitalRead(EncoderPinA);
  if ((EncoderLast == LOW) && (EncoderCurrent == HIGH))
  {
    if (digitalRead(EncoderPinB) == LOW)
    {
      EncoderPos--;
    }
    else
    {
      EncoderPos++;
    }
    Serial.println(EncoderPos);
  }
  EncoderLast = EncoderCurrent;
}
