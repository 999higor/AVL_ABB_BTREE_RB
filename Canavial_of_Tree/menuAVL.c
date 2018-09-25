#include <stdlib.h>
#include <stdio.h>

#include "avl.h"

int avl()
{
    int vrau=0;
    int op;
    int numero;
    struct Node *root = NULL; ///AVL
    FILE *arquivoGravadoAVL;

    do{
            printf("--------------------------------------");
            printf("\n1 - INSERCAO\n");
            printf("2 - REMOCAO\n");
            printf("3 - BUSCA\n");
            printf("4 - PERCURSO EM ORDEM\n");
            printf("5 - PERCURSO  EM PRE-ORDEM\n");
            printf("6 - PERCURSO EM POS-ORDEM (GRAVACAO)\n");
            printf("7 - VERIFICAR QUANTIDADE DE ELEMENTOS\n");
            printf("8 - VERIFICAR QUANTIDADE DE FOLHAS\n");
            printf("9 - VERIFICAR A ALTURA DA ARVORE\n");
            printf("11 - VERIFICAR MAIOR ELEMENTO\n");
            printf("12 - VERIFICAR MENOR ELEMENTO\n");
            printf("13 - LER ARQUIVO\n");
            printf("0 - SAIR\n");
            printf("--------------------------------------\n");

            scanf("%i",&op);

            switch(op)
            {
                case 1:
                printf("\ndigite o numero: ");
                scanf("%d",&numero);
                root = insert(root, numero);
                printf("valor inserido\n");

                break;

                case 2:
                printf("\ndigite o numero: ");
                scanf("%d",&numero);
                root = deleteNode(root ,numero);
                printf("valor removido\n");

                break;

                case 3:
                printf("\ndigite o numero: ");
                scanf("%d",&numero);
                root = search(root, numero);
                printf("valor encontrado\n");

                break;

                case 4:
                inOrder(root);

                break;

                case 5:
                preOrder(root);

                break;

                case 6:
                arquivoGravadoAVL = fopen("arquivoGravadoAVL.txt" ,"w");
                postOrder(root ,arquivoGravadoAVL);

                printf("gravado com sucesso xd xd\n");

                fclose(arquivoGravadoAVL);
                break;

                case 7:
                vrau = countElement(root);
                printf("\ntotal de elementos: %d\n",vrau);
                break;

                case 8:
                vrau = countLeaf(root);
                printf("\ntotal de folhas: %d\n",vrau);
                break;

                case 9:
                vrau = heightTree(root);
                printf("\naltura da arvore: %d\n",vrau);
                break;

                case 10:
                printf("\n ERRRRROU (voz do faustao.mp3)\n");
                break;

                case 11:
                vrau = higherElement(root);
                printf("\nmaior elemento: %d\n",vrau);
                break;

                case 12:
                vrau = smallerElement(root);
                printf("\nmenor elemento: %d\n",vrau);
                break;

                case 13:
                root = ler_arquivoAVL(root);
                printf("\nArquivo lido com sucesso xd xd\n");
                break;
            }

    }while(op!=0);

    return 0;
}

