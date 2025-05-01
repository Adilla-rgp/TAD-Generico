# Trabalho de Estrutura de Dados  
## Implementação de um TAD Coleção Genérica

Este projeto consiste na implementação de um **Tipo Abstrato de Dados (TAD) Coleção Genérica**, utilizando a linguagem de programação C. O TAD permite armazenar e manipular elementos de um tipo de dados definido pelo usuário, com uso de uma API genérica e modularizada.

O tipo adotado como exemplo neste trabalho é a estrutura `Aluno`, composta por três campos obrigatórios:

- Um campo `char[30]` (nome);
- Um campo `int` (matrícula);
- Um campo `float` (média).

---

## 1. Ambiente de Desenvolvimento

O código foi desenvolvido e testado nos seguintes ambientes:

- **Sistema Operacional:** Windows 11;  
- **Compilador:** MinGW (Windows);  
- **Bibliotecas externas:** Não foram utilizadas.

---

## 2. Estrutura dos Arquivos

O arquivo compactado entregue contém os seguintes itens:

- `README.md`: Este documento com orientações e informações do projeto;
- `colecao.c`: Implementação da lógica do TAD genérico (sem uso de entrada/saída);
- `colecao.h`: Arquivo de cabeçalho contendo a API da coleção;
- `main.c`: Programa principal contendo a execução dos testes exigidos;
- `executavel` ou `executavel.exe`: Arquivo binário gerado a partir da compilação.

---

## 3. Compilação e Execução

### 3.1 Linux/macOS

```bash
gcc -o executavel main.c colecao.c
./executavel
```

### 3.2 Windows

```bash
gcc -o executavel.exe main.c colecao.c
executavel.exe
```

---

## 4. Roteiro de Testes

Conforme solicitado, o programa implementa o seguinte roteiro de testes, presente no arquivo `main.c`:

1. Criação de uma coleção;
2. Inserção de três elementos do tipo `Aluno`;
3. Listagem de todos os elementos da coleção;
4. Consulta de um dos elementos por nome, matrícula e média;
5. Remoção do segundo elemento inserido;
6. Nova listagem da coleção;
7. Esvaziamento da coleção;
8. Listagem final, com a coleção vazia.

Todas as operações utilizam exclusivamente as funções definidas na API do TAD.

---

## 5. Restrições Atendidas

- O arquivo `colecao.c` não utiliza `printf`, `scanf` ou qualquer função de entrada/saída;
- A estrutura contém os campos obrigatórios (char[30], int e float);
- O código segue uma arquitetura modular, separando a lógica do TAD do programa principal;
- A API utilizada é única e respeita o padrão definido;
- O trabalho é individual, conforme especificado no enunciado.

---

## 6. Considerações Finais

Este trabalho demonstra o uso de TADs genéricos em C como ferramenta para a organização de dados de forma flexível e reaproveitável. A separação entre implementação e uso permite a reutilização da coleção com outros tipos de dados, bastando adaptar as funções auxiliares de comparação e exibição.

---

## 7. Identificação

**Disciplina:** Estrutura de Dados  
**Aluno:** Ádilla Roberta Gomes Pereira  
**Professor:** Anselmo Paiva  
**Data de Entrega:** 09 de maio

---
