# 🧠 PUSH_SWAP

## 📚 Descrição

**`push_swap`** é um projeto do currículo da 42 que consiste em desenvolver um programa capaz de ordenar uma sequência de inteiros com um conjunto restrito de operações em duas pilhas (`stack a` e `stack b`). O objetivo é ordenar os números utilizando o **menor número possível de operações**, respeitando regras rígidas.

---

## 🚀 Como funciona?

O programa recebe como argumento uma lista de números inteiros, constrói uma pilha (`stack a`) e, opcionalmente, utiliza uma pilha auxiliar (`stack b`) para organizar os elementos com as operações permitidas:

- `sa`, `sb`, `ss` — swap
- `pa`, `pb` — push
- `ra`, `rb`, `rr` — rotate
- `rra`, `rrb`, `rrr` — reverse rotate

O resultado é uma **sequência de comandos** impressa na `stdout`, que, se executada, ordena a pilha inicial.

---

## 🧠 Estratégia de Ordenação

O projeto implementa uma estratégia adaptativa:

- **Para 2 a 5 elementos**: algoritmos manuais otimizados.
- **Para mais de 5 elementos**: 
  - Algoritmo de **chunking** (divisão por faixas de índices)
  - Push para `stack b` com base no valor/index
  - Ordenação e reintegração dos elementos na `stack a`

---

## 📁 Estrutura do Projeto

```bash
push_swap/
├── README.md               # Documentação do projeto
├── Makefile                # Compilação automatizada
├── includes/               # Arquivos de cabeçalho
│   └── push_swap.h
├── libft/                  # Biblioteca libft pessoal (reutilizada)
│   └── *.c / *.h
├── src/                    # Código-fonte principal
│   ├── main.c              # Entrada principal
│   ├── push_swap.c         # Lógica principal de controle
│
│   ├── algorithm/          # Estratégias de ordenação
│   │   ├── two_algo.c
│   │   ├── three_sort_algo.c
│   │   ├── five_sort_algo.c
│   │   └── high_sort_algo.c
│
│   ├── basic_operations/   # Operações permitidas no projeto
│   │   ├── ft_push_a_b.c
│   │   ├── ft_rotate.c
│   │   ├── ft_reverse_rotate.c
│   │   └── ft_swap.c
│
│   ├── parse_functions/    # Validação e parsing de argumentos
│   │   └── parse_func.c
│
│   └── utils/              # Funções auxiliares
│       ├── general_utils.c
│       ├── parse_utils/
│       └── sorting_utils/

```
---

## 🧠 Lógica de Implementação

### 🔹 Parsing

Arquivo: `parse_func.c`  
Responsável por:
- Validar os argumentos recebidos (formato, limites, duplicatas)
- Converter strings para inteiros
- Inicializar a pilha `a`

### 🔹 Operações Básicas

Pasta: `basic_operations/`  
Cada operação (`swap`, `push`, `rotate`, `reverse rotate`) foi implementada separadamente com foco em modularidade e reutilização.

### 🔹 Algoritmos de Ordenação

Pasta: `algorithm/`  
Cada cenário tem uma abordagem própria:
- `two_algo.c`: para 2 elementos
- `three_sort_algo.c`: para 3 elementos (com lógica mínima ótima)
- `five_sort_algo.c`: para 4 e 5 elementos
- `high_sort_algo.c`: para listas maiores (chunk sorting)

### 🔹 Utilitários

Pasta: `utils/`  
- `general_utils.c`: funções genéricas auxiliares (ex: verificação de ordenação, cálculo de posição)
- `parse_utils/` e `sorting_utils/`: funções de apoio específicas para cada etapa

---

## 🏗️ Compilação

```bash
make
```
---

## 🧪 Como Testar o Projeto

Aqui estão alguns comandos úteis para testar a execução e a eficiência do `push_swap`:

---

### ✅ 1. Verificar se a saída ordena corretamente (com checker)

Se você tiver o `checker` da 42 (projeto `checker` compilado):

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
# Esperado: OK
```

```b̀ash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```
