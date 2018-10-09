#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "red-black.h"
#include "menu.h"

int red_black()

{
    //struct rbtNode* root;

    int choice,val=0,var=0;

    clock_t t_inicial, t_final;
    double tempo=0;

    FILE* result_search_RB;

    do
    {
        printf(">>>>>> Red Black Tree <<<<<<\n");
        printf("1 - INSERT\n");
        printf("2 - DELETE\n");
        printf("3 - SEARCH\n");
        printf("4 - PRINT - In Order\n");
        printf("5 - READ - VALUES.TXT\n");
        printf("6 - READ - SEARCH.TXT\n");
        printf("0 - EXIT\n");

        printf(">");
        scanf("%d",&choice);

        switch(choice)

        {
            case 1:
                printf("Value: \n");
                scanf("%d",&val);

                insertRB(val);
                break;

            case 2:
                printf("Value: \n");
                scanf("%d",&var);
                t_inicial = clock();

                delete(var);

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Time : %lf \n",tempo);


                break;

            case 3:
                printf("Value: \n");
                scanf("%d",&val);

                t_inicial = clock();

                searchRB(val);

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Time: %lf \n",tempo);


                break;

            case 4:
                aux_print();
                break;

            case 0:
                break;

            case 5:
                t_inicial = clock();

                read_RB();

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Time: %lf \n",tempo);
                break;

            case 6:
                result_search_RB = fopen("result_search_RB.txt" ,"w");
                read_search_txt_RB(result_search_RB);
                break;

            default:
                printf("\nERROOOOOOU\n");

        }

    }while(choice!=0);

    return 0;
}

