#ifndef LCDKEYPADSHIELD_H
#define LCDKEYPADSHIELD_H

#include <LiquidCrystal.h>
#include <Arduino.h>

#define KEY_NONE    0
#define KEY_RIGHT   1
#define KEY_UP      2
#define KEY_DOWN    3
#define KEY_LEFT    4
#define KEY_SELECT  5

class LcdKeypad : public LiquidCrystal
{
  private:
    int adc_val[5] ={30,150,360,535,760};
    int adc_value=0;

    unsigned long time_start=0;
    
    byte key_current=KEY_NONE;
    byte key_last=KEY_NONE;
  public:
    LcdKeypad() : LiquidCrystal(8,9,4,5,6,7)
    {
      pinMode(A0,INPUT);
      begin(16,2);
      clear();
    };
    byte keyPressed()
    {
      adc_value=analogRead(A0);

      for (byte i=0;i<5;i++)
        if (adc_value<adc_val[i])
        {
          if (time_start==0)
          {
            time_start=millis();
            return KEY_NONE;
          }
          else
          {
            if (millis()-time_start>250)
            {
              key_last=key_current;
              key_current=i+1;
              if (key_current!=key_last)
              {
                time_start=0;
                return  key_current;
              }
              else
                return KEY_NONE;
            }
          }
        }
      key_current=KEY_NONE;
      return KEY_NONE;
    };
};
#endif
