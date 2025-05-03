#include <stdlib.h>
#include "colecao.h"

Colecao* criarColecao(int capacidade){
    Colecao *nova = (int*)malloc(sizeof(Colecao)); 
    if(nova == NULL){
        return NULL; 
    }
    nova->discos = (Disco*)malloc(sizeof(Disco));
    if(nova->discos == NULL){
        return NULL; 
    }
    nova->capacidade = capacidade;
    nova->tamanho = 0; 
}