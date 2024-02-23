# Projeto de Gestão de Resíduos Sólidos Urbanos com IoT e MQTT

Este repositório contém o código-fonte e informações relacionadas ao Trabalho de Conclusão de Curso (TCC) desenvolvido por Felipe Jovino dos Santos. O projeto teve como objetivo explorar e desenvolver soluções inovadoras para a gestão de resíduos sólidos urbanos, integrando tecnologias de Internet das Coisas (IoT), com destaque para o protocolo de comunicação MQTT.

## Objetivos do TCC

- Explorar o uso de IoT na gestão de resíduos sólidos urbanos.
- Desenvolver uma arquitetura baseada em IoT para medições e monitoramento de resíduos sólidos.
- Integrar tecnologias como RFID, GPS, GPRS, GIS e câmeras para coleta de dados em tempo real.
- Destacar o protocolo MQTT como escolha estratégica para eficiência energética e comunicação assíncrona.

## Metodologia

O trabalho utilizou uma abordagem que envolveu a análise de projetos e revisão da literatura sobre o uso de IoT na gestão de resíduos sólidos. Além disso, incluiu a implementação prática da arquitetura proposta, demonstrando a sinergia entre diversas tecnologias para a eficiência e sustentabilidade do sistema.

## Arquitetura Proposta

A arquitetura envolveu a integração estratégica de tecnologias como RFID, GPS, GPRS, GIS e câmeras, utilizando o protocolo MQTT para comunicação assíncrona. Esta abordagem permitiu coletar dados em tempo real e fornecer informações cruciais para a gestão eficiente de resíduos sólidos urbanos.

## Implementação do Código

O código-fonte incluído neste repositório foi desenvolvido em Arduino e utiliza bibliotecas como WiFi, PubSubClient, Ultrasonic e DHT. O dispositivo realiza medições de distância, umidade e temperatura, publicando os dados em tópicos MQTT para comunicação remota.

### Configuração

- SSID da Rede Wi-Fi: "Jovino"
- Senha da Rede Wi-Fi: "benicio123"
- Servidor MQTT: "broker.hivemq.com"

### Componentes Utilizados

- Sensor Ultrassônico (HC-SR04) para medição de distância.
- Sensor de Umidade e Temperatura (DHT11).
- LED indicador.

## Instruções de Uso

1. Carregue o código no dispositivo Arduino.
2. Conecte os sensores e o LED conforme descrito no código.
3. Alimente o dispositivo.
4. Monitore as leituras remotamente usando um cliente MQTT.

## Resultados e Conclusões

O TCC representou um avanço significativo na otimização dos processos de coleta de resíduos,demonstrando a aplicação prática e integrada de tecnologias para melhorar a eficiência e sustentabilidade dos sistemas de gerenciamento de resíduos sólidos urbanos. Contribuiu para a busca por cidades mais inteligentes e sustentáveis.

**Autor:** Felipe Jovino dos Santos

**Contato:** [Inserir e-mail ou outra forma de contato]
