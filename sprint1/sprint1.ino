/* Strandtest example code modified Jan 2021 Doug Whitton, modified further by Victor Nguyen.
 * Code lights up 4 different neopixels, one of each colour in a cycle in order, then dims them back down in order, then loops. 
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
  red.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
 
  green.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  green.show();            // Turn OFF all pixels ASAP
  green.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
    
  blue.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  blue.show();            // Turn OFF all pixels ASAP
  blue.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Light each pixel up in a colour, then pause.
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
  Serial.println(val);
  if (val > 0 && val <20){
    blue.setPixelColor(0, 0,0,255);         //  Set pixel's color (in RAM)
    blue.show();  
  }else{ blue.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
    blue.show();  }  
      if (val > 60 && val <90){
    red.setPixelColor(0, 255,0,0);         //  Set pixel's color (in RAM)
    red.show();  
  }else{ red.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
    red.show();  }  
          if (val > 130 && val <180){
    green.setPixelColor(0, 0,255,0);         //  Set pixel's color (in RAM)
    green.show();  
  }else{ green.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
    green.show();  }
// red.setPixelColor(0, 255,0,0);         //  Set pixel's color (in RAM)
// red.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// yellow.setPixelColor(0, 255,150,0);         //  Set pixel's color (in RAM)
// yellow.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// green.setPixelColor(0, 0,255,0);         //  Set pixel's color (in RAM)
// green.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// blue.setPixelColor(0, 0,0,255);         //  Set pixel's color (in RAM)
// blue.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// //turn off the pixel's light. Then loops.
// red.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
// red.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// yellow.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
// yellow.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// green.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
// green.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment
// blue.setPixelColor(0, 0,0,0);         //  Set pixel's color (in RAM)
// blue.show();                          //  Update strip to match
// delay(500);                           //  Pause for a moment 

}
