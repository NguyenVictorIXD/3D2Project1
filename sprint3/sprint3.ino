/* Strandtest example code modified Jan 2021 Doug Whitton, modified further by Victor Nguyen.
 * This program uses the servo motor and potentiometer as a pointer/meter. I've affixed an arrow to the servo. By measuring the position of the motor with Serial.println I use the variable returned to check whether the arrow is pointing 
 * at a light. If it is, I display a light colour.
*/
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

// Declare our NeoPixel strip object:
Adafruit_NeoPixel red(1, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel green(1, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel blue(1, 6, NEO_GRB + NEO_KHZ800);
Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

// setup() function -- runs once at startup --------------------------------

void setup() {
  Serial.begin(9600);
  myservo.attach(11);  // attaches the servo on pin 11 to the servo object
  red.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  red.show();            // Turn OFF all pixels ASAP
  red.setBrightness(100); // Set BRIGHTNESS 
 
  green.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  green.show();            // Turn OFF all pixels ASAP
  green.setBrightness(100); // Set BRIGHTNESS
    
  blue.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  blue.show();            // Turn OFF all pixels ASAP
  blue.setBrightness(100); // Set BRIGHTNESS 
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Light each pixel up in a colour, then pause.
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
  Serial.println(val);

  //checks if servo is pointing at the rightmost light
  if (val > 0 && val <20){
    blue.setPixelColor(0, 0,0,255);         //  Set pixel's color (in RAM)
    blue.show();  
  }else{ blue.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
    blue.show();  }

  //checks if servo is pointing at the middle light
      if (val > 60 && val <90){
    red.setPixelColor(0, 255,0,0);         //  Set pixel's color (in RAM)
    red.show();  
  }else{ red.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
    red.show();  }  

      //checks if servo is pointing at the leftmost light
          if (val > 130 && val <180){
    green.setPixelColor(0, 0,255,0);         //  Set pixel's color (in RAM)
    green.show();  
  }else{ green.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
    green.show();  }

}
