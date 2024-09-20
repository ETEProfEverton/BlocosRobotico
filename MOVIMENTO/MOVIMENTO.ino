unsigned long millisToque = millis();
unsigned long millisBrilho = millis();
const int trigger = 2;
const int echo = 3;
const int buzzer = 4;
const int led = 5;
long duracao, cm;

void toque(){
  if(cm < 30){
    if((millis() - millisToque) < 1000){
      tone(buzzer, 392, 1000);
    }else{
      noTone(buzzer);
    }
    if((millis() - millisToque) > 2000){
      millisBrilho = millis();
    }
  }
  if(cm < 10){
    if((millis() - millisToque) < 500){
      tone(buzzer, 392, 500);
    }else{
      noTone(buzzer);
    }
    if((millis() - millisToque) > 1000){
      millisBrilho = millis();
    }
  }
  if(cm < 5){
    if((millis() - millisToque) < 250){
      tone(buzzer, 392, 250);
    }else{
      noTone(buzzer);
    }
    if((millis() - millisToque) > 500){
      millisBrilho = millis();
    }
  }
}

void brilho(){
  millisBrilho = 0;
  millisBrilho = millis();
  if(cm < 30){
    if((millis() - millisBrilho) < 1000){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
    if((millis() - millisBrilho) > 2000){
      millisBrilho = millis();
    }
  }
  if(cm < 10){
    millisBrilho = 0;
    millisBrilho = millis();
    if((millis() - millisBrilho) < 500){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
    if((millis() - millisBrilho) > 1000){
      millisBrilho = millis();
    }
  }
  if(cm < 5){
    millisBrilho = 0;
    millisBrilho = millis();
    if((millis() - millisBrilho) < 250){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
    if((millis() - millisBrilho) > 500){
      millisBrilho = millis();
    }
  }
}

void setup(){
  pinMode(trigger, OUTPUT);
  pinMode(echo, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  pinMode(echo, INPUT);
  duracao = pulseIn(echo, HIGH);
  cm = (duracao/2) / 29.1;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);

  toque();
  brilho();
}