#pragma once
#include <Arduino.h>

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN 7


class Stick{
  public:
  Stick();
  int getDir();
};