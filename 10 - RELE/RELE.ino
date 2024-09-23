// Definição dos pinos
const int relePin = 9;        // Pino onde o relé está conectado
const int buttonPin = 7;      // Pino onde o botão está conectado

// Variáveis para controle do estado
bool releLigado = false;      // Variável para armazenar o estado atual do relé
int buttonState = 0;          // Estado atual do botão
int lastButtonState = 0;      // Último estado do botão para detectar mudanças

void setup() {
  // Configura o pino do relé como saída
  pinMode(relePin, OUTPUT);

  // Configura o pino do botão como entrada com resistor pull-up interno
  pinMode(buttonPin, INPUT_PULLUP);

  // Inicia o relé desligado
  digitalWrite(relePin, LOW);

  // Inicializa a comunicação Serial
  Serial.begin(9600);
  Serial.println("Sistema Iniciado. Relé Desligado.");
}

void loop() {
  // Lê o estado do botão
  buttonState = digitalRead(buttonPin);

  // Detecta mudança de estado do botão (acionamento)
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) { // Botão pressionado (LOW por causa do pull-up interno)
      releLigado = !releLigado; // Inverte o estado do relé
      digitalWrite(relePin, releLigado ? HIGH : LOW); // Liga ou desliga o relé

      // Imprime o estado do relé no Serial Monitor
      if (releLigado) {
        Serial.println("Botão pressionado. Relé Ligado.");
      } else {
        Serial.println("Botão pressionado. Relé Desligado.");
      }
    }
    delay(50);  // Debouncing simples para evitar leituras erradas
  }

  // Atualiza o último estado do botão
  lastButtonState = buttonState;
}
