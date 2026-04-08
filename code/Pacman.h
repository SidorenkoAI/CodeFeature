#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Pacman{
  LiquidCrystal_I2C *_lcd;
  int x = 0;
  int y = 0;
  bool skin = true;
  void show();
  public:
  Pacman(LiquidCrystal_I2C *lcd);
  void right();
  void left();
  void up();
  void down();
  int getX();
  int getY();
};