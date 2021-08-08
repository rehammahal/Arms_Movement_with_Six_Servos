#include <Servo.h>

#define sw1_pin 7
#define sw2_pin 6
#define sw3_pin 5

Servo arm1A;
Servo arm2A;
Servo arm3A;
Servo arm1B;
Servo arm2B;
Servo arm3B;

int initialPos = 90;

volatile boolean sw1 = false;
volatile boolean sw2 = false;
volatile boolean sw3 = false;

uint8_t sw1ButtonState = 0;
uint8_t sw2ButtonState = 0;
uint8_t sw3ButtonState = 0;

uint8_t lastsw1ButtonState = 0;
uint8_t lastsw2ButtonState = 0;
uint8_t lastsw3ButtonState = 0;



void setup() {
  
  Serial.begin(9600);

  pinMode(sw1_pin, INPUT_PULLUP);
  pinMode(sw2_pin, INPUT_PULLUP);
  pinMode(sw3_pin, INPUT_PULLUP);
  
  arm1A.attach(8);
  arm2A.attach(9);
  arm3A.attach(10);
  arm1B.attach(11);
  arm2B.attach(12);
  arm3B.attach(13);
  
  arm1A.write(initialPos);
  arm2A.write(initialPos);
  arm3A.write(initialPos);
  arm1B.write(initialPos);
  arm2B.write(initialPos);
  arm3B.write(initialPos);
  delay(200);
  
  }


void loop() {
  
  checkIfSw1ButtonIsPressed();

  checkIfSw2ButtonIsPressed();
  
  checkIfSw3ButtonIsPressed();
  
  
  if(sw1){
      Serial.println("Give hug!");
      sw1 = false;
      arm1A.write(90);
      arm2A.write(90);
      arm3A.write(90);
      arm1B.write(90);
      arm2B.write(90);
      arm3B.write(90);
      delay(15);
     }

  else if(sw2){
      Serial.println("Hello there!");
      sw2 = false;
      arm1A.write(180);
      arm2A.write(180);
      arm3A.write(180);
      arm1B.write(180);
      arm2B.write(180);
      arm3B.write(180);
      delay(15);
     }
  else if(sw3){
      Serial.println("You Are Welcome!");
      sw3 = false;
      arm1A.write(130);
      arm2A.write(130);
      arm3A.write(130);
      arm1B.write(130);
      arm2B.write(130);
      arm3B.write(130);
      delay(15);
     }

}


void checkIfSw1ButtonIsPressed(){

    sw1ButtonState = digitalRead(sw1_pin);
  
    if (sw1ButtonState != lastsw1ButtonState){

    	if ( sw1ButtonState == 0){
      		sw1=true;
		}

    delay(50);

  	}
   lastsw1ButtonState = sw1ButtonState;
}


void checkIfSw2ButtonIsPressed(){

    sw2ButtonState = digitalRead(sw2_pin);
  
    if (sw2ButtonState != lastsw2ButtonState){

    	if ( sw2ButtonState == 0){
      		sw2=true;
		}

    delay(50);

  	}
   lastsw2ButtonState = sw2ButtonState;
}


void checkIfSw3ButtonIsPressed(){

    sw3ButtonState = digitalRead(sw3_pin);
  
    if (sw3ButtonState != lastsw3ButtonState){

    	if ( sw3ButtonState == 0){
      		sw3=true;
		}

    delay(50);

  	}
   lastsw3ButtonState = sw3ButtonState;
}