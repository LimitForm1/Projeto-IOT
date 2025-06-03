Este repositório apresenta o desenvolvimento de um protótipo do projeto sistema distribuído de coleta de dados para alertas precoces de risco de deslizamento de terra. Os deslizamentos de terra são 
desastres naturais graves no Brasil, especialmente em áreas urbanas, frequentemente afetando comunidades densamente povoadas e vulneráveis. O projeto propõe uma solução tecnológica baseada em monitoramento automatizado e processamento de dados para detectar fatores de risco, como níveis de precipitação, umidade do solo e inclinação do terreno. O objetivo é emitir alertas oportunos que permitam que populações em risco busquem abrigo antes que o desastre ocorra, minimizando tanto perdas humanas quanto ambientais.

Para isso, usamos os materiais WEMOS D1 Mini Pro:

E, 

Também usamos os softwares BrokerMqtt, Node-Red, InfluxDB, Grafana e CallMeBot, para, respectivamente, receber o valor detectado pelo arduino, gerenciar as informações detectadas, guardar os dados, facilitar a visualização de tais dados por meio de um dashboard e similuar um alerta por meio de uma mensagem enviada para o WhatsApp.

BrokerMqtt:

Node-Red:

InfluxDB:

Grafana:
