// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val = 90;    // variable to read the value from the analog pin 

int RtPin = A0;
int LtPin = 4;
int Right = 0;
int Left = 0;
int midLevel = 512;


void setup() 
{ 
  Serial.begin(9600); 
  pinMode(RtPin, INPUT);
  pinMode(LtPin, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  Right = analogRead(RtPin);
  Right = abs(Right - midLevel);
   Left = analogRead(LtPin);
  Left = abs(Left - midLevel);
 // sensorValue = prevSensorValue + (sensorValue - prevSensorValue) * 0.5; 
  

  if ( Right<= Left)
    {val -= 2;}
  if (Left < Right)
    {val += 2;}
      //Serial.println(Right);

    
  myservo.write(val); 
  
  
//  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 // Rval = map(Right, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
 // Lval = map(Left, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 

//  myservo.write(val);                  // sets the servo position according to the scaled value 

  Serial.print("Left = " );                       
  Serial.print(Left);      
  Serial.print(" Right = ");      
  Serial.println(Right);
  Serial.print(" val = ");      
  Serial.println(val);
  delay(1000);        // waits for the servo to get there 
} 
