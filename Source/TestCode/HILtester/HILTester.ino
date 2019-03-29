/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  PinChangeInterrupt_TickTock
  Demonstrates how to use the library

  Connect a button/cable to pin 7 and ground.
  The Led state will change if the pin state does.

  PinChangeInterrupts are different than normal Interrupts.
  See readme for more information.
  Dont use Serial or delay inside interrupts!
  This library is not compatible with SoftSerial.

  The following pins are usable for PinChangeInterrupt:
  Arduino Uno/Nano/Mini: All pins are usable
  Arduino Mega: 10, 11, 12, 13, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64),
              A11 (65), A12 (66), A13 (67), A14 (68), A15 (69)
  Arduino Leonardo/Micro: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)
  HoodLoader2: All (broken out 1-7) pins are usable
  Attiny 24/44/84: All pins are usable
  Attiny 25/45/85: All pins are usable
  Attiny 13: All pins are usable
  Attiny 441/841: All pins are usable
  ATmega644P/ATmega1284P: All pins are usable
*/

//Example of use Serial Terminal 9600,8,1,N
//SetParameters TestTime(msec) Period(msec) Precision(0-100 %)
//SetParameters 10000 500 10
//(TestTime=10000msec, Period=500msec, Precision=10%)
//
//Start
//(start the test)
//
//Response: Success, Error: xxxxxxxxxx




#include "PinChangeInterrupt.h"
#include "SimpleTimer.h"

// Choose a valid PinChangeInterrupt pin of your Arduino board
#define PinRedLed 8
#define PinGreenLed 9
SimpleTimer timer;
int TestTime_timerId, NoToggle_timerId, previousTimePeriod;
long lastTime, msec, TestTime, lowThreshold, highThreshold;

void InitMicroShell();
void MicroShell();

int myputc(char c, FILE *)
{
  Serial.write(c);
  return 0;
}

char* SetParameters(int TestTimePar, int Period, float Tolerance)
{
  TestTime = TestTimePar;
  msec = Period;
  lowThreshold = msec*(1-Tolerance);
  highThreshold = msec*(1+Tolerance);
  previousTimePeriod=0;
  disablePCINT(digitalPinToPCINT(PinRedLed));
  return "OK";
  }


char* Start()
{
  TestTime_timerId = timer.setTimeout(TestTime, Success);
  NoToggle_timerId = timer.setTimeout(highThreshold*2, NoToggle);
  previousTimePeriod=0;
  // Attach the new PinChangeInterrupt and enable event function below
  enablePCINT(digitalPinToPCINT(PinRedLed));
  return "OK";
  }

void setup()
{
  fdevopen(&myputc, NULL);
  Serial.begin(9600);  // start serial for output
  Serial.flush();
  InitMicroShell();
  attachPCINT(digitalPinToPCINT(PinRedLed), RedLed, CHANGE);
  // set pin to input with a pullup, led to output
  pinMode(PinRedLed, INPUT_PULLUP);
  pinMode(PinGreenLed, INPUT_PULLUP);
  previousTimePeriod=0;
  disablePCINT(digitalPinToPCINT(PinRedLed));
}


void EndTest(char *Message) {
  timer.disable(TestTime_timerId);
  disablePCINT(digitalPinToPCINT(PinRedLed));
  Serial.println(Message);
}

void Success() {
  disablePCINT(digitalPinToPCINT(PinRedLed));
  EndTest("Success");
}

void NoToggle() {
  disablePCINT(digitalPinToPCINT(PinRedLed));
  EndTest("Error: Red Led do not light");
}


void RedLed(void) {
  long stopTime=millis();
  long timePeriod;
  timer.disable(NoToggle_timerId);
  timePeriod=stopTime-lastTime;
  lastTime=stopTime;
  if(!previousTimePeriod){
  previousTimePeriod=timePeriod;
  return;
  }
  if(timePeriod < lowThreshold) EndTest("Error: measured period is less then expected");
  if(timePeriod > highThreshold) EndTest("Error: measured period is greater then expected");
  // Switch Led state
  delay(10);
  if(digitalRead(PinRedLed) == digitalRead(PinGreenLed))
    EndTest("Error: Green Led do not alternate");
}


void loop() {
  timer.run();
  while (Serial.available() > 0)
      MicroShell();
}
