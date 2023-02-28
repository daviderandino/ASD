// Dato un BST con nodi contenenti un tempo nel formato (hh:mm) e un contatore c, inserire un nodo nel BST e aggiornare il contatore.

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct ora_t{
    int hh;
    int mm;
} typedef Ora;

struct node{
    Ora ora;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int ora,int min);

struct node* newNode(int ora,int min){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->ora.hh = ora;
    node->ora.mm = min;
    node->left = NULL;
    node->right = NULL;
    return node;
}

link insert(Tree *T,int hh,int mm);
void inOrder(link root);

int main(){
    Tree *T = newNode(20,17);
    T->right = newNode(21,20);
    T->left = newNode(17,45);
    T->left->left = newNode(16,30);
    T->left->right = newNode(18,0);
    T->right->left = newNode(20,45);
    T = insert(T,22,00);
    inOrder(T);

}

link insert(link h,int hh,int mm){
    if(h==NULL) return newNode(hh,mm);
    if(hh>h->ora.hh && mm>h->ora.mm) h->left = insert(h->left,hh,mm);
    else h->right = insert(h->right,hh,mm);
    return h;
}

void inOrder(link root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d:%d\n",root->ora.hh,root->ora.mm);
    inOrder(root->right);
}
