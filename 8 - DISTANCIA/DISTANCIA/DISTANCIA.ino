// Definição dos pinos
const int trigger = 11; // Pino de trigger do sensor ultrassônico
const int echo = 12;    // Pino de echo do sensor ultrassônico
const int buzzer = 5;  // Pino do buzzer
const int led = 3;     // Pino do LED

long duracao; // Duração do pulso de eco
long cm;      // Distância em centímetros medida pelo sensor

// Função que controla o toque do buzzer com base na distância
void toque() {
  // Verifica se a distância é menor que 30 cm
  if (cm < 30 && cm > 20) {
    tone(buzzer, 392, 1000); // Toca a nota Lá (392 Hz) por 1 segundo
    digitalWrite(led, HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(led, LOW);
  }
  
  // Para distâncias menores que 10 cm
  if (cm < 20 && cm > 10) {
    tone(buzzer, 492, 500); // Toca a nota por 0,5 segundos
    digitalWrite(led, HIGH);
    delay(500);
    noTone(buzzer);
    digitalWrite(led, LOW);
  }
  
  // Para distâncias menores que 5 cm
  if (cm < 10) {
    tone(buzzer, 592, 250); // Toca a nota por 0,25 segundos
    digitalWrite(led, HIGH);
    delay(250);
    noTone(buzzer);
    digitalWrite(led, LOW);
  }
}

void setup() {
  pinMode(trigger, OUTPUT); // Configura o pino de trigger como saída
  pinMode(echo, INPUT);     // Configura o pino de echo como entrada
  Serial.begin(9600);       // Inicializa a comunicação serial a 9600 bps
}

void loop() {
  // Envia um pulso de trigger para o sensor ultrassônico
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // Lê a duração do pulso de eco
  pinMode(echo, INPUT); // Configura o pino de echo como entrada
  duracao = pulseIn(echo, HIGH); // Lê o tempo que o pulso leva para voltar
  cm = (duracao / 2) / 29.1; // Converte a duração para distância em cm

  // Imprime a distância medida no monitor serial
  Serial.print(cm);
  Serial.print(" cm / ");
  Serial.println();
  delay(250); // Atraso de 250 ms

  // Chama as funções para controle do buzzer e do LED
  toque();
}
