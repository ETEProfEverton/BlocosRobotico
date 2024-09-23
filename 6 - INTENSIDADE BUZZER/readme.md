# Controle de Frequência de Buzzer com Encoder Rotativo

Este projeto implementa um controle de frequência de um buzzer utilizando um encoder rotativo. A frequência do som do buzzer varia conforme o movimento do encoder no sentido horário ou anti-horário, e o estado atual do encoder é exibido no monitor serial. Um botão integrado ao encoder também pode ser detectado para interações adicionais.

## Funcionalidades
- Controle da frequência de um buzzer através do movimento de um encoder rotativo.
- Movimentos no sentido horário diminuem a frequência, e no sentido anti-horário aumentam a frequência.
- A frequência é limitada entre 100 Hz (mínimo) e 2000 Hz (máximo).
- Exibição em tempo real das mudanças no monitor serial.
- Detecção de botão pressionado (botão embutido no encoder).

## Hardware Necessário
- Arduino (ou qualquer microcontrolador compatível)
- Encoder rotativo com botão integrado
- Buzzer
- Jumpers e protoboard

## Conexões
- `pinoCLK` (Pino Digital 3): Conectado ao pino CLK do encoder.
- `pinoDT` (Pino Digital 4): Conectado ao pino DT do encoder.
- `pinoSW` (Pino Digital 5): Conectado ao pino do botão do encoder.
- `buzzerPin` (Pino Digital 9): Conectado ao terminal positivo do buzzer.

## Código Explicado

### Definição dos Pinos
```cpp
const int pinoCLK = 3;
const int pinoDT = 4;
const int pinoSW = 5;
const int buzzerPin = 9;
```
Esses pinos são utilizados para conectar o encoder e o buzzer ao Arduino.

### Variáveis de Controle
```cpp
int contadorFreq = 440;
int ultPosicao;
int leituraCLK;
boolean bCW;
const int freqMin = 100;
const int freqMax = 2000;
```
Essas variáveis armazenam o estado atual do encoder, incluindo a direção da rotação e a frequência do buzzer.

### Função `setup()`
Configura os pinos como entradas ou saídas, inicializa a comunicação serial e armazena o estado inicial do encoder.

### Função `loop()`
A função principal que:
1. Verifica mudanças na posição do encoder.
2. Determina a direção da rotação (horário ou anti-horário).
3. Ajusta a frequência do buzzer de acordo com a direção da rotação.
4. Exibe o status no monitor serial.
5. Verifica se o botão do encoder foi pressionado.

## Como Usar
1. Monte o circuito conforme as conexões descritas.
2. Carregue o código no Arduino.
3. Abra o Monitor Serial para visualizar as informações do encoder.
4. Gire o encoder para ajustar a frequência do buzzer.
5. Pressione o botão do encoder para interagir com o projeto.

## Licença
Este projeto é de código aberto e pode ser modificado e distribuído livremente.