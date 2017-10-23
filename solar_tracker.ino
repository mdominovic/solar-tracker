#include <Servo.h> 
 
Servo horizontal; 
int servoh = 180; 
 
int servohLimitHigh = 180;
int servohLimitLow = 65;
 
Servo vertical;  
int servov = 45; 
 
int servovLimitHigh = 80;
int servovLimitLow = 15;

int ldrlt = 0;
int ldrrt = 1;
int ldrld = 2;
int ldrrd = 3;
 
void setup()
{
  Serial.begin(9600);
  horizontal.attach(11);
  vertical.attach(10);
  horizontal.write(180);
  vertical.write(45);
  delay(3000);
}
 
void loop()
{
  int lt = analogRead(ldrlt);
  int rt = analogRead(ldrrt); 
  int ld = analogRead(ldrld); 
  int rd = analogRead(ldrrd);
 
  int dtime = 10; 
  int tol = 50; 
 
  int avt = (lt + rt) / 2; 
  int avd = (ld + rd) / 2; 
  int avl = (lt + ld) / 2; 
  int avr = (rt + rd) / 2; 
 
  int dvert = avt - avd; 
  int dhoriz = avl - avr;
 
 
  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");
 
   
 if (-1*tol > dvert || dvert > tol)

  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh)
     {
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
  }
 

  if (-1*tol > dhoriz || dhoriz > tol)
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {

  }
  horizontal.write(servoh);
  }
   delay(dtime);
 
}

