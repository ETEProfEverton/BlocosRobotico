int buzzer = 10;
int button = 9;
int ciclo = 0;
int maximo = 2;
bool tocando = false;

int estado = 0;

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

void trocaC(){
  if (ciclo == 0){
    dois();
  }else if(ciclo == 1){
    tres();
  }else if(ciclo == 2){
    quatro();
  }
}

void lerB(){
  int leitura = digitalRead(button);
  if (leitura == HIGH && estado == 0){
    estado = 1;
    tocando = true;
    ciclo++;
    if (ciclo > maximo){
      ciclo = 0;
    }
  }else if (leitura == LOW){
    estado = 0;

  } 

}


void setup(){
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
}



void loop(){
  lerB();
  
  if (tocando){
    trocaC();
  }
}