# Descrição do Projeto
Este projeto é um sistema de monitoramento de luz que utiliza um sensor de luz (LDR) conectado a um ESP32. Os dados do sensor são enviados para um broker MQTT e processados em tempo real usando Node-RED. O sistema inclui uma automação personalizada que controla um LED com base nos níveis de luz lidos pelo sensor. O projeto foi desenvolvido e testado no simulador Wokwi e no ambiente de fluxo do Node-RED.

## Estrutura do Projeto
Hardware Simulado no Wokwi:

ESP32
Sensor de Luz (LDR)
LED
Resistor de 10k Ohms
Resistor de 220 Ohms
Breadboard e Fios de Conexão

Software:
Código fonte do ESP32 para leitura do sensor e envio de dados via MQTT.
Fluxo do Node-RED para processamento dos dados, automação e controle do LED.

## Instruções para Replicar e Testar a Solução
Parte 1: Simulação no Wokwi
Acessar o Wokwi:

Acesse Wokwi.

Clique em "New Project" e selecione "ESP32".

Arraste e solte os componentes necessários (ESP32, LDR, LED, resistores e conexões).

Montagem do Circuito:
LDR:
VCC ao pino 3.3V do ESP32.
GND ao GND do ESP32.
AO ao pino A0 do ESP32.

LED:
Ânodo (perna mais longa) ao pino digital D13 do ESP32 através de um resistor de 220 Ohms.
Cátodo (perna mais curta) ao GND do ESP32.
Código para o ESP32:
Copie e cole o código fonte no editor do Wokwi.
