#include "personaggi.h"


link h=NULL;

link newNode(pg_t val,link next){
    link x = malloc(sizeof *x);
    if(x==NULL)
        return NULL;
    else{
        x->val = val;
        x->next = next;
    }
    return x;
}

link listInsTail(pg_t val){
    link x;
    if(h==NULL)
        return newNode(val,NULL);
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(val,NULL);
    return h;
}

int carica_lista(FILE *fp){
    pg_t pers;
    int cnt=0;
    while(!feof(fp)){
        fscanf(fp,"%s%s%s%d%d%d%d%d%d",pers.codice,pers.nome,pers.classe,&pers.stat.hp,&pers.stat.mp,&pers.stat.atk,&pers.stat.def,&pers.stat.mag,&pers.stat.spr);
        cnt++;
        h = listInsTail(pers);
        pers.equip.vettEq = (inv_t *) malloc(8*sizeof(inv_t));
    }
    if(cnt!=0){
        printf("Lista caricata\n");
        stampa_lista();
    }
    return cnt;
}

void stampa_lista(){
    link x;
    for(x=h;x!=NULL;x=x->next)
        printf("%s %s %s %d %d %d %d %d %d\n",x->val.codice,x->val.nome,x->val.classe,x->val.stat.hp,x->val.stat.mp,x->val.stat.atk,x->val.stat.def,x->val.stat.mag,x->val.stat.spr);
}

void elimina_personaggio(char *cod){
    link x;
    for(x=h;x!=NULL;x=x->next){
        if(strcmp(x->val.codice,cod)==0){
            listDelkeyR(cod);
            printf("Personaggio eliminato!\n");
            stampa_lista();
            return;
        }
    }
    printf("Personaggio non trovato\n");

}

void aggiungi_personaggio(){
    pg_t pers;
    printf("Inserisci codice:\n");
    scanf("%s",pers.codice);
    printf("Inserisci classe:\n");
    scanf("%s",pers.classe);
    printf("Inserisci nome:\n");
    scanf("%s",pers.nome);
    printf("Inserisci hp, mp, atk, def, mag, spr:\n");
    scanf("%d%d%d%d%d%d",&pers.stat.hp,&pers.stat.mp,&pers.stat.atk,&pers.stat.def,&pers.stat.mag,&pers.stat.spr);
    listInsTail(pers);
    pers.equip.vettEq = (inv_t *) malloc(8*sizeof(inv_t));
    printf("Personaggio aggiunto!\n");
    stampa_lista();
}

void listDelkeyR(char *cod){
    link x,p;
    for(x=h,p=NULL;x!=NULL;p=x,x=x->next){
        if(strcmp(cod,x->val.codice)==0){
            if(x==h) h = x->next;
            else p->next = x->next;
        }
    }
}

void aggiungi_oggetto(){

}
