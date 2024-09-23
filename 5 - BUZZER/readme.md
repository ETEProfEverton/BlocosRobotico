# Projeto: Buzzer com Botão

## Descrição

Este projeto utiliza um Arduino, um buzzer e um botão para criar um dispositivo simples que toca um som específico sempre que o botão é pressionado. O som é interrompido assim que o botão é solto. É uma ótima maneira de aprender sobre interações entre componentes eletrônicos e programação em Arduino.

## Componentes Necessários

- Arduino (qualquer modelo)
- 1 Buzzer
- 1 Botão
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)

## Esquema de Ligação

1. **Buzzer**
   - Conecte o terminal positivo do buzzer ao pino digital 10 do Arduino.
   - Conecte o terminal negativo do buzzer ao GND do Arduino.

2. **Botão**
   - Conecte um terminal do botão ao pino digital 9 do Arduino.
   - Conecte o outro terminal do botão ao GND do Arduino (com um resistor de pull-down, se necessário).

## Código

```cpp
// Definição dos pinos
const int buzzerPin = 10;  // Pino do buzzer
const int buttonPin = 9;   // Pino do botão

// Frequência da nota
int nota = 440; // Lá (A)

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Usar pull-up interno
}

void loop() {
  // Verifica se o botão está pressionado
  if (digitalRead(buttonPin) == LOW) {
    tone(buzzerPin, nota); // Toca a nota
  } else {
    noTone(buzzerPin); // Para o som se o botão não estiver pressionado
  }
}
```

## Funcionamento

- O código configura um pino para o buzzer e um para o botão. Quando o botão é pressionado, o buzzer toca uma nota (neste caso, 440 Hz, correspondente à nota Lá).
- O som continuará enquanto o botão estiver pressionado e será interrompido assim que o botão for solto.

## Como Usar

1. Monte o circuito conforme descrito na seção "Esquema de Ligação".
2. Carregue o código no seu Arduino usando a IDE do Arduino.
3. Pressione o botão e ouça o buzzer tocar. Solte o botão para parar o som.

## Contribuições

Sinta-se à vontade para contribuir com melhorias, adições ou correções. Se você fizer alguma modificação interessante, considere compartilhar!

## Licença

Este projeto é de domínio público. Sinta-se livre para usar, modificar e distribuir.