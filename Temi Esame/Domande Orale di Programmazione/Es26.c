// Dato un albero binario e due suoi nodi a e b scrivere una funzione
// in grado di determinare l'antenato comune più vicino ad a e b

#include<stdio.h>
#include<stdlib.h>

/*
 Store the path from the root to n1 in a list, let it be path1
 Store the path from the root to n2 in a list, let it be path2
 Traverse in both the obtained paths till the nodes are common and return the node that occurs just before the mismatch
 */

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);

struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findShortestPathRootNode(link root,int *path,int n,int *cnt);

int main(){
    Tree *T = newNode(1);
    T->left = newNode(2);
    T->right = newNode(3);
    T->left->left = newNode(4);
    T->left->left->right = newNode(7);
    T->left->right = newNode(5);
    T->right->right = newNode(6);
    T->right->right->right = newNode(9);
    T->right->right->left = newNode(8);
    int N=9;
    int *path1 = malloc(N*sizeof(int));
    int *path2 = malloc(N*sizeof(int));
    int n1=4,n2=5,check,cnt1=0,cnt2=0; // trovo il comune antenato tra 4 e 5
    check = findShortestPathRootNode(T,path1,n1,&cnt1);
    check = findShortestPathRootNode(T,path2,n2,&cnt2);

    // una volta trovato lo shortest path per n1 ed n2, scorro i vettori fin quando c'è un elemento comune.
    // l'ultimo elemento comune sarà l'antenato comune
    int i,j;
    for(i=0,j=0;i<cnt1,j<cnt2 && path1[i]==path2[j];i++,j++);
    printf("%d",path1[i-1]);
}


// trova lo shortest path radice-nodo
int findShortestPathRootNode(link root,int *path,int n,int *cnt){
    if(root==NULL) return 0;
    path[(*cnt)++] = root->data;
    if(root->data==n) return 1;
    if(findShortestPathRootNode(root->left,path,n,cnt) || findShortestPathRootNode(root->right,path,n,cnt)) return 1;
    path[*cnt] = -1;
    (*cnt)--;
    return 0;

}