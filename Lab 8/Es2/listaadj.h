#ifndef LAB_8_LISTAADJ_H
#define LAB_8_LISTAADJ_H

#include "ST.h"
#include <stdlib.h>
#include <stdio.h>
#define MAXCL 50

typedef struct edgelist {
    int v; int w; int wt;
} Edgelist;

typedef struct listadj *Listaadj;

Listaadj LISTinit(int V);
void  LISTinsertL(Listaadj L, int id1, int id2, int wt);
void  LISTstore(Listaadj G);
void  LISTedges(Listaadj G, Edgelist *a);
void STinsert_t(Listaadj L,char *nome, char *rete);
void check_adiacenza_listadj(Listaadj L);

#endif //LAB_8_LISTAADJ_H
