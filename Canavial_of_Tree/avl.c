#include<stdio.h>
#include<stdlib.h>
#include "avl.h"


int max(int a, int b);

///funcao para pegar a altura da arvore
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

///funcao para pegar o maximo entre dois inteiros
int max(int a, int b)
{
    return (a > b)? a : b;
}

///funcao que ajuda a alocar o novo no e setar NULL para os ponteiros da esquerda e direita
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  ///novo no e inicialmente adicionado como folha
    return(node);
}

///funcao que rotaciona a direita da sub-arvore com Y
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    /// realiza a rotacao
    x->right = y;
    y->left = T2;

    ///atualiza a altura
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    ///retorna o novo no
    return x;
}

///funcao que rotaciona a esquerda da sub-arvore com Y
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    /// realiza a rotacao
    y->left = x;
    x->right = T2;

    ///atualiza a altura
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    ///retorna o novo no
    return y;
}

///verifica o balanceamento das folhas
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{
    ///realiza a rotacao normal BST
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    ///aumenta a altura do no antecessor
    node->height = 1 + max(height(node->left),
                           height(node->right));


    ///verifica o fator de balanceamento
    int balance = getBalance(node);

    ///se estiver desbalanceada, ha os 4 cases abaixo

    ///esquerda esquerda case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    ///direita direita case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    ///esquerda direita case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    ///direita esquerda case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    ///retorna o ponteiro do no
    return node;
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;


    while (current->left != NULL)
        current = current->left;

    return current;
}


struct Node* deleteNode(struct Node* root, int key)
{

    if (root == NULL)
        return root;


    ///se a chave a ser deletada for menor que a raiz, percorre a esquerda
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    /// se a chave a ser deletada for menor que a raiz, percorre a direita
    else if( key > root->key )
        root->right = deleteNode(root->right, key);


    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;


            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;

            free(temp);
        }
        else
        {

            struct Node* temp = minValueNode(root->right);


            root->key = temp->key;


            root->right = deleteNode(root->right, temp->key);
        }
    }


    if (root == NULL)
      return root;


    root->height = 1 + max(height(root->left),
                           height(root->right));


    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);


    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }


    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct Node *ler_arquivoAVL(struct Node* root)
{
    int numero;

    FILE* file = fopen ("values.txt", "r");

    fscanf (file, "%d", &numero);

    while (!feof(file)){

        root = insert(root, numero);

        fscanf(file, "%d", &numero);

    }
    fclose(file);
    return root;
}

void postOrder(struct Node *root ,FILE *arquivo)
{
    if(root != NULL)
    {
        postOrder(root->left ,arquivo);
        postOrder(root->right ,arquivo);
        fprintf(arquivo,"%i\n", root->key);
    }
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("> %i \n", root->key);
        inOrder(root->right);
    }
}

struct Node *search(struct Node *root ,int key)
{
    if(root == NULL)
        return 0;
    if(root->key == key)
    {
        //printf("Value Found : %d <\n",root->key);
        return 1;
    }
    if(root->key < key)
        return search(root->right, key);

    return search(root->left, key);
};

int countLeaf(struct Node *root)        ///CONTA OS NOS FOLHAS DA ARVORE(SEM FILHOS)
{
    if (root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeaf(root->left) + countLeaf(root->right);
}

int heightTree (struct Node *root)
{
   if (root == NULL)
      return -1;
   else {
      int heightLeft = heightTree(root->left);
      int heightRight = heightTree(root->right);
      if (heightLeft < heightRight)
        return heightRight + 1;
      else return heightLeft + 1;
   }
}

int smallerElement(struct Node *root)
{

    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->key;
}

int higherElement(struct Node *root)
{

    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->key;
}

int countElement(struct Node *root)
{

    int result=0;
    if(root !=NULL)
    {
        result = countElement(root->left) + countElement(root->right)+1;
        return result;
    }else
        return 0;


}

void read_search_txt_AVL(struct Node *root ,FILE * result_search_AVL)
{
    int number;

    FILE* busca = fopen("search.txt", "r");

    fscanf(busca, "%d", &number);

    while(!feof(busca))
    {
        fprintf(result_search_AVL,"%d \n",search(root, number));
        fscanf(busca, "%d", &number);

    }
    fclose(busca);
}

void read_delete_txt_AVL(struct Node *root, FILE* result_remove_AVL)
{
    int num ,height;

    FILE* file = fopen ("remove.txt", "r");

    fscanf (file, "%d", &num);

    while (!feof(file)){

        root = deleteNode(root, num);

        fscanf(file, "%d", &num);

    }
    fclose(file);
}

void free_avl(struct Node *root)
{
    if(root != NULL)
    {
        free_avl(root->left);
        free_avl(root->right);
        free(root);
    }
}

