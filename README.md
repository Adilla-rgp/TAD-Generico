# Trabalho de Estrutura de Dados  
## Implementação de um TAD Coleção Genérica de Discos

Este projeto implementa um **Tipo Abstrato de Dados (TAD) Coleção Genérica** em linguagem C, permitindo armazenar e manipular elementos de qualquer tipo definido pelo usuário, por meio de uma API genérica e modularizada.

Como exemplo, utilizamos o tipo `Disco`, que possui os seguintes campos:

- `char nomeDoDisco[100]` — nome do disco;  
- `int numeroDeMusicas` — número de músicas no disco;  
- `float notaDoAlbum` — nota do álbum.

---

## 1. Ambiente de Desenvolvimento

- **Sistema Operacional:** Windows 11  
- **Compilador:** MinGW (GCC para Windows)  
- **Bibliotecas externas:** Nenhuma

---

## 2. Estrutura dos Arquivos

O pacote contém:

- `README.md` — este documento;  
- `colecao.h` — declaração da API da coleção genérica;  
- `colecao.c` — implementação do TAD genérico (sem código de entrada/saída);  
- `main.c` — programa principal contendo a interface com o usuário e testes;  
- `main.exe` (ou `executavel.exe`) — arquivo compilado gerado.

---

## 3. Compilação e Execução

### No Linux/macOS:

```bash
gcc -o main.exe main.c colecao.c
./main.exe
```

### 3.2 Windows

```bash
gcc -o main.exe main.c colecao.c
./main.exe
```

---

## 4. Funcionalidades Implementadas e Testadas

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
- O trabalho é individual. 

---

## 6. Considerações Finais

Este trabalho demonstra a implementação de TADs genéricos em C, evidenciando organização, flexibilidade e reutilização. A separação entre a lógica do TAD e sua interface possibilita a adaptação fácil da coleção para outros tipos de dados.

---

## 7. Identificação

**Disciplina:** Estrutura de Dados 1
**Aluno:** Ádilla Roberta Gomes Pereira  
**Professor:** Anselmo Paiva  
**Data de Entrega:** 16 de maio de 2025

---
