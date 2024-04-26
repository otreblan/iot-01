
const int input = 53;

const int n = 4;
int leds[n] = {41, 43, 45, 47};

int led_index = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < n; i++)
  {
      pinMode(leds[i], OUTPUT);
  }
  pinMode(input, INPUT);
}

int new_index(int old_index, int button_pressed) {
  switch(button_pressed) {
    case HIGH:
      return old_index == 0 ? n-1 : old_index - 1;
    case LOW:
      return (old_index + 1)%n;
  }
}

void loop() {
  digitalWrite(leds[led_index], LOW);

  led_index=new_index(led_index, digitalRead(input));
  
  digitalWrite(leds[led_index], HIGH);
  delay(500);
}
