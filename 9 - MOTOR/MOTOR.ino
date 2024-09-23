// Definição dos pinos
const int motorPin = 9;      // Pino para controlar o motor
const int buttonPin = 7;     // Pino do botão

// Variáveis para controle do estado
bool motorLigado = false;    // Armazena o estado atual do motor (ligado/desligado)
int buttonState = 0;         // Armazena o estado atual do botão
int lastButtonState = 0;     // Armazena o último estado do botão (para detectar mudanças)

void setup() {
  // Configura o pino do motor como saída
  pinMode(motorPin, OUTPUT);
  
  // Configura o pino do botão como entrada
  pinMode(buttonPin, INPUT_PULLUP);  // Usa resistor pull-up interno do Arduino

  // Inicializa o motor desligado
  digitalWrite(motorPin, LOW);
}

void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(buttonPin);

  // Detecta se houve mudança no estado do botão (para evitar leitura de múltiplos cliques)
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      // Troca o estado do motor (se está ligado, desliga; se está desligado, liga)
      motorLigado = !motorLigado;

      // Liga ou desliga o motor de acordo com o novo estado
      if (motorLigado) {
        digitalWrite(motorPin, HIGH);  // Liga o motor
      } else {
        digitalWrite(motorPin, LOW);   // Desliga o motor
      }
    }

    // Pequeno atraso para evitar o efeito de "bouncing" (oscilações rápidas do botão)
    delay(50);
  }

  // Atualiza o estado do botão para a próxima leitura
  lastButtonState = buttonState;
}
