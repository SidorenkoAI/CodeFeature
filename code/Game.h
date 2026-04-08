#pragma once
#include<Arduino.h>
#include <LiquidCrystal_I2C.h>


class Game{
  LiquidCrystal_I2C *_lcd;
  public:
  Game(LiquidCrystal_I2C *lcd);
  void init();
};