#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

static void insertE(Graph G, Edge e);
static void removeE(Graph G, Edge e);

static Edge EDGEcreate(int v, int w, int wt) {
    Edge e;
    e.v = v;
    e.w = w;
    e.wt = wt;
    return e;
}

static link NEW(int v, int wt, link next) {
    link x = malloc(sizeof *x);
    if (x == NULL)
        return NULL;
    x->v = v;
    x->wt = wt;
    x->next = next;
    return x;
}

Graph GRAPHinit(int V) {
    int v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->z = NEW(-1, 0, NULL);
    G->ladj = malloc(G->V*sizeof(link));
    for (v = 0; v < G->V; v++)
        G->ladj[v] = G->z;
    G->tab = STinit(V);
    return G;
}

void GRAPHfree(Graph G) {
    link t, next;
    for (int i=0; i < G->V; i++)
        for (t=G->ladj[i]; t != G->z; t = next) {
            next = t->next;
            free(t);
        }
    STfree(G->tab);
    free(G->ladj);
    free(G->z);
    free(G);
}

Graph GRAPHload(FILE *fin) {
    int V, i, id1, id2, wt;
    char label1[MAXC], label2[MAXC];
    Graph G;
    fscanf(fin, "%d", &V);
    G = GRAPHinit(V);
    for (i=0; i<V; i++) {
        fscanf(fin, "%s", label1);
        STinsert(G->tab, label1, i);
    }
    while(fscanf(fin, "%s %s %d", label1, label2, &wt) == 3) {
        id1 = STsearch(G->tab, label1);
        id2 = STsearch(G->tab, label2);
        if (id1 >= 0 && id2 >=0)
            GRAPHinsertE(G, id1, id2, wt);
    }
    return G;
}

void  GRAPHedges(Graph G, Edge *a) {
    int E = 0;
    link t;
    for (int i=0; i < G->V; i++)
        for (t=G->ladj[i]; t != G->z; t = t->next)
            a[E++] = EDGEcreate(i, t->v, t->wt);
}

void GRAPHstore(Graph G, FILE *fout) {
    int i;
    Edge *a;
    a = malloc(G->E * sizeof(Edge));
    if (a == NULL) return;
    GRAPHedges(G, a);
    for (i = 0; i < G->E; i++)
        fprintf(fout, "(%s, %s), Peso: %d\n", STsearchByIndex(G->tab, a[i].v), STsearchByIndex(G->tab, a[i].w), a[i].wt);
    free(a);
}


void GRAPHinsertE(Graph G, int id1, int id2, int wt) {
    insertE(G, EDGEcreate(id1, id2, wt));
}

void GRAPHremoveE(Graph G, int id1, int id2) {
    removeE(G, EDGEcreate(id1, id2, 0));
}

static void insertE(Graph G, Edge e) {
    int v = e.v, w = e.w, wt = e.wt;

    G->ladj[v] = NEW(w, wt, G->ladj[v]);
    G->E++;
}

static void removeE(Graph G, Edge e) {
    int v = e.v, w = e.w;
    link x;
    if (G->ladj[v]->v == w) {
        G->ladj[v] = G->ladj[v]->next;
        G->E--;
    }
    else
        for (x = G->ladj[v]; x != G->z; x = x->next)
            if (x->next->v == w) {
                x->next = x->next->next;
                G->E--;
            }
}


void dfsR(Graph G, Edge e, int *time, int *pre, int *post, int *st, int **flag_arco_back,Edge ***dagedges, int **cnt, int **cntedgeback) {
    int v, w = e.w;
    link t;
    Edge x;
    st[e.w] = e.v;
    pre[w] = (*time)++;
    for (t = G->ladj[w]; t != G->z; t = t->next)
        if (pre[t->v] == -1)
            dfsR(G, EDGEcreate(w, t->v,t->wt), time, pre, post, st,&(*flag_arco_back),dagedges,&(*cnt),&(*cntedgeback));
        else {
            v = t->v;
            x = EDGEcreate(w, v,t->wt);
            if (post[v] == -1){ // condizione necessaria per avere un arco B (back)
                **flag_arco_back=1;
                (**dagedges)[**cnt].w=x.w;
                (**dagedges)[**cnt].v=x.v;
                (**dagedges)[**cnt].wt=t->wt;
                (**cnt)++;
                (**cntedgeback)++;
                printf("(%s, %s) | Peso: %d\n", STsearchByIndex(G->tab, x.v), STsearchByIndex(G->tab, x.w),t->wt);
            }
        }
    post[w] = (*time)++;
}

void GRAPHdfs(Graph G, int id,int *flag_arco_back, Edge **dagedges,int *cnt,int *cntbackedge) {
    int v, time=0, *pre, *post, *st;
    pre = malloc(G->V * sizeof(int));
    post = malloc(G->V * sizeof(int));
    st = malloc(G->V * sizeof(int));

    if ((pre == NULL) || (post == NULL) || (st == NULL)) return;

    for (v=0; v < G->V; v++) {
        pre[v] = -1;
        post[v] = -1;
        st[v] =  -1;
    }
    *cntbackedge=0;
    dfsR(G, EDGEcreate(id,id,0), &time, pre, post, st,&flag_arco_back,&(dagedges),&cnt,&cntbackedge);

    for (v=0; v < G->V; v++) if (pre[v]== -1) dfsR(G, EDGEcreate(v,v,0), &time, pre, post, st,&flag_arco_back,&dagedges,&cnt,&cntbackedge);
}

int GRAPHfvertexdim(Graph G){
    return STsize(G->tab);
}

void EDGEdag(Graph G,Edge *dagedges,int cnt,int cntbackedge){
    int k=0,max=0,weight_sum;
    int r;
    for(int i=0;i<(cnt/cntbackedge);i++){
        weight_sum=0;
        for(int j=0;j<cntbackedge;j++){
            weight_sum=weight_sum+dagedges[k].wt;
            k++;
        }
        if(weight_sum>max){
            max=weight_sum;
            r=i;
        }
    }
    printf("MAX %d %d %d\n",dagedges[r].v,dagedges[r].w,dagedges[r].wt);

    for(k=0;k<cntbackedge;k++) GRAPHremoveE(G,dagedges[r+k].v,dagedges[r+k].w);
    GRAPHstore(G,stdout);

}

void TSdfsR(Graph D, int v, int *ts, int *pre, int *time) {
    link t; pre[v] = 0;
    for (t = D->ladj[v]; t != D->z; t = t->next)
        if (pre[t->v] == -1)
            TSdfsR(D, t->v, ts, pre, time);
    ts[(*time)--] = v;
}
void DAGrts(Graph D) {
    int v,i, time = (D->V)-1, *pre, *ts;
    pre=malloc((D->V)*sizeof(Graph));
    ts=malloc((D->V)*sizeof(Graph));
    for (v=0; v < D->V; v++) { pre[v] = -1; ts[v] = -1; }
    for (v=0; v < D->V; v++) if (pre[v]== -1) TSdfsR(D, v, ts, pre, &time);
    printf("DAG nodes in topological order \n");
    for (v=0; v<D->V; v++)
        printf("%s ", STsearchByIndex(D->tab, ts[v]));printf("\n\n");
    for(i=0;i<(D->V);i++) DAGcamminimax(D,ts,ts[i],i);
}

void DAGcamminimax(Graph D,int *st,int id,int i){
    link t;
    int *d,v=id,w; // vettore stime
    d=malloc((D->V)*sizeof(int));
    for(int j=0;j<(D->V);j++)
        d[j]=-1; // stima iniziale negativa per applicare la relaxation inversa
    d[v]=0; // partiamo da un certo vertice e il cammino massimo dal vertice stesso è 0
    for(int j=i;j<D->V;j++){
        w=st[j];
        if(d[w]==-1) continue;
        for (t = D->ladj[w]; t != D->z; t = t->next){
            if(d[t->v]==-1 || d[t->v]<d[w]+t->wt)
                d[t->v] = d[w] + t->wt;
        }
    }

    for (v = 0; v < D->V; v++)
        printf("%s: %d\n", STsearchByIndex(D->tab, v), d[v]);
    printf("\n---\n");
}