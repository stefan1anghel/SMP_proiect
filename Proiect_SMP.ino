#include <RobotIRremote.h>
#include <RobotIRremoteInt.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void clockwise(int i, int k)
{
  
  analogWrite(i, 0);
  analogWrite(k, 255);
  
}

void right(int i, int k)
{
  
  analogWrite(i, 100);
  analogWrite(k, 255);
  
}

void left(int i, int k)
{
  
  analogWrite(i, 100);
  analogWrite(k, 255);
  
}
void anticlockwise(int i, int k)
{
  analogWrite(i, 255);
  analogWrite(k, 0);
 
}
void sspin(int i, int k)
{
 
  analogWrite(i, 0);
  analogWrite(k, 0);

}
void loop() {
  if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF629D: //Keypad button "2"(fata)
          clockwise(9,8);
          clockwise(10,11);
          break;
          case 0xFFA857: //Keypad button "8"(spate)
          anticlockwise(9,8);
          anticlockwise(10,11);
          break;
          case 0xFFC23D: //Keypad button "6"(dreapta)
          clockwise(9,8);
          right(10,11);
          break;
          case 0xFF22DD: //Keypad button "4"(stanga)
          clockwise(10,11);
          left(9,8);
          break;
          case 0xFF38C7: //Keypad button "OK"(STOP)
          sspin(9,8);
          sspin(10,11);
          break;
          }

        
Serial.println(results.value, HEX);
        irrecv.resume(); 
    }
}
