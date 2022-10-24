/*
 Seguendo un approccio simile al merge sort, sappiamo che un array di un solo elemento ha come elemento maggioritario
 l'elemento stesso (Quindi dividiamo il vettore in due sottovettori dx e sx procedendo ricorsivamente fino al caso base).
 La complessità è O(Nlogn): logaritmica per la divisione in sottovettori, lineare per il conto delle occorrenze.
 */

#include<stdio.h>

int majority(int *a,int N);
int majorityR(int *A,int l,int r,int N);
int conta_occ(int A[],int el,int l,int r);

int main(){
    int a[] = {1,4,2},N=3;
    int m = majority(a,N);
    if(m==-1) printf("Nessun elemento maggioritario\n");
    else printf("Maggioritario: %d\n",m);
}

int majority(int *a, int N){
    int m,count=0;
    m = majorityR(a,0,N-1,N);
    for(int i=0;i<N;i++)
        if(m==a[i]) count++;
    if(count>N/2) return m;
    return -1;

}

int majorityR(int *A,int l,int r,int N){
    int q=(l+r)/2,l1,r1,l1_count,r1_count;
    if(l==r) return A[l];
    l1 = majorityR(A,l,q,N);
    r1 = majorityR(A,q+1,r,N);
    if(l1==r1) return r1;
    l1_count = conta_occ(A,l1,l,r);
    r1_count = conta_occ(A,r1,l,r);
    if(l1_count>r1_count) return l1;
    return r1;
}

int conta_occ(int A[],int el,int l,int r) {
    int k,count=0;
    for(k=l;k<=r;k++){
        if(A[k]==el)
            count++;
    }
    return count;
}