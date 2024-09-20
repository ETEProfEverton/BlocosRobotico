// Variáveis globais
float luminosidade = 0;  // Variável para armazenar a luminosidade lida
int led = 3;             // Pino digital onde o LED está conectado
const int ldr = A0;      // Pino analógico onde o LDR está conectado

void setup() {
  // Configura o pino do LED como saída
  pinMode(led, OUTPUT);
  
  // Configura o pino do LDR como entrada
  pinMode(ldr, INPUT);
  
  // Inicializa a comunicação serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do LDR (0 a 1023) e o mapeia para o intervalo de 0 a 255
  luminosidade = map(analogRead(ldr), 0, 1023, 0, 255);
  
  // Imprime o valor da luminosidade no monitor serial
  Serial.println(luminosidade);
  
  // Verifica se a luminosidade é maior que 150
  if (luminosidade > 150) {
    // Se a luminosidade estiver alta, liga o LED
    digitalWrite(led, HIGH); // Melhor usar HIGH em vez de 1
  } else {
    // Se a luminosidade estiver baixa, desliga o LED
    digitalWrite(led, LOW);  // Melhor usar LOW em vez de 0
  }
  
  // Aguarda 1 segundo antes de realizar a próxima leitura
  delay(1000);
}
