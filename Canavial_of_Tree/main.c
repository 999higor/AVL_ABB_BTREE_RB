#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main()
{
    int option;

    do{
        printf("1 - Arvore ABB \n");
        printf("2 - Arvore AVL \n");
        printf("3 - Arvore B \n");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                abb();
                break;

            case 2:
                avl();
                break;

            case 3:
                BTree();
                break;
        }
    }while(option!=0);

    return 0;
}
