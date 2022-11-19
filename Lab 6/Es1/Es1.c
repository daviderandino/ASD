#include<stdio.h>
#include<stdlib.h>

struct att{
    int inizio,fine,len;
};

struct att *allocaVett(struct att *V,int *N);
void ordinaVett(struct att *V,int N);
void best_activities(struct att *val,int N);
void activities_print(struct att *val, int *P, int i,int *len_max);

int main(){
    struct att *V;
    int N;
    V = allocaVett(V,&N);
    ordinaVett(V,N);

    for(int i=0;i<N;i++)
        printf("%d %d\n",V[i].inizio,V[i].fine);

    best_activities(V,N);
    free(V);
}

void best_activities(struct att *val,int N){
    int i, j, max=-1, L[N], P[N], last=1,first,len_max=0;
    for(i=0;i<N;i++) L[i] = 0;
    P[0] = -1;
    for (i=1; i<N; i++) {
        P[i] = -1;
        first = 0;
        for (j=0; j<i; j++){
            if (val[j].fine <= val[i].inizio && (L[i] < L[j]+val[i].len+val[j].len)) {
                P[i] = j;
                if(first==0){
                    L[i] = val[j].len + val[i].len ;
                    first = 1;
                }
                else
                    L[i] = L[i] + val[j].len;
            }
        }
        if (L[i]>max) {
            max = L[i];
            last = i;
        }
    }
    printf("Un sottoinsieme di attivita' che non si intersecano con durata massima e':\n");
    activities_print(val, P, last,&len_max);
    printf("Lunghezza: %d\n", len_max);
}

void activities_print(struct att *val, int *P, int i,int *len_max) {
    if (P[i]==-1) {
        printf("(%d %d)\n", val[i].inizio,val[i].fine);
        *len_max+=val[i].len;
        return;
    }
    activities_print(val, P, P[i],len_max);
    *len_max+=val[i].len;
    printf("(%d %d)\n", val[i].inizio,val[i].fine);
}

struct att *allocaVett(struct att *V,int *n){
    FILE *fin = fopen("../att.txt","r");
    fscanf(fin,"%d",n);
    V = malloc(sizeof(struct att)*(*n));
    for(int i=0;i<*n;i++){
        fscanf(fin,"%d%d",&V[i].inizio,&V[i].fine);
        V[i].len = V[i].fine-V[i].inizio;
    }
    fclose(fin);
    return V;
}

void ordinaVett(struct att *V,int N){
    // ordinamento per valore finale crescente
    int i, j, l = 0, r = N - 1;
    struct att x;
    for (i = l + 1; i <= r; i++) {
        x = V[i];
        j = i - 1;
        while (j >= l && x.fine < V[j].fine) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = x;
    }
}
