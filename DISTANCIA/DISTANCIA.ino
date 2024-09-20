// Variáveis globais para controle do tempo
unsigned long millisToque = millis(); // Tempo de toque do buzzer
unsigned long millisBrilho = millis(); // Tempo de brilho do LED

// Definição dos pinos
const int trigger = 2; // Pino de trigger do sensor ultrassônico
const int echo = 3;    // Pino de echo do sensor ultrassônico
const int buzzer = 4;  // Pino do buzzer
const int led = 5;     // Pino do LED

long duracao; // Duração do pulso de eco
long cm;      // Distância em centímetros medida pelo sensor

// Função que controla o toque do buzzer com base na distância
void toque() {
  // Verifica se a distância é menor que 30 cm
  if (cm < 30) {
    // Toca a nota por 1 segundo
    if ((millis() - millisToque) < 1000) {
      tone(buzzer, 392, 1000); // Toca a nota Lá (392 Hz) por 1 segundo
    } else {
      noTone(buzzer); // Para o som
    }
    if ((millis() - millisToque) > 2000) {
      millisBrilho = millis(); // Atualiza o tempo de brilho
    }
  }
  
  // Para distâncias menores que 10 cm
  if (cm < 10) {
    if ((millis() - millisToque) < 500) {
      tone(buzzer, 392, 500); // Toca a nota por 0,5 segundos
    } else {
      noTone(buzzer);
    }
    if ((millis() - millisToque) > 1000) {
      millisBrilho = millis(); // Atualiza o tempo de brilho
    }
  }
  
  // Para distâncias menores que 5 cm
  if (cm < 5) {
    if ((millis() - millisToque) < 250) {
      tone(buzzer, 392, 250); // Toca a nota por 0,25 segundos
    } else {
      noTone(buzzer);
    }
    if ((millis() - millisToque) > 500) {
      millisBrilho = millis(); // Atualiza o tempo de brilho
    }
  }
}

// Função que controla o brilho do LED com base na distância
void brilho() {
  millisBrilho = millis(); // Atualiza o tempo de brilho

  // Para distâncias menores que 30 cm
  if (cm < 30) {
    if ((millis() - millisBrilho) < 1000) {
      digitalWrite(led, HIGH); // Liga o LED por 1 segundo
    } else {
      digitalWrite(led, LOW); // Desliga o LED
    }
    if ((millis() - millisBrilho) > 2000) {
      millisBrilho = millis(); // Atualiza o tempo de brilho
    }
  }

  // Para distâncias menores que 10 cm
  if (cm < 10) {
    millisBrilho = millis(); // Atualiza o tempo de brilho
    if ((millis() - millisBrilho) < 500) {
      digitalWrite(led, HIGH); // Liga o LED por 0,5 segundos
    } else {
      digitalWrite(led, LOW);
    }
    if ((millis() - millisBrilho) > 1000) {
      millisBrilho = millis(); // Atualiza o tempo de brilho
    }
  }

  // Para distâncias menores que 5 cm
  if (cm < 5) {
    millisBrilho = millis(); // Atualiza o tempo de brilho
    if ((millis() - millisBrilho) < 250) {
      digitalWrite(led, HIGH); // Liga o LED por 0,25 segundos
    } else {
      digitalWrite(led, LOW);
    }
    if ((millis() - millisBrilho) > 500) {
      millisBrilho = millis(); // Atualiza o tempo de brilho
    }
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
  Serial.print(" cm");
  Serial.println();
  delay(250); // Atraso de 250 ms

  // Chama as funções para controle do buzzer e do LED
  toque();
  brilho();
}
