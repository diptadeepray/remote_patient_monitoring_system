//LCD-I2C-ARDUINO

//LCD-I2C-ARDUINO
//Vcc of I2C Adapter must be connected to 5V Vout of Arduino
//Gnd of I2C Adapter must be connected to Gnd of Arduino
//SDA of I2C Adapter must be connected to A4 of Arduino
//SCL of I2C Adapter must be connected to A5 Vout of Arduino

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//Worked with old LCD,new LCD at address 0x27 


void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  Serial.print("Ready to receive data from NodeMCU");

  lcd.init();                      // initialize the lcd  //this is needed
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Project of RAY");
  delay(1000);

}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    String receivedData = Serial.readStringUntil('\n'); // Read the incoming data
    //Serial.println("Received: " + receivedData); // Print the received data

lcd.setCursor(0,1);
lcd.print(receivedData);
  }
}
