/*
    Si supponga di dover implementare un albero di grado 3, i cui nodi contengono valori interi.
    Definire la struttura wrapper dell'albero (come ADT di prima categoria) e dei nodi (a libera scelta del candidato),
    evidenziando la suddivisione tra file dei vari contenuti. Si realizzi inoltre una funzione wrapper C void
    countIf(nTREE t, ...); e la corrispondente funzione di visita ricorsiva, che visiti l'albero e ritorni il conteggio
    del numero di nodi aventi esattamente 1, esattamente 2 o esattamente 3 figli. La funzione deve quindi calcolare e
    rendere disponibili a chi la invoca tre valori distinti, per rispondere alla richiesta posta.
 */

#include<stdlib.h>
#include<stdio.h>
#define N 3

typedef struct node* link;

struct node{
    int data;
    link figli[N];
} typedef nTree;

void countIf(nTree *t, int *cnt1,int *cnt2,int *cnt3);

int main(){
    int count1=0,count2=0,count3=0;
    // root->figli[i]->figli[i]->figli[i] deve essere inizializzato a NULL

}

void countIf(nTree *t, int *cnt1,int *cnt2,int *cnt3){
    int cnt=0;
    for(int i=0;i<N;i++)
        if(t->figli[i]!=NULL) cnt++;
    if(cnt==1) (*cnt1)++;
    if(cnt==2) (*cnt2)++;
    if(cnt==3) (*cnt3)++;
    for(int i=0;i<N;i++) countIf(t->figli[i], cnt1,cnt2,cnt3);
}

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->figli[0]->figli[0]->figli[0] = NULL;
    return (node);
}
