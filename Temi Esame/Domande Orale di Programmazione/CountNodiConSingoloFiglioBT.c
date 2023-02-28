// Funzione che determina il numero di nodi che hanno esattamente un figlio

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
void f(link root,int *count);

    int main(){
    Tree *T = newNode(3);
    T->left = newNode(4);
    T->left->left = newNode(5);
    T->left->right= newNode(6);
    T->left->left->left = newNode(7);
    T->right = newNode(8);
    T->right->left = newNode(3);
    T->right->left->right = newNode(5);
    int count=0;
    f(T,&count);
    printf("%d",count);
}

void f(link root,int *count){
    if(root==NULL) return;
    if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) (*count)++;
    f(root->left,count);
    f(root->right,count);

}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
