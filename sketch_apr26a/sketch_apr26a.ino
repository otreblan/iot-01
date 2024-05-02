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

int hour = 0;

void newDigit(int digit){
  hour = hour*10+digit;
  Serial.println(digit);
}

void enter(){
  Serial.print("Enter ");
  Serial.println(hour);

  hour = 0;
  // TODO
}

void keypadEvent(KeypadEvent key){
  switch (kpd.getState()){
    case PRESSED:
      switch(key) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          newDigit(key-'0');
          break;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case '*':
        case '#':
          enter();
          break;
      }
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

void led_delay(int index) {
  int t = car_led_times[index];
  for(int i = 0; i <= t; i += 10) {
    kpd.getKey();
    delay(i);
  }
}

void loop() {
  for(int i = 0; i < n; i++) {
    digitalWrite(car_leds[i], HIGH);
    digitalWrite(p_leds[i], HIGH);
    led_delay(i);
    digitalWrite(car_leds[i], LOW);
    digitalWrite(p_leds[i], LOW);
  }
}
