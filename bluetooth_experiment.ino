#include <SoftwareSerial.h>// import the serial library
int ledpin = 13; // led on D13 will show blink on / off
int bluetoothData; // the data given from Computer

int counter = 0;
int input;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  Serial.println("Waiting for input...");
}

String output = "";
int i;
char letter;

void loop() {
  
  while(!Serial.available());
  i = Serial.read();
  if(i != 13){
    output += (char)i;
  }else if(i == 13){
    Serial.println(output);
    output = "";
  }
  delay(500);
}


String receiveInput(){
  String s = "";
  int i;
  while(!Serial.available());
  i = Serial.read();
  if(i != 13){
     s += (char)i;
  }else{
   return s;
  }
}

