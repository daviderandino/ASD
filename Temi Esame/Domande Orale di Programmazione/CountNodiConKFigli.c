// dato un BST, contare quanti nodi hanno k figli
// faccio visita per ogni nodo e conto

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
void inOrder(link root);
void f(link root,int k,int *figli);
int count(link root);

int main(){
    Tree *T = newNode(30);
    T->left = newNode(17);
    T->left->left = newNode(12);
    T->left->right= newNode(18);
    T->right = newNode(35);
    T->right->left = newNode(31);
    T->right->right = newNode(37);
    int k=2,figli=0;
    f(T,k,&figli);
    printf("%d\n",figli);
}

void f(link root,int k,int *figli){
    if(root==NULL) return;
    if(count(root)-1==k) (*figli) ++;
    f(root->left,k,figli);
    f(root->right,k,figli);
}

int count(link root){
    if(root==NULL) return 0;
    return(count(root->left)+ count(root->right)+1);
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
