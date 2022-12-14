#ifndef LAB6ES3_INVENTARIO_H
#define LAB6ES3_INVENTARIO_H
#define LENMAX 50

#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct statistiche{
    int hp,mp,atk,def,mag,spr;
} typedef stat_t;

struct oggetto{
    char nome[LENMAX],tipologia[LENMAX];
    int mod_hp,mod_mp,mod_atk,mod_def,mod_mag,mod_spr;
} typedef inv_t;

struct tab_equip{
    int inUso;
    inv_t *vettEq;
} typedef tab_equip_t;

struct tabInv_t{
    inv_t *vettInv;
    int nInv;
} typedef tabInv_t;

int alloca_vettInv(FILE *fp);
void stampa_vettInv();
inv_t cerca_oggetto(char *nome);
void stampa_oggetto(inv_t ogg);
inv_t oggSetVoid(inv_t ogg);

#endif //LAB6ES3_INVENTARIO_H
