# Simulated Annealing para o Problema da Mochila (Knapsack Problem)

Este projeto implementa o algoritmo de Simulated Annealing (SA) para resolver o problema da mochila, um problema de otimização combinatória clássico onde o objetivo é maximizar o valor total dos itens selecionados sem exceder a capacidade da mochila.

## Como Funciona

### Problema da Mochila
- Dado um conjunto de itens, cada um com peso e valor.
- Capacidade máxima da mochila.
- Selecionar um subconjunto de itens que maximize o valor total sem exceder a capacidade.

### Simulated Annealing
O SA é uma meta-heurística inspirada no processo de recozimento de metais:
1. **Inicialização**: Solução inicial aleatória (vetor binário indicando itens selecionados).
2. **Geração de Vizinhos**: Troca aleatória de um bit (incluir/excluir item).
3. **Avaliação**: Calcula função objetivo (valor total, penalizando excesso de peso).
4. **Aceitação**: Aceita soluções melhores sempre; soluções piores com probabilidade `exp(-ΔE/T)`.
5. **Resfriamento**: Reduz temperatura gradualmente até temperatura final.
6. **Critério de Parada**: Temperatura mínima ou máximo de iterações.

### Parâmetros do SA
- `temp_inicial`: Temperatura inicial (alta para aceitar muitas mudanças).
- `temp_final`: Temperatura final (baixa para convergir).
- `alpha`: Taxa de resfriamento (fator de redução da temperatura).
- `SAmax`: Máximo de iterações por nível de temperatura.

## Estrutura do Código

- `main.cpp`: Programa principal que lê entrada, inicializa e executa SA.
- `SA.cpp`: Implementação do algoritmo SA.
- `SA.h`: Cabeçalho com declarações de funções.
- `entrada.txt`: Arquivo de entrada com dados do problema.
- `Makefile`: Script para compilação.

## Como Rodar

### Pré-requisitos
- Compilador C++ (g++).
- Sistema Linux/Mac/Windows com terminal.

### Passos
1. **Compilar**:
   ```bash
   make
   ```

2. **Executar**:
   ```bash
   ./mochila
   ```

3. **Resultado**:
   - Imprime a solução final (itens escolhidos: 0 ou 1 para cada item).
   - O valor ótimo é calculado internamente.

### Arquivo de Entrada (entrada.txt)
Formato:
```
n capacidade
peso1 valor1
peso2 valor2
...
peson valorn
```

Exemplo:
```
5 10
2 6
4 10
3 7
5 12
1 2
```
- 5 itens, capacidade 10.
- Itens: (peso=2, valor=6), (4,10), (3,7), (5,12), (1,2).

### Modificar Parâmetros
No `main.cpp`, ajuste os parâmetros do SA:
```cpp
float melhor = SimulatedAnnealing(n, s, peso, valor, capacidade,
                                  1000.0f,  // temp_inicial
                                  0.01f,    // temp_final
                                  0.95f,    // alpha
                                  200);     // SAmax
```

### Limpar
```bash
make clean
```

## Exemplo de Saída
```
Itens escolhidos: 1 0 1 1 1
```
Significa: itens 1,3,4,5 selecionados (índice 0-based).

## Notas
- Solução inicial é aleatória.
- Função objetivo penaliza excesso de peso com valor negativo.
- Logs detalhados podem ser adicionados para debug.
