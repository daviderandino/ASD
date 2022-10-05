#include<stdio.h>

int fib(int n);


int main(){
    printf("%d", fib(6));
}

int fib(int n){
    if(n<3) return 1;
    return fib(n-1)+fib(n-2);
}