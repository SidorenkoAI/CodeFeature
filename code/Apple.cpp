#include "Apple.h"

Apple::Apple(){

}

Apple::Apple(LiquidCrystal_I2C *lcd){
    _lcd = lcd;
    randomSeed(analogRead(A2));

}

  int Apple::getX(){
    return x;  
  }

int Apple::getY(){
    return y;  
  }

 void Apple::show(){
    x = random(0, 20);
    y = random(0, 4);
    _lcd->setCursor(x, y);
    _lcd->write(2);
  
 }