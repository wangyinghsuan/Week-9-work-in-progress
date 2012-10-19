// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 

 
void setup() 
{ 
  servoLeft.attach(10);  // Set left servo to digital pin 10
  servoRight.attach(9);  // Set right servo to digital pin 9
  Serial.begin(9600);
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  servoLeft.write(val);                  // sets the servo position according to the scaled value 
    servoRight.write(val);                  // sets the servo position according to the scaled value 

  delay(15);                           // waits for the servo to get there 
  
  Serial.println(val);  
} 
