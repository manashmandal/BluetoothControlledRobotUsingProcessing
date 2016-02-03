#include <SoftwareSerial.h>
#define RX 10
#define TX 11
#define BAUD 9600

char command = 'g';

int leftMotor[] = {2, 3};
int rightMotor[] = {5, 4};

SoftwareSerial bt(RX, TX);

void setup()
{
    bt.begin(BAUD);
    Serial.begin(BAUD);
    for (int i = 0; i < 2; i++){
        pinMode(leftMotor[i], OUTPUT);
        pinMode(rightMotor[i], OUTPUT);
    }
  Serial.println("Serial initialized");
}

void printSomething(void){
  bt.println("PRINTING SOMETHING");
}


void motordirection()
{
 if(bt.available()>0){
 
   command=bt.read();
   
   switch (command){
       case 'w':
          setMotors(200,200);
          break;
        case 's':
          setMotors(-200,-200);
          break;
        case 'a':
          setMotors(0,200);
          break;
        case 'd':
          setMotors(200,0);
          break;
        case 'r':
          printSomething();
          break;
        default:
          setMotors(0,0);
          break;
      }
   }
}

void setMotors(int l, int r)
{
    if (l >= 0 && r >= 0)
    {
        analogWrite(leftMotor[0], l);
        digitalWrite(leftMotor[1], LOW);
        analogWrite(rightMotor[0], r);
        digitalWrite(rightMotor[1], LOW);
    }

    else if (l < 0 && r < 0)
    {
        r = -r;
        l = -l;
        digitalWrite(leftMotor[0], LOW);
        analogWrite(leftMotor[1], l);
        digitalWrite(rightMotor[0], LOW);
        analogWrite(rightMotor[1], r);
    }

    else if (l > 0 && r < 0)
    {
        analogWrite(leftMotor[0], l);
        digitalWrite(leftMotor[1], LOW);
        digitalWrite(rightMotor[0], LOW);
        analogWrite(rightMotor[1], r);
    }

    else if (l < 0 && r > 0)
    {
        digitalWrite(leftMotor[0], LOW);
        analogWrite(leftMotor[1], l);
        analogWrite(rightMotor[0], r);
        digitalWrite(rightMotor[1], LOW);
    }

    else
    {
        digitalWrite(leftMotor[0], LOW);
        digitalWrite(leftMotor[1], LOW);
        digitalWrite(rightMotor[0], LOW);
        digitalWrite(rightMotor[1], LOW);
    }
}
void loop()
{
  motordirection();
}
