#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 45; 
String inputs;
void setup() {
  Serial.begin(9600);
   myservo.attach(7);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  myservo.write(pos);
}

void loop() {
  while(Serial.available()) 
{
delay(10); //Delay to make it stable
char c = Serial.read();
if (c == '#'){
break; 
}
inputs += c; 
}
if(digitalRead(10)== false || digitalRead(11)== false)
{myservo.write(80);
Serial.print("went");
digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  delay(1000);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  myservo.write(45);}
  

  if (inputs.length() >0)
{
Serial.println(inputs);
if(inputs == "1")
{ digitalWrite(8,HIGH);
  digitalWrite(9,LOW);}
  
 if(inputs == "2")
{ digitalWrite(9,HIGH);
  digitalWrite(8,LOW);}
  if(inputs == "3")
{ digitalWrite(9,LOW);
  digitalWrite(8,LOW);}
 if(inputs == "4" )
{if(pos<46){pos=pos+35;
myservo.write(pos);}}
  if(inputs == "5")
{if(pos>44){ pos=pos-35;
myservo.write(pos);}}

  
  }
  
  inputs ="";
  
  
  

}
