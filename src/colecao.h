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
int inserirDisco(Colecao *c, Disco d);
int removerDisco(Colecao *c, int indice); 
int obterTamanho(Colecao* c);
Disco obterDisco(Colecao* c, int indice);
Disco* listarDiscos(Colecao* c, int* tamanho); 
Disco* consultarDisco(Colecao* c, const char* nomeDoDisco); 
void esvaziarColecao(Colecao* c); 

 


#endif 
