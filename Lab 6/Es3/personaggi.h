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
void elimina_personaggio(char *cod);
void aggiungi_personaggio();
void listDelkeyR(char *cod);
void num_oggetti(int n);
void aggiungi_oggetto();

#endif //LAB6ES3_PERSONAGGI_H
