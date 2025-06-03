Este repositório apresenta o desenvolvimento de um protótipo do projeto sistema distribuído de coleta de dados para alertas precoces de risco de deslizamento de terra. Os deslizamentos de terra são 
desastres naturais graves no Brasil, especialmente em áreas urbanas, frequentemente afetando comunidades densamente povoadas e vulneráveis. O projeto propõe uma solução tecnológica baseada em monitoramento automatizado e processamento de dados para detectar fatores de risco, como níveis de precipitação, umidade do solo e inclinação do terreno. O objetivo é emitir alertas oportunos que permitam que populações em risco busquem abrigo antes que o desastre ocorra, minimizando tanto perdas humanas quanto ambientais.

Para isso, usamos os materiais WEMOS D1 Mini Pro:
![Captura de tela 2025-06-03 100006](https://github.com/user-attachments/assets/a447939b-5ec5-4f87-a0e3-19001ba02bd2)

E, um higrômetro:
![Captura de tela 2025-06-03 100026](https://github.com/user-attachments/assets/8a0056a7-41f4-43e9-bba1-81f7d26b7db7)

Também usamos os softwares Arduino IDE, BrokerMqtt, Node-Red, InfluxDB, Grafana e CallMeBot, para, respectivamente, implementar o código da aplicação no arduino, receber o valor detectado pelo arduino, gerenciar as informações detectadas, guardar os dados, facilitar a visualização de tais dados por meio de um dashboard e similuar um alerta por meio de uma mensagem enviada para o WhatsApp.

Arduino IDE:
![Captura de tela 2025-06-03 105450](https://github.com/user-attachments/assets/fe8fd1ba-ae67-477f-8620-5dabd4fd78da)

BrokerMqtt:
![Broker](https://github.com/user-attachments/assets/f31a6f83-2da8-4dbb-9c9d-037e95b57501)
![Broker2](https://github.com/user-attachments/assets/a8614db9-66a4-41a0-8fd3-9c2572ba2adf)

Node-Red:
![Capture](https://github.com/user-attachments/assets/2879a502-cfa8-4d4d-aba7-66c94c02a428)

InfluxDB:
![Captura de tela 2025-06-03 090228](https://github.com/user-attachments/assets/62d39047-915a-4ba9-84d6-03d6d1be840a)

Grafana:
![Captura de tela 2025-06-03 090330](https://github.com/user-attachments/assets/76deb5dc-6524-4108-8e71-f28d15fe6539)
