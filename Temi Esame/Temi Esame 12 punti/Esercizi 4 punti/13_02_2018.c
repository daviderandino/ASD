/*
    Dati 2 alberi binari cui si accede mediante il puntatore alla radice, si scriva una funzione C con il seguente
    prototipo che decida se il secondo è uguale a un sottoalbero del primo o meno.
    int subtree(link root1, link root2);
    Si supponga la disponibilità di una funzione KEYcmp(KEY k1, KEY k2) per comparare le chiavi. Un
    sottoalbero di un albero T è un albero composto da un nodo che appartiene a T e da tutti i suoi discendenti.
 */

/*
 --Soluzione--
 Inizializzo il BST
 Nella funzione isSubtree se il secondo BST è vuoto allora è sicuramente un sottoalbero del primo BST
 Altrimenti attraversa T in preorder
 Per ogni nodo visitato nell'attraversamento verifico se il sottoalbero radicato con questo nodo è identico a S
 Per farlo faccio un preorder contemporaneo su S e T
 Se un nodo visitato non è uguale allora return 0 (false)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
};

struct node* newNode(int data);
int isSubtree(struct node* T, struct node *S);
int preOrder(link root1, link root2);

int main(){

    struct node* T = newNode(3);
    T->right = newNode(1);
    T->right->right = newNode(0);
    T->left = newNode(7);
    T->left->left = newNode(2);
    T->left->right = newNode(2);
    T->left->right->left = newNode(9);


    struct node* S = newNode(7);
    S->right = newNode(2);
    S->left = newNode(2);
    S->right->left = newNode(9);

    if (isSubtree(T, S)==1)
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");

    return 0;
}

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int isSubtree(struct node* T, struct node *S){
    if (S == NULL)
        return 1;

    if (T == NULL)
        return 0;

    if(preOrder(T,S)) return 1;

    /* Se l'albero S non è un sottoalbero di T allora
        prova i sottoalberi di T sinistro e destro uno per uno */
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}

int preOrder(link root1, link root2){
    if(root1==NULL && root2==NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data
            && preOrder(root1->left, root2->left)
            && preOrder(root1->right, root2->right));
}