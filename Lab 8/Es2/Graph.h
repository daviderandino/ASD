#ifndef LAB_8_GRAPH_H
#define LAB_8_GRAPH_H

#include "ST.h"
#include "listaadj.h"
#include <stdio.h>

#define MAXC 30

typedef struct edge { int v; int w; int wt; } Edge;
struct graph {int V; int E; int **madj; ST tab; };
typedef struct graph *Graph;

Graph GRAPHinit(int V);
static Edge  EDGEcreate(int v, int w, int wt);
int **MATRIXinit(int r, int c, int val);
void  GRAPHfree(Graph G);
Graph GRAPHload(FILE *);
static void  insertE(Graph G, Edge e);
void  GRAPHinsertE(Graph G, int id1, int id2, int wt);
void  GRAPHstore(Graph G);
void  GRAPHedges(Graph G, Edge *a);
void check_adiacenza_madj(Graph G);
Listaadj LISTload(Graph G);
void stampaVerticiOrdinati(Graph G);
static int graph_get_index(Graph G, char *nome, char *rete);

#endif //LAB_8_GRAPH_H
