const int RED_PIN = 12;
const int GREEN_PIN = 11;
const int YELLOW_PIN = 10;
const int BRED_PIN = 4;
const int BGREEN_PIN = 5;
const int BYELLOW_PIN = 6;
const int BUZZER_PIN = 2;

int red = RED_PIN;
int green = GREEN_PIN;
int yell = YELLOW_PIN;
int bred = BRED_PIN;
int bgreen = BGREEN_PIN;
int byell = BYELLOW_PIN;
int buzzpin = BUZZER_PIN;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yell, OUTPUT);
  pinMode(bred, INPUT_PULLUP);
  pinMode(bgreen, INPUT_PULLUP);
  pinMode(byell, INPUT_PULLUP);
  pinMode(buzzpin, OUTPUT);
}

void loop() {
  if (digitalRead(bred) == HIGH && digitalRead(bgreen) == LOW && digitalRead(byell) == LOW) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yell, LOW);
    tone(buzzpin, HIGH);
    delay(5000);
  } else if (digitalRead(bgreen) == HIGH && digitalRead(bred) == LOW && digitalRead(byell) == LOW) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yell, LOW);
    tone(buzzpin, HIGH);
    delay(5000);
  } else if (digitalRead(byell) == HIGH && digitalRead(bgreen) == LOW && digitalRead(bred) == LOW) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yell, HIGH);
    tone(buzzpin, HIGH);
    delay(5000);
      } else if (digitalRead(byell) == LOW && digitalRead(bgreen) == LOW && digitalRead(bred) == LOW) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yell, LOW);
    noTone(buzzpin);
    
  }
}

