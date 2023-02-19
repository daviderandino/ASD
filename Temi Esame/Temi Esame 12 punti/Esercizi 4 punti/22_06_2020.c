/*
    Siano dati 2 vettori di interi (positivi, negativi o nulli) v1 e v2 di lunghezza rispettivamente d1 e d2.
    Si scriva una funzione prodCart che generi una lista concatenata
    L contenente il risultato del prodotto cartesiano dei due vettori.
    La lista sia ordinata in fase di costruzione per prodotto crescente degli elementi di ogni coppia. Il
    prototipo della funzione prodCart sia:
    list_t prodCart(int *v1, int d1, int *v2, int d2);
    Si definisca la lista come ADT di I classe e il tipo nodo come quasi ADT. Si indichi
    esplicitamente in quale modulo/file appare la definizione dei tipi proposti. E vietato `
    l’uso di funzioni di libreria.
    Esempio
    v1 = (1, 2, 3)
    v2 = (3, 4, 5, 6)
    L = (1, 3),(1, 4),(1, 5),(2, 3),(1, 6),(2, 4),(3, 3),(2, 5),(3, 4),(2, 6),(3, 5),(3, 6)
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo *link;

struct nodo{
    int val1;
    int val2;
    int prod;
    link next;
};

typedef struct lista{
    link head;
}lista_t;

link newNode(int n1,int n2,link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(int n1,int n2,link h);
void stampaLista(lista_t *l);
link SortListIns(link h, int n1,int n2);

lista_t prodCart(int *v1, int d1, int *v2, int d2);

int main(){
    int v1[] = {1,2,3},d1=3;
    int v2[] = {3,4,5,6},d2=4;
    lista_t L;
    L = prodCart(v1,d1,v2,d2);
    stampaLista(&L);
}

lista_t prodCart(int *v1, int d1, int *v2, int d2){
    lista_t *L = Crea_Lista();
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            L->head = SortListIns(L->head,v1[i],v2[j]);
        }
    }
    return *L;
}

link SortListIns(link h, int n1,int n2) {
    link x, p;
    int prod = n1*n2; // chiave di ordinamento
    if (h==NULL ||h->prod>prod)
        return newNode(n1,n2, h);
    for (x=h->next, p=h;
         x!=NULL && prod>x->prod;
         p=x, x=x->next);
    p->next = newNode(n1,n2, x);
    return h;
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("(%d,%d) ",x->val1,x->val2);
    printf("\n");
}

link Crea_Nodo_tail(int n1,int n2,link h){
    link x;
    if(h==NULL) return(newNode(n1,n2,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n1,n2,NULL);
    return h;
}

link newNode(int n1,int n2,link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        x->val1 = n1;
        x->val2 = n2;
        x->prod = n1*n2;
        x->next = next;
    }
    return x;
}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}