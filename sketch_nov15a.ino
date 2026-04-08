void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(A1, INPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
int summa(int x){
  int s;
  for(int i = 1; i>=x; i++){
    s+=i;
  }
  return s;
}

int ints(int g){
  if (g >0){
    return g;
  }
  else{
    return 0;
  }
}

void RGB(int speed = 1, int oldR = 0, int oldG = 0, int oldB = 0, int newR = 0, int newG = 0, int newB = 0, int step = 1) {
  int r = oldR, g = oldG, b = oldB;
  
  while (r != newR || g != newG || b != newB) {
    r = constrain(r, 0, 255);
    g = constrain(g, 0, 255);
    b = constrain(b, 0, 255);
    
    int yellow = 0;
    int white = 0;
    int redOut = 0;
    int greenOut = 0;
    int blueOut = 0;
    
    if (r == g && g == b) {
      white = r;
      yellow = 0;
      redOut = 0;
      greenOut = 0;
      blueOut = 0;
    } 
    else if (r == g && r > b) {
      yellow = min(r, g);
      white = b;
      redOut = ints(r - yellow - white);
      greenOut = ints(g - yellow - white);
      blueOut = ints(b - white);
    }
    else if (r == b && r > g) {
      yellow = 0;
      white = min(g, min(r, b));
      redOut = ints(r - white - 25); // -25 как в оригинале
      greenOut = ints(g - white);
      blueOut = ints(b - white);
    }
    else {
      int minComponent = min(r, min(g, b));
      white = minComponent;
      
      // Оставшиеся компоненты после вычитания белого
      int remainingR = r - white;
      int remainingG = g - white;
      int remainingB = b - white;
      
      // Желтый формируется из красного и зеленого
      yellow = min(remainingR, remainingG);
      
      redOut = ints(remainingR - yellow);
      greenOut = ints(remainingG - yellow);
      blueOut = ints(remainingB);
    }

    analogWrite(5, constrain(redOut, 0, 255));
    analogWrite(3, constrain(greenOut, 0, 255));
    analogWrite(6, constrain(blueOut, 0, 255));
    analogWrite(9, constrain(yellow, 0, 255));
    analogWrite(10, constrain(white, 0, 255));
    
    if (r < newR) r = min(r + step, newR);
    else if (r > newR) r = max(r - step, newR);
    
    if (g < newG) g = min(g + step, newG);
    else if (g > newG) g = max(g - step, newG);
    
    if (b < newB) b = min(b + step, newB);
    else if (b > newB) b = max(b - step, newB);
    
    delay(speed);
  }
  
  r = newR;
  g = newG;
  b = newB;
  

  int yellow = 0;
  int white = 0;
  int redOut = 0;
  int greenOut = 0;
  int blueOut = 0;
  
  if (r == g && g == b) {
    white = r;
  } 
  else if (r == g && r > b) {
    yellow = min(r, g);
    white = b;
    redOut = ints(r - yellow - white);
    greenOut = ints(g - yellow - white);
    blueOut = ints(b - white);
  }
  else {
    int minComponent = min(r, min(g, b));
    white = minComponent;
    int remainingR = r - white;
    int remainingG = g - white;
    int remainingB = b - white;
    yellow = min(remainingR, remainingG);
    redOut = ints(remainingR - yellow);
    greenOut = ints(remainingG - yellow);
    blueOut = ints(remainingB);
  }
  
  analogWrite(5, constrain(redOut, 0, 255));
  analogWrite(3, constrain(greenOut, 0, 255));
  analogWrite(6, constrain(blueOut, 0, 255));
  analogWrite(9, constrain(yellow, 0, 255));
  analogWrite(10, constrain(white, 0, 255));
}
int counter = 0;
bool notNow = true,notNow2 = true;
int a, mod=0, speed=2;

void loop() {
  a = digitalRead(2);
  bool now = digitalRead(4);
  if (now && notNow){
      delay(10);
      if (digitalRead(4)){
        speed += 5;
        notNow2 = false;
      }
    }
    if (!notNow && !now){
      notNow = true;
    }
    //конец блока подсчета нажатий
  bool noww = digitalRead(2);
  if (noww && notNow){
      delay(10);
      if (digitalRead(2)){
        mod += 1;
        notNow = false;
      }
    }
    if (!notNow && !noww){
      notNow = true;
    }
    //конец блока подсчета нажатий
  if (mod > 14){
    mod=0;
  }
  if (speed > 20){
    speed=0;
  }
  if (mod == 0){
    RGB(speed,255,0,0,0,0,255);
    RGB(speed,0,0,255,0,255,0);
    RGB(speed,0,255,0,255,0,0);
  }
  else if (mod == 1){
    RGB(speed,0,0,0,255,255,255);
    RGB(speed,255,255,255,0,0,0);
  }
  else if (mod == 2){
    RGB(speed,255,0,0,0,0,255);
    RGB(speed,0,0,255,255,0,0);
  }
  else if (mod == 3){
    RGB(speed,55,80,25,100,255,0);
    RGB(speed,100,255,0,55,186,25);
  }
  else if (mod == 4){
    RGB(speed,0,0,0,255,255,255);
    RGB(speed,255,255,255,255,0,0);
    RGB(speed,255,0,0,0,255,0);
    RGB(speed,0,255,0,0,0,255);
    RGB(speed,0,0,255,255,0,255);
    RGB(speed,255,0,255,0,255,255);
    RGB(speed,0,255,255,255,0,255);
    RGB(speed,255,0,255,0,0,0);
  }
  else if (mod == 5){
    RGB(speed,255,0,0,0,0,0);
    RGB(speed,0,0,0,255,0,0);
  }
  else if (mod == 6){
    RGB(speed,0,255,0,0,0,0);
    RGB(speed,0,0,0,0,255,0);
  }
  else if (mod == 7){
    RGB(speed,0,0,255,0,0,0);
    RGB(speed,0,0,0,0,0,255);
  }
  else if (mod == 8){
    RGB(speed,255,255,0,0,0,0);
    RGB(speed,0,0,0,255,255,0);
  }
  else if (mod == 9){
    RGB(speed,255,0,255,0,0,0);
    RGB(speed,0,0,0,255,0,255);
  }
  else if (mod == 10){
    RGB(1,1,0,0,100,0,255);
    RGB(1,15,0,255,0,0,0);
    RGB(0,0,0,0,25,0,55);
    RGB(2,15,0,255,0,0,0);
    RGB(0,0,0,0,170,0,255);
    RGB(2,170,0,255,1,1,0);
  }
  else if (mod == 11){
    RGB(6,255,255,0,255,100,0);
    RGB(4,255,100,0,255,150,20);
    RGB(2,255,150,0,255,255,50);
  }
  else if (mod == 12){
    RGB(10,100,0,255,150,0,205);
    RGB(10,150,0,205,100,0,255);
  }
  else if (mod == 13){
    int t = 20;
    RGB(t,0,0,255,0,255,0);
    RGB(t,0,255,0,0,0,255);
  }
  else if (mod == 14){
    int t = 20;
    RGB(t,255,0,0,0,255,0);
    RGB(t,0,255,0,255,0,0);
  }
}
