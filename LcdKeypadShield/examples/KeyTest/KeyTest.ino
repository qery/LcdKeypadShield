#include"LcdKeypadShield.h"
#include<LiquidCrystal.h>

LcdKeypad lcdShield;

int keycode=0;
int count=0;
byte bright=100;

void setup()
{
  lcdShield.clear();
  lcdShield.println("LCDKeypad Shield");
  lcdShield.setBrightness(bright);
}

void loop()
{
  keycode=lcdShield.keyPressed();
  if (keycode>0)
  {
    lcdShield.setCursor(0,2);
    switch (keycode)
    {
      case KEY_RIGHT:
        lcdShield.print("Right  ");
        count++;
        break;
      case KEY_UP:
        lcdShield.print("Up     ");
        count++;
        if (bright<250)
        	bright+=5;
        lcdShield.setBrightness(bright);
        break;
      case KEY_DOWN:
        lcdShield.print("Down   ");
        if (bright>5)
          bright-=5;
        lcdShield.setBrightness(bright);
        count++;
        break;
      case KEY_LEFT:
        lcdShield.print("Left   ");
        count++;
        break;
      case KEY_SELECT:
        lcdShield.print("Select ");
        count++;
        break;
    }
    lcdShield.print(count);
  }
}
