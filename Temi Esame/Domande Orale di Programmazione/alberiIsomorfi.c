// Verificare se due alberi binari sono isomorfi

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

int areIsomorph(Tree *T1,Tree *T2);

int main(){
    Tree *T1 = newNode(3);
    T1->left = newNode(2);
    T1->left->left = newNode(7);
    T1->right = newNode(5);
    T1->right->right = newNode(2);
    T1->right->left = newNode(8);
    Tree *T2 = newNode(3);
    T2->left = newNode(2);
    T2->left->left = newNode(7);
    T2->right = newNode(5);
    T2->right->right = newNode(2);
    T2->right->left = newNode(8);
    int check = areIsomorph(T1,T2);
    printf("%d",check);
}

int areIsomorph(Tree *T1,Tree *T2){
    if(T1==NULL && T2==NULL) return 1;
    if(T1==NULL || T2==NULL) return 0;
    if(T1->data==T2->data) return(areIsomorph(T1->left,T2->left) && areIsomorph(T1->right,T2->right));
    return 0;
}
