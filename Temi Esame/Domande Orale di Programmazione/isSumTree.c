// verificare che un albero sia un SumTree
// ovvero che la somma di tutti i discendenti di un nodo è uguale al valore del nodo stesso per tutti i nodi

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef BST;

struct node* newNode(int data);
int isSumTree(link root);
int sum(link root);

int main(){
    BST *T = newNode(26);
    T->left = newNode(10);
    T->left->left = newNode(4);
    T->left->right= newNode(6);
    T->right = newNode(3);
    T->right->right = newNode(3);
    int check;
    check = isSumTree(T);
    printf("%d",check);
}

int isSumTree(link root){
    if(root==NULL) return 1;
    if(root->left!=NULL && root->right!=NULL && root->data!= (sum(root->left) + sum(root->right))) return 0;
    return (isSumTree(root->left) && isSumTree(root->left));

}

int sum(link root){
    if(root==NULL) return 0;
    return (sum(root->left) + sum(root->right) + root->data);
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
