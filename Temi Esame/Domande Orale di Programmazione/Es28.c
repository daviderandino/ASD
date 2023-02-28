// Calcolo dei nodi COMPLETI compresi tra due livelli di un binary tree

#include<stdlib.h>
#include<stdio.h>

/*
 Visito l'albero tenendo traccia di un contatore che segna il livello in cui sono arrivato
 verifico che il livello a cui sono sia compreso tra l1 e l2, in caso affermativo aggiorno un contatore
 altrimenti visito prima a dx e poi a sx aumentando contatore del livello di 1.
 Bisogna verificare che i figli siano !=NULL in quanto ci chiede "nodi completi"
 */

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef BST;

struct node* newNode(int data);
int nodiCompleti(BST b,int l1,int l2);
void recursiveVisit(link root,int l1,int l2,int *count,int pos);

int main(){
    BST *T = newNode(3);
    T->left = newNode(4);
    T->left->left = newNode(5);
    T->left->right= newNode(6);
    T->left->left->left = newNode(7);
    T->right = newNode(8);
    T->right->left = newNode(3);
    T->right->left->right = newNode(5);
    int l1=0,l2=2;
    int count = nodiCompleti(*T,l1,l2);
    printf("%d",count);
}

int nodiCompleti(BST b,int l1,int l2){
    int count=0;
    recursiveVisit(&b,l1,l2,&count,0);
    return count;
}

void recursiveVisit(link root,int l1,int l2,int *count,int pos){
    if(root==NULL) return;
    if(pos>l1 && pos<l2){
        if(root->left!=NULL && root->right!=NULL)
            (*count)++;
    }
    if(pos>=l2) return;
    recursiveVisit(root->left,l1,l2,count,pos+1);
    recursiveVisit(root->right,l1,l2,count,pos+1);
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}