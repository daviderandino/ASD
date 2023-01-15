#include <stdio.h>
#include <stdlib.h>

/*
 Il diametro di un albero binario è definito come la lunghezza del cammino più lungo tra una qualsiasi coppia di
 nodi. Si scriva una funzione C che, dato il puntatore alla radice dell’albero, ne determini il diametro:
 int diameter(link root);
 */

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
};

int diameter(link root);
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct node* node);

int diameter(link root){
    if (root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight + rheight + 1,max(ldiameter, rdiameter));
}

int height(struct node* node){
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int main(){
    struct node* T = newNode(1);
    T->right = newNode(3);
    T->left = newNode(2);
    T->left->left = newNode(4);
    T->left->left->left = newNode(6);
    T->right = newNode(3);
    T->right->right = newNode(5);
    T->left->left->right = newNode(7);

    printf("Diametro: %d\n",diameter(T));

    return 0;
}