// Conta quanti elementi di un BST sono compresi tra due valori a,b

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
int countAB(int a,int b,link root,int count);

int main(){
    Tree *T = newNode(15);
    T->left = newNode(12);
    T->right = newNode(17);
    T->left->left = newNode(7);
    T->left->right = newNode(13);
    T->right->left = newNode(16);
    T->right->right = newNode(20);
    int a=13,b=16;
    int count = 0; count = countAB(a,b,T,count);
    printf("%d\n",count);
}

int countAB(int a,int b,link root,int count){
    if(root==NULL) return count;
    if(root->data>=a && root->data<=b) return 1+ countAB(a,b,root->left,count) + countAB(a,b,root->right,count);
    if(root->data<a) return countAB(a,b,root->right,count);
    if(root->data>b) return countAB(a,b,root->left,count);

}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
