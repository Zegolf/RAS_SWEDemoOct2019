#include <Wire.h>
#include <Zumo32U4.h>

#define led 13
#define pwmL 9
#define pwmR 10
Zumo32U4Encoders encoders;
Zumo32U4LCD lcd;
Zumo32U4Motors motors;
int timeDelay = 500;

void setup() {
  // put your setup code here, to run once:
  lcd.print("START");
  delay(2000);
  lcd.clear();
  pinMode(pwmL,OUTPUT);
  pinMode(pwmR,OUTPUT);

 // testTurnLeft();
 // delay(500);
 // testTurnRight();
 // delay(500);
 // testTurnRight();
 // delay(500);
 // testTurnLeft();
 // delay(500);
 // testGoForward();

    goForward();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    turnLeft();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    turnLeft();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    turnLeft();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    goForward();
    delay(timeDelay);
    turnLeft();
    delay(timeDelay);
    goForward();
    
    
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
  delay(2000);
  Serial.println(Zumo32U4Encoders::getCountsLeft());
}

void testTurnRight(){
  //Testing turnRight
  lcd.print("TestR");
  delay(1000);
  turnRight();
  lcd.clear();
}

void testTurnLeft(){
  //Testing turnLeft
  lcd.print("turnL");
  delay(1000);
  turnLeft();
}

void testGoForward(){
  //Tetsing goForward
  lcd.print("Forward");
  delay(1000);
  goForward();
}

void turnRight(){
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
  
  int16_t countsRight = 0;

  while(countsRight >= -600){
    motors.setSpeeds(200,-200);
    countsRight = encoders.getCountsRight();
    /*Debugging*/ //lcd.clear(); lcd.print(countsRight);
  }
  motors.setSpeeds(0,0);
  
}

void turnLeft(){
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
  
  int16_t countsLeft = 0;

  while(countsLeft >= -675){
    motors.setSpeeds(-200,200);
    countsLeft = encoders.getCountsLeft();
    /*Debugging*/ //lcd.clear(); lcd.print(countsLeft);
  }
  motors.setSpeeds(0,0);
}

void goForward(){
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
  int countsRight = 0;

  while(countsRight < 1300){
    motors.setSpeeds(200,200);
    countsRight = encoders.getCountsRight();
    /*Debugging*/ lcd.clear(); lcd.print(countsRight);
  }
 
  motors.setSpeeds(0,0);
}
