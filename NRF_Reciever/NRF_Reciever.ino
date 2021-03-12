#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const byte address[6] = "00001";
RF24 radio2(9, 10); // CE, CSN
void setup() {
  radio2.begin();
  radio2.openReadingPipe(0, address);
  radio2.setPALevel(RF24_PA_MIN);
  radio2.startListening();
  Serial.begin(9600);
}
void loop() {
if (radio2.available())
  {
    char text[32] = "";
    radio2.read(&text, sizeof(text));
    Serial.print(text);
  }
}
