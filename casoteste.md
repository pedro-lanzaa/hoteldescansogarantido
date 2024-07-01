# Planejamento dos Casos de Teste

| Entradas     | Classes Válidas | Resultado Esperado                       | Classes Inválidas                             | Resultado Esperado       |
|--------------|-----------------|------------------------------------------|-----------------------------------------------|--------------------------|
| Data         | Datas válidas a partir de 2024 | Data aceita                               | Datas anteriores a 2024, dias, meses ou anos inválidos | Solicitar nova data       |
| Hóspedes     | Número entre 1 e 6  | Número aceito                            | Número menor que 1 ou maior que 6               | Solicitar novo número de hóspedes |
| Cliente      | ID ou nome existente | Exibir informações do cliente          | ID ou nome inexistente                           | Cliente não encontrado    |
| Quarto       | ID existente       | Exibir informações do quarto            | ID inexistente                                  | Quarto não encontrado     |
| Funcionário  | ID ou nome existente | Exibir informações do funcionário      | ID ou nome inexistente                           | Funcionário não encontrado|

## Procedimento de Teste
- Inserir dados válidos e verificar se o sistema aceita.
- Inserir dados inválidos e verificar se o sistema rejeita e solicita nova entrada.
- Verificar a contagem de dias e cálculo do valor da estadia.

## Saídas Esperadas
- Sucesso na inserção de dados válidos.
- Mensagens de erro e solicitação de nova entrada para dados inválidos.
- Correta contagem de dias e cálculo do valor total da estadia.

