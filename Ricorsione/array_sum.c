#include<stdio.h>

int findSum(int A[],int N);

int main(){
    int A[] = {1,2,3,4,5},N=sizeof(A)/sizeof(A[0]),s;
    s = findSum(A,N);
    printf("%d\n",s);

}

int findSum(int A[],int N){
    if(N==0) return 0;
    return(findSum(A,N-1)+A[N-1]);
}