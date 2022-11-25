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
        pers.equip.inUso = 0;
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

void elimina_personaggio(){
    stampa_lista();
    char cod[LENMAX];
    printf("Inserisci il codice del personaggio che vuoi eliminare:\n");
    scanf("%s",cod);
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
    pers.equip.inUso = 0;
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

void aggiungi_oggetto(int num_ogg){
    char cod_pers[LENMAX],nome_ogg[LENMAX];
    int i;
    inv_t oggetto;
    pg_t pg;
    stampa_lista();
    printf("A quale personaggio vuoi aggiungere un oggetto? Inserisci il codice:\n");
    scanf("%s",cod_pers);
    pg = cerca_personaggio(cod_pers);
    if(strcmp(pg.codice,"") == 0){
        printf("Input errato\n");
        return;
    }
    stampa_vettInv(num_ogg);
    printf("Inserisci il nome dell'oggetto da aggiungere:\n");
    scanf("%s",nome_ogg);
    oggetto = cerca_oggetto(nome_ogg,num_ogg);
    link x;
    for(x=h;x!=NULL;x=x->next){
        if(strcmp(x->val.codice,cod_pers)==0){
            i = x->val.equip.inUso;
            x->val.equip.vettEq[i] = oggetto;
            x->val.equip.inUso++;
            stampa_dettagli_personaggio(x->val);
        }
    }
}

pg_t cerca_personaggio(char *cod){
    link x;
    for(x=h;x!=NULL;x=x->next){
        if(strcmp(x->val.codice,cod)==0)
            return x->val;
    }
    return pgSetVoid();
}

pg_t pgSetVoid(){
    pg_t pg;
    strcpy(pg.nome,"");
    strcpy(pg.codice,"");
    strcpy(pg.classe,"");
    return pg;
}

void stampa_dettagli_personaggio(pg_t pg){
    printf("%s %s %s %d %d %d %d %d %d\n",pg.codice,pg.nome,pg.classe,pg.stat.hp,pg.stat.mp,pg.stat.atk,pg.stat.def,pg.stat.mag,pg.stat.spr);
    printf("Oggetti equipaggiati: \n");
    for(int i=0;i<pg.equip.inUso;i++){
        printf("%s %s\n",pg.equip.vettEq[i].nome,pg.equip.vettEq[i].tipologia);
    }
}

void rimuovi_oggetto(int num_ogg){
    char cod_pers[LENMAX],nome_ogg[LENMAX];
    int i;
    pg_t pg;
    stampa_lista();
    printf("A quale personaggio vuoi rimuovere un oggetto? Inserisci il codice:\n");
    scanf("%s",cod_pers);
    pg = cerca_personaggio(cod_pers);
    if(strcmp(pg.codice,"") == 0){
        printf("Input errato\n");
        return;
    }
    if(pg.equip.inUso==0){
        printf("Il personaggio non ha oggetti equipaggiati!\n");
        return;
    }
    stampa_dettagli_personaggio(pg);
    printf("Quale oggetto vuoi rimuovere? Inserisci il nome:\n");
    scanf("%s",nome_ogg);

    link x;
    for(x=h;x!=NULL;x=x->next){
        if(strcmp(x->val.codice,cod_pers)==0){
            i = x->val.equip.inUso;
            for(int j=0;j<i;j++){
                if(strcmp(x->val.equip.vettEq[j].nome,nome_ogg)==0){
                    x->val = elimina_mod_ogg(x->val,j);
                    x->val.equip.inUso--;
                }
            }
        }
    }
    printf("Oggetto rimosso con successo\n");
}

pg_t elimina_mod_ogg(pg_t pg,int j){
    pg.stat.hp = pg.stat.hp - pg.equip.vettEq[j].mod_hp;
    pg.stat.def = pg.stat.def - pg.equip.vettEq[j].mod_def;
    pg.stat.mag = pg.stat.mag - pg.equip.vettEq[j].mod_mag;
    pg.stat.spr = pg.stat.spr - pg.equip.vettEq[j].mod_spr;
    pg.stat.mp = pg.stat.mp - pg.equip.vettEq[j].mod_mp;
    pg.stat.atk = pg.stat.atk - pg.equip.vettEq[j].mod_atk;
    return pg;
}


void calcola_stats(){
    char cod_pers[LENMAX];
    int k;
    int hp=0,mp=0,atk=0,def=0,mag=0,spr=0;
    pg_t pg;
    printf("Di che personaggio vuoi calcolare le statistiche? Inserisci il codice:\n");
    scanf("%s",cod_pers);
    pg = cerca_personaggio(cod_pers);
    k = pg.equip.inUso;
    for(int i=0;i<k;i++){
        hp = pg.equip.vettEq[i].mod_hp + hp;
        mp = pg.equip.vettEq[i].mod_mp + mp;
        atk = pg.equip.vettEq[i].mod_atk + atk;
        def = pg.equip.vettEq[i].mod_def + def;
        mag = pg.equip.vettEq[i].mod_mag + mag;
        spr = pg.equip.vettEq[i].mod_spr + spr;
    }
    link x;
    for(x=h;x!=NULL;x=x->next){
        if(strcmp(x->val.codice,cod_pers)==0){
            x->val.stat.def+=def;x->val.stat.atk+=atk;x->val.stat.mp+=mp;
            x->val.stat.mag+=mag;x->val.stat.spr+=spr;x->val.stat.hp+=hp;
            pg = x->val;
        }
    }
    printf("Statistiche calcolate con successo\n");
    stampa_dettagli_personaggio(pg);
}
