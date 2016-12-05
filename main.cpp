#include "application.h"
#include "LiquidCrystal/LiquidCrystal.h"

// Setup Crystal Display
LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);

void setup() {
  // Write
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Inside:");
  
  // Set timezone to Helsinki
  Time.zone(+2);
  
  // Set A0 Pinmode to input (temp sensor)
  pinMode(A0, INPUT);
}

void loop() {
  // Read TMP sensor value
  int analogValue = analogRead(A0); 
  double voltage = 3.3 * ((double)analogValue / 4095.0);
  int temperatureC = (voltage - 0.5) * 100;
  
  // Write temperature
  lcd.setCursor(14, 0);
  lcd.print(temperatureC);
  
  // Write time
  lcd.setCursor(0, 1);
  lcd.print(Time.format("%d/%m   %H:%M:%S"));
  
  delay(1000);
}
