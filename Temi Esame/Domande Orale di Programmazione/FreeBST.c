/*
 Dato un BST dentro i cui nodi c'è una stringa allocata dinamicamente, deallocare tutto (albero, nodi e stringhe)
 */

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    char *str;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);

void freebst_r(link root){
    if(root==NULL) return;
    freebst_r(root->left);
    freebst_r(root->right);
    free(root->str);
    free(root);
}
