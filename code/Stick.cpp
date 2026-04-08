#include "Stick.h"

Stick::Stick(){
    pinMode(SEL_PIN, INPUT);
}

 
 int Stick::getDir(){
    if (analogRead(VERT_PIN) > 1000)
        return 1;
    else if (analogRead(VERT_PIN) < 50)
        return 3;
    else if (analogRead(HORZ_PIN) > 1000)
        return 4;
    else if (analogRead(HORZ_PIN) < 50)
        return 2;
    else
        return 0;

 }