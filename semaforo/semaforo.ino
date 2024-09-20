// Definição dos pinos para os LEDs
int pinVM = 9; // Pino do LED vermelho
int pinVD = 10; // Pino do LED verde

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(pinVD, OUTPUT);
  pinMode(pinVM, OUTPUT);
}

// Função para acender o LED vermelho por um determinado tempo
void vermelho(int tempo) {
  digitalWrite(pinVM, HIGH); // Liga o LED vermelho
  delay(tempo * 1000); // Aguarda o tempo especificado (em segundos)
  digitalWrite(pinVM, LOW); // Desliga o LED vermelho
}

// Função para acender o LED verde por um determinado tempo
void verde(int tempo) {
  digitalWrite(pinVD, HIGH); // Liga o LED verde
  delay(tempo * 1000); // Aguarda o tempo especificado (em segundos)
  digitalWrite(pinVD, LOW); // Desliga o LED verde
}

// Função para acender o LED amarelo (vermelho e verde) por um determinado tempo
void amarelo(int tempo) {
  digitalWrite(pinVM, HIGH); // Liga o LED vermelho
  analogWrite(pinVD, 80); // Liga o LED verde em um nível de brilho baixo (80)
  delay(tempo * 1000); // Aguarda o tempo especificado (em segundos)
  digitalWrite(pinVD, LOW); // Desliga o LED verde
  digitalWrite(pinVM, LOW); // Desliga o LED vermelho
}

void loop() {
  // Ciclo de funcionamento do semáforo
  verde(4);    // Acende o LED verde por 4 segundos
  amarelo(2);  // Acende o LED amarelo por 2 segundos
  vermelho(4); // Acende o LED vermelho por 4 segundos
}
