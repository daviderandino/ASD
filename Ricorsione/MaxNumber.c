#include<stdio.h>

int max(int a[],int l,int r);

int main(){
    int a[] = {10,3,40,6},l=0,r=3,maxn;
    maxn = max(a,l,r);
    printf("%d\n", maxn);

}

int max(int a[],int l,int r){
    int u, v;
    int m = (l + r)/2;
    if (l == r)
        return a[l];
    u = max (a, l, m);
    v = max (a, m+1, r);
    if (u > v)
        return u;
    else
        return v;
}
