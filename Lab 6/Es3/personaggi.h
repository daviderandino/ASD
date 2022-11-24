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

link newNode(pg_t val,link next);
link listInsTail(pg_t val);
int carica_lista(FILE *fp);
void stampa_lista();
void elimina_personaggio();
void aggiungi_personaggio();
void listDelkeyR(char *cod);
void aggiungi_oggetto(int num_ogg);
void rimuovi_oggetto(int num_ogg);
pg_t cerca_personaggio(char *cod);
void stampa_dettagli_personaggio(pg_t pg);
void calcola_stats();

#endif //LAB6ES3_PERSONAGGI_H
