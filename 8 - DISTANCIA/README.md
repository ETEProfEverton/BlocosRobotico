# Sensor Ultrassônico com Buzzer e LED

## Descrição

Este projeto utiliza um Arduino, um sensor ultrassônico, um buzzer e um LED para criar um sistema que emite sons e acende um LED com base na distância medida pelo sensor. O buzzer toca notas diferentes dependendo da proximidade de um objeto, enquanto o LED acende em resposta à distância medida.

## Componentes Necessários

- Arduino (qualquer modelo)
- 1 Sensor Ultrassônico (HC-SR04)
- 1 Módulo Buzzer
- 1 Módulo LED
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)

## Esquema de Ligação

1. **Sensor Ultrassônico (HC-SR04)**
   - Pino **Trigger** ao pino digital 2 do Arduino.
   - Pino **Echo** ao pino digital 3 do Arduino.
   - Pino **VCC** ao 5V do Arduino.
   - Pino **GND** ao GND do Arduino.

2. **Buzzer**
   - Terminal positivo do buzzer ao pino digital 4 do Arduino.
   - Terminal negativo do buzzer ao GND do Arduino.

3. **LED**
   - Terminal positivo (ânodo) do LED ao pino digital 5 do Arduino.
   - Terminal negativo (cátodo) do LED ao GND através de um resistor de 220Ω.

## Funcionamento

- O sensor ultrassônico mede a distância até um objeto e a converte em centímetros.
- O buzzer emite diferentes sons dependendo da proximidade do objeto:
  - Abaixo de 30 cm: som por 1 segundo.
  - Abaixo de 10 cm: som por 0,5 segundos.
  - Abaixo de 5 cm: som por 0,25 segundos.
- O LED acende quando a distância é menor que 30 cm, com diferentes durações conforme a proximidade.

## Como Usar

1. Monte o circuito conforme descrito na seção "Esquema de Ligação".
2. Carregue o código no seu Arduino usando a IDE do Arduino.
3. Abra o monitor serial para visualizar as distâncias medidas e escute o buzzer e veja o LED reagindo conforme os objetos se aproximam.

## Contribuições

Sinta-se à vontade para contribuir com melhorias, adições ou correções. Se você fizer alguma modificação interessante, considere compartilhar!

## Licença

Este projeto é de domínio público. Sinta-se livre para usar, modificar e distribuir.