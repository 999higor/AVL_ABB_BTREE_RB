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
        printf("1 - Insert\n");
        printf("2 - Delete\n");
        printf("3 - Search\n");
        printf("4 - Percuso - In Order\n");
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

            default:
                printf("\nInvalid Choice\n");

        }

    }while(choice!=0);

    return 0;
}

