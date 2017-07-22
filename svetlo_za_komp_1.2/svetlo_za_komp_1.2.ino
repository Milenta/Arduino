int value;
int ledPin11=9;
int ledPin12=10; 
void setup ()
{
  pinMode(ledPin11,OUTPUT); 
  pinMode(ledPin12,OUTPUT); 
  
}
void loop ()
{
 treperenje();
  svetlo();
  delay(1800000);
  treperenje2();
  svetlo();
  delay(1800000);
}
void svetlo()
{
   for (value=0; value<91; value++)
  {
    analogWrite(ledPin11, value);
    analogWrite(ledPin12, value);
    delay(20);
  }
 if (value=90)
 {
 analogWrite(ledPin11, 90);
 analogWrite(ledPin12, 90);
 }
  }

void treperenje()
{
  digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(50);     
  
  digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(50); 
  
  digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(50);  //pauza sekund 

 digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(200);  //pauza sekund

  digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(50);  

     digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(50); 
  
  digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(50);  //pauza sekund 

   digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(50);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(300);     
  
}

void treperenje2()
{
  digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(150);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(150);     

   digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(150);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(150);     
  
   digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(150);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(150);  //pauza sekund 
  
  digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(150);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(150);  //pauza sekund 

digitalWrite(ledPin11,HIGH); //pali diodu 
  delay(150);               //pauza sekund
  digitalWrite(ledPin11,LOW);  //gasi diodu
  delay(150);  //pauza sekund
  
   digitalWrite(ledPin12,HIGH); //pali diodu 
  delay(150);               //pauza sekund
  digitalWrite(ledPin12,LOW);  //gasi diodu
  delay(250);     
  
}
