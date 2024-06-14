/*
    Project name : IR Transmiter Sensor
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-ir-transmiter-sensor
*/

#include <IRremote.h>

const int irLedPin = 3; // Pin where the IR LED is connected

IRsend irsend;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(irLedPin, OUTPUT); // Set the IR LED pin as output
}

void loop() {
  // Example: Send an IR signal
  sendIRSignal();

  // Wait for 5 seconds before sending the next signal
  delay(5000);
}

void sendIRSignal() {
  // Example: Send NEC protocol signal (replace with the actual code for your device)
  unsigned long irCode = 0xFFA25D; // Replace with your device's IR code

  // Send the IR code
  irsend.sendNEC(irCode, 32); // Send NEC signal with 32-bit length
  Serial.print("Sent IR code: ");
  Serial.println(irCode, HEX);
  
  // Blink the IR LED for visual confirmation (optional)
  digitalWrite(irLedPin, HIGH);
  delay(200);
  digitalWrite(irLedPin, LOW);
}
