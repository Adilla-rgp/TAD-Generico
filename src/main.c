// src/main.c
#include <stdio.h>
#include "colecao.h"

/*1 - Crie uma coleção
2 - Insira tres elementos na coleção
3- Liste os elementos da Colecao
4 - Consulte um dos elementos da coleçào
5 - remova o segundo elemento inserido na colecao
6- Liste os elementos da coleçào
7 - Esvazie a colecao
8- Liste os elementos da coleçào*/

void exibirMenu(){
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

int main() {
    int opcao;

    do{
        exibirMenu();
        scanf("%d", &opcao);
        
        while (getchar() != '\n');

        switch (opcao){
            case 1:
            printf("Colecao criada.\n");
            break;
            
            case 2:
            printf("Elemento inserido.\n");
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
    
    return 0; 
}
