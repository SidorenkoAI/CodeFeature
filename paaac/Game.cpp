#include "Game.h"


byte Apple[] = {
  0b00011,
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01010,
  0b00000
}

byte pacOpen[] = {
  0b00110,
  0b01101,
  0b11111,
  0b11100,
  0b11110,
  0b01111,
  0b00110,
  0b00000
};

byte pacClose[] = {
  0b00000,
  0b01110,
  0b11111,
  0b11101,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};


Game::Game(LiquidCrystal_I2C *lcd){
    _lcd = lcd;
}

 void Game::init(){
  _lcd->init();
  _lcd->backlight(); 
  _lcd->createChar(0, pacOpen);
  _lcd->createChar(1, pacClose);
  _lcd->createChar(2, Apple);

 }