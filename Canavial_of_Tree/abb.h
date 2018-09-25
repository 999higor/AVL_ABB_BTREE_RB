#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

struct node
{
    int numero;
    struct node *direita, *esquerda;
};

struct node *novoNode(int item);

struct node *procura(struct node *raiz ,int numero);

struct node *insere(struct node *node, int numero);

struct node *minimoNode(struct node* node);

struct node* deletaNo(struct node *raiz , int numero);

void emOrdem(struct node *raiz);

void preOrdem(struct node *raiz);

void posOrdem(struct node *raiz ,FILE *arquivo);

int contaFolhas(struct node *raiz);

int alturaArvore (struct node *raiz);

int menorElemento(struct node *raiz);

int maiorElemento(struct node *raiz);

int contaElementos(struct node *raiz);

struct node *ler_arquivo(struct node* raiz);

#endif // ABB_H_INCLUDED
