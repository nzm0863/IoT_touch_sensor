#include <Adafruit_NeoPixel.h>

#define KEY_C 4
#define KEY_D 13
#define KEY_E 27
int LED_PIN = 5;

int LED_COUNT = 8;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  Serial.begin(115200);
  
  strip.begin();
  strip.setBrightness(5);
  strip.show();
}


void loop() {

  int C = touchRead(KEY_C);
  int D = touchRead(KEY_D);
  int E = touchRead(KEY_E);

  Serial.println(String(C) + "," + String(D) + "," + String(E));

  C = constrain(C,0,1000);
  D = constrain(D,0,1000);
  E = constrain(E,0,1000);
  int colorC = map(C,1000,0,0,255);
  int colorD = map(D,1000,0,0,255);
  int colorE = map(E,1000,0,0,255);

  if(C<500||D<500||E<500){
    for(int i=0;i<LED_COUNT;i++){
      strip.setPixelColor(i,colorC,colorD,colorE);
    }
  }else{
    strip.clear();
  }
  strip.show();
  delay(100);
  
}