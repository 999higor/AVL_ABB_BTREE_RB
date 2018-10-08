#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main()
{
    int option;

    do{
        printf("---> 1 -  ABB Tree \n");
        printf("---> 2 -  AVL Tree \n");
        printf("---> 3 -  B Tree \n");
        printf("---> 4 -  RED-BLACK Tree \n");
        printf("---> 0 - EXIT \n");
        printf("> ");

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

            case 4:
                red_black();
                break;
        }
    }while(option!=0);

    return 0;
}
