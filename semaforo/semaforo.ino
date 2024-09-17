int pinVM = 9;
int pinVD = 10;

void setup(){
  pinMode(pinVD, OUTPUT);
  pinMode(pinVM, OUTPUT);
}

void vermelho(int tempo){
  digitalWrite(pinVM, HIGH);
  delay(tempo*1000);
  digitalWrite(pinVD, LOW);
}

void verde(int tempo){
  digitalWrite(pinVD, HIGH);
  delay(tempo*1000);
  digitalWrite(pinVD, LOW);
}

void amarelo(int tempo){
  digitalWrite(pinVM, HIGH);
  analogWrite(pinVD, 80);
  delay(tempo*1000);
  digitalWrite(pinVD, LOW);
  digitalWrite(pinVM, LOW);
}
void loop() {
  verde(4);
  amarelo(2);
  vermelho(4);
}
