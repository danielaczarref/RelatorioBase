# Relatório de Base de Produtos em Rede de Supermercado

Este projeto tem como intuito gerar um relatório dinâmico em que, através dos parâmetros definidos pelo usuário, resulte em um relatório contendo os produtos e suas respectivas particularidades. Isto é, em uma rede de supermercados que contém várias filiais, os preços dos produtos variam de acordo com regras de negócio de cada filial; a fim de descobrir a base de preço para cada produto, o usuário pode filtrar sua pesquisa através de:
  - Filial;
  - Departamento;
  - Seção;
  - Categoria;
  - Produto.
  
 Em que, pelo menos um dos campos é obrigatório para filtragem de dados proveniente do BD. A aplicação foi desenvolvida em linguagem C++ orientada a objetos, através da IDE Qt Creator versão 4.5.2, e fazendo uso de Postegres como sistema gerenciador de banco de dados objeto relacional.
 
## Getting Started

Para o desenvolvimento deste projeto, foram criadas classes para visão, regras de negócio, domínio e BD. O poder de abstração e orientação a objetos são palavras-chave para o desenvolvimento desta aplicação. 

A tela inicial mostra relatório vazio, uma vez que a sobrecarga de todos os dados não é uma opção, em que o usuário deve fazer a filtragem de dados de acordo com os parâmetros desejados. E então, o mesmo pode gerar um relatório de base de produtos, sejam estes de uma determinada filial, e/ou de um determinado departamento, e/ou de uma determinada seção, etc.

As devidas validações foram implementadas para evitar quaisquer possível erro, bem como foram implementadas funcionalidades de busca de um ou mais parâmetros desejados, em que, com apenas dois cliques, o usuário consegue selecionar o dado desejado.

### Prerequisites

Para o desenvolvimento e uso deste programa, foram utilizados:
  - Qt Creator 4.5.2;
  - Postegres;
  - DataGrip.
