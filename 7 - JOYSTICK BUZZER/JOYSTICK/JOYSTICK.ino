// Definição dos pinos
const int pinJoystickX = A0;  // Pino do eixo X do joystick
const int pinJoystickY = A1;  // Pino do eixo Y do joystick
const int pinBuzzer = 5;      // Pino do buzzer

// Variáveis para armazenar as leituras do joystick
int valorX = 0;
int valorY = 0;
int frequencia = 0;

void setup() {
  // Inicializa o pino do buzzer como saída
  pinMode(pinBuzzer, OUTPUT);
  
  // Inicializa o pino do joystick como entrada (pinos analógicos)
  pinMode(pinJoystickX, INPUT);
  pinMode(pinJoystickY, INPUT);
  
  // Inicializa a comunicação serial para monitorar os valores (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lê os valores dos eixos X e Y do joystick (valores de 0 a 1023)
  valorX = analogRead(pinJoystickX);
  valorY = analogRead(pinJoystickY);

  // Mapeia os valores lidos para uma faixa de frequência de 100 Hz a 2000 Hz
  frequencia = map(valorX, 0, 1023, 100, 2000);
  
  // Exibe os valores e a frequência na serial (opcional)
  Serial.print("Joystick X: ");
  Serial.print(valorX);
  Serial.print(" | Joystick Y: ");
  Serial.print(valorY);
  Serial.print(" | Frequência do buzzer: ");
  Serial.println(frequencia);

  // Reproduz o som no buzzer de acordo com o movimento do joystick
  tone(pinBuzzer, frequencia);

  // Pequeno atraso para evitar leituras muito rápidas
  delay(100);
}
