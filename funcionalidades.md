# Documentação das Funcionalidades do Software

## Funções

### void limpaTela()
- Descrição: Limpa a tela do console.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### void pausaTela()
- Descrição: Exibe uma mensagem para pressionar Enter antes de continuar.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### int validarData(int dia, int mes, int ano)
- Descrição: Verifica se uma data é válida com base no dia, mês e ano fornecidos.
- Parâmetros de Entrada: `int dia`, `int mes`, `int ano`
- Saída: `int` (1 se a data for válida, 0 caso contrário).

### int calcularDiferencaDias(struct tm dataEntrada, struct tm dataSaida)
- Descrição: Calcula a diferença em dias entre duas datas.
- Parâmetros de Entrada: `struct tm dataEntrada`, `struct tm dataSaida`
- Saída: `int` (diferença em dias).

### int contarQuartosDisponiveis(struct tm dataEntrada, struct tm dataSaida)
- Descrição: Conta o número de quartos disponíveis entre duas datas.
- Parâmetros de Entrada: `struct tm dataEntrada`, `struct tm dataSaida`
- Saída: `int` (número de quartos disponíveis).

### void cadastrarCliente()
- Descrição: Adiciona um novo cliente ao sistema após validar CEP e telefone.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### void cadastrarFuncionario(int cargo)
- Descrição: Adiciona um novo funcionário ao sistema após validar telefone.
- Parâmetros de Entrada: `int cargo`
- Saída: Nenhuma.

### float calcularValorDiaria(int numHospedes)
- Descrição: Calcula o valor da diária com base no número de hóspedes.
- Parâmetros de Entrada: `int numHospedes`
- Saída: `float` (valor da diária).

### void cadastrarEstadia(char clienteId[])
- Descrição: Registra uma nova estadia para um cliente existente.
- Parâmetros de Entrada: `char clienteId[]`
- Saída: Nenhuma.

### void darBaixaEstadia()
- Descrição: Encerra uma estadia e libera o quarto.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### void pesquisarCliente()
- Descrição: Busca e exibe informações detalhadas de um cliente.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### void pesquisarFuncionario()
- Descrição: Busca e exibe informações detalhadas de um funcionário.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### void mostrarEstadiasCliente()
- Descrição: Exibe todas as estadias de um cliente específico.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.

### void pesquisarQuarto()
- Descrição: Busca e exibe informações detalhadas de um quarto.
- Parâmetros de Entrada: Nenhum.
- Saída: Nenhuma.
