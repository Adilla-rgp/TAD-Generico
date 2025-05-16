#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

void exibirMenu()
{
    printf("\n ===== Menu ===== \n");
    printf("1 - Criar Colecao\n");
    printf("2 - Inserir elementos\n");
    printf("3 - Remover elementos\n");
    printf("4 - Consultar elementos\n");
    printf("5 - Listar elementos\n");
    printf("6 - Esvaziar colecao\n");
    printf("7 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main()
{
    int opcao;
    Colecao *minhaColecao = NULL;  // Ponteiro para a coleção, inicialmente NULL

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado após leitura

        switch (opcao)
        {
        case 1:
            // Criar a coleção se ainda não existir
            if (minhaColecao != NULL)
            {
                printf("Colecao ja foi criada anteriormente.\n");
            }
            else
            {
                minhaColecao = criarColecao(CAPACIDADE_INICIAL);
                if (minhaColecao != NULL)
                    printf("Colecao criada com sucesso!\n");
                else
                    printf("Erro ao criar a colecao.\n");
            }
            break;

        case 2:
            // Inserir um novo disco na coleção
            if (minhaColecao == NULL)
            {
                printf("Crie a colecao primeiro.\n");
                break;
            }
            else
            {
                Disco d;
                printf("Nome do disco: ");
                scanf(" %[^\n]", d.nomeDoDisco); // Lê linha com espaços
                printf("Numero de musicas: ");
                scanf("%d", &d.numeroDeMusicas);
                printf("Nota do album: ");
                scanf("%f", &d.notaDoAlbum);

                if (inserirDisco(minhaColecao, d))
                    printf("Disco inserido com sucesso!\n");
                else
                    printf("Erro ao inserir disco.\n");
            }
            break;

        case 3:
            // Remover disco pelo índice informado
            if (minhaColecao == NULL || obterTamanho(minhaColecao) == 0)
            {
                printf("Colecao vazia ou nao criada.\n");
                break;
            }
            else
            {
                int indice;
                printf("Informe o indice do disco a remover: ");
                scanf("%d", &indice);
                getchar(); // Limpa buffer

                if (removerDisco(minhaColecao, indice))
                    printf("Disco removido com sucesso.\n");
                else
                    printf("Indice invalido.\n");
            }
            break;

        case 4:
            // Consultar disco pelo nome
            if (minhaColecao == NULL || obterTamanho(minhaColecao) == 0)
            {
                printf("Colecao vazia ou nao criada.\n");
                break;
            }
            else
            {
                char nomeDoDisco[100];
                printf("Informe o nome do disco a consultar: ");
                scanf(" %[^\n]", nomeDoDisco);

                Disco *disco = consultarDisco(minhaColecao, nomeDoDisco);

                if (disco != NULL)
                {
                    printf("\n----- Disco encontrado! -----\n");
                    printf("Nome: %s\n", disco->nomeDoDisco);
                    printf("Numero de musicas: %d\n", disco->numeroDeMusicas);
                    printf("Nota do album: %.1f\n", disco->notaDoAlbum);
                    printf("\n-----------------------------\n");
                }
                else
                {
                    printf("\n----- O disco não foi encontrado na coleção -----\n");
                    printf("Verifique se o nome está correto e tente novamente.\n");
                    printf("\n-------------------------------------------------\n");
                }
            }
            break;

        case 5:
            // Listar todos os discos da coleção
            if (minhaColecao == NULL || obterTamanho(minhaColecao) == 0)
            {
                printf("Colecao vazia.\n");
            }
            else
            {
                int tamanho = 0;
                Disco *discos = listarDiscos(minhaColecao, &tamanho);
                if (discos != NULL)
                {
                    printf("\n===== Minha Biblioteca Musical ======\n");
                    for (int i = 0; i < tamanho; i++)
                    {
                        printf("Disco %d:\n", i + 1);
                        printf("Nome: %s\n", discos[i].nomeDoDisco);
                        printf("Numero de musicas: %d\n", discos[i].numeroDeMusicas);
                        printf("Nota do album: %.1f\n", discos[i].notaDoAlbum);
                        printf("-----------------------------\n");
                    }
                    free(discos); // Libera memória alocada para lista de discos
                    printf("\n===== Discos listados com sucesso! =====\n");
                }
                else
                {
                    printf("Erro ao listar discos.\n");
                }
            }
            break;

        case 6:
            // Esvaziar todos os discos da coleção (mas mantém a coleção criada)
            if (minhaColecao == NULL)
            {
                printf("Colecao não criada.\n");
            }
            else
            {
                esvaziarColecao(minhaColecao);
                printf("Colecao esvaziada com sucesso.\n");
            }
            break;

        case 7:
            // Sair do programa
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente...\n");
            break;
        }
    } while (opcao != 7);

    // Limpa toda a memória usada pela coleção antes de sair
    if (minhaColecao != NULL)
    {
        esvaziarColecao(minhaColecao);
        free(minhaColecao->elementos);
        free(minhaColecao);
    }

    return 0;
}
