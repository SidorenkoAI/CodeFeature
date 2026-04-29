#include <Button.h>
#define PIR 2
#define BUT 8
#define LED 11
#define BUZ 5
#define PHOTO A0
int porog = 950;

Button b(8);
void setup() {
  pinMode(PIR, INPUT);
  pinMode(BUT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

uint32_t t, hand;
int dvij = 0;
void loop() {
  static bool flag = false;
  if (b.pressed()){
    digitalWrite(LED, HIGH);
    hand = millis();
    flag = true;
  }
  if (flag)
    if(millis() - hand > 30000){
      digitalWrite(LED, LOW);
      flag = false;
    }
  
  bool svetlo = false;
  if (analogRead(PHOTO) < porog)
    svetlo = true;
 
  Serial.println(dvij);
   //tone(5, 3000, 500);
   bool now = digitalRead(PIR); 
   static bool lastState = true;
   if (now and lastState and svetlo){
        delay(10);
        if (digitalRead(PIR)){
          lastState = false;
          digitalWrite(LED, HIGH);
          dvij += 1;
          t = millis();
        }
      }
    if (now == 0 and lastState == false){
        lastState = true;
    }
  
    
      if (!digitalRead(PIR) and !flag){
        if (millis() - t > 5000){
          digitalWrite(LED, LOW);
        }   
      }
  
  
}

