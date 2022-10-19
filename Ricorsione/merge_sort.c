#include <stdio.h>

void MergeSort(int A[], int B[], int N);
void MergeSortR(int A[], int B[], int l, int r);
void Merge(int A[], int B[], int l, int q, int r);

int main(){
    int A[]={12,6,4,5,9,2,3,1},N=8;
    int B[N];
    for(int i=0;i<N;i++) B[i]=0;
    MergeSort(A,B,N);
    for(int i=0;i<N;i++) printf("%d ",A[i]);
    return 0;
}

void MergeSort(int A[],int B[],int N){
    int l=0,r=N-1;
    MergeSortR(A,B,l,r);
}

void MergeSortR(int A[],int B[],int l,int r){
    int q=(l+r)/2;
    if(l>=r) return; 
    MergeSortR(A,B,l,q);
    MergeSortR(A,B,q+1,r);
    Merge(A,B,l,q,r);
}

void Merge(int A[],int B[],int l,int q,int r){
    int i,j,k;
    i=l;
    j=q+1;

    for(k=l;k<=r;k++){
        if(i>q){
            B[k]=A[j++];
        }else if(j>r){
            B[k]=A[i++];
        }else if(A[j]>A[i]){ 
          B[k]=A[i++];
        }else{
            B[k]=A[j++];
        }
    }
    for(k=l;k<=r;k++) A[k]=B[k];
}
