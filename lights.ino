#include <FastLED.h>
#define pins 5            
#define numOfLEDs 10 

int r=152;
int g=0;
int b=10;

CRGB leds[numOfLEDs];
CRGB led[numOfLEDs];
int s=0;

void setup() {
  FastLED.addLeds<WS2812, pins, GRB>(leds, numOfLEDs);
  for (int i = numOfLEDs/2; i >= 0; i--){
     leds[i] = CRGB ( r,g,b);
     leds[numOfLEDs-i] = CRGB (r,g,b );
     delay(40);
     FastLED.show();
  }
  Serial.begin(9600);
   pinMode(A0,INPUT);

}

void loop(){
  sound = analogRead(A0);
  sound *= 2;
  if((sound>=200)&&(sound<=230)){
     leds[(numOfLEDs/2)-1]=CRGB (1, 0, 1);
     leds[numOfLEDs/2]=CRGB (1, 0, 1);
   }
     else if((sound>=235)&&(sound<=250)){
       leds[(numOfLEDs/2)-1]=CRGB (0, 160, 0);
       leds[numOfLEDs/2]=CRGB (0, 160, 0);
   }
     else if((sound>=250)&&(sound<=275)){
       leds[(numOfLEDs/2)-1]=CRGB (230, 0, 10);
       leds[numOfLEDs/2]=CRGB (230, 0, 10);
   }
     else if((sound>=276)&&(sound<=300)){
       leds[(numOfLEDs/2)-1]=CRGB (50, 50, 150);
       leds[numOfLEDs/2]=CRGB (50, 50, 150);
   }
     else if((sound>=300)&&(sound<=350)){
       leds[(numOfLEDs/2)-1]=CRGB (10, 25, 217);
       leds[numOfLEDs/2]=CRGB (10, 25, 217);
   }
     else if((sound>=350)&&(sound<=400)){
       leds[(numOfLEDs/2)-1]=CRGB (255, 50, 255);
       leds[numOfLEDs/2]=CRGB (255, 50, 255);
   }
     else if((sound>=400)&&(sound<=450)){
       leds[(numOfLEDs/2)-1]=CRGB (153, 153, 0);
       leds[numOfLEDs/2]=CRGB (153, 153, 0);
  }
     else if((sound>=450)&&(sound<=550)){
       leds[(numOfLEDs/2)-1]=CRGB (0, 0, 255);
       leds[numOfLEDs/2]=CRGB (0, 0, 255);
   }
  else{
     leds[(numOfLEDs/2)-1] = CRGB ( r,s-100,b);
     leds[numOfLEDs/2] = CRGB ( r,s-100,b);
  }
    for (int i = 0; i <= ((numOfLEDs/2)-2); i++) {
     leds[i] = leds[i+1];
     leds[numOfLEDs-1-i] = leds[(numOfLEDs)-i-2]; 
  }
 FastLED.show();
 delay(25);

}