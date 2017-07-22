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
    if (a=='1')
    {
      digitalWrite(4, HIGH);
      BT.println("LED on");
    }
    if (a=='2')
    {
      digitalWrite(4, LOW);
      BT.println("LED off");
    }
    if (a=='3')
    {
      digitalWrite(5, HIGH);
      BT.println("LED on");
    }
    if (a=='4')
    {
      digitalWrite(5, LOW);
      BT.println("LED off");
    }
    if (a=='5')
    {
      digitalWrite(6, HIGH);
      BT.println("LED on");
    }
    if (a=='6')
    {
      digitalWrite(6, LOW);
      BT.println("LED off");
    }
    if (a=='7')
    {
      digitalWrite(7, HIGH);
      BT.println("LED on");
    }
    if (a=='8')
    {
      digitalWrite(7, LOW);
      BT.println("LED off");
    }
     

    if (a=='9')
    {
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(7, HIGH);
      delay(500);
      BT.println("LED on");
    }
    if (a=='0')
    {
      digitalWrite(4, LOW);
      delay(500);
      digitalWrite(5, LOW);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
      digitalWrite(7, LOW);
      delay(500);
      BT.println("LED off");
    }

    if (a=='q')
    {
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(7, HIGH);
      delay(100);
      BT.println("LED on");
    }
    if (a=='w')
    {
      digitalWrite(4, LOW);
      delay(100);
      digitalWrite(5, LOW);
      delay(100);
      digitalWrite(6, LOW);
      delay(100);
      digitalWrite(7, LOW);
      delay(100);
      BT.println("LED off");
    }

     if (a=='e')
    {
      digitalWrite(4, HIGH);
      delay(250);
      digitalWrite(5, HIGH);
      delay(250);
      digitalWrite(6, HIGH);
      delay(250);
      digitalWrite(7, HIGH);
      delay(250);
      BT.println("LED on");
    }
    if (a=='r')
    {
      digitalWrite(4, LOW);
      delay(250);
      digitalWrite(5, LOW);
      delay(250);
      digitalWrite(6, LOW);
      delay(250);
      digitalWrite(7, LOW);
      delay(250);
      BT.println("LED off");
    }


    if (a=='t')
    {
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(200);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(200);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(200);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      delay(200);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(200);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(200);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(200);
      BT.println("LED on");
    }
    if (a=='y')
    {
      digitalWrite(4, LOW);
    
      digitalWrite(5, LOW);
   
      digitalWrite(6, LOW);
   
      digitalWrite(7, LOW);
     
      BT.println("LED off");
    }
    if (a=='?')
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }   
    // you can add more "if" statements with other characters to add more commands
  }
}
