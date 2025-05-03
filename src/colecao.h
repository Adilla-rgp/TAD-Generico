#ifndef COLECAO_H
#define COLECAO_H
#define CAPACIDADE_INICIAL 10 // Número inicial de discos na coleção 

typedef struct {
    char nomeDoDisco[30];
    int numeroDeMusicas;
    float notaDoAlbum;
} Disco;

typedef struct {
    Disco *discos; // Vetor dinâmico para armazenar os discos
    int capacidade;
    int tamanho;   // Quantidade atual de discos
} Colecao;


Colecao* criarColecao(int capacidade);
 


#endif 
