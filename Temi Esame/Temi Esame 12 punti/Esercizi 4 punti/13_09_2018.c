/*
    Sia data una lista di interi, cui si accede mediante puntatore alla testa link1 head. Si scriva una
    funzione C che costruisca una nuova lista “compressa”: per ogni elemento della prima lista si
    memorizza nella seconda lista l’elemento stesso e il numero di ripetizioni consecutive nella prima. Si
    definisca opportunamente il nodo della seconda lista. Il prototipo sia:
    link2 comprimi(link1 head);
    Esempio: se la prima lista è (3, 3, 3, 3, 2, 2, 3, 5, 5, 5), la seconda lista sarà ((3, 4), (2, 2), (3, 1), (5, 3)).
 */

#include<stdlib.h>
#include<stdio.h>

typedef struct nodo *link;
typedef struct nodo2 *link2;

struct nodo{
    int val;
    link next;
};

struct nodo2{
    int val1;
    int val2;
    link2 next;
};

typedef struct lista{
    link head;
}lista_t;

typedef struct lista2{
    link2 head;
}lista_2;

link newNode(int n,link next);
lista_t *Crea_Lista();

link Crea_Nodo_tail(int n,link h);
void stampaLista(lista_t *l);
link2 newNode2(int n1,int n2,link2 next);
link2 Crea_Nodo_tail2(int n1,int n2,link2 h);
lista_2 *Crea_Lista2();
link2 comprimi(link head);
void stampaLista2(lista_2 *l);

int main(){
    lista_t *L = Crea_Lista();
    for(int i=0;i<4;i++) L->head = Crea_Nodo_tail(3,L->head);
    for(int i=0;i<2;i++) L->head = Crea_Nodo_tail(2,L->head);
    L->head = Crea_Nodo_tail(3,L->head);
    for(int i=0;i<3;i++) L->head = Crea_Nodo_tail(5,L->head);
    // stampaLista(L);
    lista_2 *L2 = Crea_Lista2();
    L2->head = comprimi(L->head);
    stampaLista2(L2);
}

link2 comprimi(link head){
    lista_2 *L2 = Crea_Lista2();
    link x,p=NULL;
    int k = 0,cnt=1,last;
    for(x=head;x!=NULL;p=x,x=x->next){
        if(k>0 && x->val==p->val) cnt++;
        else if(k>0 && x->val!=p->val){
            L2->head = Crea_Nodo_tail2(p->val,cnt,L2->head);
            cnt = 1;
        }
        k++;
        if(x->next==NULL) last = x->val;
    }
    L2->head = Crea_Nodo_tail2(last,cnt,L2->head);
    return L2->head;
}

void stampaLista2(lista_2 *l){
    link2 x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("(%d,%d) ",x->val1,x->val2);
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

lista_2 *Crea_Lista2(){
    lista_2 *l=malloc(sizeof(lista_2));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}

link2 Crea_Nodo_tail2(int n1,int n2,link2 h){
    link2 x;
    if(h==NULL) return(newNode2(n1,n2,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode2(n1,n2,NULL);
    return h;
}

link2 newNode2(int n1,int n2,link2 next){
    link2 x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        x->val1 = n1;
        x->val2 = n2;
        x->next = next;
    }
    return x;
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
