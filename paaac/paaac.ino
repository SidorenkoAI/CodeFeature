#include <LiquidCrystal_I2C.h>
#include "Game.h"
#include "Pacman.h"
#include "Stick.h"
#include "Apple.h"
LiquidCrystal_I2C lcd(0x27, 20, 4);

Game game(&lcd);
Pacman pac(&lcd);
Apple apple[10];
Stick stick;

void setup() {
  game.init();
  for(int i = 0; i < 10; i ++){
  apple[i] = ap(&lsd);
  apple[i].show();
  }
}

void loop() {
if(stick.getDir() == 1)
  pac.up();
if(stick.getDir() == 2)
  pac.right();
if(stick.getDir() == 3)
  pac.down();
if(stick.getDir() == 4)
  pac.left();
 }