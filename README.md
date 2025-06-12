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
