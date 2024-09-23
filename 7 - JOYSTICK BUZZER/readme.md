# Controle de Som com Joystick e Buzzer

## Descrição

Este projeto utiliza um módulo joystick para controlar o som de um buzzer. À medida que o joystick é movido, a frequência do som emitido pelo buzzer muda. É um ótimo projeto para entender como ler entradas analógicas e gerar saídas audíveis utilizando um Arduino.

## Componentes Necessários

- Arduino (qualquer modelo)
- 1 Módulo Joystick
- 1 Módulo Buzzer
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)

## Esquema de Ligação

1. **Módulo Joystick**:
   - **Pino X** do joystick → Pino analógico **A0** do Arduino.
   - **Pino Y** do joystick → Pino analógico **A1** do Arduino.
   - **GND** do joystick → **GND** do Arduino.
   - **VCC** do joystick → **5V** do Arduino.

2. **Módulo Buzzer**:
   - Pino positivo do buzzer → Pino digital **9** do Arduino.
   - Pino negativo do buzzer → **GND** do Arduino.

## Funcionamento

- O joystick tem dois eixos: X e Y. O movimento do eixo X controla a frequência do som emitido pelo buzzer.
- Quando o joystick é movido, o som do buzzer muda, variando a frequência entre 100 Hz e 2000 Hz, dependendo da posição do joystick.

## Como Usar

1. Monte o circuito conforme descrito na seção "Esquema de Ligação".
2. Carregue o código fornecido no Arduino usando a IDE do Arduino.
3. Movimente o joystick e ouça a variação de som no buzzer.

## Ajustes

- Você pode alterar a faixa de frequências no código para ajustar o som do buzzer de acordo com sua necessidade.
- O eixo Y do joystick pode ser usado para outro tipo de controle, como volume ou intensidade.

## Contribuições

Sinta-se à vontade para melhorar, modificar ou expandir o projeto. Se fizer melhorias interessantes, compartilhe!

## Licença

Este projeto é de domínio público. Fique à vontade para usar, modificar e distribuir como quiser.