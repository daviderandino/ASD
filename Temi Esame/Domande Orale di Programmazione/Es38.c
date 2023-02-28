// vedere se un BST è contenuto in un altro
// faccio la visita di entrambi,salvo in due vettori e vedo se "si intersecano"

#include<stdio.h>
#include<stdlib.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
void inOrder(link root,int *V,int *k);
int count(link root);
int isSubtree(int *V1,int d1,int *V2,int d2);

int main(){
    Tree *T = newNode(30);
    T->left = newNode(17);
    T->left->left = newNode(12);
    T->left->right= newNode(18);
    T->right = newNode(35);
    T->right->left = newNode(31);
    T->right->right = newNode(37);
    Tree *T2 = newNode(17);
    T2->right = newNode(18);
    T2->left = newNode(12);
    int d1 = count(T); int d2 = count(T2);
    int *V1 = malloc(d1*sizeof(int));
    int *V2 = malloc(d2*sizeof(int));
    int k=0;
    inOrder(T,V1,&k);
    k=0;
    inOrder(T2,V2,&k);
    int check = isSubtree(V1,d1,V2,d2);
    printf("%d\n",check);

}

int isSubtree(int *V1,int d1,int *V2,int d2){
    int i,j,flag=0;
    for(i=0,j=0;i<d1,j<d2;){
        if(V1[i]==V2[j]){
            i++;
            j++;
            flag = 1;
        }
        else if(flag==1) return 0;
        else j++;
    }
    return 1;
}

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrder(link root,int *V,int *k){
    if(root==NULL) return;
    inOrder(root->left,V,k);
    V[*k] = root->data;
    (*k)++;
    inOrder(root->right,V,k);
}

int count(link root){
    if(root==NULL) return 0;
    return count(root->left) + count(root->right) + 1;
}
