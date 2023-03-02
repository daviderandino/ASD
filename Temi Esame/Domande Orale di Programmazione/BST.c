#include "BST.h"

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    Tree *T = newNode(3);
}

int count(link root){
    if(root==NULL) return 0;
    return count(root->left) + count(root->right) + 1;
}

int height(link root){
    int u,v;
    if(root==NULL) return -1;
    u = height(root->left); v = height(root->right);
    if(u>v)
        return u+1;
    return v+1;
}

void inOrder(link root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder(link root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(link root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

// per la ricerca faccio una keycompare, se la chiave che sto cercando è minore ricorro a SX, altrimenti ricorro a DX
// per trovare il min scendo a sx finchè nodo->left == NULL, il nodo minimo sarà quindi nodo. Analogo per il max, scendendo a DX
// per l'inserzione in foglia, se il nodo da inserire deve stare a sx scendiamo a sx, altrimenti scendiamo a dx