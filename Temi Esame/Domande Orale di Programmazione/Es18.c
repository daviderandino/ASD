// Intersezione insiemistica di due vettori ordinati in O(n)
/*
 v1 = 1,2,2,5,6,8
 v2 = 2,3,4,6,9,10,11,12
 v3 = 2,6
 */

#include<stdlib.h>
#include<stdio.h>

int*f(int*v1,int*v2,int d1, int d2,int *d3);
int min(int d1,int d2);

int main(){
    int v1[] = {1,2,2,5,6,8};
    int v2[] = {2,3,4,6,9,10,11,12};
    int d1=6,d2=8,d3;
    int *v3;
    v3 = f(v1,v2,d1,d2,&d3);
    for(int i=0;i<d3;i++) printf("%d ",v3[i]);

}

int *f(int*v1,int*v2,int d1, int d2,int *d3){
    int i=0,j=0,k=0;
    int *v3 = malloc(min(d1,d2)*sizeof(int));
    while(i<d1 && j<d2){
        if(v1[i]<v2[j]) i++;
        else if(v1[i]>v2[j]) j++;
        else{
            v3[k++] = v1[i];
            i++; j++;
        }
    }
    realloc(v3,k);
    *d3 = k;
    return v3;

}

int min(int d1,int d2){
    if(d1<=d2) return d1;
    return d2;
}

