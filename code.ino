#include <LiquidCrystal.h> // include lcd library 

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int tempPin = A0; // TMP36 output connected to A0

void setup() {
  lcd.begin(16, 2);  // Set up the LCD
  lcd.print("Initializing...");
  delay(1000);       // Wait for 1 second
}

void loop() {
  // Read analog value from TMP36
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
  float temperature = (voltage - 0.5) * 100.0;  // Convert to temperature

  // Display temperature on LCD
  lcd.clear();
  lcd.setCursor(0, 0); // starting position of cursor
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  delay(2000); // Wait 2 seconds before updating
}
