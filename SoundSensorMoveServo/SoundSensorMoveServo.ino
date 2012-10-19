// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 

int servoPin = 11; // out pin for servo control.
 // analog pin 0 has a pushbutton attached to it. Give it a name:
int soundSensor = A0;
int sensorValue = 0;
int prevSensorValue = 0;
const int bufSiz = 10;
static int micBuf[bufSiz];
int midLevel = 512;
void setup() 
{ 
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
void loop() 
{ 
   // read the input from SoundSensor.

  
  sensorValue = analogRead(soundSensor);
  sensorValue = abs(sensorValue - midLevel);
  sensorValue = prevSensorValue + (sensorValue - prevSensorValue) * 0.01;
  
  prevSensorValue = sensorValue;
  
  // print out the value you read:
  Serial.println(sensorValue);
  int brightness;
  brightness = map(sensorValue,0,512,0,179);            // reads the value of the potentiometer (value between 0 and 1023) 
  myservo.write(brightness);                  // sets the servo position according to the scaled value 
  delay(10);                           // waits for the servo to get there 
  
  Serial.println(brightness);  
} 
