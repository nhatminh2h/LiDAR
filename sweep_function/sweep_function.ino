#include <Servo.h>
#include <Wire.h>

Servo servoh;
Servo servov;

int stepCount;

void setup() {
  // put your setup code here, to run once:
  servov.attach(12);  // attaches the servo on pin 9 to the servo object
  servoh.attach(4);
  
  Serial.begin(9600); 
}

void span() {
  
  for(int v_angle = 135; v_angle >= 45; )//verticle angle is 0 at up; 90 at horizontal
  {
    for(int h_angle = 20; h_angle <= 180; h_angle++)//sweeps right to left
    {
        servoh.write(h_angle);
        Serial.println(h_angle); Serial.print("\t");
        Serial.print(v_angle); Serial.print("\t");
        lidar();
        delay(50);//delay between horizontal angle changes
    }
    
    v_angle = v_angle - 10;//decrease verticle angle by 2
    servov.write(v_angle); // change verticle motor
        
    for(int h_angle = 180; h_angle >= 20; h_angle--)//sweeps left to right
    {
        servoh.write(h_angle);
        Serial.println(h_angle); Serial.print("\t");
        Serial.print(v_angle); Serial.print("\t");
        lidar();
        delay(50);//delay between horizontal angle changes
    }
       
    v_angle = v_angle - 2;//decrease verticle angle by 2
    servov.write(v_angle); // change verticle motor
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  span();
  
  
}
