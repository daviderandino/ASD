#include<stdio.h>
#include<stdlib.h>

typedef struct node* link;

struct Key_t{
    int num;
} typedef Key;

struct node{
    Key data;
    link left;
    link right;
};

struct node* newNode(int data);
int count(link root);
void postOrder(link root);
int TREEisomorph(struct node *t1, struct node *t2);
int KEYcmp(Key k1, Key k2);

int main(){
    struct node* t1 = newNode(3);
    t1->right = newNode(2);
    t1->right->right = newNode(0);
    t1->left = newNode(7);
    t1->left->left = newNode(2);
    t1->left->right = newNode(2);
    t1->left->right->left = newNode(9);
    struct node* t2 = newNode(3);
    t2->right = newNode(2);
    t2->right->right = newNode(0);
    t2->left = newNode(7);
    t2->left->left = newNode(2);
    t2->left->right = newNode(2);
    t2->left->right->left = newNode(9);

    if(TREEisomorph(t1,t2)==1)
        printf("Alberi isomorfi\n");
    else printf("Alberi non isomorfi\n");

}

int TREEisomorph(struct node *t1, struct node *t2){
    // if(count(t1)!= count(t1)) return 0; // se il numero di foglie è diverso sicuramente non sono strutturalmente identici -> non è necessario questo controllo (aumenta la complessità)
    if(t1==NULL && t2==NULL) return 1;
    if(t1==NULL || t2==NULL) return 0;

    if(KEYcmp(t1->data,t2->data)==1)
        return (TREEisomorph(t1->left,t2->left) && TREEisomorph(t1->right,t2->right));

    /* Se il campo dato fosse semplicemente un intero e non un tipo Key
    if(t1->data==t2->data)
        return (TREEisomorph(t1->left,t2->left) && TREEisomorph(t1->right,t2->right));
    return 0; */

}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data.num = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int KEYcmp(Key k1, Key k2){
    if(k1.num == k2.num) return 1;
    return 0;
}

int count(link root){
    if(root==NULL) return 0;
    return count(root->left) + count(root->right);
}