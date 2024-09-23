# Controle de Motor DC com Botão

## Descrição

Este projeto utiliza um motor DC e um módulo botão para controlar o motor. Toda vez que o botão for pressionado, o motor inicia; ao pressionar novamente, o motor desliga. Esse projeto é útil para aprender o controle básico de dispositivos de saída com entradas simples como botões.

## Componentes Necessários

- Arduino (qualquer modelo)
- 1 Motor DC
- 1 Módulo Botão (push-button)
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)
- Opcional: Módulo driver de motor (dependendo do motor DC utilizado)

## Esquema de Ligação

1. **Motor DC**:
   - Conecte o pino positivo do motor ao pino **9** do Arduino.
   - Conecte o pino negativo do motor ao **GND** do Arduino.

2. **Botão**:
   - Conecte um dos terminais do botão ao pino **7** do Arduino.
   - Conecte o outro terminal do botão ao **GND** do Arduino.

Se estiver usando um módulo driver de motor, conecte o pino de controle do módulo ao pino **9** do Arduino e siga as instruções do fabricante para a alimentação e controle do motor.

## Funcionamento

- Quando o botão é pressionado pela primeira vez, o motor DC será **ligado**.
- Ao pressionar o botão novamente, o motor será **desligado**.
- O sistema funciona alternando o estado do motor a cada pressão no botão.

## Código Explicado

1. O pino **9** do Arduino controla o motor DC, e o pino **7** é usado para ler o estado do botão.
2. A cada vez que o botão é pressionado, o estado do motor é invertido (ligado/desligado).
3. O código utiliza o resistor pull-up interno do Arduino no botão para garantir que ele leia corretamente o estado quando não estiver pressionado.
4. Pequenos delays são aplicados para eliminar o efeito de "bouncing" do botão, que poderia gerar leituras incorretas.

## Instruções

1. Monte o circuito conforme descrito no **Esquema de Ligação**.
2. Carregue o código fornecido na IDE do Arduino e faça o upload para a placa.
3. Pressione o botão para iniciar ou parar o motor.

## Possíveis Melhorias

- Adicionar controle de velocidade usando um potenciômetro ou PWM.
- Utilizar um driver de motor para controle mais eficiente e proteção do Arduino.
- Implementar um display para mostrar o estado atual do motor (ligado/desligado).

## Licença

Este projeto é de domínio público. Fique à vontade para modificar e distribuir como quiser.
