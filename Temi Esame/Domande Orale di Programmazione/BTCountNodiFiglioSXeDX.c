// dato un BST, determinare quanti nodi hanno solo il figlio dx e quanti nodi hanno solo il figlio dx

#include<stdio.h>

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void f(link root,int *cntDx,int *cntSx);

int main(){
    Tree *T = newNode(3);
    T->left = newNode(4);
    T->left->left = newNode(5);
    T->left->right= newNode(6);
    T->left->left->left = newNode(7);
    T->right = newNode(8);
    T->right->left = newNode(3);
    T->right->left->right = newNode(5);
    int cntDx=0,cntSx=0;
    f(T,&cntDx,&cntSx);
    printf("Nodi con solo figli destri: %d\nNodi con solo figli sinistri: %d\n",cntDx,cntSx);
}

void f(link root,int *cntDx,int *cntSx){
    if(root==NULL) return;
    if(root->left==NULL && root->right!=NULL) (*cntDx) ++;
    if(root->left!=NULL && root->right==NULL) (*cntSx) ++;
    f(root->left,cntDx,cntSx);
    f(root->right,cntDx,cntSx);
}
