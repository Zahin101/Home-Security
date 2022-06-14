
# include <LiquidCrystal.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

int buzzer = 4;
int green = 2;
int red = 6;
int b1 = A3;
int d1 = 5;
int buzzer_1 = 3;

//int cnt=0,cnt2;
//int timer=0;
                // a maximum of eight servo objects can be created 
//int pos = 0; 

 void setup(){
  lcd.begin(16,2);
  pinMode (buzzer, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(b1, INPUT_PULLUP);
  pinMode(d1, OUTPUT);
  pinMode (buzzer_1, OUTPUT);
  digitalWrite(d1, HIGH);
  digitalWrite(d1,LOW);               // wait for a second
//  cnt=0;
  Serial.begin(9600);
  
 }

 void loop (){
  int pirState = digitalRead(7);//could be some other pin
  lcd.setCursor (0, 0);
  lcd.print("Team 4-mation");
  delay(300);
 
  if(pirState == LOW){
//    Serial.print(pirState);
//    Serial.println();
    lcd.clear();
    lcd.setCursor (0, 1);
    lcd.print("NO INTRUDER");
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
    Serial.print(pirState);
    Serial.println();
//    delay(500);
    //lcd.clear();
  }
  else if(pirState == HIGH){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Warning Intruder Alert");
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.print(pirState);
    Serial.println();
//    delay(500);
    //lcd.clear();
    
    
  }
  if(digitalRead(b1) == HIGH){
      
    Serial.print(1);
    Serial.println(); 
    lcd.setCursor(0,1);
    lcd.print("Warning Intruder Alert");
    digitalWrite(buzzer_1, HIGH);
    digitalWrite(d1, HIGH);
//    delay(500);               // wait for a second

  }
  else if(digitalRead(b1) == LOW){
    Serial.print(0);
    Serial.println();
    digitalWrite(buzzer_1, LOW);
    digitalWrite(d1, LOW);
//    delay(500);
  }
 }
