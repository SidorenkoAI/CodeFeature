#include <Button.h>
#define PIR 2
#define BUT 8
#define LED 11
#define BUZ 5
#define PHOTO A0

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
void loop() {
  //tone(5, 3000, 500);
 Serial.println(analogRead(PHOTO));
 
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

  if (digitalRead(PIR)){
      digitalWrite(LED, HIGH);
      t = millis();
  }
 
  if (!digitalRead(PIR) and !flag){
    if (millis() - t > 5000){
      digitalWrite(LED, LOW);
     }   
  }
  
}
