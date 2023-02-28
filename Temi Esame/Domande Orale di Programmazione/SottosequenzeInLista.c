// Data una stringa aabb;ccbb;ddbb; si faccia una funzione che
// permetta di dividere le sottosequenze comprese tra i ‘ ; ’ e si inseriscano le liste risultanti in una lista ordinata.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo *link;

struct nodo{
    char val[20];
    link next;
};

typedef struct lista{
    link head;
}lista_t;

link newNode(char val[20],link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(char val[20],link h);
void stampaLista(lista_t *l);
link listDelTail(link h);
link listDelKey(link h,int n);
void split(lista_t *L,char *str);

int main(){
    char str[] = "aabb;ccbb;ddbb";
    lista_t *L = Crea_Lista();
    split(L,str);
}

void split(lista_t *L,char *str){
    int start=0,i=0,len= strlen(str);
    char substr[20];
    while(i<len){
        if(str[i]==';'){
            for(int j=start;j<i;j++) substr[j-start] = str[j];
            start = i+1;
            L->head = Crea_Nodo_tail(substr,L->head);
            substr[0] = '\0';
        }
        i++;
    }
    substr[0] = '\0';
    for(int j=start;j<=len;j++) substr[j-start] = str[j];
    L->head = Crea_Nodo_tail(substr,L->head);
    stampaLista(L);
}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link Crea_Nodo_tail(char val[20],link h){
    link x;
    if(h==NULL) return(newNode(val,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(val,NULL);
    return h;
}

link newNode(char val[20],link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        strcpy(x->val,val);
        x->next = next;
    }
    return x;
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%s\n",x->val);
}
