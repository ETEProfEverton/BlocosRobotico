// Definição do pino do LED
const int pinoLED = 13; // O pino onde o LED está conectado

// A função de configuração é chamada uma vez quando o programa inicia
void setup() {
  // Inicializa o pino do LED como saída
  pinMode(pinoLED, OUTPUT);
}

// A função loop é chamada repetidamente
void loop() {
  // Liga o LED
  digitalWrite(pinoLED, HIGH);
  // Espera por 1000 milissegundos (1 segundo)
  delay(1000);
  
  // Desliga o LED
  digitalWrite(pinoLED, LOW);
  // Espera por 1000 milissegundos (1 segundo)
  delay(1000);
}
