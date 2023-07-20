#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
  #define PSTR // use flash instead of ram??
#endif

#define MATRIXPIN 4 //D2 on my esp8266
#define BTNPIN 5

// Configure matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, MATRIXPIN,
  NEO_MATRIX_TOP + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(0, 15, 255), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)
};

int mode = 0;
int buttonState = 0;

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);

  pinMode(BTNPIN, INPUT);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  buttonState = digitalRead(BTNPIN);

  if (buttonState == HIGH) {
    changeMode();
    delay(300); // Debounce delay
  }

  if (mode == 0) {
    matrix.setCursor(0, 0);
    matrix.print(F("HiJuan"));
  } else if (mode == 1) {
    matrix.setCursor(0, 0);
    matrix.print(F("Howdy"));
  }

  matrix.show();
  delay(100);
}

void changeMode() {
  mode++;
  if (mode > 1) {
    mode = 0;
  }
}