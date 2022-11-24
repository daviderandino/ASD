#include "inventario.h"

inv_t *vettInv;

int alloca_vettInv(FILE *fp){
    int n;
    fscanf(fp,"%d",&n);
    vettInv = (inv_t *) malloc(n*sizeof(inv_t));
    for(int i=0;i<n;i++){
        fscanf(fp,"%s%s%d%d%d%d%d%d",vettInv[i].nome,vettInv[i].tipologia,&vettInv[i].mod_hp,&vettInv[i].mod_mp,&vettInv[i].mod_atk,&vettInv[i].mod_def,&vettInv[i].mod_mag,&vettInv[i].mod_spr);
    }
    printf("Vettore di oggetti caricato con successo\n");
    stampa_vettInv(n);
    return n;
}

void stampa_vettInv(int n){
    for(int i=0;i<n;i++){
        printf("%s %s %d %d %d %d %d %d\n",vettInv[i].nome,vettInv[i].tipologia,vettInv[i].mod_hp,vettInv[i].mod_mp,vettInv[i].mod_atk,vettInv[i].mod_def,vettInv[i].mod_mag,vettInv[i].mod_spr);
    }
}
