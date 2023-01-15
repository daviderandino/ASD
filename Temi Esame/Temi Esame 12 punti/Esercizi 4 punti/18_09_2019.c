#include<stdio.h>
#include<stdlib.h>

/*
    Sia dato un albero binario T, cui si accede tramite il puntatore root alla radice. I nodi dell’albero hanno
    come chiavi stringhe di lunghezza massima maxC. Si scriva una funzione C con prototipo
    linkL tree2List(linkT root, int visit);
    che visiti l'albero secondo la strategia specificata nel parametro visit (1: inorder, 2: preorder, 3:
    postorder), memorizzando le chiavi in una lista concatenata, di cui ritorna il puntatore alla testa.
    Si definiscano il nodo dell’albero e relativo puntatore (tipo linkT), il nodo della lista e il relativo
    puntatore (tipo linkL). Si scriva esplicitamente la funzione di inserzione in lista senza fare uso di
    funzioni di libreria.
 */

typedef struct nodeL *linkL;

struct nodeL{
    int val;
    linkL next;
};

typedef struct nodeT* linkT;

struct nodeT{
    int data;
    linkT left;
    linkT right;
};

struct nodeT* newNodeT(int data);
void preOrder(linkT root,linkL *h);
void inOrder(linkT root,linkL *h);
void postOrder(linkT root,linkL *h);
void tree2List(linkT root, int visit);
linkL newNodeL(int val,linkL next);
void listInsTailP(linkL *h,int val);
void stampa_lista(linkL h);

int main(){
    struct nodeT* T = newNodeT(1);
    T->right = newNodeT(3);
    T->left = newNodeT(2);
    T->left->left = newNodeT(4);
    T->left->left->left = newNodeT(6);
    T->right->right = newNodeT(5);
    T->left->left->right = newNodeT(7);
    int visit = 3; // 1 = inorder, 2 = preorder, 3 = postorder
    tree2List(T,visit);
}

void listInsTailP(linkL *h,int val){
    linkL x = *h;
    if(x==NULL)
        *h = newNodeL(val,NULL);
    else{
        for(;x->next!=NULL;x=x->next);
        x->next = newNodeL(val,NULL);
    }
}

linkL newNodeL(int val,linkL next){
    linkL x = malloc(sizeof(struct nodeL));
    if(x==NULL) return NULL;
    else{
        x->val = val;
        x->next = next;
    }
}

void tree2List(linkT root, int visit){
    linkL h=NULL;
    if(visit==1) inOrder(root,&h);
    if(visit==2) preOrder(root,&h);
    if(visit==3) postOrder(root,&h);
    stampa_lista(h);
}

struct nodeT* newNodeT(int data){
    struct nodeT* node = (struct nodeT*)malloc(sizeof(struct nodeT));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void stampa_lista(linkL h){
    linkL x;
    for(x=h;x!=NULL;x=x->next)
        printf("%d ",x->val);

}

void preOrder(linkT root,linkL *h){
    if (root == NULL)
        return;
    // printf("%d ",root->data);
    listInsTailP(h,root->data);
    newNodeT(root->data);
    preOrder(root->left,h);
    preOrder(root->right,h);
}

void inOrder(linkT root,linkL *h){
    if (root == NULL)
        return;
    inOrder(root->left,h);
    listInsTailP(h,root->data);
    // printf("%d ",root->data);
    inOrder(root->right,h);
}

void postOrder(linkT root,linkL *h){
    if (root == NULL)
        return;
    postOrder(root->left,h);
    postOrder(root->right,h);
    listInsTailP(h,root->data);
    // printf("%d ",root->data);
}