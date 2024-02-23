# Projeto de Gestão de Resíduos Sólidos Urbanos com IoT e MQTT

Este repositório contém o código-fonte e informações relacionadas ao Trabalho de Conclusão de Curso (TCC) desenvolvido por me. O projeto teve como objetivo explorar e desenvolver soluções inovadoras para a gestão de resíduos sólidos urbanos, integrando tecnologias de Internet das Coisas (IoT), com destaque para o protocolo de comunicação MQTT.

## Objetivos do TCC

- Explorar o uso de IoT na gestão de resíduos sólidos urbanos.
- Desenvolver uma arquitetura baseada em IoT para medições e monitoramento de resíduos sólidos.
- Integrar tecnologias IoT para coleta de dados em tempo real.
- Destacar o protocolo MQTT como escolha estratégica para eficiência energética e comunicação assíncrona.

## Metodologia

O trabalho utilizou uma abordagem que envolveu a análise de projetos e revisão da literatura sobre o uso de IoT na gestão de resíduos sólidos. Além disso, incluiu a implementação prática da arquitetura proposta, demonstrando a sinergia entre diversas tecnologias para a eficiência e sustentabilidade do sistema.

## Arquitetura Proposta

A arquitetura envolveu a integração estratégica de tecnologias IoT utilizando o protocolo MQTT para comunicação assíncrona. Esta abordagem permitiu coletar dados em tempo real e fornecer informações cruciais para a gestão eficiente de resíduos sólidos urbanos.

## Implementação do Código

O código-fonte incluído neste repositório foi desenvolvido com o ESP32 e utiliza bibliotecas como WiFi, PubSubClient, Ultrasonic e DHT. O dispositivo realiza medições de distância, umidade e temperatura, publicando os dados em tópicos MQTT para comunicação remota.

### Configuração

- SSID da Rede Wi-Fi: "Jovino"
- Senha da Rede Wi-Fi: "benicio123"
- Servidor MQTT: "broker.hivemq.com"

**OBS: Você pode alterar a rede e senha para o seu ambiente próprio.**

### Componentes Utilizados

- Sensor Ultrassônico (HC-SR04) para medição de distância.
- Sensor de Umidade e Temperatura (DHT11).
- DOIT ESP32 DEVKIT V1 (30 PINS)

## Instruções de Uso

1. Carregue o código no dispositivo ESP32.
2. Conecte os sensores.
3. Alimente o dispositivo.
4. Monitore as leituras remotamente usando um cliente MQTT.

## Resultados e Conclusões

O TCC representou um avanço significativo na otimização dos processos de coleta de resíduos,demonstrando a aplicação prática e integrada de tecnologias para melhorar a eficiência e sustentabilidade dos sistemas de gerenciamento de resíduos sólidos urbanos. Contribuiu para a busca por cidades mais inteligentes e sustentáveis.

**Autor:** Felipe Jovino dos Santos
**Contato:** felipejovinogamerplay@gmail.com

## Links Úteis

Aqui estão algumas referências que podem ser úteis para ajudá-lo a aprofundar seus conhecimentos sobre MQTT, ESP32 e projetos de IoT:

- **Vídeos Informativos**:

- **MQTT**
	- [O QUE É MQTT | PROJETO COM ESP32](https://www.youtube.com/watch?v=aqLq-22A5rU&t=335s)
	- [MQTT DASHBOARD | CONTROLE TUDO PELO CELULAR](https://www.youtube.com/watch?v=ZiVWhYgvY2U&t=423s)

- **Componentes**
	- [Projeto 31 - Leitura com entrada Analógica com ESP32 e Potenciômetro - Projetos de IoT, IA Robótica](https://www.youtube.com/watch?v=E5k_77qljDU)
	- [3 Modos de ligar botões no Arduino - Push Button](https://www.youtube.com/watch?v=_3334pm7ZvU)
	- [How to blink an LED with ESP32 board](https://www.youtube.com/watch?v=savZODDR4pw)
	- [Arduino – Usando o módulo sensor ultrassônico](https://www.youtube.com/watch?v=fB4VqINML_0&t=330s)

- **Configurações e Drivers**
	- [COMO INSTALAR A VERSÃO 2.0 DO IDE DO ARDUINO](https://www.youtube.com/watch?v=5-rVocboDC0).
	- [Como Instalar a IDE do Arduino no Linux Ubuntu](https://www.youtube.com/watch?v=VE-yrGQUajA).

- **Sites e Documentação**:

- **MQTT**
	- [HiveMQ Cloud](https://console.hivemq.cloud/)
	- [MQTT](https://mqtt.org/)

- **ESP32**
	- [DOIT Esp32 DevKit v1 Datasheet](https://drive.google.com/file/d/1DOeS-xbmvErDHROzWt1AvkltjIoBziXE/view?usp=drive_link)
	- [ESP32 DEVKIT V1 - DOIT (30 GPIOs)](https://drive.google.com/file/d/1TbZTc--lP1tSb9LJms1i3TvMKHpC3X8M/view?usp=drive_link)
	- [ESP32 Pinout: Saiba Tudo Sobre A ESP!](https://lobodarobotica.com/blog/esp32-pinout/#ESP32_Pinout_-_Pinos_de_Entrada_Analogica)
	
- **Componentes**
	- [Como conectar o Sensor Ultrassônico HC-SR04 ao Arduino](https://www.makerhero.com/blog/sensor-ultrassonico-hc-sr04-ao-arduino/)
	- [ESP32 - LED - Blink](https://esp32io.com/tutorials/esp32-led-blink)
	- [ESP32 - Button](https://esp32io.com/tutorials/esp32-button)

- **Configurações e Drivers**
	- [Instalando o Driver do NodeMCU e ESP32](https://www.robocore.net/tutoriais/instalando-driver-do-nodemcu)
	- [Installing the ESP32 Board in Arduino IDE (Windows, Mac OS X, Linux)](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

- **Material Usado**
	- [Imagens Utilizadas](https://drive.google.com/drive/folders/17mGdQTGRChREig39GXtv6__PNpP42hFj?usp=sharing)
	- [Código Final](https://drive.google.com/file/d/1qaXn7UBSK856b-wvqv8Q28z2boBRh18J/view?usp=drive_link)

- [Artigo do meu Trabalho](https://labic.dev.br/article/9/)

