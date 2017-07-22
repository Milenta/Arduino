
// LCD pinovi Gore sa desne strane od 5 do 10 na pinove arduina od 5 do 10
// pinovi dole levo 1 na reset; 3 na 5V; 4 na masu; 7 na analognu 0

#include <LiquidCrystal.h>
#include "LCDKeypad.h"
 
#define DAN 0
#define SAT 1
#define MINUT 2
#define SEKUNDE 3


/*-----( Declare objects )-----*/
/*-----( Declare Variables )-----*/
  // Arduino Digital I/O pin number


int ledPin1=3;
int ledPin2=12;
int ledPin3 = 10;

 
// The LCD screen
LCDKeypad lcd;
 
// The time model
unsigned int dan = 0;
unsigned int sat = 11;
unsigned int minut = 8;
unsigned int sekunde = 0;
unsigned int podesi = 0;
 
void setup() {
  // Set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
 
  // Set the cursor at the begining of the first row
  lcd.setCursor(0,0);
 
  // Print a text in the first row
  lcd.print("Podesi: Dan     ");
  
  //-------( Initialize Pins so relays are inactive at reset)----
  analogWrite(ledPin1, 0);
 
  
   
  
//---( THEN set pins as outputs )----  
    
 
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT); 
  pinMode(ledPin3, OUTPUT);
 
}
 
void loop() {

  digitalWrite(ledPin2,HIGH);
  
  // Increase the time model by one second
  incTime();
 
  // Print the time on the LCD
  printTime();
 
  Paljenje();
  
  Gasenje();
  // Listen for buttons for 1 second
  buttonListen();
}
 
void buttonListen() {
  // Read the buttons five times in a second
  for (int i = 0; i < 5; i++) {
 
    // Read the buttons value
    int button = lcd.button();
 
    switch (button) {
 
    // Right button was pushed
    case KEYPAD_RIGHT:
      podesi++;
      break;
 
    // Left button was pushed
    case KEYPAD_LEFT:
      podesi--;
      break;
 
    // Up button was pushed
    case KEYPAD_UP:
      switch (podesi) {
      case DAN:
        dan++;
        break;
      case SAT:
        sat++;
        break;
      case MINUT:
        minut++;
        break;
      case SEKUNDE:
        sekunde++;
      }     
      break;
 
    // Down button was pushed
    case KEYPAD_DOWN:
      switch (podesi) {
      case DAN:
        dan--;
        if (dan == -1) dan = 7;
        break;
      case SAT:
        sat--;
        if (sat == -1) sat = 23;
        break;
      case MINUT:
        minut--;
        if (minut == -1) minut = 59;
        break;
      case SEKUNDE:
        sekunde--;
        if (sekunde == -1) sekunde = 59;
      }
    }
 
    podesi %= 4;
    printSetting();
 
    dan %= 7;
    sat %= 24;
    minut %= 60;
    sekunde %= 60;
    printTime();
 
    // Wait one fifth of a second to complete
    while(millis() % 200 != 0);
  }
}
 
// Print the current setting
void printSetting() {
  lcd.setCursor(8,0);
 
  switch (podesi) {
  case DAN:
    lcd.print("Dan    ");
    break;  
  case SAT:
    lcd.print("Sat    ");
    break;
  case MINUT:
    lcd.print("Minut  ");
    break;
  case SEKUNDE:
    lcd.print("Sekunde");
  }
}
 
// Increase the time model by one second
void incTime() {
  // Increase seconds
  sekunde++;
 
  if (sekunde == 60) {
    // Reset seconds
    sekunde = 0;
 
    // Increase minutes
    minut++;
 
    if (minut == 60) {
      // Reset minutes
      minut = 0;
 
      // Increase hours
      sat++;
 
      if (sat == 24) {
        // Reset hours
        sat = 0;
 
        // Increase days
        dan++;
      }
    }
  }
}
 
// Print the time on the LCD
void printTime() {
  // Set the cursor at the begining of the second row
  lcd.setCursor(0,1);
  char time[17];
  sprintf(time, "%02i dan  %02i:%02i:%02i", dan, sat, minut, sekunde);
  lcd.print(time);
}




void Paljenje()
{
  if(sat == 11 && minut == 0 && sekunde == 0) {
    analogWrite(ledPin1, 3);
  }
  if(sat == 11 && minut == 30 && sekunde == 0) {
    analogWrite(ledPin1, 7);
  }
  if(sat == 12 && minut == 00 && sekunde == 0) {
    analogWrite(ledPin1, 8);
  }
  if(sat == 13 && minut == 53 && sekunde == 0) {
    analogWrite(ledPin1, 12);
  }
  if(sat == 13 && minut == 54 && sekunde == 0) {
    analogWrite(ledPin1, 25);
  }
  if(sat == 13 && minut == 55 && sekunde == 0) {
    analogWrite(ledPin1, 40);
  }
  if(sat == 13 && minut == 56 && sekunde == 0) {
    analogWrite(ledPin1, 80);
  }
  if(sat == 13 && minut == 57 && sekunde == 0) {
    analogWrite(ledPin1, 180);
  }
  if(sat == 13 && minut == 58 && sekunde == 0) {
    analogWrite(ledPin1, 215);
  }
  
  
//plava traka
  if(sat == 20 && minut == 00 && sekunde == 05) {
    analogWrite(ledPin3, 20);
  }
  if(sat == 20 && minut == 00 && sekunde == 10) {
    analogWrite(ledPin3, 40);
  }
  if(sat == 20 && minut == 00 && sekunde == 20) {
    analogWrite(ledPin3, 60);
  }
  if(sat == 20 && minut == 00 && sekunde == 30) {
    analogWrite(ledPin3, 80);
  }
  if(sat == 20 && minut == 00 && sekunde == 40) {
    analogWrite(ledPin3, 100);
  }
  if(sat == 20 && minut == 00 && sekunde == 50) {
    analogWrite(ledPin3, 120);
  }
  if(sat == 20 && minut == 01 && sekunde == 00) {
    analogWrite(ledPin3, 150);
  }
  if(sat == 20 && minut == 01 && sekunde == 10) {
    analogWrite(ledPin3, 180);
  }
  if(sat == 20 && minut == 1 && sekunde == 20) {
    analogWrite(ledPin3, 210);
  }
  
 }
 
void Gasenje()
{
    
  if(sat == 20 && minut == 00 && sekunde == 00) {
    analogWrite(ledPin1, 200);
  }
  if(sat == 20 && minut == 02 && sekunde == 00) {
    analogWrite(ledPin1, 100);
  }
  if(sat == 20 && minut == 03 && sekunde == 00) {
    analogWrite(ledPin1, 50);
  }
  if(sat == 20 && minut == 04 && sekunde == 00) {
    analogWrite(ledPin1, 20);
  }
  if(sat == 20 && minut == 05 && sekunde == 00) {
    analogWrite(ledPin1, 10);
  }
  if(sat == 20 && minut == 06 && sekunde == 0) {
    analogWrite(ledPin1, 5);
  }
  if(sat == 21 && minut == 00 && sekunde == 0) {
    analogWrite(ledPin1, 4);
  }
  if(sat == 21 && minut == 59 && sekunde == 0) {
    analogWrite(ledPin1, 2);
  }
  if(sat == 21 && minut == 59 && sekunde == 10) {
    analogWrite(ledPin1, 0);
  }

//gasenje plave trake

    if(sat == 21 && minut == 59 && sekunde == 00) {
    analogWrite(ledPin3, 200);
  }
  if(sat == 21 && minut == 59 && sekunde == 10) {
    analogWrite(ledPin3, 100);
  }
  if(sat == 21 && minut == 59 && sekunde == 20) {
    analogWrite(ledPin3, 70);
  }
  if(sat == 21 && minut == 59 && sekunde == 30) {
    analogWrite(ledPin3, 0);
  }

}
