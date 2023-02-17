#include "listaadj.h"

typedef struct node *link;

struct node { int v; int wt; link next; };
struct listadj{int V; int E; link *ladj; ST tabL; link z;} ;
static link NEW(int v,int wt,link next);
static Edgelist EDGElistcreate(int v,int w,int wt);
static void insertL(Listaadj L, Edgelist e);

static link NEW(int v,int wt,link next){
    link x=malloc(sizeof *x);
    if(x==NULL) return NULL;
    x->v=v; x->wt=wt; x->next=next;
    return x;
}

static Edgelist EDGElistcreate(int v,int w,int wt){
    Edgelist e;
    e.v=v;
    e.w=w;
    e.wt=wt;
    return e;
}

Listaadj LISTinit(int V){
    int v;
    Listaadj L = malloc(sizeof *L);
    L->V = V; L->E = 0;
    L->z = NEW(-1, 0, NULL);
    L->ladj = malloc(L->V*sizeof(link));
    for (v = 0; v < L->V; v++)
        L->ladj[v] = L->z;
    L->tabL = STinit(V);
    return L;
}

void LISTedges(Listaadj L, Edgelist *a){
    int v,E=0;
    link t;
    for(v=0;v< STsize(L->tabL);v++){
        for(t=L->ladj[v];t!=L->z;t=t->next){
            a[E++]= EDGElistcreate(v,t->v,t->wt);
        }
    }
}

void LISTinsertL(Listaadj L, int id1, int id2, int wt){
    insertL(L,EDGElistcreate(id1,id2,wt));
}
static void insertL(Listaadj L, Edgelist e) {
    int v = e.v, w = e.w, wt = e.wt;
    L->ladj[v] = NEW(w, wt, L->ladj[v]);
    L->E++;
}

void LISTstore(Listaadj L) {
    int i;
    Edgelist *a;

    a = malloc(STsize(L->tabL) * sizeof(Edgelist));
    LISTedges(L, a);

    printf("Vertici: %d\n", L->V);
    printf("Archi: %d\n", (L->E)/2);
    for (i = 0; i < STsize(L->tabL); i++ )
        printf("%s\n", STsearchByIndiceNome(L->tabL, i));


    for (i = 0; i < (L->E); i++)
        printf("%s  %s %d\n", STsearchByIndiceNome(L->tabL, a[i].v), STsearchByIndiceNome(L->tabL, a[i].w), a[i].wt);
    free(a);

}

void STinsert_t(Listaadj L,char *nome, char *rete){
    STinsert(L->tabL,nome,rete);
}

void check_adiacenza_listadj(Listaadj L){
    char v1[MAXCL],v2[MAXCL],v3[MAXCL];
    int id1,id2,id3;
    int k=0;
    link t;

    printf("Inserisci i nomi dei tre vertici: \n");
    scanf("%s %s %s",v1,v2,v3);

    id1= STgetindex(L->tabL,v1);
    id2= STgetindex(L->tabL,v2);
    id3= STgetindex(L->tabL,v3);

    for(t=L->ladj[id1];t!=L->z;t=t->next) if(t->v==id2) k++;

    for(t=L->ladj[id2];t!=L->z;t=t->next) if(t->v==id3) k++;

    for(t=L->ladj[id3];t!=L->z;t=t->next) if(t->v==id1) k++;

    if(k==3) printf("Vertici adiacenti\n");
    else printf("Vertici non adiacenti\n");

}