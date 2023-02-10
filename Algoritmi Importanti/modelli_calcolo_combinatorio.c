#include<stdio.h>
#include<stdlib.h>

int disp(int pos,int *val,int *sol,int *mark,int n,int k,int cnt);
int disp_rip(int pos,int *val,int *sol,int n,int k,int cnt);
int perm(int pos,int *val,int *sol,int *mark,int n,int cnt);
int perm_r(int pos,int *dist_val,int *sol,int *mark,int n,int n_dist,int cnt);
int comb(int pos,int *val,int *sol,int n,int k,int start,int cnt);
int comb_r(int pos,int *val,int *sol,int n,int k,int start,int cnt);
int powerset(int pos,int *val,int *sol,int n,int cnt);

int main(){
    int val[] = {0,1,2},N=3;
    int *sol = malloc(N*sizeof(int));
    int *mark = malloc(N*sizeof(int));
    int pos=0,cnt=0,start=0,k=2;
    for(int i=0;i<N;i++) mark[i] = 0;
    // cnt = disp(pos,val,sol,mark,N,N,cnt);
    // cnt = disp_rip(pos,val,sol,N,k,cnt);
    // cnt = perm(pos,val,sol,mark,N,cnt);
    // cnt = comb(pos,val,sol,N,k,start,cnt);
    // cnt = comb_r(pos,val,sol,N,k,start,cnt);
    cnt = powerset(pos,val,sol,N,cnt);
}


// modello disposizioni semplici: genera tutte le disposizioni semplici utilizzando k degli N elementi del vettore
// esempio: val = {0,1,2} N=3 k=2 ---> (0,1) (0,2) (1,0) ecc...

int disp(int pos,int *val,int *sol,int *mark,int n,int k,int cnt){
    int i;
    if(pos>=k){
        for(i=0;i<k;i++)
            printf("%d ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(i=0;i<n;i++){
        if(mark[i]==0){
            mark[i] = 1;
            sol[pos] = val[i];
            cnt = disp(pos+1,val,sol,mark,n,k,cnt);
            mark[i] = 0;
        }
    }
    return cnt;
}

// modello disposizioni ripetute: genera tutte le disposizioni utilizzando k degli elementi del vettore
// e inoltre ogni elemento del vettore può essere ripetuto fino a k volte
// esempio: val = {0,1,2} N=3 k=2 ---> (0,1) (0,2) (1,0) ma anche (0,0) (2,2) ecc...

int disp_rip(int pos,int *val,int *sol,int n,int k,int cnt){
    int i;
    if(pos>=k){
        for(i=0;i<k;i++)
            printf("%d ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(i=0;i<n;i++){
        sol[pos] = val[i];
        cnt = disp_rip(pos+1,val,sol,n,k,cnt);
    }

}

// modello permutazioni semplici: genera tutte le permutazioni
// esempio: val = {0,1,2} N=3 --> (0,1,2),(0,2,1),(2,1,0)...
// equivale al modello delle disposizioni semplici con k==N

int perm(int pos,int *val,int *sol,int *mark,int n,int cnt){
    int i;
    if(pos>=n){
        for(i=0;i<n;i++) printf("%d ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(i=0;i<n;i++)
        if(mark[i]==0){
            mark[i] = 1;
            sol[pos] = val[i];
            cnt = perm(pos+1,val,sol,mark,n,cnt);
            mark[i] = 0;
        }
    return cnt;
}

// modello permutazioni ripetute: genera tutte le permutazioni distinte di un vettore
// ad esempio: stringa="oro" dist_val = "o,r" n_dist = 2
// genera (oor) (oro) (roo)

int perm_r(int pos,int *dist_val,int *sol,int *mark,int n,int n_dist,int cnt){
    int i;
    if(pos>=n){
        for(i=0;i<n;i++)
            printf("%d ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(i=0;i<n_dist;i++){
        if(mark[i]>0){
            mark[i]--;
            sol[pos] = dist_val[i];
            cnt = perm_r(pos+1,dist_val,sol,mark,n,n_dist,cnt);
            mark[i]++;
        }
    }
    return cnt;
}

// modello combinazioni semplici: genera alcune delle disposizioni possibili
// utilizzando k elementi del vettore di dimensione N
// esempio val={0,1,2} k=2 --> (0,1) (0,2) (1,2)
// in pratica come disposizioni semplici ma forzando l'ordinamento!!!

int comb(int pos,int *val,int *sol,int n,int k,int start,int cnt){
    int i,j;
    if(pos>=k){
        for(i=0;i<k;i++)
            printf("%d ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(i=start;i<n;i++){
        sol[pos] = val[i];
        cnt = comb(pos+1,val,sol,n,k,i+1,cnt);
    }
    return cnt;
}

// modello combinazioni ripetute: genera alcune delle disposizioni possibili
// utilizzando k elementi del vettore di dimensione N
// ogni elemento può essere ripetuto inoltre k volte
// esempio val={0,1,2} k=2 --> (0,0) (0,1) (0,2) (1 1) (1,2) ecc...
// in pratica come disposizioni ripetute ma forzando l'ordinamento!!!

int comb_r(int pos,int *val,int *sol,int n,int k,int start,int cnt){
    int i,j;
    if(pos>=k){
        for(i=0;i<k;i++)
            printf("%d ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(i=start;i<n;i++){
        sol[pos] = val[i];
        cnt = comb_r(pos+1,val,sol,n,k,start,cnt);
        start++;
    }
    return cnt;
}

// powerset: insieme delle parti

int powerset(int pos,int *val,int *sol,int n,int cnt){
    int j;
    if(pos>=n){
        for(j=0;j<n;j++)
            if(sol[j]!=0)
                printf("%d ",val[j]);
        printf("\n");
        return cnt+1;
    }
    sol[pos] = 0;
    cnt = powerset(pos+1,val,sol,n,cnt);
    sol[pos] = 1;
    cnt = powerset(pos+1,val,sol,n,cnt);
}
