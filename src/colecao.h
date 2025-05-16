#ifndef COLECAO_H
#define COLECAO_H

#define CAPACIDADE_INICIAL 10

// Definição do tipo Disco, representando um álbum musical
typedef struct
{
    char nomeDoDisco[100];
    int numeroDeMusicas;
    float notaDoAlbum;
} Disco;

// Definição da coleção, que armazena múltiplos discos dinamicamente
typedef struct
{
    Disco *elementos;  // ponteiro para array dinâmico de discos
    int tamanho;       // número atual de discos armazenados
    int capacidade;    // capacidade máxima atual do array
} Colecao;

// Função que cria uma coleção com capacidade inicial definida
Colecao *criarColecao(int capacidadeInicial);

// Insere um disco na coleção, redimensionando se necessário
int inserirDisco(Colecao *colecao, Disco d);

// Remove um disco pelo índice; retorna 1 se sucesso, 0 se índice inválido
int removerDisco(Colecao *colecao, int indice);

// Consulta um disco pelo nome; retorna ponteiro para disco ou NULL se não encontrado
Disco *consultarDisco(Colecao *colecao, const char *nomeDoDisco);

// Lista todos os discos, retornando um array copiado e o tamanho via parâmetro
Disco *listarDiscos(Colecao *colecao, int *tamanho);

// Esvazia a coleção, removendo todos os discos (mas não desaloca a estrutura)
void esvaziarColecao(Colecao *colecao);

// Retorna o número de discos atualmente armazenados
int obterTamanho(Colecao *colecao);

#endif
