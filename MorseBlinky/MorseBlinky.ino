/**********************************************************  
NeoPixel Valentine message by Tim Bartlett
current settings for 5v Trinket and single Flora NeoPixel
**********************************************************/

#include <Adafruit_NeoPixel.h>
#define PIN 1

int aPx = 255;  // set
int bPx = 20;  // set
int fadeHigh = 70; // set
int fDelay = 15;  // set
int dahDelay;
int diDelay;
int spaceDelay;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  dahDelay = (fDelay * 2);
  diDelay = fDelay;
  spaceDelay = (fDelay * (255 - bPx));

  strip.begin();
  strip.show();
}

void loop() {
  pinkOn(5); // variable is in seconds if less than 100, or milliseconds if greater
  // Morse code is listed at the bottom of this code
  // End each letter with dit or daht  
  di(); di(); di(); dit(); // H
  dit(); // E
  di(); dah(); di(); dit(); // L
  di(); dah(); di(); dit(); // L
  dah(); dah(); daht(); // O
  space();
  di(); dah(); daht(); // W
  dah(); dah(); daht(); // O
  di(); dah(); dit(); // R
  di(); dah(); di(); dit(); // L
  dah(); di(); dit(); // D
  space();}

void dah() {
  for (int i = bPx; i < fadeHigh; i++) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(dahDelay);
  }  
  for (int i = (fadeHigh - 1); i > (bPx - 1); i--) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(dahDelay);
  } 
}

void daht() {
  for (int i = bPx; i < fadeHigh; i++) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(dahDelay);
  }  
  for (int i = (fadeHigh - 1); i > (bPx - 1); i--) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(dahDelay);
  }
  delay(spaceDelay);
}

void di() {
  for (int i = bPx; i < fadeHigh; i++) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(diDelay);
  }  
  for (int i = (fadeHigh - 1); i > (bPx - 1); i--) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(diDelay);
  } 
}

void dit() {
  for (int i = bPx; i < fadeHigh; i++) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(diDelay);
  }  
  for (int i = (fadeHigh - 1); i > (bPx - 1); i--) {
    strip.setPixelColor(0, aPx, i, i);
    strip.show();
    delay(diDelay);
  }
  delay(spaceDelay);
}

void pinkOn(int f){
  int d;
  if (f > 0 && f <100){
    d = (f * 1000);
  }
  else if (f > 99){
    d = f;
  }
  else {
    d = 2000;
  }
 
  strip.setPixelColor(0, aPx, bPx, bPx);
  strip.show();
  delay(d); 
}

void space(){
  delay(spaceDelay);
}


/*  MORSE CODE
A
di-dah
B
dah-di-di-dit
C
dah-di-dah-dit
D
dah-di-dit
E
dit
F
di-di-dah-dit
G
dah-dah-dit
H
di-di-di-dit
I
di-dit
J
di-dah-dah-dah
K
dah-di-dah
L
di-dah-di-dit
M
dah-dah
N
dah-dit
O
dah-dah-dah
P
di-dah-dah-dit
Q
dah-dah-di-dah
R
di-dah-dit
S
di-di-dit
T
dah
U
di-di-dah
V
di-di-di-dah
W
di-dah-dah
X
dah-di-di-dah
Y
dah-di-dah-dah
Z
dah-dah-di-dit

0
dah-dah-dah-dah-dah
1
di-dah-dah-dah-dah
2
di-di-dah-dah-dah
3
di-di-di-dah-dah
4
di-di-di-di-dah
5
di-di-di-di-dit
6
dah-di-di-di-dit
7
dah-dah-di-di-dit
8
dah-dah-dah-di-dit
9
dah-dah-dah-dah-dit

*/

