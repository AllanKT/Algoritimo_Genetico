# SIMULAÇÃO DE ALGORITMOS DE RECONFIGURAÇÃO DE UMA REDE DE SENSORES SEM FIO

Projeto de Iniciação Científica IESB

# PROJETO DE PESQUISA
## 1 RESUMO

Este projeto tem como objetivo descrever o que são redes de sensores sem fio, onde a aplicação de tais pode ser viável e os problemas relacionados a essas aplicações, após isso será detalhado o procedimento da criação de uma ferramenta de simulação que otimiza de forma heurística o posicionamento de nós sensores baseado em algoritmo genético e descrever os protocolos de roteamento viáveis a aplicação. 

# RELATÓRIO FINAL
## 2 INTRODUÇÃO

Com os avanços tecnológicos que tem ocorrido nos ramos de comunicação sem fio, os novos materiais de sensoriamento, micro-eletro-mecânicos e na eletrônica digital, tornou-se viável a fabricação em larga escala de dispositivos de sensores inteligentes, o que levou a criação de Redes de Sensores Sem Fio (RSSF). Pode ser utilizada no monitoramento, processamento e rastreamento em diversas áreas. Tem aplicações em áreas perigosas ou locais de difícil acesso, seja na utilização militar, monitoramento de áreas ambientais, entre outros.

Com o objetivo de utilizar uma aplicação de Algoritmos Genéticos (AG) no protocolo de comunicação de nós sensores HACBA (New Approach to Hierarchical Routing for Wireless Sensor Network), foi realizado um estudo sob a camada de transporte do modelo TCP/IP, e uma pesquisa muito aprofundada em relação a AGs e técnicas de construção da mesma com embasamento matemático.

O resultado final pretendido seria realizar uma simulação dessa iteração de protocolo com inteligência artificial, a fim de otimizar a área de monitoramento em relação a diminuição da quantidade de nodos utilizados no mapeamento.

Este trabalho está dividido da seguinte forma: o capítulo 2 são abordados conceitos fundamentais sobre RSSF e aqueles associados a técnica de Inteligência Artificial (IA), AG; no capítulo 3 apresenta os resultados; e por fim, no capítulo 4 são apresentadas as conclusões e os trabalhos futuros. 

## 3 DESENVOLVIMENTO (METODOLOGIA)

Neste capítulo são apresentados conceitos fundamentais sobre RSSF, protocolo de roteamento e IA.

### 3.1 REDES DE SENSORES SEM FIO

RSSF consistem essencialmente de certa quantidade de dispositivos interligados a uma infraestrutura computacional robusta tratados a partir daqui simplesmente como “nós” ou nodos da rede que coletam dados, processam as informações e disseminam os resultados de um ponto à outro. Os nós sensores são dispostos em uma área geográfica de forma autônoma, determinística ou pré-calculada, a fim de monitorar aquele ambiente. [Chi-Tsun et al., 2011]
Cada nó sensor é equipado com o sensor adequado para fazer o monitoramento do ambiente ao qual foi exposto. Estes são organizados em clusters, onde os eventos detectados são processados e após uma tomada de decisão, as informações são ou não disseminadas na rede. O roteamento de uma RSSF é feita basicamente pela tarefa de encontrar a melhor rota para que a informação processada seja enviada a outro nodo, a fim de chegar a um destino. [Keyur et al., 2011]
Os protocolos de roteamento convencionais e ad hoc não são benéficos a uma RSSF, onde os nós precisam de mecanismos de roteamento que maximizem o desempenho de processamento e de consumo energético. [Keyur et al., 2011]

### 3.2 PROTOCOLOS DE ROTEAMENTO

Existem diversos protocolos de roteamento na literatura. Eles são basicamente divididos em protocolos de roteamento plano e de roteamento hierárquico [Zoby 2013 apud Singh 2010]. No primeiro, todos os nós possuem a mesma tarefa. No segundo, existem diferentes níveis de hierarquia entre os nós sensores.
Para este trabalho, foi realizado um estudo sobre o protocolo hierárquico, HACBA (Hardware-Adaptative Clustering Based Algorithm) [Zoby et al., 2013], que se baseia no protocolo LEACH (Low Energy Adaptive Clustering Hierarchy) [Heinzelman, 2002].

### 3.2.1 PROTOCOLO HACBA

Os nós sensores da rede de um protocolo hierárquico têm diferentes níveis de hierarquia. Utilizando a clusterização, são formados grupos com os nós sensores e um cluster head (CH) em cada grupo, este ira gerenciar a comunicação recebendo dados dos nós sensores de seu grupo e enviando para a estação base. Essa forma de organização ocasiona na redução da agregação de dados que são recebidos pela estação base.
A principal função do HACBA é a de providenciar a troca de informações em uma RSSF, tendo como foco o desenvolvimento de um código capaz de reduzir o consumo de energia e garantindo a qualidade no envio das mensagens. Este se adpta as características do hardware para fazer o roteamento na rede. Este providência critérios para a comunicação entre os nós sensores com base na distância e no raio de comunicação individual de cada nó sensor.
A estratégia sleeping, utilizada pelo protocolo, é um método utilizado pelo protocolo a fim de evitar redundância de informações e providenciar a economia de energia dos nós sensores. Esta estratégia mantém alguns nós sensores ligados enquanto outros nós sensores próximos a estes se mantém desligados, e assim revezam seu status.
Utilizando sistemas embutidos como GPS ou outros sistemas de localização, pode-se assumir que os nós sensores sabem da localização de todos na rede. Com algoritmos, como AMEER [Pavai et al., 2009], os nós sensores também são capazes de determinar sua distância com os outros nós e para a estação base.

### 3.3 ALGORITMO GENÉTICO

AGs são algoritmos de busca baseados na seleção natural e genética, propostas por Charles Darvin e Gregor Mendel respectivamente, utilizando os princípios de seleção, crossover e mutação [Deb el al., 2002]. Inicialmente são selecionados os melhores indivíduos da população atual e os combinam com uma troca de informação genética, similar ao crossover, formando uma estrutura heurística de busca. A mutação é realizada em determinados indivíduos da população, alterando o valor de seus genes.
O tamanho da população inicial deve ser bastante estudado neste cenário para o melhor desempenho do AG, pois caso seja grande demais, o algoritmo demorará muito para ser processado e encontrar uma solução, caso seja pequeno demais, não haverá espaço suficiente para calcular as variações genéticas da mesma [Man et al., 1996].
Com o uso de AG em uma RSSF, proposta por este projeto, pode-se otimizar o melhor posicionamento dos nós sensores, garantindo a conectividade dos nós, controlando a densidade e consequentemente evitando problemas como a vida útil e a perda de pacotes. 

## 4 IMPLEMENTAÇÃO DO HACBA UTILIZANDO ALGORITMO GENÉTICO

Para a implementação do AG em uma RSSF, foi utilizado o protocolo HACBA. Desta forma, pretende otimizar a comunicação, o consumo de energia e o envio de mensagens dos nós sensores. Será abordado os principais componentes de um AG com a implementação do HACBA, como a função-objetivo, indivíduos, seleção, crossover e mutação.

### 4.1 FUNÇÃO OBJETIVO

A função-objetivo tem como finalidade otimizar o posicionamento dos nós sensores, a fim de maximizar a área de monitoramento, minimizando a quantidade de nós sensores distribuídos na área, assim diminuindo custos e a quantidade de saltos para enviar um dado a estação base.

### 4.2 INDIVÍDUO

Como este é meramente o portador de seu código genético, no contexto de RSSF, o indivíduo será representado pela área total que os nós sensores distribuídos na rede conseguem monitorar.
A área total de monitoramento pode ser calculada pela soma das áreas de monitoramento individuais de cada nodo, com a diferença da intersecção dos mesmos, conforme exemplificado na Figura 1.
