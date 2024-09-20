# Projeto: Controle de Brilho de LED com Encoder Rotativo

Este projeto implementa um controle de brilho de LED utilizando um encoder rotativo. O brilho do LED varia conforme o movimento do encoder no sentido horário ou anti-horário, e o estado atual do encoder é exibido no monitor serial. Um botão integrado ao encoder também pode ser detectado para interações adicionais.

## Funcionalidades
- Controle de brilho de um LED através do movimento de um encoder rotativo.
- Movimentos no sentido horário diminuem o brilho, e no sentido anti-horário aumentam o brilho.
- O brilho é limitado entre 0 (mínimo) e 255 (máximo).
- Exibição em tempo real das mudanças no monitor serial.
- Detecção de botão pressionado (botão embutido no encoder).

## Hardware Necessário
- Arduino (ou qualquer microcontrolador compatível)
- Encoder rotativo com botão integrado
- LED
- Resistores (se necessário)
- Jumpers e protoboard

## Conexões
- `pinoCLK` (Pino Digital 3): Conectado ao pino CLK do encoder.
- `pinoDT` (Pino Digital 4): Conectado ao pino DT do encoder.
- `pinoSW` (Pino Digital 5): Conectado ao pino do botão do encoder.
- `ledPin` (Pino Digital 9): Conectado ao ânodo do LED (com resistor limitador de corrente).

## Código Explicado

### Definição dos Pinos
```cpp
const int pinoCLK = 3;
const int pinoDT = 4;
const int pinoSW = 5;
const int ledPin = 9;
```
Esses pinos são utilizados para conectar o encoder e o LED ao Arduino.

### Variáveis de Controle
```cpp
int contadorPos = 0;
int ultPosicao;
int leituraCLK;
boolean bCW;
int brightness = 0;
```
Essas variáveis armazenam o estado atual do encoder, incluindo a direção da rotação e o brilho do LED.

### Função `setup()`
Configura os pinos como entradas ou saídas, inicializa a comunicação serial e armazena o estado inicial do encoder.

### Função `loop()`
A função principal que:
1. Verifica mudanças na posição do encoder.
2. Determina a direção da rotação (horário ou anti-horário).
3. Ajusta o brilho do LED de acordo com a direção da rotação.
4. Exibe o status no monitor serial.
5. Verifica se o botão do encoder foi pressionado.

## Como Usar
1. Monte o circuito conforme as conexões descritas.
2. Carregue o código no Arduino.
3. Abra o Monitor Serial para visualizar as informações do encoder.
4. Gire o encoder para ajustar o brilho do LED.
5. Pressione o botão do encoder para interagir com o projeto.

## Licença
Este projeto é de código aberto e pode ser modificado e distribuído livremente.

