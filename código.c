/*
 ============================================================================
 Nome     : Hotel Descanso Garantido
 Autores  : Pedro Lanza e Vitor Lucas
 Trabalho : Projeto AEDS e FES
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "munit.h"

#define MAX_QUARTOS 5  // Define o número máximo de quartos disponíveis

// Estrutura para Cliente
typedef struct {
    char id[10];
    char nome[50];
    char endereco[100];
    char telefone[20];
} Cliente;

// Estrutura para Funcionário
typedef struct {
    char id[10];
    char nome[50];
    char telefone[20];
    float salario;
} Funcionario;

// Estrutura para Estadia
typedef struct {
    char clienteId[10];
    char quartoId[10];
    int numHospedes;
    struct tm dataEntrada;
    struct tm dataSaida;
    int dias;
    float valorTotal;
    float valorDiaria;
} Estadia;

Cliente clientes[100];
Funcionario funcionarios[100];
Estadia estadias[100];
int numClientes = 0;
int numFuncionarios = 0;
int numEstadias = 0;

// Declarações das funções
void limpaTela();
void pausaTela();
int validarData(int dia, int mes, int ano);
int calcularDiferencaDias(struct tm dataEntrada, struct tm dataSaida);
int contarQuartosDisponiveis(struct tm dataEntrada, struct tm dataSaida);
void cadastrarCliente();
void cadastrarFuncionario(int cargo);
void cadastrarEstadia(char clienteId[]);
void darBaixaEstadia();
void pesquisarCliente();
void pesquisarFuncionario();
void mostrarEstadiasCliente();
void pesquisarQuarto();

void limpaTela() {
    system("cls || clear");
}

void pausaTela() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

int validarData(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 2024) {
        return 0;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) return 0;
    }
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            if (dia > 29) return 0;
        } else {
            if (dia > 28) return 0;
        }
    }
    return 1;
}

int calcularDiferencaDias(struct tm dataEntrada, struct tm dataSaida) {
    dataEntrada.tm_hour = 0;
    dataEntrada.tm_min = 0;
    dataEntrada.tm_sec = 0;
    dataSaida.tm_hour = 0;
    dataSaida.tm_min = 0;
    dataSaida.tm_sec = 0;

    time_t entrada = mktime(&dataEntrada);
    time_t saida = mktime(&dataSaida);

    double diferenca = difftime(saida, entrada) / (60 * 60 * 24);
    return (int)diferenca + 1;
}

int contarQuartosDisponiveis(struct tm dataEntrada, struct tm dataSaida) {
    int contagem = 0;
    for (int i = 0; i < numEstadias; i++) {
        if (mktime(&estadias[i].dataSaida) < mktime(&dataEntrada) || mktime(&estadias[i].dataEntrada) > mktime(&dataSaida)) {
            contagem++;
        }
    }
    return contagem;
}

void cadastrarCliente() {
    limpaTela();
    Cliente novoCliente;
    printf("Digite o Nome e o Sobrenome: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    strtok(novoCliente.nome, "\n");

    int cepValido = 0;
    while (!cepValido) {
        printf("Digite o CEP (8 dígitos): ");
        fgets(novoCliente.endereco, sizeof(novoCliente.endereco), stdin);
        strtok(novoCliente.endereco, "\n");

        if (strlen(novoCliente.endereco) == 8) {
            cepValido = 1;
        } else {
            printf("Formato inválido. Digite um CEP válido.\n");
        }
    }

    int telefoneValido = 0;
    while (!telefoneValido) {
        printf("Digite o Telefone com ddd: ");
        fgets(novoCliente.telefone, sizeof(novoCliente.telefone), stdin);
        strtok(novoCliente.telefone, "\n");

        if (strlen(novoCliente.telefone) >= 9 && strlen(novoCliente.telefone) <= 12) {
            telefoneValido = 1;
        } else {
            printf("Formato inválido. Digite um número válido.\n");
        }
    }

    sprintf(novoCliente.id, "C%d", numClientes + 1);
    clientes[numClientes++] = novoCliente;
    limpaTela();
    printf("Cadastrado com sucesso!\n");
    printf("ID do cliente: %s\n", novoCliente.id);
    printf("Voce gostaria de se hospedar? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
    getchar();
    if (resposta == 'S' || resposta == 's') {
        cadastrarEstadia(novoCliente.id);
    }
}

void cadastrarFuncionario(int cargo) {
    limpaTela();
    Funcionario novoFuncionario;
    printf("Digite o nome: ");
    fgets(novoFuncionario.nome, sizeof(novoFuncionario.nome), stdin);
    strtok(novoFuncionario.nome, "\n");

    int telefoneValido = 0;
    while (!telefoneValido) {
        printf("Digite o Telefone com o ddd: ");
        fgets(novoFuncionario.telefone, sizeof(novoFuncionario.telefone), stdin);
        strtok(novoFuncionario.telefone, "\n");

        if (strlen(novoFuncionario.telefone) >= 9 && strlen(novoFuncionario.telefone) <= 12) {
            telefoneValido = 1;
        } else {
            printf("Formato inválido. Digite um número válido.\n");
        }
    }

    sprintf(novoFuncionario.id, "F%d", numFuncionarios + 1);

    switch (cargo) {
        case 1:
            novoFuncionario.salario = 1600.40;
            break;
        case 2:
            novoFuncionario.salario = 1400.60;
            break;
        case 3:
            novoFuncionario.salario = 1500.60;
            break;
        case 4:
            novoFuncionario.salario = 1800.60;
            break;
    }
    funcionarios[numFuncionarios++] = novoFuncionario;
    limpaTela();
    printf("Cadastrado com sucesso!\n");
    printf("ID: %s\n", novoFuncionario.id);
    printf("Nome: %s\n", novoFuncionario.nome);
    printf("Telefone: %s\n", novoFuncionario.telefone);
    printf("Salario: R$ %.2f\n", novoFuncionario.salario);
    pausaTela();
}

float calcularValorDiaria(int numHospedes) {
    switch (numHospedes) {
        case 1: return 260.0;
        case 2: return 320.0;
        case 3: return 400.0;
        case 4: return 490.0;
        case 5: return 550.0;
        case 6: return 620.0;
        default: return 0.0;
    }
}

void cadastrarEstadia(char clienteId[]) {
    limpaTela();
    Estadia novaEstadia;
    strcpy(novaEstadia.clienteId, clienteId);
    
    do {
        printf("Digite o número de hóspedes (máx 6): ");
        scanf("%d", &novaEstadia.numHospedes);
        getchar();
        if (novaEstadia.numHospedes < 1 || novaEstadia.numHospedes > 6) {
            printf("Número inválido de hóspedes. Tente novamente.\n");
        }
    } while (novaEstadia.numHospedes < 1 || novaEstadia.numHospedes > 6);

    novaEstadia.valorDiaria = calcularValorDiaria(novaEstadia.numHospedes);

    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    do {
        printf("Digite a data de entrada (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
        getchar();
        if (!validarData(diaEntrada, mesEntrada, anoEntrada)) {
            printf("Data inválida. Tente novamente.\n");
        } else {
            novaEstadia.dataEntrada.tm_mday = diaEntrada;
            novaEstadia.dataEntrada.tm_mon = mesEntrada - 1;
            novaEstadia.dataEntrada.tm_year = anoEntrada - 1900;
            novaEstadia.dataEntrada.tm_hour = 0;
            novaEstadia.dataEntrada.tm_min = 0;
            novaEstadia.dataEntrada.tm_sec = 0;
        }
    } while (!validarData(diaEntrada, mesEntrada, anoEntrada));

    do {
        printf("Digite a data de saída (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);
        getchar();
        if (!validarData(diaSaida, mesSaida, anoSaida)) {
            printf("Data inválida. Tente novamente.\n");
        } else {
            novaEstadia.dataSaida.tm_mday = diaSaida;
            novaEstadia.dataSaida.tm_mon = mesSaida - 1;
            novaEstadia.dataSaida.tm_year = anoSaida - 1900;
            novaEstadia.dataSaida.tm_hour = 0;
            novaEstadia.dataSaida.tm_min = 0;
            novaEstadia.dataSaida.tm_sec = 0;
        }
    } while (!validarData(diaSaida, mesSaida, anoSaida));

    int quartosDisponiveis = contarQuartosDisponiveis(novaEstadia.dataEntrada, novaEstadia.dataSaida);
    if (quartosDisponiveis >= MAX_QUARTOS) {
        printf("Todos os quartos estão ocupados para as datas selecionadas. Por favor, aguarde até que algum quarto esteja disponível.\n");
        pausaTela();
        return;
    }

    novaEstadia.dias = calcularDiferencaDias(novaEstadia.dataEntrada, novaEstadia.dataSaida);

    if (novaEstadia.dias < 1) {
        novaEstadia.dias = 1;
    }

    novaEstadia.valorTotal = novaEstadia.dias * novaEstadia.valorDiaria;
    sprintf(novaEstadia.quartoId, "Q%d", numEstadias + 1);
    estadias[numEstadias++] = novaEstadia;
    limpaTela();
    printf("Estadia cadastrada com sucesso!\n");
    printf("ID do quarto: %s - Desocupado\n", novaEstadia.quartoId);
    printf("Tempo total da estadia: %d dias\n", novaEstadia.dias);
    printf("Valor total: R$ %.2f\n", novaEstadia.valorTotal);
    pausaTela();
}

void darBaixaEstadia() {
    limpaTela();
    char clienteId[10];
    printf("Digite o ID do cliente: ");
    scanf("%s", clienteId);
    getchar();
    for (int i = 0; i < numEstadias; i++) {
        if (strcmp(estadias[i].clienteId, clienteId) == 0) {
            printf("Baixa da estadia do cliente %s realizada com sucesso!\n", clienteId);
            for (int j = i; j < numEstadias - 1; j++) {
                estadias[j] = estadias[j + 1];
            }
            numEstadias--;
            pausaTela();
            return;
        }
    }
    printf("Estadia nao encontrada para o cliente %s.\n", clienteId);
    pausaTela();
}

void pesquisarCliente() {
    limpaTela();
    char busca[50];
    printf("Digite o nome ou ID do cliente: ");
    scanf("%49s", busca);
    getchar();
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, busca) == 0 || strcmp(clientes[i].id, busca) == 0) {
            printf("ID: %s\n", clientes[i].id);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Estadias:\n");
            for (int j = 0; j < numEstadias; j++) {
                if (strcmp(estadias[j].clienteId, clientes[i].id) == 0) {
                    printf("Quarto ID: %s\n", estadias[j].quartoId);
                    printf("Numero de hospedes: %d\n", estadias[j].numHospedes);
                    printf("Data de entrada: %02d/%02d/%04d\n", estadias[j].dataEntrada.tm_mday, estadias[j].dataEntrada.tm_mon + 1, estadias[j].dataEntrada.tm_year + 1900);
                    printf("Data de saida: %02d/%02d/%04d\n", estadias[j].dataSaida.tm_mday, estadias[j].dataSaida.tm_mon + 1, estadias[j].dataSaida.tm_year + 1900);
                    printf("Dias: %d\n", estadias[j].dias);
                    printf("Valor total: R$ %.2f\n", estadias[j].valorTotal);
                    printf("\n");
                }
            }
            pausaTela();
            return;
        }
    }
    printf("Cliente nao encontrado.\n");
    pausaTela();
}

void pesquisarFuncionario() {
    limpaTela();
    char busca[50];
    printf("Digite o nome ou ID do funcionario: ");
    scanf("%49s", busca);
    getchar();
    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].nome, busca) == 0 || strcmp(funcionarios[i].id, busca) == 0) {
            printf("ID: %s\n", funcionarios[i].id);
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Telefone: %s\n", funcionarios[i].telefone);
            printf("Salario: R$ %.2f\n", funcionarios[i].salario);
            pausaTela();
            return;
        }
    }
    printf("Funcionario nao encontrado.\n");
    pausaTela();
}

void mostrarEstadiasCliente() {
    limpaTela();
    char clienteId[10];
    printf("Digite o ID do cliente: ");
    scanf("%9s", clienteId);
    getchar();
    int encontrado = 0;
    for (int i = 0; i < numEstadias; i++) {
        if (strcmp(estadias[i].clienteId, clienteId) == 0) {
            printf("Quarto ID: %s\n", estadias[i].quartoId);
            printf("Numero de hospedes: %d\n", estadias[i].numHospedes);
            printf("Data de entrada: %02d/%02d/%04d\n", estadias[i].dataEntrada.tm_mday, estadias[i].dataEntrada.tm_mon + 1, estadias[i].dataEntrada.tm_year + 1900);
            printf("Data de saida: %02d/%02d/%04d\n", estadias[i].dataSaida.tm_mday, estadias[i].dataSaida.tm_mon + 1, estadias[i].dataSaida.tm_year + 1900);
            printf("Dias: %d\n", estadias[i].dias);
            printf("Valor total: R$ %.2f\n", estadias[i].valorTotal);
            printf("\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma estadia encontrada para o cliente %s.\n", clienteId);
    }
    pausaTela();
}

void pesquisarQuarto() {
    limpaTela();
    char quartoId[10];
    printf("Digite o ID do quarto: ");
    scanf("%9s", quartoId);
    getchar();
    int encontrado = 0;
    for (int i = 0; i < numEstadias; i++) {
        if (strcmp(estadias[i].quartoId, quartoId) == 0) {
            printf("Cliente ID: %s\n", estadias[i].clienteId);
            printf("Numero de hospedes: %d\n", estadias[i].numHospedes);
            printf("Data de entrada: %02d/%02d/%04d\n", estadias[i].dataEntrada.tm_mday, estadias[i].dataEntrada.tm_mon + 1, estadias[i].dataEntrada.tm_year + 1900);
            printf("Data de saida: %02d/%02d/%04d\n", estadias[i].dataSaida.tm_mday, estadias[i].dataSaida.tm_mon + 1, estadias[i].dataSaida.tm_year + 1900);
            printf("Dias: %d\n", estadias[i].dias);
            printf("Valor total: R$ %.2f\n", estadias[i].valorTotal);
            printf("\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma estadia encontrada para o quarto %s.\n", quartoId);
    }
    pausaTela();
}

int main() {
    char opcao;
    while (1) {
        limpaTela();
        printf(" *Seja Bem Vindo ao Hotel Descanso Garantido! Nosso objetivo é atender cordialmente nossos clientes! Venha nos visitar, estamos localizados no centro de Itacaré – BA.*\n");
        printf("\n Escolha uma das seguintes opções!\n");
        printf(" \n-Cliente(C)\n-Funcionário(F)\n-Pesquisar(P)\n");
        scanf(" %c", &opcao);
        getchar();
        if (opcao == 'C' || opcao == 'c') {
            limpaTela();
            printf("1. Cadastrar\n2. Voltar\n");
            int escolha;
            scanf("%d", &escolha);
            getchar();
            if (escolha == 1) {
                cadastrarCliente();
            }
        } else if (opcao == 'F' || opcao == 'f') {
            limpaTela();
            printf("1. Recepcionista\n2. Auxiliar de Limpeza\n3. Garcom\n4. Gerente\n");
            int escolha;
            scanf("%d", &escolha);
            getchar();
            cadastrarFuncionario(escolha);
        } else if (opcao == 'P' || opcao == 'p') {
            limpaTela();
            printf("1. Pesquisar Cliente\n2. Pesquisar Funcionario\n3. Mostrar estadias de um cliente\n4. Dar baixa em estadia\n5. Pesquisar Quarto\n6. Sair\n");
            int escolha;
            scanf("%d", &escolha);
            getchar();
            switch (escolha) {
                case 1:
                    pesquisarCliente();
                    break;
                case 2:
                    pesquisarFuncionario();
                    break;
                case 3:
                    mostrarEstadiasCliente();
                    break;
                case 4:
                    darBaixaEstadia();
                    break;
                case 5:
                    pesquisarQuarto();
                    break;
                case 6:
                    exit(0);
            }
        }
    }
    return 0;
}
