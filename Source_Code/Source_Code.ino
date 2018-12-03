/*  Vibration Sensor With I2C LCD And Buzzer
 * 
 *  GitHub URL - https://github.com/narayanvyas/Arduino-Vibration-Sensor-With-LCD
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - A Buzzer
 *  - A Vibration Sensor Module
 *  - An I2C LCD
 *  
 *  Libraries
 *  ---------
 *  - None
 *  
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

int buzzerPin = 7;
int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin (16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.home ();    // set cursor to 0,0
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue<1000) {
    tone(buzzerPin, 1000);
    lcd.print("Welcome Guest");
    lcd.setBacklight(HIGH);
    delay(5000);
  }
  noTone(buzzerPin);
  lcd.clear();
  lcd.setBacklight(LOW);
}
