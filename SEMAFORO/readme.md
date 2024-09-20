# Semáforo com LEDs

## Descrição

Este projeto simula um semáforo utilizando LEDs para representar as luzes vermelha, verde e amarela. O semáforo acende as luzes em sequência, controlando o tempo que cada luz permanece acesa. O sistema é simples e ideal para aprender sobre controle de LEDs com Arduino.

## Componentes Necessários

- Arduino (qualquer modelo)
- 1 Módulo LED RGB
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)

## Esquema de Ligação

1. **LEDs**
   - Conecte o ânodo (terminal positivo) do LED vermelho ao pino digital 9 do Arduino, e o cátodo (terminal negativo) ao GND através de um resistor de 220Ω.
   - Conecte o ânodo do LED verde ao pino digital 10 do Arduino, e o cátodo ao GND através de um resistor de 220Ω.
   - Conecte o ânodo do LED amarelo ao pino digital 9 do Arduino, e o cátodo ao GND através de um resistor de 220Ω.

## Funcionamento

- O semáforo acende as luzes na seguinte sequência:
  1. Luz verde por 4 segundos.
  2. Luz amarela por 2 segundos.
  3. Luz vermelha por 4 segundos.
  
O ciclo se repete continuamente.

## Como Usar

1. Monte o circuito conforme descrito na seção "Esquema de Ligação".
2. Carregue o código no seu Arduino usando a IDE do Arduino.
3. Conecte o Arduino à alimentação e observe o funcionamento do semáforo.

## Contribuições

Sinta-se à vontade para contribuir com melhorias, adições ou correções. Se você fizer alguma modificação interessante, considere compartilhar!

## Licença

Este projeto é de domínio público. Sinta-se livre para usar, modificar e distribuir.
