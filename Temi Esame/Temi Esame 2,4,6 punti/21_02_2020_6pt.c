#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 Sia data un insieme S = {S0, S1, …, Sn-1} di stringhe di lettere maiuscole.
 Si determini mediante un algoritmo ricorsivo il numero massimo di stringhe appartenenti
 ad S mutuamente disgiunte, cioè che non presentano nessuna lettera in comune.
 */

int have_common_char(char *s1,char *s2);
int disgiunte(char **stringhe,int n);
int powerset(int pos,char **val,char **sol,int n,int start,int cnt,int *num_disgiunte);

int main(){
    char *stringhe[] = {
            "ABGCIEF",
            "BA",
            "CD",
            "FE",
            "GHBD",
            "JKLGHI",
            "FK"
    };
    int num_disgiunte,n=7;
    num_disgiunte = disgiunte(stringhe,n);
    printf("%d\n",num_disgiunte);

}

int disgiunte(char **stringhe,int n){
    int cnt=0,start=0,pos=0,num_disgiunte=0;
    char **sol;
    sol = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
        sol[i] = malloc((n+1) * sizeof(char)); // yeah, I know sizeof(char) is 1, but to make it clear...

    cnt = powerset(pos,stringhe,sol,n,start,cnt,&num_disgiunte);
    return num_disgiunte;
}

int powerset(int pos,char **val,char **sol,int n,int start,int cnt,int *num_disgiunte){
    int i,tmp;
    if(start>=n){
        tmp = 0;
        for(i=0;i<pos;i++){
            for(int j=i+1;j<pos;j++){
                if(have_common_char(sol[i],sol[j])==0)
                    tmp++; break;
            }
        }
        if(tmp>*num_disgiunte){
            *num_disgiunte = tmp;
        }
        return cnt+1;
    }
    for(i=start;i<n;i++){
        strcpy(sol[pos],val[i]);
        cnt = powerset(pos+1,val,sol,n,i+1,cnt,num_disgiunte);
    }
    cnt = powerset(pos,val,sol,n,i+1,cnt,num_disgiunte);
    return cnt;
}

int have_common_char(char *s1,char *s2){
    for(int i=0;i< strlen(s1);i++){
        for(int j=0;j< strlen(s2);j++){
            if(s1[i]==s2[j]) return 1;
        }
    }
    return 0;
}
