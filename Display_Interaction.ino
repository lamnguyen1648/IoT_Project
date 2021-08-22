//Libraries
#include <BlynkSimpleStream.h>
#include <Servo.h>
Servo servo;
//Authentication for the board to connect with Blynk application
char auth[] = "YlU6j8D329kZcfVh_fV492JLO4_UXT0Q";

void setup() {
  // put your setup code here, to run once:
  //Set the exchange rate between the board and the Serial monitor as 9600 binary per second
  Serial.begin(9600);
  //Blynk application begins with the authentication code and the exchange speed
  Blynk.begin(auth, Serial);
  //Servo attacked pin
  servo.attach(13);
  //Servo initial input
  servo.write(0);
}

//Receiving instructions from Blynk application
BLYNK_WRITE(V0)
{
  //Retrieving the input of Blynk appllication as int type
  int pinData = param.asInt();
  if(pinData==1){     //Input returns as 1 = Servo turns 180 degress = Open Lid
    servo.write(180);
  }
  if(pinData==0){     //Input returns as 0 = Servo remains 0 degrees = Close Lid
    servo.write(0);
  }
}

//System loop
void loop() {
  //Blynk application starts and system starts receiving instructions from Blynk application
  Blynk.run();
}
