#include<stdio.h>

int fact(int n);

int main(){
    int n=4;
    int fattoriale = fact(n);
    printf("%d\n",fattoriale);
}

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}