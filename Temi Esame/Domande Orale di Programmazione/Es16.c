// Da matrice sparsa inserire gli elementi
// non nulli in un vettore di liste(ogni riga<->una lista), nel nodo della lista valore intero e indice della colonna nella matrice;

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

int main(){
    int M[N][N] = {
            {0,2,0,1,0},
            {0,0,3,1,4},
            {0,0,7,0,0},
            {3,4,0,0,0},
            {5,0,2,0,0}
    };
    lista_t **V = malloc(N*sizeof(lista_t));
    for(int i=0;i<N;i++) V[i] = Crea_Lista();

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            if(M[i][j]!=0) V[i]->head = Crea_Nodo_tail(M[i][j],V[i]->head);
    }

    for(int i=0;i<N;i++)
        stampaLista(V[i]);

}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link Crea_Nodo_head(int n,link h){
    h = newNode(n,h);
    return h;
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