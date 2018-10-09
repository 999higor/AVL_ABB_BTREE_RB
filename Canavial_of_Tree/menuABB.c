#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "menu.h"
#include "abb.h"

int abb()
{
    int vrau=0, op ,numero ,teste;
    struct node *t = NULL; ///ABB
    FILE *arquivoGravado;

    clock_t t_inicial, t_final;
    double tempo=0;

    do{
            printf(">>>>> ABB - Binary Search Tree <<<<<\n");
            printf("1 - INSERT\n");
            printf("2 - DELETE\n");
            printf("3 - SEARCH\n");
            printf("4 - PRINT - IN Order\n");
            printf("5 - PRINT - PRE Order\n");
            printf("6 - RECORD - POS Order\n");
            printf("7 - COUNT - All Elements\n");
            printf("8 - COUNT - All Leafs\n");
            printf("9 - VERIFY - The Height of the Tree\n");
            printf("11 - VERFIFY - The Higher Value\n");
            printf("22 - VERIFY - The Lower Value\n");
            printf("33 - READ - VALUES.TXT\n");
            printf("44 - READ - SEARCH.TXT\n");
            printf("0 - EXIT\n");
            printf(">");
            scanf("%i",&op);

            switch(op)
            {
                case 1:
                printf("\nValue: ");
                scanf("%d",&numero);
                t = insere(t,numero);

                break;

                case 2:
                printf("\nValue: ");
                scanf("%d",&numero);

                t_inicial = clock();

                t = deletaNo(t,numero);

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Time Executation: %lf \n",tempo);


                break;

                case 3:
                printf("\nValue: ");
                scanf("%d",&numero);

                t_inicial = clock();

                printf("\nReturn: %d\n" ,procura(t,numero));

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("\nTime Executation: %lf \n",tempo);
                break;

                case 4:
                emOrdem(t);
                break;

                case 5:
                preOrdem(t);
                break;

                case 6:
                arquivoGravado = fopen("arquivoGravado.txt" ,"w");
                posOrdem(t ,arquivoGravado);

                fclose(arquivoGravado);
                break;

                case 7:
                vrau = contaElementos(t);
                printf("\nTotal of Elements: %d\n",vrau);
                break;

                case 8:
                vrau = contaFolhas(t);
                printf("\nTotal of Leafs: %d\n",vrau);
                break;

                case 9:
                vrau = alturaArvore(t);
                printf("\nTree Height: %d\n",vrau);
                break;

                case 10:
                printf("\n ERRRRROU (voz do faustao.mp3)\n");
                break;

                case 11:
                vrau = maiorElemento(t);
                printf("\nHigher Element: %d\n",vrau);
                break;

                case 22:
                vrau = menorElemento(t);
                printf("\nLower Element: %d\n",vrau);
                break;

                case 33:

                t_inicial = clock();
                t = ler_arquivo(t);
                t_final = clock();

                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                printf("\nFile Read\n");
                printf("Time Executation: %lf \n",tempo);

                break;

                case 44:
                    read_search_txt(t);
                    break;

                case 0:
                    break;

                default:
                    printf("\nInvalid Choice my friend\n");
            }

    }while(op!=0);

    return 0;
}


