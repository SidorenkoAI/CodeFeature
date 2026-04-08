#include "Apple.h"
Apple::Apple(){

}
Apple::Apple(LiquidCrystal_I2C *lcd){
    _lcd = lcd;
}
void Apple::show(){
 x = random(0,20);
 y = random(0,3);
_lcd->setCursor(x, y);
 _lcd->write(2)
}