# PONTIFÍCIA UNIVERSIDADE CATÓLICA DE MINAS GERAIS
## Engenharia de Software

### Hotel Descanso Garantido

## Autores
- Pedro Lanza
- Vitor Lucas

## Projeto
Projeto AEDS e FES

## Apresentação
O sistema de controle do Hotel Descanso Garantido tem como objetivo gerenciar as reservas, clientes e funcionários do hotel, eliminando a necessidade de planilhas e cadernos. O sistema previne a dupla reserva de quartos, organiza a gestão de estadias e facilita a administração dos dados de clientes e funcionários.

## Funcionalidades Principais
- Cadastrar Clientes
- Cadastrar Funcionários
- Cadastrar Estadias
- Pesquisar Clientes
- Pesquisar Funcionários
- Pesquisar Quartos
- Mostrar Estadias de um Cliente
- Dar Baixa em Estadia

## Bibliotecas Utilizadas
- `stdio.h`: Funções de entrada e saída.
- `stdlib.h`: Funções utilitárias de propósito geral, como alocação de memória.
- `string.h`: Funções para manipulação de strings.
- `time.h`: Funções para manipulação de datas e tempos.
- `munit.h`: Biblioteca para execução de testes unitários.

## Estrutura do Projeto
- `src/`: Código fonte do projeto.
  - `main.c`: Implementação principal do sistema.
  - `tests.c`: Implementação dos casos de teste.
- `docs/`: Documentação do projeto.
  - `EvolucaoBacklog.md`: Evolução do backlog do produto.
  - `Funcionalidades.md`: Descrição detalhada das funcionalidades do sistema.
  - `CasosTeste.md`: Planejamento dos casos de teste e relatórios de execução.
  - `DadosTeste.md`: Arquivos contendo dados já incluídos para teste das funcionalidades.
- `README.md`: Documentação geral do projeto.

## Instruções de Compilação e Execução
Para compilar o programa principal:
```sh
gcc src/main.c -o hotel
