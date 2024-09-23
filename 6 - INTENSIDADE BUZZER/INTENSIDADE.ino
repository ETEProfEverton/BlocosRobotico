// Definição dos pinos
const int pinoCLK = 3;  // PINO DIGITAL (CLK)
const int pinoDT = 4;   // PINO DIGITAL (DT)
const int pinoSW = 5;   // PINO DIGITAL (SW)
const int buzzerPin = 9; // PINO DO BUZZER

// Variáveis de controle
int contadorFreq = 440; // FREQUÊNCIA INICIAL (em Hz)
int ultPosicao;         // ÚLTIMA LEITURA DO PINO CLK
int leituraCLK;         // LEITURA DO PINO CLK
boolean bCW;            // SENTIDO DE ROTAÇÃO (HORÁRIO / ANTI-HORÁRIO)
const int freqMin = 100; // FREQUÊNCIA MÍNIMA (em Hz)
const int freqMax = 2000; // FREQUÊNCIA MÁXIMA (em Hz)
int lastButtonState = HIGH; // ESTADO ANTERIOR DO BOTÃO

void setup() {
  Serial.begin(9600);                    // INICIALIZA A SERIAL
  pinMode(pinoCLK, INPUT);               // DEFINE O PINO CLK COMO ENTRADA
  pinMode(pinoDT, INPUT);                // DEFINE O PINO DT COMO ENTRADA
  pinMode(pinoSW, INPUT_PULLUP);         // ATIVA O RESISTOR PULL-UP INTERNO
  pinMode(buzzerPin, OUTPUT);            // DEFINE O PINO DO BUZZER COMO SAÍDA
  ultPosicao = digitalRead(pinoCLK);     // ARMAZENA A LEITURA INICIAL DO PINO CLK
  noTone(buzzerPin);                      // Garante que o buzzer esteja desligado inicialmente
}

void loop() {
  leituraCLK = digitalRead(pinoCLK);  // LÊ O VALOR ATUAL DO PINO CLK
  tone(buzzerPin, contadorFreq); 
  // Verifica se houve mudança na posição
  if (leituraCLK != ultPosicao) {
    // Determina o sentido da rotação
    if (digitalRead(pinoDT) != leituraCLK) {  
      // Sentido horário
      contadorFreq = max(contadorFreq - 50, freqMin);  // DECREMENTA A FREQUÊNCIA, MANTENDO MÍNIMO EM freqMin
      bCW = true;  // SENTIDO HORÁRIO
    } else {
      // Sentido anti-horário
      contadorFreq = min(contadorFreq + 50, freqMax); // INCREMENTA A FREQUÊNCIA, MANTENDO MÁXIMO EM freqMax
      bCW = false; // SENTIDO ANTI-HORÁRIO
    }

    // Atualiza a frequência do buzzer
    tone(buzzerPin, contadorFreq);  

    // Exibe informações na serial
    Serial.print("Giro no ");
    Serial.print(bCW ? "sentido horário" : "sentido anti-horário");
    Serial.print(" / Frequência do buzzer: ");
    Serial.println(contadorFreq);
  }

  // Verifica se o botão foi pressionado
  if (digitalRead(pinoSW) == LOW && lastButtonState == HIGH) {  
    Serial.println("Botão pressionado");
    delay(200);  // INTERVALO DE 200 MILISSEGUNDOS
  }
  lastButtonState = digitalRead(pinoSW); // Atualiza o estado do botão

  // Atualiza a última posição
  ultPosicao = leituraCLK;  
}
