#ifndef LAB6ES3_PERSONAGGI_H
#define LAB6ES3_PERSONAGGI_H


#include "inventario.h"

typedef struct node *link;


struct personaggio{
    char codice[7];
    char nome[LENMAX];
    char classe[LENMAX];
    stat_t stat;
    tab_equip_t equip;
} typedef pg_t;

struct node{
    pg_t val;
    link next;
};

struct tabPg_t{
    link *head;
    int nPg;
} typedef tabPg_t;

link newNode(pg_t val,link next);
link listInsTail(pg_t val);
int carica_lista(FILE *fp);
void stampa_lista();
void elimina_personaggio();
void aggiungi_personaggio();
pg_t pgSetVoid();
void listDelkeyR(char *cod);
void aggiungi_oggetto();
void rimuovi_oggetto();
pg_t cerca_personaggio(char *cod);
void stampa_dettagli_personaggio(pg_t pg);
void calcola_stats();
pg_t elimina_mod_ogg(pg_t pg,int j);

#endif //LAB6ES3_PERSONAGGI_H
