#include<stdio.h>

int gcd(int a, int b);

int main(){
    int a=376,b=24,mcd;
    mcd = gcd(a,b);
    printf("%d\n",mcd);
}

int gcd(int a, int b){
    int tmp;
    if(b>a){
        tmp = a;
        a = b;
        b = tmp;
    }
    if(b==a) return a;
    else if(a%2==0 && b%2==0) return 2* gcd(a/2,b/2);
    else if(a%2==1 && b%2==0) return gcd(a,b/2);
    else if(a%2==0 && b%2==1) return gcd(a/2,b);
    else if(a%2==1 && b%2==1) return gcd((a-b)/2,b);
}