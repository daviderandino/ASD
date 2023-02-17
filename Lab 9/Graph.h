#ifndef LAB_9_GRAPH_H
#define LAB_9_GRAPH_H

#include "ST.h"
#define MAXC 30

typedef struct node *link;

typedef struct edge { int v; int w; int wt; } Edge;
struct node { int v; int wt; link next; } ;
struct graph { int V; int E; link *ladj; ST tab; link z; } ;

static Edge  EDGEcreate(int v, int w, int wt);

typedef struct graph *Graph;

Graph GRAPHinit(int V);
static link  NEW(int v, int wt, link next);
void  GRAPHfree(Graph G);
Graph GRAPHload(FILE *fin);
void  GRAPHstore(Graph G, FILE *fin);
void  GRAPHinsertE(Graph G, int id1, int id2, int wt);
void  GRAPHremoveE(Graph G, int id1, int id2);
void  GRAPHedges(Graph G, Edge *a);
void GRAPHdfs(Graph G, int id,int *flag_arco_back, Edge **dagedges,int *cnt,int *cntedgeback);
void dfsR(Graph G,Edge e,int *time,int *pre,int *post,int *st,int **flag_arco_back,Edge ***dagedges,int **cnt,int **cntedgeback);
void EDGEdag(Graph G,Edge *dagedges,int cnt,int countedgeback);
int GRAPHfvertexdim(Graph G);
void TSdfsR(Graph D, int v, int *ts, int *pre, int *time);
void DAGrts(Graph D);
void DAGcamminimax(Graph D,int *st,int id,int i);

#endif //LAB_9_GRAPH_H
