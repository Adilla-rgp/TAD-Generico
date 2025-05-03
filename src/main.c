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
    Colecao *minhaColecao = NULL; // Definindo minhaColecao como ponteiro para Colecao

    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        while (getchar() != '\n')
            ; // Limpa o buffer do teclado

        switch (opcao)
        {
        case 1:
            if (minhaColecao != NULL)
            {
                printf("Colecao ja foi criada anteriormente.\n");
            }
            else
            {
                minhaColecao = criarColecao(CAPACIDADE_INICIAL); // Cria a coleção com capacidade inicial
                if (minhaColecao != NULL)
                {
                    printf("Colecao criada com sucesso!\n");
                }
                else
                {
                    printf("Erro ao criar a colecao.\n");
                }
            }
            break;

        case 2:
            if (minhaColecao == NULL)
            {
                printf("Crie a coleção primeiro.\n");
                break;
            }

            Disco d;
            printf("Nome do disco: ");
            scanf(" %[^\n]", d.nomeDoDisco);
            printf("Numero de musicas: ");
            scanf("%d", &d.numeroDeMusicas);
            printf("Nota do album: ");
            scanf("%f", &d.notaDoAlbum);

            if (inserirDisco(minhaColecao, d))
            {
                printf("Disco inserido com sucesso!\n");
            }
            else
            {
                printf("Erro ao inserir disco.\n");
            }
            break;

        case 3:
            printf("Elemento removido.\n");
            break;

        case 4:
            printf("Elemento consultado.\n");
            break;

        case 5:
            printf("Listando elementos...\n");
            break;

        case 6:
            printf("Colecao esvaziada.\n");
            break;

        case 7:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente...\n");
            break;
        }

    } while (opcao != 7);

    // Liberando a memória da coleção ao final
    if (minhaColecao != NULL)
    {
        free(minhaColecao->discos);
        free(minhaColecao);
    }

    return 0;
}
