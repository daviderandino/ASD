#include<stdio.h>

int mcd(int x,int y);

int main(){
    int x=600,y=54,m;
    m = mcd(600,54);
    printf("%d\n",m);


}

int mcd(int x,int y){
    if(y==0) return x;
    return mcd(y,x%y);
}