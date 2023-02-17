#include <stdlib.h>
#include <string.h>
#include "ST.h"

struct st {char **nomi; char**reti; int maxN; int N;};

ST STinit(int maxN) {
    ST st;
    st = malloc(sizeof (*st));
    st->nomi = malloc(maxN * sizeof(char *));
    st->reti = malloc(maxN * sizeof(char *));
    st->maxN = maxN;
    st->N = 0;
    return st;
}

void STfree(ST st) {
    if (st==NULL) return;
    for (int i=0; i<st->N; i++){
       free(st->nomi[i]); free(st->reti[i]);
    }
    free(st->nomi); free(st->reti); free(st);
}

int STsize(ST st) {
    return st->N;
}

int STinsert(ST st, char *name,char *subnet) {
    if(st->N == st->maxN) {
        st->maxN = 2*st->maxN;
        st->nomi = realloc(st->nomi, st->maxN * sizeof(char *));
        st->reti = realloc(st->reti, st->maxN * sizeof(char *));
    }
    st->nomi[st->N] = strdup(name);
    st->reti[st->N] = strdup(subnet);
    st->N++;
    return st->N - 1;
}

int STgetindex(ST st, char *name) {
    for(int i = 0; i < st->N; i++) {
        if(strcmp(name, st->nomi[i]) == 0) return i;
    }
    return -1;
}

char *STsearchByIndiceNome(ST st, int i){
    if (i < 0 || i >= st->N) return NULL;
    return (st->nomi[i]);
}

char *STsearchByIndiceRete(ST st, int i){
    if (i < 0 || i >= st->N) return NULL;
    return (st->reti[i]);
}

void STsort(ST st,int *v){
    int i,j,tmp,n= STsize(st);
    for(i=0;i<n;i++) v[i]=i;
    for(i=0; i <n-1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(strcmp(st->nomi[v[j]],st->nomi[v[j+1]]) >= 0) {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}