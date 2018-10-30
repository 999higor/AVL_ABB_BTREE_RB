#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

struct node *novoNode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->numero = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
};

struct node *procura(struct node *raiz ,int numero)
{
    if(raiz == NULL)
    {
        //printf(">%d", raiz->numero);
        return 0;
    }
    if(raiz->numero == numero)
    {
        //printf("> Value Found: %d <", raiz->numero);
        return 1;
    }
    if(raiz->numero < numero)
        return procura(raiz->direita, numero);

    return procura(raiz->esquerda, numero);


};

struct node *insere(struct node *node, int numero)
{
    if(node == NULL)
        return novoNode(numero);
    if(numero < node->numero)
        node->esquerda = insere(node->esquerda ,numero);
    else if(numero > node->numero)
        node->direita = insere(node->direita ,numero);

    return node;
};

struct node *minimoNode(struct node* node)
{
    struct node* current = node;

    while(current->esquerda != NULL)
        current = current->esquerda;

        return current;
};


struct node* deletaNo(struct node *raiz , int numero)
{
    if(raiz == NULL)
        return raiz;
    if(numero < raiz->numero)
        raiz->esquerda = deletaNo(raiz->esquerda, numero);
    else if(numero > raiz->numero)
        raiz->direita = deletaNo(raiz->direita ,numero);
    else{
        if(raiz->esquerda == NULL)
        {
            struct node *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if(raiz->direita == NULL){
            struct node *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        else{
            struct node *temp = minimoNode(raiz->direita);
            raiz->numero = temp->numero;
            raiz->direita = deletaNo(raiz->direita ,temp->numero);
        }
    }

    return raiz;
};

void emOrdem(struct node *raiz)
{
    if(raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("> %i \n", raiz->numero);
        emOrdem(raiz->direita);
    }
}

void preOrdem(struct node *raiz)
{
    if(raiz != NULL)
    {
        printf("> %i \n", raiz->numero);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(struct node *raiz ,FILE *arquivo)
{

    if(raiz != NULL)
    {
        posOrdem(raiz->esquerda ,arquivo);
        posOrdem(raiz->direita ,arquivo);
        fprintf(arquivo,"%i\n", raiz->numero);
    }
}

int contaFolhas(struct node *raiz)        ///CONTA OS NOS FOLHAS DA ARVORE(SEM FILHOS)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if(raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return 1;
    }

    return contaFolhas(raiz->esquerda) + contaFolhas(raiz->direita);
}

int alturaArvore (struct node *raiz)
{
   if (raiz == NULL)
      return -1;
   else {
      int alturaEsq = alturaArvore(raiz->esquerda);
      int alturaDir = alturaArvore(raiz->direita);
      if (alturaEsq < alturaDir)
        return alturaDir + 1;
      else return alturaEsq + 1;
   }
}

int menorElemento(struct node *raiz)
{

    while(raiz->esquerda != NULL)
    {
        raiz = raiz->esquerda;
    }
    return raiz->numero;
}

int maiorElemento(struct node *raiz)
{

    while(raiz->direita != NULL)
    {
        raiz = raiz->direita;
    }
    return raiz->numero;
}

int contaElementos(struct node *raiz)
{

    int soma=0;
    if(raiz !=NULL)
    {
        soma = contaElementos(raiz->esquerda) + contaElementos(raiz->direita)+1;
        return soma;
    }else
        return 0;
}

struct node *ler_arquivo(struct node* raiz)
{
    int numero;

    FILE* file = fopen ("values.txt", "r");

    //fscanf (file, "%d", &numero);

    while (!feof(file)){

        fscanf(file, "%d", &numero);

        raiz = insere(raiz, numero);

        //fscanf(file, "%d", &numero);

    }
    fclose(file);
    return raiz;
}

void read_search_txt(struct node* raiz, FILE* result_search_ABB)
{
    int number;

    FILE* busca = fopen("search.txt", "r");

    //fscanf(busca, "%d", &number);

    while(!feof(busca))
    {
        fscanf(busca, "%d", &number);
        fprintf(result_search_ABB,"%d \n",procura(raiz, number));
        //fscanf(busca, "%d", &number);

    }
    fclose(busca);
}

void read_delete_txt(struct node* raiz, FILE* result_remove_ABB)
{
    int num ,height;

    FILE* file = fopen ("remove.txt", "r");

    //fscanf (file, "%d", &num);

    while (!feof(file)){

        fscanf(file, "%d", &num);

        raiz = deleteNode(raiz, num);

        //fscanf(file, "%d", &num);

    }
    fclose(file);
}

void free_abb(struct node *raiz)
{
    if(raiz == NULL)
        return 0;

    if(raiz != NULL)
    {
        free_abb(raiz->esquerda);
        free_abb(raiz->direita);
        free(raiz);
    }
}
