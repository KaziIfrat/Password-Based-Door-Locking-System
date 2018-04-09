#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

Servo myservo;
int pos = 0; 


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 4;

/*char hexaKeys[ROWS][COLS] = {
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},   //FOR SIMULATION PART
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};*/

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},  //FOR REAL PROJECT
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {A3, A2, A1, A0};
byte colPins[COLS] = {10, 8, 7, 6};
String us_id[10] = {"123456"};
String us_ps[10]={"123456","0000","1111","2222","2222"};

int x,i;
String ps = "";
String us = "";


Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(13, OUTPUT);
  myservo.attach(9);
  lcd.begin(16, 2);
  lcd.print("HELLOW");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  lcd.setCursor(0, 1);
  
}

void loop() {
  
  
  
  char key = myKeypad.getKey();

  if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == 'D' || key == 'A' || key == 'B' || key == 'C' ) {
    lcd.print("*");
    ps = ps + String(key);
    digitalWrite(13, HIGH);
          delay(30);
          digitalWrite(13, LOW);
  }
  if (key == '*')
  {
    ps="";
    digitalWrite(13, HIGH);
          delay(200);
          digitalWrite(13, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Password");
    lcd.setCursor(0, 1);
    
  }
  if (key == '#')
  {
    lcd.setCursor(0, 0);
    x=0;
    for ( int i=0;i<10;i++ )
    {
      if(ps!="" && ps == us_ps[i] && x==0 )
      {
        x=1;
        lcd.clear();
        lcd.print("match");
        digitalWrite(0, HIGH);
        for(i=0;i<2;i++)
        {
          digitalWrite(13, HIGH);
          delay(100);
          digitalWrite(13, LOW);
          delay(100);
        }
        delay(1000);
        
        ps ="";
         digitalWrite(0,LOW);
         for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
           // in steps of 1 degree
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(15);                       // waits 15ms for the servo to reach the position
  }
         
         delay(1000);
         for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
        // delay(15); 
   }
         
        lcd.clear();
        lcd.setCursor(0, 0);
        
        lcd.print("Enter Password");
         lcd.setCursor(0, 1);
      }
    }
    if(x==0)
   {
    
    for(i=0;i<5;i++){
      lcd.clear();
      delay(100);
      digitalWrite(13, HIGH);
      lcd.print("invalid");
      digitalWrite(1, HIGH);
      delay(200);
      digitalWrite(1,LOW);
    }
    delay(400);
    digitalWrite(13, LOW);
        ps ="";
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Password");
         lcd.setCursor(0, 1);
    
   }

  }


}
