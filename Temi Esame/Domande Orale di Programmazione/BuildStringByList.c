// data una lista di stringhe implementata come ADT di 1 classe, scrivere una funzione
// che ritorna una stringa enorme con tutte le stringhe della lista al suo interno

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo *link;

struct nodo{
    char val[10];
    link next;
};

typedef struct lista{
    link head;
}lista_t;

link newNode(char s[20],link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(char s[20],link h);
void stampaLista(lista_t *l);
char *crea(lista_t *l,char *string);

int main(){
    lista_t *l;
    char *string;
    l = Crea_Lista(l);
    l->head = Crea_Nodo_tail("ciao ",l->head);
    l->head = Crea_Nodo_tail("a ",l->head);
    l->head = Crea_Nodo_tail("tutti ",l->head);
    // stampaLista(l);
    string = crea(l,string);
    printf("%s",string);
}

char *crea(lista_t *l,char *string){
    link x;
    int len=0,k=0;
    for(x=l->head;x!=NULL;x=x->next) len+= strlen(x->val);
    string = malloc(len);
    for(x=l->head;x!=NULL;x=x->next){
        for(int i=0;i<strlen(x->val);i++)
            string[k++] = x->val[i];
    }
    string[k] = '\0';
    return string;

}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link Crea_Nodo_tail(char s[20],link h){
    link x;
    if(h==NULL) return(newNode(s,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(s,NULL);
    return h;
}

link newNode(char s[20],link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        strcpy(x->val,s);
        x->next = next;
    }
    return x;
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%s\n",x->val);
}
