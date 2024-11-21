# Hotel Descanso Garantido

## Desenvolvedores
- **Pedro Lanza**  
- **Eduardo Spinelli**  
- **André Bianchini**  

---

## Sobre o Projeto

O **Hotel Descanso Garantido** é um sistema informatizado desenvolvido em linguagem C, voltado para a gestão de pequenos e médios hotéis. Ele foi projetado com base em boas práticas de engenharia de software e visa oferecer eficiência e simplicidade na administração de hotéis, eliminando problemas comuns como reservas duplicadas e inconsistências em registros.

---

## Funcionalidades Principais

- **Cadastro de Clientes**  
  Permite registrar clientes, validar dados como CEP e telefone, além de gerar IDs únicos.  

- **Cadastro de Funcionários**  
  Registra informações de funcionários e associa salários com base nos cargos.  

- **Registro de Estadias**  
  Calcula valores totais das estadias e verifica a disponibilidade de quartos.  

- **Pesquisa**  
  Busca clientes, funcionários ou quartos pelo ID ou nome.  

- **Controle de Quartos**  
  Verifica a disponibilidade de quartos e controla sua ocupação.  

---

## Regras de Negócio

- Limite máximo de **5 quartos disponíveis por período**.  
- Validação de **telefones** (9 a 12 dígitos) e **datas de estadia** (formato DD/MM/AAAA).  
- **Tarifas Diárias** variam conforme o número de hóspedes:
  - 1 hóspede: R$ 260,00
  - 2 hóspedes: R$ 320,00
  - 3 hóspedes: R$ 400,00
  - 4 hóspedes: R$ 490,00
  - 5 hóspedes: R$ 550,00
  - 6 hóspedes: R$ 620,00

---

## Arquitetura do Sistema

### Estrutura de Arquivos
- **src/main.c**: Código principal do sistema.
- **docs/**: Documentação detalhada do projeto.
- **data/**: Contém arquivos de exemplo com dados de clientes e funcionários.

---

## Planejamento e Sprints

| Sprint | Atividades Realizadas                                      | Datas                |
|--------|------------------------------------------------------------|----------------------|
| 1      | Definição da estrutura básica do sistema e desenvolvimento do cadastro. | 20/11/2024 a 23/11/2024 |
| 2      | Implementação do registro de estadias e pesquisa de dados. | 24/11/2024 a 26/11/2024 |
| 3      | Testes automatizados e ajustes finais no sistema.          | 27/11/2024 a 29/11/2024 |

---

## Links Importantes

| Repositório no GitHub               | https://github.com/pedro-lanzaa/hoteldescansogarantido                  |
|-------------------------------------|---------------------------------------------------------------------------|
| Repositório no Replit               | https://replit.com/@pedro-lanza/HotelDescansoGarantido#main.c            |
| Vídeo de apresentação no YouTube    | https://www.youtube.com/watch?v=4kH1ARzC8NU                              |

---

## Casos de Teste

| ID | Funcionalidade            | Entrada                      | Saída Esperada                   | Resultado |
|----|---------------------------|------------------------------|-----------------------------------|-----------|
| 1  | Cadastro de Clientes      | Nome, CEP, Telefone          | Cliente cadastrado com sucesso    | Aprovado  |
| 2  | Cadastro de Funcionários  | Nome, Telefone, Cargo        | Funcionário cadastrado com sucesso | Aprovado  |
| 3  | Registro de Estadias      | Cliente ID, Data Entrada/Saída | Estadia registrada com sucesso  | Aprovado  |
| 4  | Controle de Quartos       | Datas com quartos indisponíveis | Todos os quartos ocupados       | Aprovado  |
| 5  | Pesquisa de Clientes      | ID ou Nome                   | Dados do cliente exibidos         | Aprovado  |
| 6  | Pesquisa de Quarto        | ID inexistente               | Quarto não encontrado             | Aprovado  |

---

## Principais Trechos de Código

### Cadastro de Clientes
```c
void cadastrarCliente() {
    printf("Digite o Nome: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    // Validação do telefone e CEP
    // Geração de ID único
}
