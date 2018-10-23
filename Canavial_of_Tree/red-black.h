#ifndef RED_BLACK_H_INCLUDED
#define RED_BLACK_H_INCLUDED

struct rbtNode
{
    int key;
    char color;
    struct rbtNode *left, *right, *parent;

};
    struct rbtNode* root;

void aux_print();

int aux_height_RB();

aux_free_RB();

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

struct rbtNode* delete_RB(int var);

void read_RB();

void read_search_txt_RB(FILE* result_search_RB);

void read_delete_txt_RB(FILE* result_remove_RB);

int heightTree_RB(struct rbtNode *root);

void free_RB(struct rbtNode* root);


#endif // RED_BLACK_H_INCLUDED
