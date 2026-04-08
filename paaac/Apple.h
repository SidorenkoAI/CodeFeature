#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Apple{
  LiquidCrystal_I2C *_lcd;
  int x = 0;
  int y = 0;
  public:
  Apple(LiquidCrystal_I2C *lcd);
  void show();
  Apple();
};