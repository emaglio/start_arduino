#include <Arduino.h>
#include <stdlib.h>
#include "/first_arduino/libraries/LiquidCrystal/LiquidCrystal.h"

#include "/first_arduino/libraries/TempAndLight/TempAndLight.h"
#include "/first_arduino/libraries/MyLCD/MyLCD.h"

float tempVal;
float lightVal;

//these must be volatile to be used in the interrupt
volatile float temp;
volatile float light;

//button pins
const uint8_t ok_pin = 3;
const uint8_t scroll_pin = 2;

//buzzer pin
const uint8_t buzzer_pin = 13;

//libraries
TempAndLight sensors(0,1);
MyLCD lcd(11,12,7,6,5,4);

//Event functions

void buzzer(){
	tone(buzzer_pin, 1000);
	delay(500);
	noTone(buzzer_pin);
}

void ok(){
	lcd.clean();
	lcd.setCursor(0,0);
	lcd.print("OK");
	Serial.println("ok");
}

void scroll (){
	lcd.clean();
	lcd.setCursor(0,0);
	lcd.print("scroll");
	Serial.println("scroll");
}

void setup() {
	Serial.begin(115200);

	//columns, rows, font (58 -> 5x8 or 511 -> 5x11)
	lcd.begin(16,2,58);

	//using internal pullup resistor
	pinMode(ok_pin, INPUT_PULLUP);
	pinMode(scroll_pin, INPUT_PULLUP);
	//set up the interrupt pin, what to call and when to call it
	attachInterrupt(digitalPinToInterrupt(ok_pin), ok, CHANGE);
	attachInterrupt(digitalPinToInterrupt(scroll_pin), scroll, CHANGE);

	//buzzer set up
	pinMode(buzzer_pin, OUTPUT);

	//Start-up with something in the display
	lcd.setCursor(2,0);
	lcd.print("Welcome to:");
	lcd.setCursor(1,1);
	lcd.print("First Arduino");
	delay(4000);
	lcd.clean();
}

void loop() {
	delay(3000);
	lcd.setCursor(0,0);
	lcd.print("Trailblazer");
	lcd.setCursor(6,1);
	lcd.print("PowerUser");

//	lcd.print("Hello world!");
//	Serial.println("Check Hello World");
//	delay(4000);
//	Serial.println("Cleaning display");
//	lcd.clean();
//	tempVal = sensors.getTemp();
//	lightVal = sensors.getLight();
//	Serial.print("Light: ");
//	Serial.print(lightVal);
//	Serial.println(" V");
//	Serial.print("Temp:");
//	Serial.print(tempVal);
//	Serial.println(" C");

//	lcd.setCursor(0, 0);
//	Serial.println("Write temp");
//	lcd.print(tempVal);
//	delay(1000);
}
