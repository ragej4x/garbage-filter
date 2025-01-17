#include <Servo.h>

#define TRIG_PIN 9 
#define ECHO_PIN 10 
#define SAFE_DISTANCE 15 

Servo motor; 

void setup() {
  
  pinMode(TRIG_PIN, OUTPUT);
  
  pinMode(ECHO_PIN, INPUT);
  motor.attach(11);
  
  Serial.begin(9600);
}

int count = 0;
bool count_bool = false;

void loop() {
  
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  

  duration = pulseIn(ECHO_PIN, HIGH);

  // calculate distance in cm
  distance = (duration * 0.034) / 2;

  //Serial.print("Distance: ");
  //Serial.println(distance);

  //======================================================



  if (distance > 0 && distance <= SAFE_DISTANCE) {
    // Object detected, move motor right
    count += 1;
    Serial.println("Detect");
    Serial.println(count);

    } else 
    {count -= 1;
    Serial.println("Not Detect");
    }

    if (count == 0 && count_bool == false){
      motor.attach(11);
      motor.write(360);
      
      delay(321);
      motor.detach();
      delay(500);
      count_bool = true;
      
      } 
      
      else if (count == -1 && count_bool == true){
        
        motor.attach(11);
        motor.write(-360);
        delay(321);
        motor.detach();
        delay(500);
        count_bool = false;
        }

    if (count >= 0){
        count = 0;
    }

    if (count <= -1){
      count = -1;
      }

}
