//Library
#include <LiquidCrystal.h>
#include <Servo.h>
//LCD connection
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);
//Ultrasonic sensors have 2 signal connection pins, trigger and echo
//echo is the input pin, monitoring the bin capacity
//trigger is the output pin, which sends the data collected to the board
const int trig = 11;
const int echo = 12;
Servo servo;
float time, distance;

void setup() {
  //lcd starts with its dimensional specifications (in this case 16x2)
  lcd.begin(16, 2);
  //setting trig pin as output
  pinMode(trig, OUTPUT);
  //setting echo pin as input
  pinMode(echo, INPUT);
  //exchange rate between Serial monitor and the board is 9600 binary per second
  servo.attach(13);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  //lcd display
  //starts at the first line (line 0)
  lcd.setCursor(0, 0);
  lcd.print("Bin Status: ");
  
  //trig pin calculation before sending data
  digitalWrite(trig, LOW);
  delay(200);
  digitalWrite(trig, HIGH);
  delay(200);
  digitalWrite(trig, LOW);
  
  //setting time as data inputted from echo pin
  time = pulseIn(echo, HIGH);
  
  //calculating the distance
  distance = (time*.0342)/2;
  if(distance <= 60) {
    //Servo turns 180 degrees
    servo.write(180);
    //Update bin status
    lcd.setCursor(0, 1);
  	lcd.print("Open");
  }
  else {
    servo.write(0);
    lcd.setCursor(0, 1);
    lcd.print("Closed");
  }
  
  //updates every 100 miliseconds
  delay(100);
}
