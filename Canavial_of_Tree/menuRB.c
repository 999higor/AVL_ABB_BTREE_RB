#include "red-black.h"
#include "menu.h"
#include <stdio.h>


int red_black()

{
    //struct rbtNode* root;

    int choice,val=0,var=0;

    do
    {
        //printf("\nRed Black Tree Management - Enter your choice :1:Insert  2:Delete  3:Search  4:Traversal  5:Exit\n");
        printf(">>>>>> Red Black Tree <<<<<<\n");
        printf("1 - INSERT\n");
        printf("2 - DELETE\n");
        printf("3 - SEARCH\n");
        printf("4 - PRINT - In Order\n");
        printf("5 - READ - VALUES.TXT\n");
        printf("0 - EXIT\n");

        printf(">");
        scanf("%d",&choice);

        switch(choice)

        {
            case 1:
                printf("Enter the integer you want to add : ");
                scanf("%d",&val);

                insertRB(val);
                break;

            case 2:
                printf("Enter the integer you want to delete : ");
                scanf("%d",&var);

                delete(var);
                break;

            case 3:
                printf("Enter search element \n");
                scanf("%d",&val);

                searchRB(val);
                break;

            case 4:
                aux_print();
                break;

            case 0:
                break;

            case 5:
                read_RB();
                break;

            default:
                printf("\nInvalid Choice\n");

        }

    }while(choice!=0);

    return 0;
}

