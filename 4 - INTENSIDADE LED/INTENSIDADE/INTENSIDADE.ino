// Definição dos pinos
const int pinoCLK = 11;  // PINO DIGITAL (CLK)
const int pinoDT = 12;   // PINO DIGITAL (DT)
//const int pinoSW = 5;   // PINO DIGITAL (SW)
const int ledPin = 3;   // PINO DO LED

// Variáveis de controle
int contadorPos = 0;    // CONTADOR DE POSIÇÕES DO ENCODER
int ultPosicao;         // ÚLTIMA LEITURA DO PINO CLK
int leituraCLK;         // LEITURA DO PINO CLK
boolean bCW;            // SENTIDO DE ROTAÇÃO (HORÁRIO / ANTI-HORÁRIO)
int brightness = 0;     // BRILHO DO LED

void setup() {
  Serial.begin(9600);                    // INICIALIZA A SERIAL
  pinMode(pinoCLK, INPUT);               // DEFINE O PINO CLK COMO ENTRADA
  pinMode(pinoDT, INPUT);                // DEFINE O PINO DT COMO ENTRADA
  //pinMode(pinoSW, INPUT_PULLUP);         // ATIVA O RESISTOR PULL-UP INTERNO
  pinMode(ledPin, OUTPUT);               // DEFINE O PINO DO LED COMO SAÍDA
  ultPosicao = digitalRead(pinoCLK);     // ARMAZENA A LEITURA INICIAL DO PINO CLK
}

void loop() {
  leituraCLK = digitalRead(pinoCLK);  // LÊ O VALOR ATUAL DO PINO CLK

  // Verifica se houve mudança na posição
  if (leituraCLK != ultPosicao) {
    // Determina o sentido da rotação
    if (digitalRead(pinoDT) != leituraCLK) {  
      // Sentido horário
      contadorPos = max(contadorPos - 5, 0);  // DECREMENTA CONTAGEM, MANTENDO MÍNIMO EM 0
      bCW = true;  // SENTIDO HORÁRIO
    } else {
      // Sentido anti-horário
      contadorPos = min(contadorPos + 5, 255); // INCREMENTA CONTAGEM, MANTENDO MÁXIMO EM 255
      bCW = false; // SENTIDO ANTI-HORÁRIO
    }

    // Atualiza o brilho do LED
    analogWrite(ledPin, contadorPos);  

    // Exibe informações na serial
    Serial.print("Giro no ");
    Serial.print(bCW ? "sentido horário" : "sentido anti-horário");
    Serial.print(" / Posição do encoder: ");
    Serial.println(contadorPos);
  }

  // Verifica se o botão foi pressionado
  /*if (digitalRead(pinoSW) == LOW) {  
    Serial.println("Botão pressionado");
    delay(200);  // INTERVALO DE 200 MILISSEGUNDOS
  }*/

  // Atualiza a última posição
  ultPosicao = leituraCLK;  
}
