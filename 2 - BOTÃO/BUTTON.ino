// constantes que não mudam. Elas são usadas aqui para definir os números dos pinos:
const int buttonPin = 2;  // o número do pino do botão
const int ledPin = 13;    // o número do pino do LED

// variáveis que mudarão:
int buttonState = 0;  // variável para ler o status do botão

void setup() {
  // inicializa o pino do LED como saída:
  pinMode(ledPin, OUTPUT);
  // inicializa o pino do botão como entrada:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // lê o estado do valor do botão:
  buttonState = digitalRead(buttonPin);

  // verifica se o botão está pressionado. Se estiver, o buttonState é HIGH:
  if (buttonState == HIGH) {
    // acende o LED:
    digitalWrite(ledPin, HIGH);
  } else {
    // apaga o LED:
    digitalWrite(ledPin, LOW);
  }
}