#ifndef RED-BLACK_H_INCLUDED
#define RED-BLACK_H_INCLUDED

struct rbtNode
{
    int key;
    char color;
    struct rbtNode *left, *right, *parent;

};
    struct rbtNode* root;

void aux_print();

void left_Rotate(struct rbtNode *x);

void right_Rotate(struct rbtNode *y);

void color_insert(struct rbtNode *z);

void insertRB(int val);

void inorderTree(struct rbtNode* root);

void postorderTree(struct rbtNode* root);

void traversal(struct rbtNode* root);

int searchRB(int val);

struct rbtNode* min(struct rbtNode *x);

struct rbtNode* successor(struct rbtNode *x);

void color_delete(struct rbtNode *x);

struct rbtNode* delete(int var);

struct rbtNode* read_RB();



#endif // RED-BLACK_H_INCLUDED
