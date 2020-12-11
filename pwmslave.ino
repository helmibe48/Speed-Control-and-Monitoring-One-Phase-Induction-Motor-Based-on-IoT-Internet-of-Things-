#include <Wire.h>
int x = 0;
const int output_2 = 2;
const int output_3 = 3;
const int buzzer = 4;

void setup() {
  Serial.begin(9600);
  pinMode(output_2,OUTPUT);
  pinMode(output_3,OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  delay(250);
  digitalWrite(buzzer, LOW);
  Wire.begin(9); // Start the I2C Bus as Slave on address 9
  Wire.onReceive(receiveEvent);  // Attach a function to trigger when something is received.
  Wire.onRequest(requestEvent);
}

void requestEvent()
{
  Wire.write("Slave Terhubung");
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}


void loop() {
Serial.println(x);

if (x == 0){
  digitalWrite(output_2,LOW);
  digitalWrite(output_3,LOW);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,LOW);
}
else if (x <= 40){
  digitalWrite(output_2,HIGH);
  digitalWrite(output_3,LOW);
  delay(12);
  delayMicroseconds(500);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,HIGH);
  delay(12);
  delayMicroseconds(500);
}
else if (x <= 45){
  digitalWrite(output_2,HIGH);
  digitalWrite(output_3,LOW);
  delay(11);
  delayMicroseconds(111);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,HIGH);
  delay(11);
  delayMicroseconds(111);
}
else if (x <= 50){
  digitalWrite(output_2,HIGH);
  digitalWrite(output_3,LOW);
  delay(10);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,HIGH);
  delay(10);
}
else if ( x <= 55) {
  digitalWrite(output_2,HIGH);
  digitalWrite(output_3,LOW);
  delay(9);
  delayMicroseconds(111);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,HIGH);
  delay(9);
  delayMicroseconds(111);
}
else if (x <= 60){
  digitalWrite(output_2,HIGH);
  digitalWrite(output_3,LOW);
  delay(8);
  delayMicroseconds(333);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,HIGH);
  delay(8);
  delayMicroseconds(333);
}
else if (x >= 61){
  digitalWrite(output_2,HIGH);
  digitalWrite(output_3,LOW);
  delay(7);
  delayMicroseconds(777);

  digitalWrite(output_2,LOW);
  digitalWrite(output_3,HIGH);
  delay(7);
  delayMicroseconds(777);
}
else {
  Serial.println("Masukkan frekuensi tidak benar");
  Wire.write("Masukkan frekuensi tidak benar");
}
}
