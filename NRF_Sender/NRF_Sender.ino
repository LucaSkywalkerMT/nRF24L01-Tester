#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio1(9, 10); // CE, CSN
const byte address[6] = "00001";
void setup() {
  radio1.begin();
  radio1.openWritingPipe(address);
  radio1.setPALevel(RF24_PA_MIN);
  radio1.stopListening();
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()) {
    char in = Serial.read();
    radio1.write(&in, sizeof(in));
  }
}
