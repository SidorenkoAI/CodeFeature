#include <LiquidCrystal_I2C.h>
#include "Game.h"
#include "Pacman.h"
#include "Stick.h"
#include "Apple.h"
LiquidCrystal_I2C lcd(0x27, 20, 4);

Game game(&lcd);
Pacman pac(&lcd);
Apple apples[10];
Stick stick;


void setup() {
  game.init();
  Serial.begin(9600);
  for(int i = 0; i < 10; i++){
    apples[i] = Apple(&lcd);
    apples[i].show();
  }
}



void loop() {
   for(int i = 0; i < 10; i++){
      if (apples[i].getX() == pac.getX())
        Serial.println("!!!!");
   };
  if (stick.getDir() == 1)
    pac.up();
  else if (stick.getDir() == 2)
    pac.right();
  else if (stick.getDir() == 3)
    pac.down();
  else if (stick.getDir() == 4)
    pac.left();
 }
