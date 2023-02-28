// verificare che un vettore è uno heap
// in pratica, per ogni i devo verificare che A[2i+1]<A[i] e A[2i+2]<A[i]

#include<stdio.h>

int isHeap(int V[],int N);

int main(){
    int V[] = {20,15,10,12,11,5,4,9,8,5,7,2,0},N=13;
    int check;
    check = isHeap(V,N);
    printf("%d\n",check);
}

int isHeap(int V[],int N){
    int i,j;
    for(i=0;i<N;i++){
        j = 2*i+1;
        if(j>=N) return 1;
        if(j<N && V[j]>=V[i]) return 0;
        j = 2*i+2;
        if(j>=N) return 1;
        if(j<N && V[j]>=V[i]) return 0;
    }
    return 1;
}