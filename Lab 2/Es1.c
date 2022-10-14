#include<stdio.h>

int gcd(int a, int b);

int main(){
    int a=1639238420,b=1324701,mcd;
    mcd = gcd(a,b);
    printf("%d\n",mcd);
}

int gcd(int a, int b){
    if(b>a) return gcd(b,a);
    if(a==b) return a;
    if(a%2==0 && b%2==0) return 2* gcd(a/2,b/2);
    if(a%2==1 && b%2==0) return gcd(a,b/2);
    if(a%2==0 && b%2==1) return gcd(a/2,b);
    if(a%2==1 && b%2==1) return gcd((a-b)/2,b);
}
