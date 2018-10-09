#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

int height(struct Node *N);

int max(int a, int b);

struct Node* newNode(int key);

struct Node *rightRotate(struct Node *y);

struct Node *leftRotate(struct Node *x);

int getBalance(struct Node *N);

struct Node* insert(struct Node* node, int key);

struct Node * minValueNode(struct Node* node);

struct Node* deleteNode(struct Node* root, int key);

void preOrder(struct Node *root);

struct Node *ler_arquivoAVL(struct Node* root);

void postOrder(struct Node *root ,FILE *arquivo);

void inOrder(struct Node *root);

struct Node *search(struct Node *root ,int key);

int countLeaf(struct Node *root);

int heightTree (struct Node *root);

int smallerElement(struct Node *root);

int higherElement(struct Node *root);

int countElement(struct Node *root);

void read_search_txt_AVL(struct Node *root);


#endif // AVL_H_INCLUDED
