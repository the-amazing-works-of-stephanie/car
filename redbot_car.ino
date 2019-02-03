#include "notes.h"  // Individual "notes" have been #defined in the notes.h tab to make
                    // playing sounds easier. noteC4, for example, is defined as 262, the
                    // frequency for middle C. See the tab above? 

#include <RedBot.h> 
RedBotMotors motors;

// Create a couple of constants for our pins.
const int buzzerPin = 9;
const int buttonPin = 12;
const int ledPin = 10; 

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzerPin, OUTPUT);  // configures the buzzerPin as an OUTPUT
  pinMode(ledPin, OUTPUT); 
}

void loop()
{
  if(digitalRead(buttonPin) == LOW)
  {
    digitalWrite(ledPin, HIGH); 
    playMario();
  }
}

void playMario()
{ 
  // we use a custom function below called playNote([note],[duration]) 
  // to play a note and delay a certain # of milliseconds. 
  //
  // Both notes and durations are #defined in notes.h -- WN = whole note, 
  // HN = half note, QN = quarter note, EN = eighth note, SN = sixteenth note.
  //
  playNote(noteE7, EN);
  playNote(noteE7, EN);
  playNote(Rest, EN);
  playNote(noteE7, EN);  
  playNote(Rest, EN);
  playNote(noteC7, EN);
  playNote(noteE7, EN);
  playNote(Rest, EN);
  playNote(noteG7, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(noteG6, HN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
  
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
  playNote(noteB6, EN);
  playNote(Rest, EN);
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
  playNote(noteE7, EN);
  playNote(Rest, EN);
  playNote(noteC7, EN);
  playNote(noteD7, EN);
  playNote(noteB6, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);

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
  playNote(noteB6, EN);
  playNote(Rest, EN);
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
  playNote(noteE7, EN);
  playNote(Rest, EN);
  playNote(noteC7, EN);
  playNote(noteD7, EN);
  playNote(noteB6, EN);
  playNote(Rest, EN);
  playNote(Rest, EN);
}

void playNote(int note, int duration)
// This custom function takes two parameters, note and duration to make playing songs easier.
// Each of the notes have been #defined in the notes.h file. The notes are broken down by 
// octave and sharp (s) / flat (b).
{
  tone(buzzerPin, note, duration);
  delay(duration);
}

/***********************************************************************
 * Troubleshooting for experiment 4.1
 * My code won't upload!
 * - Make sure that your USB cable is plugged into the robot and the
 * computer you're using to write code.
 * - Make sure that the "Power" switch is switched to "ON".
 * - Double check that you have the right serial port selected under the
 * "Tools" menu. The easiest way to check is to see which item
 * disappears from the menu when you unplug the USB cable, and select
 * that one when you plug the board back in.
 * - Make sure the Serial Select switch at the top edge of the board is 
 * switched to "XBEE SW SERIAL", even if you have an Xbee attached.
 * - Check that you have the right board selected under the "Tools" menu.
 * The RedBot is Uno-compatible, so select "Arduino Uno" from the list.
 * My motors aren't turning!
 * - This code demonstrates only the tone() commands; there's no code to
 * make the motors turn.
 ***********************************************************************/
