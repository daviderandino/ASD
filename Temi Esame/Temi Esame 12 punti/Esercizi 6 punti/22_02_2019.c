/*
    Sia dato un vettore V di N interi. Si definisce sottosequenza di V di lunghezza k (k<N)
    un qualsiasi n-upla Y di kelementi di Vnon necessariamente contigui.Si ricordi che nella n-upla l’ordine conta.
    Esempio: :
    se N=9 e V = [8, 9, 6, 4, 5, 7, 3, 2, 4] una sottosequenza alternante minore-maggiore di lunghezza massima k=6 è V = [8, 9, 6, 7, 3, 4].
 */

#include<stdio.h>
#include<stdlib.h>

void comb(int pos,int *val,int *sol,int n,int k,int start,int cnt,int *check);

int main(){
    int N=9;
    int V[] = {8,9,6,4,5,7,3,2,4};
    int k;
    int pos=0,start=0,cnt=0,check=0;
    int *sol = malloc(N*sizeof(int));

    for(k=N;k>0 && check==0;k--)
        comb(pos,V,sol,N,k,start,cnt,&check);
}

void comb(int pos,int *val,int *sol,int n,int k,int start,int cnt,int *check){
    int i,isValid=1;
    if(*check==1) return;
    if(pos>=k){
        for(i=1;i<k;i++){
            if(i%2==1 && sol[i]<=sol[i-1]) isValid = 0;
            if(i%2==0 && sol[i]>=sol[i-1]) isValid = 0;
        }
        if(isValid==1){
            for(i=0;i<k;i++) printf("%d ",sol[i]);
            printf("\n");
            *check=1;
        }
        return;
    }
    for(i=start;i<n;i++){
        sol[pos] = val[i];
        comb(pos+1,val,sol,n,k,i+1,cnt,check);
    }
}