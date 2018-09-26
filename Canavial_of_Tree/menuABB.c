#include <stdlib.h>
#include <stdio.h>

#include "menu.h"
#include "abb.h"

int abb()
{
    int vrau=0;
    int op;
    int numero;
    struct node *t = NULL; ///ABB
    FILE *arquivoGravado;

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
            printf("\n\n");

            switch(op)
            {
                case 1:
                printf("\ndigite o numero: ");
                scanf("%d",&numero);
                t = insere(t,numero);
                printf("valor inserido\n");
                break;

                case 2:
                printf("\ndigite o numero: ");
                scanf("%d",&numero);
                t = deletaNo(t,numero);
                printf("valor removido\n");
                break;

                case 3:
                printf("\ndigite o numero: ");
                scanf("%d",&numero);
                t = procura(t,numero);
                printf("valor encontrado\n");
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

                printf("gravado com sucesso xd xd\n");

                fclose(arquivoGravado);
                break;

                case 7:
                vrau = contaElementos(t);
                printf("\ntotal de elementos: %d\n",vrau);
                break;

                case 8:
                vrau = contaFolhas(t);
                printf("\ntotal de folhas: %d\n",vrau);
                break;

                case 9:
                vrau = alturaArvore(t);
                printf("\naltura da arvore: %d\n",vrau);
                break;

                case 10:
                printf("\n ERRRRROU (voz do faustao.mp3)\n");
                break;

                case 11:
                vrau = maiorElemento(t);
                printf("\nmaior elemento: %d\n",vrau);
                break;

                case 12:
                vrau = menorElemento(t);
                printf("\nmenor elemento: %d\n",vrau);
                break;

                case 13:
                t = ler_arquivo(t);
                printf("\nArquivo lido com sucesso xd xd\n");
                break;
            }

    }while(op!=0);

    return 0;
}


