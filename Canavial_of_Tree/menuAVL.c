#include <stdlib.h>
#include <stdio.h>

#include "menu.h"
#include "avl.h"

int avl()
{
    int vrau=0;
    int op;
    int numero;
    struct Node *root = NULL; ///AVL
    FILE *arquivoGravadoAVL;

    do{
            printf(">>>>>> AVL - Balanced Binary Search Tree <<<<<\n");
            printf("1 - Insert\n");
            printf("2 - Delete\n");
            printf("3 - Search\n");
            printf("4 - PERCURSO - IN Order\n");
            printf("5 - PERCURSO - PRE Order\n");
            printf("6 - RECORD - POS Order\n");
            printf("7 - COUNT - All Elements\n");
            printf("8 - COUNT - All Leafs\n");
            printf("9 - VERIFY - The Height of the Tree\n");
            printf("11 - VERFIFY - The Higher Value\n");
            printf("22 - VERIFY - The Lower Value\n");
            printf("33 - READ - VALUES.TXT\n");
            printf("0 - EXIT\n");
            printf(">");
            scanf("%i",&op);

            switch(op)
            {
                case 1:
                printf("\nValue: ");
                scanf("%d",&numero);
                root = insert(root, numero);


                break;

                case 2:
                printf("\nValue: ");
                scanf("%d",&numero);
                root = deleteNode(root ,numero);


                break;

                case 3:
                printf("\nValue: ");
                scanf("%d",&numero);
                root = search(root, numero);


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


                fclose(arquivoGravadoAVL);
                break;

                case 7:
                vrau = countElement(root);
                printf("\nTotal of Elements: %d\n",vrau);
                break;

                case 8:
                vrau = countLeaf(root);
                printf("\nTotal of Leafs: %d\n",vrau);
                break;

                case 9:
                vrau = heightTree(root);
                printf("\nTree Height: %d\n",vrau);
                break;

                case 10:
                printf("\n ERRRRROU (voz do faustao.mp3)\n");
                break;

                case 11:
                vrau = higherElement(root);
                printf("\nHigher Element: %d\n",vrau);
                break;

                case 22:
                vrau = smallerElement(root);
                printf("\nLower Element: %d\n",vrau);
                break;

                case 33:
                root = ler_arquivoAVL(root);
                printf("\nFile Read\n");
                break;

                case 0:
                    break;

                default:
                    printf("\nWrong way little grasshopper\n");
            }

    }while(op!=0);

    return 0;
}

