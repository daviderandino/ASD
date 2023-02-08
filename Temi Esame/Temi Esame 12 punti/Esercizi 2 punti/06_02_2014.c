#include<stdio.h>
#include<stdlib.h>

int *merge3 (int *a,int *b,int *c,int na,int nb,int nc);

int main(){
    int na=3,nb=2,nc=2;
    int N=na+nb+nc,*d;
    int *a = malloc(na*sizeof(int));
    int *b = malloc(nb*sizeof(int));
    int *c = malloc(nc*sizeof(int));
    a[0] = 0; a[1] = 1; a[2] = 2; b[0] = 3; b[1] = 4; c[0] = 5; c[1] = 6;
    // il vettore d di "merge" sarà d[]={0,1,2,3,4,5,6}
    d = merge3(a,b,c,na,nb,nc);
    for(int i=0;i<N;i++) printf("%d ",d[i]);

}

int *merge3 (int *a,int *b,int *c,int na,int nb,int nc){
    int N = na+nb+nc;
    int *d = malloc(N*sizeof(int));
    for(int i=0;i<N;i++){
        if(i<na) d[i] = a[i];
        if(i>=na && i<nb+na) d[i] = b[i-na];
        if(i>=nb+na && i<nc+nb+na) d[i] = c[i-na-nb];

    }
    return d;
}