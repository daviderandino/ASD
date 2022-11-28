#include "inventario.h"

tabInv_t *tabInv;

int alloca_vettInv(FILE *fp){
    int n;
    fscanf(fp,"%d",&n);
    tabInv = malloc(sizeof(tabInv_t));
    tabInv->vettInv = (inv_t *) malloc(n*sizeof(inv_t));
    tabInv->nInv = n;
    for(int i=0;i<n;i++){
        fscanf(fp,"%s%s%d%d%d%d%d%d",tabInv->vettInv[i].nome,tabInv->vettInv[i].tipologia,&tabInv->vettInv[i].mod_hp,&tabInv->vettInv[i].mod_mp,&tabInv->vettInv[i].mod_atk,&tabInv->vettInv[i].mod_def,&tabInv->vettInv[i].mod_mag,&tabInv->vettInv[i].mod_spr);
    }
    printf("Vettore di oggetti caricato con successo\n");
    stampa_vettInv();
    return n;
}

void stampa_vettInv(){
    for(int i=0;i<tabInv->nInv;i++){
        stampa_oggetto(tabInv->vettInv[i]);
    }
}

inv_t cerca_oggetto(char *nome){
    for(int i=0;i<tabInv->nInv;i++){
        if(strcmp(tabInv->vettInv[i].nome,nome)==0)
            return tabInv->vettInv[i];
    }
}

void stampa_oggetto(inv_t ogg){
    printf("%s %s %d %d %d %d %d %d\n",ogg.nome,ogg.tipologia,ogg.mod_hp,ogg.mod_mp,ogg.mod_atk,ogg.mod_def,ogg.mod_mag,ogg.mod_spr);
}

inv_t oggSetVoid(inv_t ogg){
    ogg.mod_spr = 0; ogg.mod_mag = 0; ogg.mod_def = 0; ogg.mod_atk = 0; ogg.mod_mp = 0; ogg.mod_hp = 0;
    strcpy(ogg.nome,"");
    strcpy(ogg.tipologia,"");
    return ogg;
}