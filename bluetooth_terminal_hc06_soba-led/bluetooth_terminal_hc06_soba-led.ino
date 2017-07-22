#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set digital pin to control as an output
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
}
char a; // stores incoming character from other device

void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='b')
    {
      digitalWrite(4, HIGH);
      BT.println("Blue LED on");
    }
/*    if (a=='')
    {
      digitalWrite(4, LOW);
      BT.println("LED off");
   }
  */   if (a=='r')
    {
      digitalWrite(5, HIGH);
      BT.println("Red LED on");
    }
/*    if (a=="red off")
    {
      digitalWrite(5, LOW);
      BT.println("Red LED off");
    }
  */  if (a=='g')
    {
      digitalWrite(6, HIGH);
      BT.println("Green LED on");
    }
/*    if (a=="green off")
    {
      digitalWrite(6, LOW);
      BT.println("Green LED off");
    }
*/    if (a=='o')
    {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      BT.println("All LED off");
    }
     

    if (a=='p')
    {
      digitalWrite(4, HIGH);
      delay(80);
      digitalWrite(4, LOW);
      delay(80);
      digitalWrite(4, HIGH);
      delay(80);
      digitalWrite(4, LOW);
      delay(80);
      digitalWrite(5, HIGH);
      delay(80);
      digitalWrite(5, LOW);
      delay(80);
      digitalWrite(5, HIGH);
      delay(80);
      digitalWrite(5, LOW);
      delay(80);

      digitalWrite(4, HIGH);
      delay(80);
      digitalWrite(4, LOW);
      delay(80);
      digitalWrite(4, HIGH);
      delay(80);
      digitalWrite(4, LOW);
      delay(80);
      digitalWrite(5, HIGH);
      delay(80);
      digitalWrite(5, LOW);
      delay(80);
      digitalWrite(5, HIGH);
      delay(80);
      digitalWrite(5, LOW);
      delay(80);

      digitalWrite(4, HIGH);
      delay(80);
      digitalWrite(4, LOW);
      delay(80);
      digitalWrite(4, HIGH);
      delay(80);
      digitalWrite(4, LOW);
      delay(80);
      digitalWrite(5, HIGH);
      delay(80);
      digitalWrite(5, LOW);
      delay(80);
      digitalWrite(5, HIGH);
      delay(80);
      digitalWrite(5, LOW);
      delay(80);
      
      
      BT.println("Police on");
      BT.println("Ovo je samo amatersko testiranje uredjaja :0)");
    }

    
    if (a=='?')
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }   
    // you can add more "if" statements with other characters to add more commands
  }
}
