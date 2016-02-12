#define __BLUETOOTH_CONTROLLED__

#include <Motor.h>
#include <SoftwareSerial.h>

#define RX 10
#define TX 11
#define BAUD 9600
#define lspeed 180
#define rspeed 180

motorPins pins = {3, 5, 6, 9};

Motor motor(pins);

char command = 'g';

SoftwareSerial bluetooth(RX, TX);

void setup(void){
  Serial.begin(BAUD);
  bluetooth.begin(BAUD);
  motor.begin();
  bluetooth.println("Initialized");
}

void controlRobot(void){
  if (bluetooth.available() > 0){
    command = bluetooth.read();
    switch (command){
      case 'w':
        motor.go(lspeed, rspeed, FORWARD);
        Serial.println("Forward");
        break;
      case 's':
        motor.go(lspeed, rspeed, BACKWARD);
        Serial.println("Backward");
        break;
      case 'a':
        motor.go(lspeed, rspeed, ANTICLOCKWISE);
        Serial.println("Anticlockwise");
        break;
      case 'd':
        motor.go(lspeed, rspeed, CLOCKWISE);
        Serial.println("Clockwise");
        break;
      default:
        motor.go(0, 0, NOWHERE);
        Serial.println("Stop");
        break;
    }
  }
}

#ifdef __BLUETOOTH_CONTROLLED__

void loop(void){
  controlRobot();
}

#else

void loop(void){
  
}

#endif
