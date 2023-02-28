/*
 Implementare la merge di due vettori

 Esempio:
 V1 = 1 1 2 3 3 5 7
 V2 = 2 4 4 5 6
 V = 1 1 2 2 3 3 4 4 5 5 6 7
 */

#include<stdio.h>
#include<stdlib.h>

int *merge(int *V1,int *V2,int n1,int n2);

int main(){
    int n1=8,n2=5;
    int V1[] = {1,1,2,3,3,5,7,8};
    int V2[] = {2,4,4,5,6};
    int *V3;
    V3 = merge(V1,V2,n1,n2);
    for(int i=0;i<n1+n2;i++)
        printf("%d ",V3[i]);
}

int *merge(int *V1,int *V2,int n1,int n2){
    int dim=n1+n2,k=0;
    int *V3 = malloc(dim*sizeof(int));
    int i,j;

    for(i=0,j=0;i<n1,j<n2;){
        if(V1[i]<V2[j]){
            V3[k++] = V1[i];
            i++;
        }
        if(V2[j]<V1[i]){
            V3[k++] = V2[j];
            j++;
        }
        if(V2[j]==V1[i]){
            V3[k++] = V2[j];
            V3[k++] = V1[i];
            i++; j++;
        }
    }

    // una volta finito, riempio V3 con gli eventuali elementi rimanenti

    if(i<n1) for(int r=i;r<n1;r++) V3[k++] = V1[r];
    if(j<n2) for(int r=j;r<n2;r++) V3[k++] = V2[r];

    return V3;
}

