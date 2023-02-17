/*
 Data una lista, un min e un max rimuovere gli elementi inferiori del min OR maggiori del max
 ESEMPIO:
 L = 1 2 3 4 5 6 7 8 9 10
 min = 3 max = 8
 L sarà 3 4 5 6 7 8
 */

#include<stdlib.h>
#include<stdio.h>

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
void remove_el(lista_t *l,int min,int max);
link listDelKey(link h, int k);

int main(){
    lista_t *l = Crea_Lista();
    for(int i=1;i<=10;i++) l->head = Crea_Nodo_tail(i,l->head);
    stampaLista(l);
    printf("\n");
    remove_el(l,3,8);
    stampaLista(l);
}

void remove_el(lista_t *l,int min,int max){
    link x,t;
    for(x=l->head;x!=NULL;){
        if(x->val<min || x->val>max){
            t = x->next;
            l->head = listDelKey(l->head,x->val);
            x = t;
        }
        else x = x->next;
    }

}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
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

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}

link listDelKey(link h, int k) {
    link x, p;
    if (h == NULL)
        return NULL;
    for (x=h, p=NULL; x!=NULL; p=x, x=x->next) {
        if (x->val==k){
            if (x==h)
                h = x->next;
            else
                p->next = x->next;
            free(x);
            break;
        }
    }
    return h;
}
