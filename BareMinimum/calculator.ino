#include <LiquidCrystal.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int lastCurrent;
String allNumber = "";
void setup() { lcd.begin(16,2); }

void printCurrent(int value) {
  lcd.setCursor(0,1);
  lcd.print(value);
  delay(500);
  lcd.clear();
}

void loop() {
  int value = analogRead(0);

  printCurrent(value);

  lastCurrent = value; 
}

void validateValue(int value) {

  if(value > 0 && value < 10) {
    onClick(1);
  }
}


void onClick(int number) {
  allNumber += number;
  lcd.setCursor(0,0);
  lcd.print(allNumber);
}


/*int buttonOne = 10;
int buttonOneVal;
int lastButtonOneVal;

//int butonPin2 = 11;
//int butonVal2;
//  pinMode(butonPin2, INPUT);

void setup () {
  pinMode(buttonOne, INPUT);
  Serial.begin(9600);
}

bool pressed = false;

void onClick () { }

void loop() {
  buttonOneVal=digitalRead(buttonOne);

  Serial.print(typeid(buttonOneVal).name()); 
  
  if(buttonOneVal && buttonOneVal == 0 && lastButtonOneVal == 1) {
    // onClick()
    Serial.println("Mita Caabron!!!"); 
    pressed = true;
  } else if(pressed) {
    pressed = false;
  }

  lastButtonOneVal = buttonOneVal; 

  delay(1000);
}*/
