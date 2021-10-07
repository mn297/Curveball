#include <Servo.h>
#define aPin 6
#define bPin 7
#define led_pin 13

int counter = 0;
int aState, aLastState = 0;
int i= 0;
int straight = 101;
Servo myservo;

void setup() {

  Serial.begin (9600);


  pinMode(6, INPUT); //encoder A
  pinMode(7, INPUT);  //encoder B

  pinMode(led_pin,OUTPUT);
  myservo.attach(10);

  myservo.write(straight);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(straight);
 
}
 
void loop() {
   
//1 CHANNEL
  aState = digitalRead(aPin);
  if ( aState != aLastState){
      counter++;
     Serial.println(counter);
  }
  aLastState = aState;

  
////TRIGGER
  if (counter >= 37) {
    trigger();
  }

}
void trigger() {
      for (i = straight; i >= 90; i -=1){
       myservo.write(i);
       delay(25);
    }
    for (i = 90; i >= 83; i -=1){
       myservo.write(i);
       delay(18);
    }
    for (i = 83; i >= 75; i -=1){
       myservo.write(i);
       delay(15);
    }
    
    delay(180);
    
    for (i = 45; i <= straight; i +=1){
       myservo.write(i);
       delay(10);
    }
//
//  myservo.write(straight);
    counter = 0;
    delay(3000);
}
