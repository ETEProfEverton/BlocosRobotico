int buzzer = 10;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void dois(){
  tone(buzzer, 700, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
  tone(buzzer, 392, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
}

void tres(){
  tone(buzzer, 700, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
  tone(buzzer, 392, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
  tone(buzzer, 392, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
}

void quatro(){
  tone(buzzer, 700, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
  tone(buzzer, 392, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
  tone(buzzer, 392, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
  tone(buzzer, 392, 500);
  delay(100);
  noTone(buzzer);
  delay(500);
}

void loop() {
  
}
