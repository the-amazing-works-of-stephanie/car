#include "notes.h"  // Individual "notes" have been #defined in the notes.h tab to make
                    // playing sounds easier. noteC4, for example, is defined as 262, the
                    // frequency for middle C. See the tab above? 

#include <RedBot.h> 
RedBotMotors motors;

RedBotBumper lBumper = RedBotBumper(3);  // initialzes bumper object on pin 3
RedBotBumper rBumper = RedBotBumper(11); // initialzes bumper object on pin 11

const int buzzerPin = 9;
const int buttonPin = 12;

int leftPower;  // variable for setting the drive power
int rightPower;
int data;  // variable for holding incoming data from PC to Arduino
int lBumperState;  // state variable to store the bumper value
int rBumperState;  // state variable to store the bumper value

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzerPin, OUTPUT);  // configures the buzzerPin as an OUTPUT
  /*motors.drive(255); 
  lBumperState = lBumper.read();  // default INPUT state is HIGH, it is LOW when bumped
  rBumperState = rBumper.read();  // default INPUT state is HIGH, it is LOW when bumped
  if (lBumperState == LOW) // left side is bumped/
  { 
    reverse();    // backs up
    turnRight();  // turns
  }
  if (rBumperState == LOW) // right side is bumped/
  { 
    reverse();   // backs up
    turnLeft();  // turns
  }*/
}

void loop()
{ 
  if(digitalRead(buttonPin) == LOW)
  { 
    //dance(); 
    playSongs();
  }
}

void dance()
{
  motors.drive(-255);   // Turn on Left and right motors at full speed forward.
  delay(100);         // Waits for 2 seconds
  //motors.brake();      // Stops both motors

  // pivot -- spinning both motors CCW causes the RedBot to turn to the right
  motors.rightMotor(500); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  delay(300);        // for 500 ms.
  
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-500);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
      
  motors.drive(255);   // Turn on Left and right motors at full speed forward.
  delay(100);         // Waits for 2 seconds
  //motors.brake();

  motors.rightMotor(500); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
  
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-500);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
      
  motors.drive(255);   // Turn on Left and right motors at full speed forward.
  delay(100);         // Waits for 2 seconds
  //motors.brake();

  motors.rightMotor(500); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
  
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-500);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
      
  /*motors.drive(255);   // Turn on Left and right motors at full speed forward.
  delay(100); 

  motors.rightMotor(500); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
  
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-500);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
      
  motors.drive(255);   // Turn on Left and right motors at full speed forward.
  delay(100); 
  //
  motors.rightMotor(500); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
  
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-500);  // Turn CCW at motorPower of 100
  delay(600);        // for 500 ms.
      
  motors.drive(255);   // Turn on Left and right motors at full speed forward.
  delay(100); */
  motors.brake();
}

void playSongs()
{ 
  // we use a custom function below called playNote([note],[duration]) 
  // to play a note and delay a certain # of milliseconds. 
  //
  // Both notes and durations are #defined in notes.h -- WN = whole note, 
  // HN = half note, QN = quarter note, EN = eighth note, SN = sixteenth note.
 
  /*//GoT
  motors.drive(100);   // Turn on Left and right motors
  delay(100);        
  playNote(noteG4, HN+QN);
  playNote(noteC4, HN+QN); 
  playNote(noteDs4, QN);
  playNote(noteF4, HN);
  playNote(noteG4, HN+QN); 
  motors.rightMotor(85); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  //delay(100);  
  playNote(noteC4, HN+QN); 
  motors.drive(100);   // Turn on Left and right motors
  //delay(100); 
  playNote(noteDs4, HN); 
  playNote(noteF4, QN); 
  playNote(noteG4, HN+QN); 
  playNote(noteC4, HN+QN); 
  playNote(noteDs4, HN+QN);  
  playNote(noteF4, HN+QN); 
  playNote(noteG4, HN+QN); 
  playNote(noteC4, HN+QN); 
  playNote(noteE4, HN); 
  playNote(noteF4, QN); 
  playNote(noteG4, HN+QN); 
  playNote(noteC4, HN+QN); 
  playNote(noteE4, HN); 
  playNote(noteF4, QN);
  playNote(noteG4, HN+QN); 
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-85);  // Turn CCW at motorPower of 100
  //delay(100);
  playNote(noteC4, HN+QN); 
  motors.drive(100);   // Turn on Left and right motors
  //delay(100);
  playNote(noteE4, HN); 
  playNote(noteF4, QN);
 
  playNote(noteG4, HN+QN); 
  playNote(noteC4, HN+QN); 
  playNote(noteDs4, HN); 
  playNote(noteF4, HN);
  playNote(noteD4, HN+QN); 
  
  playNote(noteG3, HN+QN); 
  playNote(noteAs3, HN); 
  playNote(noteC4, QN); 
  playNote(noteD4, HN+QN);
  motors.rightMotor(85); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  //delay(100);
  playNote(noteG3, HN+QN); 
  motors.drive(100);   // Turn on Left and right motors
  //delay(100);
  playNote(noteAs3, HN); 
  playNote(noteC4, QN); 
  playNote(noteD4, HN+QN);
  playNote(noteG3, HN+QN); 
  playNote(noteAs3, HN); 
  playNote(noteC4, QN); 
  playNote(noteD4, HN+QN);
  motors.brake(); 

  //Decided not to use second half of song
 /* playNote(noteG3, HN+QN); 
  playNote(noteAs3, HN); 
  playNote(noteC4, QN); 
  playNote(noteD4, HN+SN);
  
  playNote(noteF4, HN+SN); 
  playNote(noteAs4, HN+SN); 
  playNote(noteDs4, HN); 
  playNote(noteD4, HN);
  playNote(noteF4, HN+SN); 
  playNote(noteAs3, HN+SN); 
  playNote(noteDs4, HN); 
  playNote(noteD4, QN);
  playNote(noteC4, HN+QN); 
  
  playNote(noteGs3, HN); 
  playNote(noteAs3, QN); 
  playNote(noteC4, HN+QN);
  playNote(noteF3, HN+QN); 
  playNote(noteGs3, HN); 
  playNote(noteAs3, QN); 
  playNote(noteC4, HN+QN);
  playNote(noteF3, HN+QN);
  
  playNote(noteG4, HN+SN); 
  playNote(noteC4, HN+SN); 
  playNote(noteDs4, HN);
  playNote(noteF4, HN); 
  playNote(noteG4, HN+SN); 
  playNote(noteC4, HN+SN); 
  playNote(noteDs4, HN);
  playNote(noteF4, QN); 
  playNote(noteD4, HN+QN); 
  
  playNote(noteG3, HN+QN); 
  playNote(noteAs3, HN);
  playNote(noteC4, QN); 
  playNote(noteD4, HN+QN);  
  playNote(noteG3, HN+QN); 
  playNote(noteAs3, HN);
  playNote(noteC4, QN); 
  playNote(noteD4, HN+QN); 
  playNote(noteG3, HN+QN); 
  playNote(noteAs3, HN);
  playNote(noteC4, QN); 
  playNote(noteD4, HN+QN); 
  //GoT END*/

  /*//Mario START
  motors.drive(125);   // Turn on Left and right motors
  delay(3000);   
  playNote(Rest, WN); 
  playNote(noteE7, EN);
  playNote(noteE7, EN);
  playNote(Rest, EN);
  playNote(noteE7, EN);  
  playNote(Rest, EN);
  playNote(noteC7, EN);
  motors.rightMotor(50); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  //delay(50); 
  playNote(noteE7, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500); 
  playNote(Rest, EN);
  playNote(noteG7, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(noteG6, HN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-50);  // Turn CCW at motorPower of 100
  //delay(100);
  
  playNote(noteC7, EN);
  playNote(Rest, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500); 
  playNote(Rest, EN);
  playNote(noteG6, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(noteE6, EN);
  playNote(Rest, EN);
  motors.rightMotor(50); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  //delay(100);
  playNote(Rest, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500);
  playNote(noteA6, EN);
  playNote(Rest, EN);
  playNote(noteB6, EN);
  playNote(Rest, EN);
  playNote(noteAs6, EN);
  playNote(noteA6, EN);
  playNote(Rest, EN);

  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-50);  // Turn CCW at motorPower of 100
  //delay(50); 
  playNote(noteG6, EN);
  playNote(noteE7, EN);
  playNote(noteG7, EN);
  playNote(noteA7, EN);
  playNote(Rest, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500);
  playNote(noteF7, EN);
  playNote(noteG7, EN);
  playNote(Rest, EN);
  playNote(noteE7, EN);
  playNote(Rest, EN);
  playNote(noteC7, EN);
  playNote(noteD7, EN);
  playNote(noteB6, EN);
  playNote(Rest, EN);
  motors.rightMotor(50); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  //delay(100);
  playNote(Rest, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500);

  playNote(noteC7, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(noteG6, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(noteE6, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(noteA6, EN);
  playNote(Rest, EN);
  motors.rightMotor(0); // Turn CCW at motorPower of 100
  motors.leftMotor(-50);  // Turn CCW at motorPower of 100
  //delay(50); 
  playNote(noteB6, EN);
  playNote(Rest, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500);
  playNote(noteAs6, EN);
  playNote(noteA6, EN);
  playNote(Rest, EN);

  playNote(noteG6, EN);
  playNote(noteE7, EN);
  playNote(noteG7, EN);
  playNote(noteA7, EN);
  playNote(Rest, EN);
  playNote(noteF7, EN);
  playNote(noteG7, EN);
  playNote(Rest, EN);
  motors.rightMotor(50); // Turn CCW at motorPower of 100
  motors.leftMotor(0);  // Turn CCW at motorPower of 100
  //delay(100);
  playNote(noteE7, EN);
  playNote(Rest, EN);
  motors.drive(125);   // Turn on Left and right motors
  //delay(500);
  playNote(noteC7, EN);
  playNote(noteD7, EN);
  playNote(noteB6, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  motors.brake(); */
  //Mario END

  //Mario Underwater Theme
  playNote(noteC4, QN);
  playNote(noteC5, QN);
  playNote(noteA3, QN);
  playNote(noteA4, QN);
  playNote(noteAs3, QN);
  playNote(noteAs4, QN);
  playNote(Rest, WN);
  playNote(Rest, HN);
  
  playNote(noteC4, QN); // 9
  playNote(noteC5, QN);
  playNote(noteA3, QN);
  playNote(noteA4, QN);
  playNote(noteAs3, QN);
  playNote(noteAs4, QN);
  playNote(Rest, WN);
  playNote(Rest, HN);

  playNote(noteF3, QN); // third row
  playNote(noteF4, QN);
  playNote(noteD3, QN);
  playNote(noteD4, QN);
  playNote(noteDs3, QN);
  playNote(noteDs4, QN);
  playNote(Rest, WN);
  playNote(Rest, HN);

  playNote(noteF3, QN); // third row
  playNote(noteF4, QN);
  playNote(noteD3, QN);
  playNote(noteD4, QN);
  playNote(noteDs3, QN);
  playNote(noteDs4, QN);
  playNote(Rest, WN);
  playNote(Rest, HN);

  playNote(noteE4, EN);
  playNote(noteD4, EN);
  playNote(noteDs4, EN);
  playNote(noteC4, EN);
  playNote(Rest,EN);
  playNote(noteDs4,EN);
  playNote(Rest,EN);
  playNote(noteDs4,EN);
  playNote(Rest,EN);
  playNote(noteGs3,EN);
  playNote(Rest,EN);
  playNote(noteG3,EN);
  playNote(Rest,EN);
  playNote(noteCs4,EN);
  playNote(Rest,EN);

  
  
  
  
/*  playNote(noteDs4, EN);
  playNote(noteDs4, EN);
  playNote(noteGs3, EN);
  playNote(noteG3, EN);
  playNote(noteCs4, EN);
  playNote(noteC4, HN);
  playNote(noteFs4, HN);
  playNote(noteF4, HN);
  playNote(noteE3, HN);
  playNote(noteAs4, HN);
  playNote(noteA4, HN);
  playNote(noteGs4, QN);
  playNote(noteDs4, QN);
  playNote(noteB3, QN);
  playNote(noteAs3, QN);
  playNote(noteA3, QN);
  playNote(noteGs3, QN);
  playNote(Rest, SN);
  playNote(Rest, SN);
  playNote(Rest, SN);
  */
}

void playNote(int note, int duration)
// This custom function takes two parameters, note and duration to make playing songs easier.
// Each of the notes have been #defined in the notes.h file. The notes are broken down by 
// octave and sharp (s) / flat (b).
{
  tone(buzzerPin, note, duration);
  delay(duration);
}

// reverse() function -- backs up at full power
void reverse()
{
  motors.drive(255);
  delay(500);
  motors.brake();
  delay(100);  // short delay to let robot fully stop
}

// turnRight() function -- turns RedBot to the Right
void turnRight()
{
  motors.leftMotor(-150);  // spin CCW
  motors.rightMotor(-150); // spin CCW
  delay(500);
  motors.brake();
  delay(100);  // short delay to let robot fully stop
}

// turnRight() function -- turns RedBot to the Left
void turnLeft()
{
  motors.leftMotor(+150);  // spin CW
  motors.rightMotor(+150); // spin CW
  delay(500);
  motors.brake();
  delay(100);  // short delay to let robot fully stop
}
