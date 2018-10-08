#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "menu.h"
#include "BTree.h"

int BTree()
{
    bTree b;
    int i ,option ,valor;

    FILE *arquivo;

    ///b = bTree_Create();

    do{
        printf(">>>>>>>>>>> B Tree <<<<<<<<<<<<<<<\n");
        printf("1 - Insert\n");
        printf("2 - Delete\n");///implementar
        printf("3 - Search\n"); ///implementar
        printf("4 - PERCURSO - IN Order\n");
        printf("5 - COUNT - All Elements\n");
        printf("6 - COUNT - All Leafs\n");
        printf("7 - VERIFY - The Height of the Tree\n");
        printf("8 - VERFIFY - The Higher Value\n");
        printf("9 - VERIFY - The Lower Value\n");
        printf("11 - READ - VALUES.TXT\n");
        printf("33 - CREATE - Create the B Tree First ! !\n");
        printf("44 - DESTROY - Burn the Tree\n");
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


        case 11:
            printf("Reading File . . . \n");
            Btree_Read_File(b);
            break;

        case 22:
            bTree_Print_Keys_TreeMode(b);
            break;

        case 33:
            b = bTree_Create();
            break;

        case 44:
            bTree_Destroy(b);
            break;

        case 0:
            break;

        default:
            printf("Are you lost ? \n");

        }


    }while(option != 0);


    return 0;
}
