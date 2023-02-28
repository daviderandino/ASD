// Crea una funzione che determina lo sbilanciamento di un BST (sbilanciamento = profondità max - profondità min)

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
int tree_imbalance(Tree *root);
int tree_height(Tree *root);

int main(){
    Tree *T = newNode(2);
    T->right = newNode(5); T->right->right = newNode(6); T->right->right->right = newNode(7);
    T->left = newNode(3); T->left->left = newNode(4);
    int p = tree_imbalance(T);
    printf("%d",p);

}

int tree_height(Tree *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int tree_imbalance(Tree *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    int imbalance = right_height - left_height;
    return imbalance;
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
