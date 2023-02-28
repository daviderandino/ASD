// stampare tutti i valori possibili utilizzando 6 dadi
// la somma deve essere >=S e ci deve essere almeno un valore doppio

#include<stdio.h>
#include<stdlib.h>

void comb_r(int pos,int *val,int *sol,int n,int k,int start,int S);

int main(){
    int val[] = {1,2,3,4,5,6};
    int N=6,pos=0,k=6,start=0,S=20;
    int *sol = malloc(k*sizeof(val));
    comb_r(pos,val,sol,N,k,start,S);

}

void comb_r(int pos,int *val,int *sol,int n,int k,int start,int S){
    int i,j,act_sum,check_doppio;
    if(pos>=k){
        act_sum = 0;
        check_doppio = 0;
        for(i=0;i<k;i++){
            for(j=0;j<k;j++){
                if(sol[i]==sol[j]&&i!=j) check_doppio = 1;
        }
            act_sum+=sol[i];
        }

        if(act_sum>=S && check_doppio==1){
            for(i=0;i<k;i++) printf("%d ",sol[i]);
            printf("\n");
        }
        return;
    }
    for(i=start;i<n;i++){
        sol[pos] = val[i];
        comb_r(pos+1,val,sol,n,k,start,S);
        start++;
    }
}
