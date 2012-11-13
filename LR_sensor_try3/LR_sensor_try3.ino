// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val = 90;    // variable to read the value from the analog pin 

int RtPin = A0;
int LtPin = A1;
int Right = 0;
int preRight = 0;

int Left = 0;
int preLeft = 0;

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
 Right = preRight + (Right - preRight) * 0.5;
 Left = preLeft + (Left - preLeft) * 0.5; 
 
  preRight = Right;
  preLeft = Left;

  if ( Right - Left > 10){
      if (val > 2) val -= 2;
     
   }
  if (Left - Right >  10)
    {
      if(val < 178)
    val += 2;
  
    }
      //Serial.println(Right);

    
  myservo.write(val); 
  
  
//  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 // Rval = map(Right, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
 // Lval = map(Left, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 

//  myservo.write(val);                  // sets the servo position according to the scaled value 

  //Serial.print("Left = " );                       
  Serial.print(Left);  
  Serial.print(",");      

  //Serial.print(" Right = ");      
  Serial.print(Right);
    
  Serial.print(","); 
  //Serial.print(" val = ");      
  Serial.println(val);
  delay(100);        // waits for the servo to get there 
} 
