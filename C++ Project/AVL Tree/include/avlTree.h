#define AVLTREE_H
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root;

class avlTree
{
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, int);
        avl_node* delete_node(avl_node *, int);
        void display(avl_node *, int);
        void inorder(avl_node *);
        avlTree(){root=NULL;}
};

struct avl_node *minValueNode(struct avl_node *node)
{
    struct avl_node *current = node;
    while (current->left !=NULL) {current = current->left;}
    return current;
};

