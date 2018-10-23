#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "menu.h"
#include "BTree.h"

int BTree()
{
    bTree b;
    int option ,valor;

    FILE *result_search_Btree;

    clock_t t_inicial, t_final;
    double tempo=0;

    b = bTree_Create();

    do{
        printf(">>>>>>>>>>> B Tree <<<<<<<<<<<<<<<\n");
        printf("1 - INSERT\n");
        printf("2 - DELETE\n"); ///FALTA IMPLEMENTAR
        printf("3 - SEARCH\n"); ///AQ TAMBÉM
        printf("4 - PRINT - IN Order\n");
        printf("5 - COUNT - All Elements\n");
        printf("6 - COUNT - All Leafs\n");
        printf("7 - VERIFY - The Height of the Tree\n");
        printf("8 - VERFIFY - The Higher Value\n");
        printf("9 - VERIFY - The Lower Value\n");
        printf("33 - READ - VALUES.TXT\n");
        printf("44 - READ - SEARCH.TXT\n");
       // printf("33 - CREATE - Create the B Tree First ! !\n");
        //printf("44 - DESTROY - Burn the Tree\n");
        printf("0 - EXIT\n");

        scanf("%d",&option);
        printf("\n");

        switch(option)
        {
        case 1:
            printf("\nValue: ");
            scanf("%d",&valor);
            bTree_Insert(b ,valor);
            break;

        case 2:
            printf("Not Implemented ); \n");
            break;

        case 3:
            printf("\nValue: ");
            scanf("%d",&valor);
             t_inicial = clock();

            printf("\nReturn %d" ,bTree_Search(b, valor));

            t_final = clock();
            tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
            printf("\nTime: %lf \n",tempo);

            printf("\n");
            break;

        case 4:
            Btree_Print_Keys(b);
            break;


        case 5:
            printf("Total of Elements: %d <\n",bTree_Count_All(b));
            break;


        case 6:
            printf("Total of Leafs: %d <\n",bTree_Count_Leaf(b));
            break;


        case 7:
            printf("Tree Height: %d <\n",bTree_Height(b));
            break;


        case 8:
            printf("Higher Element: %d <\n",bTree_MAX(b));
            break;


        case 9:
            printf("Lower Element: %d <\n",bTree_MIN(b));
            break;


        case 33:
            printf("Reading File . . . \n");

            t_inicial = clock();

            Btree_Read_File(b);
            t_final = clock();
            tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
            printf("Time: %lf \n",tempo);
            break;

        case 44:
            t_inicial = clock();

            result_search_Btree = fopen("result_search_Btree.txt" ,"w");
            read_search_txt_B(b, result_search_Btree);
            fclose(result_search_Btree);

            t_final = clock();

            tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

            // printf("\nFile Read\n");
            printf("Time: %lf \n",tempo);
            break;

        case 22:
            bTree_Print_Keys_TreeMode(b);
            break;

        /*case 33:
            b = bTree_Create();
            break;*/

        /*case 44:
            bTree_Destroy(b);
            break;*/

        case 0:
            break;

        default:
            printf("ih rapaiz ? \n");

        }


    }while(option != 0);


    bTree_Destroy(b);

    return 0;
}
