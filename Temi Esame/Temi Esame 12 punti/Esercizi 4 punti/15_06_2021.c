/*
     Definire una struttura dati adeguata a rappresentare una lista singolo linkata di
    stringhe come ADT I classe, dove il tipo lista si chiami LIST. Indicare esplicitamente
    in quale modulo/file appare la definizione dei tipi proposti. La struttura cos`ı definita
    `e quella da usare per completare la seconda domanda di questo esercizio. Non `e
    ammesso l’uso di funzioni di libreria. Implementare una funzione caratterizzata
    dal seguente prototipo:
    void split(LIST l, char *str, char sep)
    la funzione split suddivide la stringa str in una lista di (sotto)stringhe spezzando
    str ogni volta che viene incontrato il carattere sep.
    Il carattere sep deve essere incluso come primo carattere della (sotto)stringa successiva a quella corrente. Attenersi
    al prototipo dato.
    Esempio 1
    s = "abracadabra" sep = ‘r’
    ab → racadab → ra
    Esempio 2
    s = "ramarro" sep = ‘r’
    rama → r → ro
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct nodo *link;

struct nodo{
    char val[MAX];
    link next;
};

typedef struct lista{
    link head;
}LIST;

link newNode(char val[MAX],link next);
LIST Crea_Lista();
link Crea_Nodo_tail(char val[MAX],link h);
void stampaLista(LIST l);

void split(LIST l, char *str, char sep);

int main(){
    char *str = "abracadabra";
    char sep = 'r';
    LIST l = Crea_Lista();
    split(l,str,sep);
}

void split(LIST l, char *str, char sep){
    // leggo la stringa, appena trovo sep mi fermo e costruisco la sottostringa da aggiungere in coda alla lista
    int start=0,i=0,len= strlen(str);
    char str2[30];
    while(i<len){
        if(str[i]==sep){
            for(int j=start;j<i;j++) str2[j-start] = str[j];
            start = i;
            l.head = Crea_Nodo_tail(str2,l.head);
            str2[0] = '\0';
        }
        i++;
    }
    str2[0] = '\0';
    for(int j=start;j<=len;j++) str2[j-start] = str[j];
    l.head = Crea_Nodo_tail(str2,l.head);
    stampaLista(l);
}

LIST Crea_Lista(){
    LIST *l=malloc(sizeof(LIST));
    l->head=NULL;
    return *l;
}

link Crea_Nodo_tail(char val[MAX],link h){
    link x;
    if(h==NULL) return(newNode(val,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(val,NULL);
    return h;
}

link newNode(char val[MAX],link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        strcpy(x->val,val);
        x->next = next;
    }
    return x;
}

void stampaLista(LIST l){
    link x;
    for(x=l.head;x!=NULL;x=x->next)
        printf("%s\n",x->val);
}