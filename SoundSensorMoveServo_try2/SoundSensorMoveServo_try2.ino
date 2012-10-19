// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 

int servoPin = 9; // out pin for servo control.
 // analog pin 0 has a pushbutton attached to it. Give it a name:
int soundSensor = A0;
int sensorValue = 0;
int LtPin = 4;
int Left = 0;
int prevSensorValue = 0;
int prevLeft = 0;
const int bufSiz = 10;
static int micBuf[bufSiz];
int midLevel = 512;
void setup() 
{  pinMode(soundSensor, INPUT);
  pinMode(LtPin, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
void loop() 
{ 
   // read the input from SoundSensor.
int val;
  
  sensorValue = analogRead(soundSensor);
  sensorValue = abs(sensorValue - midLevel);
  sensorValue = prevSensorValue + (sensorValue - prevSensorValue) * 0.01;
  
  prevSensorValue = sensorValue;
     Left = analogRead(LtPin);
     Left = abs(Left - midLevel);
     Left = prevLeft + (Left - prevLeft) * 0.01;
     prevLeft = Left;


  if ( sensorValue<= Left)
    {val = 2;}
  if (Left < sensorValue)
    {val = 172;}
      //Serial.println(Right);


  // print out the value you read:
  
  Serial.print("Left = " );                       
  Serial.print(Left);      
  Serial.print(" Right = ");      
  Serial.println(sensorValue);
  Serial.print(" val = ");      
  Serial.println(val);
 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(500);                           // waits for the servo to get there 
  
} 
