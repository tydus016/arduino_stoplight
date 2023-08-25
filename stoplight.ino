/* Arduino Tutorial - 7 Segment 
   One 7 segment is one digit, from 0 to  9.
   Dev: Vasilakis Michalis // Date: 25/7/2015 // www.ardumotive.com */

//Library
#include "SevenSeg.h"

//Defines the segments A-G: SevenSeg(A, B, C, D, E, F, G);
SevenSeg disp(5, 6, 7, 9, 10, 4, 3);
//Number of 7 segments
const int numOfDigits = 1;
//CC(or CA) pins of segment
int digitPins[numOfDigits] = { 8 };

// set variables for stop lights
int GREEN = 13;   // green
int YELLOW = 12;  // yellow
int RED = 11;     // red

//Variables
int number = 0;  //Default number
int timer = 6;
int flag;
int buzzerPin = 2;

void setup() {

  Serial.begin(9600);
  //Defines the number of digits to be "numOfDigits" and the digit pins to be the elements of the array "digitPins"
  disp.setDigitPins(numOfDigits, digitPins);
  //Only for common cathode 7segments
  disp.setCommonCathode();
  //Control brightness (values 0-100);
  disp.setDutyCycle(50);

  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  tone(buzzerPin, 1000, 1000);
}

void loop() {
  greenLight();
  yellowLight();
  redLight();
}

void redLight() {
  while (timer != 0) {
    timer--;
    Serial.println(timer);
    disp.writeDigit(timer);
    digitalWrite(RED, HIGH);
    if (timer < 4) {
      tone(buzzerPin, 1000, 1000);
    }
    delay(1000);
  }
  digitalWrite(RED, LOW);
  noTone(buzzerPin);

  timer = 6;  // set the timer for green light
}

void yellowLight() {
  while (timer != 0) {
    timer--;
    Serial.println(timer);
    disp.writeDigit(timer);
    digitalWrite(YELLOW, HIGH);
    delay(1000);
  }
  digitalWrite(YELLOW, LOW);
  timer = 10;  // set the timer for red light
}

void greenLight() {
  while (timer != 0) {
    timer--;
    Serial.println(timer);
    disp.writeDigit(timer);
    digitalWrite(GREEN, HIGH);
    delay(1000);
  }
  digitalWrite(GREEN, LOW);
  timer = 4;  // set the timer for yellow light
}
