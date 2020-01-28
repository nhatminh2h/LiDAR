#include <Servo.h>
#include <Wire.h>
#include <LIDARLite.h>

Servo servoh;
Servo servov;
LIDARLite lidarLite; //lidar object

//const int stepsPerRevolution = 90;
// initialize the stepper library on pins 8 through 11:
//Stepper Stepper1(stepsPerRevolution, 8, 9, 10, 11);




int v_angle = 60;//135 = flat,resting position 90, 
//Verticle 40
int h_angle = 20;//DO NOT SET AT 0, resting position 90
//FRONT (sticker) 90
//LEFT (of the lidar) 180
//RIGHT 20



void setup() {
  servov.attach(12);  // tilt servo to pin 12
  servoh.attach(4);   // pan servo to pin 4
  servov.write(v_angle);
  
  Serial.begin(115200); 

  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0); // Change this number to try out alternate configurations
}

void span() {
  
  for(int v_angle = 60; v_angle <= 150; )//angle is 135 at flat
  {
    for(int h_angle = 20; h_angle <= 180; h_angle++)//sweeps right to left
    {
        servoh.write(h_angle);
        Serial.println(h_angle); //Serial.print("\t");
        Serial.println(v_angle); //Serial.print("\t");
        lidar();
        //delay(1);//delay between horizontal angle changes
    }
    
    v_angle = v_angle + 1;//change verticle angle by 1
    servov.write(v_angle); // update change
        
    for(int h_angle = 180; h_angle >= 20; h_angle--)//sweeps left to right
    {
        servoh.write(h_angle);
        Serial.println(h_angle); //Serial.print("\t");
        Serial.println(v_angle); //Serial.print("\t");
        lidar();
        //delay(1);//delay between horizontal angle changes
    }
       
    v_angle = v_angle + 1;//change verticle angle by 1
    servov.write(v_angle); // update change
  }
}

void lidar() {
  int dist, cal_cnt = 0, sample = 5, i;
  int distance[sample];
  
  // At the beginning of every 100 readings,
  // take a measurement with receiver bias correction
  for (i = 0; i <sample; i++){
    if ( cal_cnt == 0 ) {
      distance[i] = lidarLite.distance();      // With bias correction
    }
    else {
      distance[i] = lidarLite.distance(false); // Without bias correction
    }
  }

  Array_sort(distance, sample);//sort distance array
  dist = Find_median(distance, sample);//find median distance

  // Increment reading counter
  cal_cnt++;
  cal_cnt = cal_cnt % 100;

  // Display distance
  Serial.println(dist);

  //delay(1);
}



void loop(){
  span();
  Serial.write("--End of Scan--");
  
}
