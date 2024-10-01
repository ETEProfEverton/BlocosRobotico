// Definição dos pinos
const int buzzerPin = 5;  // Pino do buzzer
const int buttonPin = 7;   // Pino do botão

// Frequência da nota
int nota = 440; // Lá (A)

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Usar pull-up interno
}

void loop() {
  // Verifica se o botão está pressionado
  if (digitalRead(buttonPin) == LOW) {
    tone(buzzerPin, nota); // Toca a nota
  } else {
    noTone(buzzerPin); // Para o som se o botão não estiver pressionado
  }
}
