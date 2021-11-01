#include "avlTree.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#define pow2(n) (1 << (n))

using namespace std;

int avlTree::height(avl_node *temp)
{
    int h=0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height +1;
    }
    return h;
}
int avlTree::diff(avl_node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}
avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}
avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}
avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor>1)
    {
        if (diff(temp->left)>0) {temp = ll_rotation(temp);}
        else {temp = lr_rotation(temp);}
    }
    else if (bal_factor<-1)
    {
        if (diff(temp->right)>0) {temp=rl_rotation(temp);}
        else {temp=rr_rotation(temp);}
    }
    return temp;
}
avl_node *avlTree::insert(avl_node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}
void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level+1);
        printf("\n");
        if(ptr == root)
            cout<<"Root ->";
        for (i = 0;i < level && ptr != root;i++)
            cout<<"    ";
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}
void avlTree::inorder(avl_node *tree)
{
    if (tree==NULL) {return;}
    inorder(tree->left);
    cout<<tree->data<<" ";
    inorder(tree->right);
}
avl_node *avlTree::delete_node(avl_node *root, int data)
{
    if (root == NULL) {return root;}
    if (data<root->data) {root->left = delete_node(root->left, data);}
    else if (data>root->data) {root->right = delete_node(root->right,data);}
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct avl_node *temp = root->left ? root->left: root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else {*root = *temp;}
            free(temp);
        }
        else
        {
            struct avl_node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);
        }
    }
    if (root==NULL) {return root;}
}
