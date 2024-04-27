#include <Keypad.h>

const int n = 3;
int car_leds[n] = {41, 43, 45};
int car_led_times[n] = {10000, 2000, 7000};
int p_leds[n] = {53, 53, 51};

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {36,34,32,30};
byte colPins[COLS] = {28,26,24,22};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void keypadEvent(KeypadEvent key){
  Serial.println("aaaa");
  switch (kpd.getState()){
    case PRESSED:
      Serial.println(key);
      break;
  }
}

void setup() {
  for(int i = 0; i < n; i++) {
    pinMode(car_leds[i], OUTPUT);
    pinMode(p_leds[i], OUTPUT);
  }
  Serial.begin(9600);
  kpd.addEventListener(keypadEvent);
  interrupts();
}

void loop() {
  char key = kpd.getKey();
  
  //if (key != NO_KEY){
  //  Serial.println(key);
  //}
  
  for(int i = 0; i < n; i++) {
    digitalWrite(car_leds[i], HIGH);
    digitalWrite(p_leds[i], HIGH);
    delay(car_led_times[i]);
    digitalWrite(car_leds[i], LOW);
    digitalWrite(p_leds[i], LOW);
  }
}
