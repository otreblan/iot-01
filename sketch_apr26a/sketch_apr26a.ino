const int n = 3;
int car_leds[n] = {41, 43, 45};
int car_led_times[n] = {10000, 2000, 7000};
int p_leds[n] = {53, 53, 51};

void setup() {
  for(int i = 0; i < n; i++) {
    pinMode(car_leds[i], OUTPUT);
    pinMode(p_leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < n; i++) {
    digitalWrite(car_leds[i], HIGH);
    digitalWrite(p_leds[i], HIGH);
    delay(car_led_times[i]);
    digitalWrite(car_leds[i], LOW);
    digitalWrite(p_leds[i], LOW);
  }
}
