#include <stdlib.h>
#include "Graph.h"

static int graph_get_index(Graph G, char *nome, char *rete) {
    int id;
    id = STgetindex(G->tab, nome);
    if (id == -1)
        id = STinsert(G->tab, nome, rete);
    return id;
}

static Edge EDGEcreate(int v, int w, int wt) {
    Edge e;
    e.v = v;
    e.w = w;
    e.wt = wt;
    return e;
}

int **MATRIXinit(int r, int c, int val) {
    int i, j;
    int **t = malloc(r * sizeof(int *));

    for (i=0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    for (i=0; i < r; i++)
        for (j=0; j < c; j++)
            t[i][j] = val;
    return t;
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->madj = MATRIXinit(V, V, 0);
    G->tab = STinit(V);
    return G;
}

Graph GRAPHload(FILE *fin){
    int V,edges=0,id1,id2,wt;
    char elab1[MAXC],rete1[MAXC],elab2[MAXC],rete2[MAXC],ch;
    Graph G;
    for (ch = getc(fin); ch != EOF; ch = getc(fin))
        if (ch == '\n') edges+=1;
    V = 2*edges;
    rewind(fin);
    G= GRAPHinit(V);
    for(int i=0;i<edges;i++){
        fscanf(fin,"%s %s %s %s %d\n",elab1,rete1,elab2,rete2,&wt);
        id1 = graph_get_index(G,elab1,rete1); id2 = graph_get_index(G,elab2,rete2);
        GRAPHinsertE(G,id1,id2,wt);
    }
    printf("Grafo acquisito con successo\n");
    return G;
}

void GRAPHinsertE(Graph G, int id1, int id2, int wt) {
    insertE(G, EDGEcreate(id1, id2, wt));
}

static void  insertE(Graph G, Edge e) {
    int v = e.v, w = e.w, wt = e.wt;
    if (G->madj[v][w] == 0)
        G->E++;
    G->madj[v][w] = wt;
    G->madj[w][v] = wt;
}

void GRAPHedges(Graph G, Edge *a) {
    int v, w, E = 0;
    for (v=0; v < G->V; v++)
        for (w=v+1; w < G->V; w++)
            if (G->madj[v][w] != 0)
                a[E++] = EDGEcreate(v, w, G->madj[v][w]);
}

void GRAPHstore(Graph G){
    int i;
    Edge *a;

    a=malloc(G->E * sizeof(Edge));
    if(a==NULL) return;

    GRAPHedges(G,a);

    for(i=0;i<G->E;i++)
        printf("%s %s %s %s %d\n", STsearchByIndiceNome(G->tab,a[i].v), STsearchByIndiceRete(G->tab,a[i].v),STsearchByIndiceNome(G->tab,a[i].w),
        STsearchByIndiceRete(G->tab,a[i].w),a[i].wt);
    free(a);
}

Listaadj LISTload(Graph G){
    Listaadj L=NULL;
    int i,j;
    L=LISTinit((STsize(G->tab)));
    for(i=0;i< STsize(G->tab);i++){
        STinsert_t(L,STsearchByIndiceNome(G->tab,i),STsearchByIndiceRete(G->tab,i));
    }
    for(i=0;i<STsize(G->tab);i++){
        for(j=0;j< STsize(G->tab);j++){
            if(G->madj[i][j]!=0)
                LISTinsertL(L,i,j,G->madj[i][j]);
        }
    }
    return L;
}

void check_adiacenza_madj(Graph G){
    char v1[MAXC],v2[MAXC],v3[MAXC];
    int id1,id2,id3,k=0;
    printf("Inserisci i nomi dei tre vertici: \n");
    scanf("%s %s %s",v1,v2,v3);
    id1= STgetindex(G->tab,v1); id2= STgetindex(G->tab,v2); id3= STgetindex(G->tab,v3);
    if(G->madj[id1][id2]==G->madj[id2][id1] && G->madj[id1][id2]!=0 && G->madj[id2][id1]!=0) k++;
    if(G->madj[id1][id3]==G->madj[id3][id1] && G->madj[id3][id1]!=0 && G->madj[id1][id3]!=0) k++;
    if(G->madj[id2][id3]==G->madj[id3][id2] && G->madj[id2][id3]!=0 && G->madj[id3][id2]!=0) k++;
    if(k==3) printf("Vertici adiacenti \n");
    else printf("Vertici non adiacenti\n");
}

void stampaVerticiOrdinati(Graph G){
    int i,j, *vett = malloc(STsize(G->tab) * sizeof(int));

    STsort(G->tab,vett);
    for(i=0;i< STsize(G->tab);i++){
        printf("---Archi insistenti sul vertice %s---\n", STsearchByIndiceNome(G->tab,vett[i]));
        for(j=0;j< STsize(G->tab);j++){
            if(G->madj[vett[i]][vett[j]]!=0 && i!=j){
                printf(" %s\n", STsearchByIndiceNome(G->tab,vett[j]));
            }
        }
    }
    free(vett);
}

void GRAPHfree(Graph G) {
    int i;
    if(G==NULL) return;
    for (i=0; i<G->V; i++)
        free(G->madj[i]);
    free(G->madj);
    STfree(G->tab);
    free(G);
}