/*
 Dichiare un BST come ADT di 1 classe
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct bst *BST;
BST BSTinit();
typedef struct BSTnode *link;
link new(int val,link left,link right);

struct bst{
    link root;
};

struct BSTnode{
    int val;
    link right;
    link left;
};

link new(int val,link left,link right){
    link x = malloc(sizeof *x);
    x->val = val;
    x->left = left;
    x->right = right;
    return x;
}

BST BSTinit(){
    BST bst = malloc(sizeof *bst);
    bst->root = NULL;
    return bst;
}

int main(){
    BST Tree = BSTinit();
}
