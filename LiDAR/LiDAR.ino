#include <Servo.h>
#include <Wire.h>
#include <LIDARLite.h>

Servo servoh;
Servo servov;

//const int stepsPerRevolution = 90;
// initialize the stepper library on pins 8 through 11:
//Stepper Stepper1(stepsPerRevolution, 8, 9, 10, 11);

int v_angle = 90;//135 = flat,resting position 90, 
//Verticle 40
int h_angle = 20;//DO NOT SET AT 0, resting position 90
//FRONT (sticker) 90
//LEFT (of the lidar) 180
//RIGHT 20

LIDARLite lidarLite;
int cal_cnt = 0;

void setup() {
  servov.attach(12);  // tilt servo to pin 12
  servoh.attach(4);   // pan servo to pin 4
  servov.write(v_angle);
  
  Serial.begin(115200); 

  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0); // Change this number to try out alternate configurations
}

void span() {
  
  for(int v_angle = 90; v_angle <= 135; )//angle is 90 at
  {
    for(int h_angle = 20; h_angle <= 180; h_angle++)//sweeps right to left
    {
        servoh.write(h_angle);
        Serial.println(h_angle); //Serial.print("\t");
        Serial.println(v_angle); //Serial.print("\t");
        lidar();
        delay(5);//delay between horizontal angle changes
    }
    
    v_angle = v_angle + 1;//change verticle angle by 1
    servov.write(v_angle); // update change
        
    for(int h_angle = 180; h_angle >= 20; h_angle--)//sweeps left to right
    {
        servoh.write(h_angle);
        Serial.println(h_angle); //Serial.print("\t");
        Serial.println(v_angle); //Serial.print("\t");
        lidar();
        delay(5);//delay between horizontal angle changes
    }
       
    v_angle = v_angle + 1;//change verticle angle by 1
    servov.write(v_angle); // update change
  }
}

void lidar() {
  int dist;

  // At the beginning of every 100 readings,
  // take a measurement with receiver bias correction
  if ( cal_cnt == 0 ) {
    dist = lidarLite.distance();      // With bias correction
  } else {
    dist = lidarLite.distance(false); // Without bias correction
  }

  // Increment reading counter
  cal_cnt++;
  cal_cnt = cal_cnt % 100;

  // Display distance
  Serial.println(dist);
  //Serial.print(" cm");

  delay(10);
}

void loop(){
  span();

  
}
