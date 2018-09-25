#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "menu.h"
#include "BTree.h"

int BTree()
{
    bTree b;
    int i ,option ,valor;

    FILE *arquivo;

    ///b = bTree_Create();

    do{
        printf("\n1 - INSERIR\n");
        printf("2 - REMOCAO\n");
        printf("3 - CONTAR TOTOS OS ELEMENTOS DA ARVORE B\n");
        printf("4 - CONTAR AS FOLHAS DA ARVORE B\n");
        printf("5 - VERIFICAR A ALTURA DA ARVORE B\n");
        printf("6 - VERIFICAR O MAIOR ELEMENTO DA ARVORE B\n");
        printf("7 - VERIFICAR O MENOR ELEMENTO DA ARVORE B\n");
        printf("8 - LER ARQUIVO VALUES.TXT\n");
        printf("11 - IMPRIMIR A ARVORE B EM FORMA DE ARVORE\n");
        printf("22 - IMPRIMIR A ARVORE B\n");
        printf("33 - CRIA A ARVORE B <<<<<<<<<<<<< (CRIE A ARVORE PRIMEIRO) \n");
        printf("0 - SAIR\n\n");

        scanf("%d",&option);
        printf("\n");

        switch(option)
        {
        case 1:
            printf("Digite o valor a ser inserido: \n");
            scanf("%d",&valor);
            bTree_Insert(b ,valor);
            printf("\n\n");
            break;

        case 2:
            printf("not working ); \n");
            break;

        case 3:
            printf("Total de Elementos na Arvore B : %d <\n",bTree_Count_All(b));
            break;

        case 4:
            printf("Total de Folhas da Arvore B : %d <\n",bTree_Count_Leaf(b));
            break;

        case 5:
            printf("Altura da Arvore B : %d <\n",bTree_Height(b));
            break;

        case 6:
            printf("Maior Elemento da Arvore B : %d <\n",bTree_MAX(b));
            break;

        case 7:
            printf("Menor Elemento da Arvore B : %d <\n",bTree_MIN(b));
            break;

        case 8:
            printf("Lendo Arquivo . . . \n");
            Btree_Read_File(b);
            break;

        case 11:
            bTree_Print_Keys_TreeMode(b);
            break;

        case 22:
            Btree_Print_Keys(b);
            break;

        case 33:
            b = bTree_Create();
            break;

        }


    }while(option != 0);

    //bTree_Destroy(b);
    return 0;
}
