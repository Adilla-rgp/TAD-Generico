#include <stdlib.h>
#include "colecao.h"
#include "string.h"
#include <stdio.h>

Colecao* criarColecao(int capacidade) {
    Colecao *nova = (Colecao*)malloc(sizeof(Colecao)); 
    if (nova == NULL) {
        return NULL; 
    }
    
    nova->discos = (Disco*)malloc(capacidade * sizeof(Disco));
    if (nova->discos == NULL) {
        free(nova); // Libera a memória alocada para evitar vazamento
        return NULL; 
    }

    nova->capacidade = capacidade;
    nova->tamanho = 0; 

    return nova;
}

int inserirDisco(Colecao *c, Disco d){
    if(c == NULL || c->tamanho >= c->capacidade){
        return 0; 
    }
    c->discos[c->tamanho] = d;
    c->tamanho++;
    return 1; 
} 

int removerDisco(Colecao* c, int indice) {
    if (c == NULL || indice < 0 || indice >= c->tamanho) {
        return 0;
    }

    // Desloca os elementos para preencher o espaço do disco removido
    for (int i = indice; i < c->tamanho - 1; i++) {
        c->discos[i] = c->discos[i + 1];
    }

    c->tamanho--;
    return 1;
}
int obterTamanho(Colecao* c) {
    if (c == NULL) {
        return 0;
    }
    return c->tamanho;
}

Disco obterDisco(Colecao* c, int indice) {
    if (c == NULL || indice < 0 || indice >= c->tamanho) {
        Disco discoVazio = {"", 0, 0.0}; // Disco vazio para erro
        return discoVazio;
    }
    return c->discos[indice];
}

// Função que retorna um array com os discos, para ser usado no main.c
Disco* listarDiscos(Colecao* c, int* tamanho) {
    *tamanho = obterTamanho(c);  // Passa o tamanho da coleção para o ponteiro
    if (*tamanho == 0) {
        return NULL;
    }
    return c->discos;  // Retorna o array de discos
}

Disco* consultarDisco(Colecao* c, const char* nomeDoDisco) {
    if (c == NULL || c->tamanho == 0) {
        return NULL;  // Coleção vazia
    }

    for (int i = 0; i < c->tamanho; i++) {
        if (strcmp(c->discos[i].nomeDoDisco, nomeDoDisco) == 0) {
            return &c->discos[i];  // Disco encontrado
        }
    }

    return NULL;  // Disco não encontrado
}
void esvaziarColecao(Colecao* c) {
    if (c != NULL) {
        // Libera a memória dos discos
        free(c->discos);
        c->discos = NULL;
        c->tamanho = 0;  // Redefine o tamanho da coleção para 0
    }
}
