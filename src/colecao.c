#include <stdlib.h>
#include "colecao.h"

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
