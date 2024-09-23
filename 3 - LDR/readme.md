# Controle de LED com LDR

## Descrição

Este projeto utiliza um Arduino, um LDR (resistor dependente de luz) e um LED para criar um sistema que acende o LED quando a luminosidade detectada pelo LDR é baixa. O valor da luminosidade é lido continuamente e impresso no monitor serial.

## Componentes Necessários

- Arduino (qualquer modelo)
- Módulo LED
- Módulo LDR
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)

## Esquema de Ligação

1. **LED**
   - Conecte o terminal positivo (ânodo) do LED ao pino digital 3 do Arduino.
   - Conecte o terminal negativo (cátodo) do LED ao GND através de um resistor de 220Ω.

2. **LDR**
   - Conecte um terminal do LDR ao pino analógico A0 do Arduino.
   - Conecte o outro terminal do LDR ao VCC (5V).
   - Conecte um resistor de 10kΩ entre o terminal do LDR conectado ao A0 e o GND (formando um divisor de tensão).

## Funcionamento

- O código lê continuamente o valor de luminosidade do LDR e mapeia esse valor para um intervalo de 0 a 255.
- Se a luminosidade for maior que 150, o LED é aceso. Caso contrário, o LED é desligado.
- O valor da luminosidade é impresso no monitor serial a cada segundo.

## Como Usar

1. Monte o circuito conforme descrito na seção "Esquema de Ligação".
2. Carregue o código no seu Arduino usando a IDE do Arduino.
3. Abra o monitor serial para visualizar os valores de luminosidade e observe o LED acender e apagar conforme as condições de luz mudam.

## Contribuições

Sinta-se à vontade para contribuir com melhorias, adições ou correções. Se você fizer alguma modificação interessante, considere compartilhar!

## Licença

Este projeto é de domínio público. Sinta-se livre para usar, modificar e distribuir.