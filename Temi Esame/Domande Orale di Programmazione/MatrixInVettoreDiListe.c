// Data una matrice di interi, copiarla in un vettore di liste ignorando gli zeri

#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct nodo *link;

struct nodo{
    int val;
    link next;
};

typedef struct lista{
    link head;
}lista_t;

link newNode(int n,link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(int n,link h);
void stampaLista(lista_t *l);

void f(lista_t **V,int M[][N]);

int main(){
    int M[][N] = {
            {1,2,0,4,5},
            {2,3,0,1,2},
            {2,5,6,0,5},
            {0,0,3,6,0},
            {5,4,2,0,9}
    };
    lista_t **V = malloc(N*sizeof(lista_t));
    for(int i=0;i<N;i++)
        V[i] = Crea_Lista();
    f(V,M);

    for(int i=0;i<N;i++)
        stampaLista(V[i]);
}

void f(lista_t **V,int M[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(M[i][j]!=0) V[i]->head = Crea_Nodo_tail(M[i][j],V[i]->head);
        }
    }
}

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}

link newNode(int n,link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        x->val = n;
        x->next = next;
    }
    return x;
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%d ",x->val);
    printf("\n");
}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}
