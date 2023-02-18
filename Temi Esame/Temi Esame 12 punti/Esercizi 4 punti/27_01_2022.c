/*
    Si scriva una funzione (wrapper) int f(BT t) che ricevuto in input un albero binario di interi t di
    tipo BT verifichi se questo rappresenti o meno un BST.
    Fornire, inoltre, la definizione del tipo BT e del tipo nodo al suo intero, come ADT di prima classe e
    come quasi ADT rispettivamente
 */

#include<stdlib.h>
#include<stdio.h>

/*
 Per definizione un binary tree visitato in order ci dà come risultato degli interi crescenti
 Quindi basta visitarlo: se un valore è maggiore del precedente allora NON è un BST
 Se non incontriamo mai questo caso allora ritorna true
 */

typedef struct node *link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
int inOrder(link root,int n);
int isBst(struct node* T);

int main(){
    struct node* T = newNode(15);
    T->right = newNode(18);
    T->right->right = newNode(20);
    T->right->left = newNode(17);
    T->left = newNode(6);
    T->left->right = newNode(7);
    T->left->left = newNode(3);
    T->left->left->left = newNode(2);
    T->left->left->right = newNode(4);
    int check;
    check = isBst(T);
    if(check==1) printf("E' un BST");
    else printf("Non e' un BST");
}

int isBst(struct node* T){
    int n = T->data;
    int check = inOrder(T,n);
    return check;
}

int inOrder(link root,int n){
    if(root==NULL) return 1;
    inOrder(root->left,root->data);
    if(root->data<n) return 0;
    inOrder(root->right,root->data);
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}