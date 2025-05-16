#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"

// Cria uma nova coleção, alocando espaço para o array de discos
Colecao *criarColecao(int capacidadeInicial)
{
    Colecao *c = (Colecao *)malloc(sizeof(Colecao));
    if (c == NULL)
        return NULL;

    c->elementos = (Disco *)malloc(sizeof(Disco) * capacidadeInicial);
    if (c->elementos == NULL)
    {
        free(c);
        return NULL;
    }

    c->tamanho = 0;
    c->capacidade = capacidadeInicial;
    return c;
}

// Função para inserir um disco na coleção
// Se a coleção estiver cheia, realoca o array aumentando a capacidade
int inserirDisco(Colecao *colecao, Disco d)
{
    if (colecao->tamanho == colecao->capacidade)
    {
        int novaCapacidade = colecao->capacidade * 2;
        Disco *novoArray = (Disco *)realloc(colecao->elementos, sizeof(Disco) * novaCapacidade);
        if (novoArray == NULL)
            return 0; // Falha ao alocar memória

        colecao->elementos = novoArray;
        colecao->capacidade = novaCapacidade;
    }

    colecao->elementos[colecao->tamanho++] = d; // Insere e incrementa tamanho
    return 1; // Sucesso
}

// Remove um disco do índice informado
int removerDisco(Colecao *colecao, int indice)
{
    if (indice < 0 || indice >= colecao->tamanho)
        return 0; // Índice inválido

    // Desloca todos discos após o índice uma posição para trás
    for (int i = indice; i < colecao->tamanho - 1; i++)
    {
        colecao->elementos[i] = colecao->elementos[i + 1];
    }

    colecao->tamanho--;
    return 1;
}

// Procura por um disco pelo nome na coleção e retorna ponteiro para ele
Disco *consultarDisco(Colecao *colecao, const char *nomeDoDisco)
{
    for (int i = 0; i < colecao->tamanho; i++)
    {
        if (strcmp(colecao->elementos[i].nomeDoDisco, nomeDoDisco) == 0)
            return &(colecao->elementos[i]);
    }
    return NULL; // Não encontrado
}

// Retorna uma cópia do array de discos e o tamanho via parâmetro
Disco *listarDiscos(Colecao *colecao, int *tamanho)
{
    if (colecao->tamanho == 0)
    {
        *tamanho = 0;
        return NULL;
    }

    // Aloca novo array para retorno
    Disco *lista = (Disco *)malloc(sizeof(Disco) * colecao->tamanho);
    if (lista == NULL)
    {
        *tamanho = 0;
        return NULL;
    }

    memcpy(lista, colecao->elementos, sizeof(Disco) * colecao->tamanho);
    *tamanho = colecao->tamanho;
    return lista;
}

// Remove todos os discos da coleção (tamanho volta a zero)
void esvaziarColecao(Colecao *colecao)
{
    colecao->tamanho = 0;
}

// Retorna o tamanho atual da coleção
int obterTamanho(Colecao *colecao)
{
    return colecao->tamanho;
}
