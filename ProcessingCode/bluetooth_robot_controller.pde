import processing.serial.*;
int value = 0;
int width = 50;
int height = 50;
int baud = 9600;

Serial arduino;
 
void setup(){
  size(height, width);
  String arduinoPort = "COM5";
  println(Serial.list());
  arduino = new Serial(this, arduinoPort, baud);
}
 
void draw(){
   if (keyPressed == true){
      println(key);
    if (key == 'w') arduino.write('w');
    else if (key == 's') arduino.write('s');
    else if (key == 'a') arduino.write('a');
    else if (key == 'd') arduino.write('d');
    else if (key == 'r') arduino.write('r');
  } else arduino.write('z');
}

void serialEvent(Serial port){
  String inByte = port.readStringUntil('\n');
  if (inByte != null) println(inByte);
}
