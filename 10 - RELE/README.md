# Controle de Relé com Botão e Monitoramento Serial

## Descrição

Este projeto utiliza um **módulo relé** e um **módulo botão** para controlar o acionamento de dispositivos eletrônicos. Ao pressionar o botão, o relé alterna entre ligado e desligado, permitindo o controle de dispositivos como lâmpadas ou motores. O estado do relé é monitorado em tempo real através do **Monitor Serial**, facilitando o acompanhamento das operações.

## Componentes Necessários

- Arduino (qualquer modelo)
- 1 Módulo Relé
- 1 Módulo Botão (push-button)
- Fios de conexão
- Placa de prototipagem (breadboard) (opcional)
- Dispositivo controlado pelo relé (lâmpada, motor, etc.)

## Esquema de Ligação

1. **Módulo Relé**:
   - Conecte o pino **IN** do módulo relé ao pino **9** do Arduino.
   - Conecte o pino **VCC** do módulo relé ao pino **5V** do Arduino.
   - Conecte o pino **GND** do módulo relé ao **GND** do Arduino.

2. **Botão**:
   - Conecte um terminal do botão ao pino **7** do Arduino.
   - Conecte o outro terminal do botão ao **GND** do Arduino.

## Funcionamento

- Ao pressionar o botão, o relé alterna seu estado entre **ligado** e **desligado**.
- O estado do relé (ligado/desligado) é exibido no **Monitor Serial**, permitindo que o usuário monitore as alterações.

## Código Explicado

1. O pino **9** do Arduino controla o relé, enquanto o pino **7** é usado para ler o estado do botão.
2. A cada pressão do botão, o estado do relé é invertido (ligado/desligado).
3. O código utiliza o resistor pull-up interno do Arduino no botão para garantir que ele leia corretamente o estado quando não estiver pressionado.
4. O estado do relé é impresso no Monitor Serial a cada mudança.

## Instruções

1. Monte o circuito conforme descrito no **Esquema de Ligação**.
2. Carregue o código fornecido na IDE do Arduino e faça o upload para a placa.
3. Abra o Monitor Serial para acompanhar o estado do relé.
4. Pressione o botão para alternar o estado do relé.

## Possíveis Melhorias

- Adicionar um **LED** para indicar visualmente o estado do relé.
- Incluir um **buzzer** que emita um som sempre que o botão for pressionado.
- Implementar debounce de hardware ou software para evitar múltiplas leituras incorretas.

## Licença

Este projeto é de domínio público. Fique à vontade para modificar e distribuir como quiser.