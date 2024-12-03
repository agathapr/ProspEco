# Descrição do Projeto

O ProspEco ajuda residências a reduzirem o consumo de energia e economizarem na conta de luz por meio de insights personalizados, monitoramento de uso de eletrodomésticos, integração com informações de bandeiras tarifárias, e orientações sobre horários ideais para consumo. Utilizando IA generativa para análises e recomendações, o aplicativo se torna um assistente energético para o usuário, ajudando-o a entender e melhorar seus hábitos de consumo.
O ProspEco permite que o usuário registre todos os eletrodomésticos, aparelhos eletrônicos e luzes da residência.
Este projeto em IOT é um sistema de monitoramento de luz que utiliza um sensor de luz (LDR) conectado a um ESP32. Os dados do sensor são enviados para um broker MQTT e processados em tempo real usando Node-RED. O sistema inclui uma automação personalizada que controla um LED com base nos níveis de luz lidos pelo sensor. O projeto foi desenvolvido e testado no simulador Wokwi e no ambiente de fluxo do Node-RED. 

## Objetivo
O objetivo principal é que funcione como um sensor de luz ambiente para o usuário, para que automaticamente, as luzes da sua casa possam ser ligadas ou desligadas a partir do reconhecimento do nivel de iluminação ambiente presente no momento.

## Feito por
Agatha Pires
David Bryan
Gabriel Lima
Giovanna Alvarez
Murilo Matos
2TDSPH - 2024 - FIAP

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

1. Acessar o Wokwi
2. Clique em "New Project" e selecione "ESP32".
3. Arraste e solte os componentes necessários (ESP32, LDR, LED, resistores e conexões).

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
