// Strutture dati per dichiarare un albero binario (Tree)
// (non per forza adt) + funzione ricorsiva per contare tutti i nodi completi (con entrambi i figli)

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
void contaNodiCompleti(int *cnt,link root);

int main(){
    Tree *T = newNode(3);
    T->left = newNode(4); T->left->left = newNode(5); T->left->right = newNode(6);
    T->right = newNode(8); T->right->left = newNode(3); T->right->right = newNode(1);
    int cnt=0;
    contaNodiCompleti(&cnt,T);
    printf("%d",cnt);
}

void contaNodiCompleti(int *cnt,link root){
    if(root==NULL) return;
    if(root->left!=NULL && root->right!=NULL) (*cnt)++;
    contaNodiCompleti(cnt,root->left);
    contaNodiCompleti(cnt,root->right);
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
