const int pinDisplay_4 = 6;
const int pinDisplay_3 = 7;
const int pinDisplay_2 = 8;
const int pinDisplay_1 = 9;

const int pinD = 5;
const int pinC = 4;
const int pinB = 3;
const int pinA = 2;




// pin 4 -> GP2  -> A  LSB
// pin 5 -> GP3  -> B
// pin 6 -> GP4  -> C
// pin 7 -> GP5  -> D  MSB



int count = 1000;

void setup() {
  Serial.begin(9600);

  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);  
  }
  
}

int c = 0;
unsigned long dt, t1;

void loop() {

  displayDigit(1, (c%10));
  delay(2);
  displayDigit(2, ((c/10)%10));
  delay(2);
  displayDigit(3, ((c/100)%10));
  delay(2);
  displayDigit(4, ((c/1000)%10));
  delay(2);
  
  dt = millis() - t1;
  if (dt >= 200) {
  c++;
  t1 = millis();
    
  } 
}

void displayDigit(int d, int n) {
  
 switch(d){
 case 1:
  digitalWrite(pinDisplay_1, HIGH); 
  digitalWrite(pinDisplay_2, LOW); 
  digitalWrite(pinDisplay_3, LOW); 
  digitalWrite(pinDisplay_4, LOW); 
  break;
 case 2:
  digitalWrite(pinDisplay_1, LOW); 
  digitalWrite(pinDisplay_2, HIGH); 
  digitalWrite(pinDisplay_3, LOW); 
  digitalWrite(pinDisplay_4, LOW); 
  break; 
 case 3:
  digitalWrite(pinDisplay_1, LOW); 
  digitalWrite(pinDisplay_2, LOW); 
  digitalWrite(pinDisplay_3, HIGH); 
  digitalWrite(pinDisplay_4, LOW); 
  break;
 case 4:
  digitalWrite(pinDisplay_1, LOW); 
  digitalWrite(pinDisplay_2, LOW); 
  digitalWrite(pinDisplay_3, LOW); 
  digitalWrite(pinDisplay_4, HIGH); 
  break; 

 }      
     
  
  digitalWrite(pinA, (n & 0b00000001));
  digitalWrite(pinB, (n & 0b00000010));
  digitalWrite(pinC, (n & 0b00000100));
  digitalWrite(pinD, (n & 0b00001000));    
}
