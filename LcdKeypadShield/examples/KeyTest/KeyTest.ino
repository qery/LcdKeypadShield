#include"LcdKeypadShield.h"
#include<LiquidCrystal.h>

LcdKeypad lcdShield;

void setup()
{
  lcdShield.clear();
  lcdShield.println("LCDKeypad Shield");
  lcdShield.println("testing keys...");
}

int keycode=0;
int count=0;

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
        break;
      case KEY_DOWN:
        lcdShield.print("Down   ");
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
