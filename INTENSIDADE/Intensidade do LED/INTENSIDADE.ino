float luminosidade = 0;
int led = 3;
const int ldr = A0;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop(){
  luminosidade = map(analogRead(ldr), 0, 1023, 0, 255);
  Serial.println(luminosidade);
  analogWrite(led, luminosidade);
  delay(1000);
}