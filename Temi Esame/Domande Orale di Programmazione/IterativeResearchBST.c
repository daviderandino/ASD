// ricerca iterativa in un BST

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
int search(Tree *T,int n);

int main(){
    Tree *T = newNode(30);
    T->left = newNode(17);
    T->left->left = newNode(12);
    T->left->right= newNode(18);
    T->right = newNode(35);
    T->right->left = newNode(31);
    T->right->right = newNode(37);
    int n=31,found;
    found = search(T,n);
    printf("%d\n",found);
}

int search(Tree *T,int n){
    while(T->data!=n){
        if(T->data==n) return 1;
        if(T->right==NULL && T->left==NULL) return 0;
        if(T->data<n) T=T->right;
        if(T->data>n) T=T->left;
    }
    return 1;
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
