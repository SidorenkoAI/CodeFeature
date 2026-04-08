#include "Pacman.h"

Pacman::Pacman(LiquidCrystal_I2C *lcd){
    _lcd = lcd;
}

 void Pacman::show(){
    _lcd->setCursor(x, y);
    if (skin)
        _lcd->write(0);
    else 
        _lcd->write(1);
    skin = !skin;
    delay(200);
 }

 void Pacman::right(){
    _lcd->setCursor(x, y);
    _lcd->print(' ');
    x += 1;
    if (x > 19)
        x = 0;
    show();
 }
 
 void Pacman::left(){
    _lcd->setCursor(x, y);
    _lcd->print(' ');
    x -= 1;
    if (x < 0)
        x = 19;
    show();
 }

  void Pacman::up(){
    _lcd->setCursor(x, y);
    _lcd->print(' ');
    y -= 1;
    if (y < 0)
        y = 3;
    show();
 }

  void Pacman::down(){
    _lcd->setCursor(x, y);
    _lcd->print(' ');
    y += 1;
    if (y > 3)
        y = 0;
   show();
 }

   int Pacman::getX(){
        return x;
   }
  int Pacman::getY(){
        return y;
  }

 