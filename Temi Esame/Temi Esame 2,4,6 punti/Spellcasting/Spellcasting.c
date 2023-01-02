/*
 N rune colorate in un sacchetto, di cui R rosse, V verdi e B blu.
 Generare tutte le sequenze di rune per cui
 - Una runa rossa non è tra le prime due rune estratte
 - Una runa rossa non viene mai estratta per ultima
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int perm_r(int pos, char *dist_val, char *sol,int *mark,int n, int n_dist, int cnt);
int check(char *s,int n);

int main(){
    int cnt=0,pos=0,n_dist=3,n=5;
    char *dist_val = malloc(n_dist);
    dist_val[0] = 'R'; dist_val[1] = 'V'; dist_val[2] = 'B';
    int *mark = malloc(n_dist*sizeof(int));
    char *sol = malloc(n);
    mark[0] = 1; mark[1] = 3; mark[2] = 1;
    cnt = perm_r(pos,dist_val,sol,mark,n,n_dist,cnt);
}

int perm_r(int pos, char *dist_val, char *sol,int *mark,int n, int n_dist, int cnt) {
    int i;
    if (pos >= n) {
        if(check(sol,n)==1){
            for (i=0; i<n; i++)
                printf("%c ", sol[i]);
            printf("\n");
            return cnt+1;
        }
        else return cnt;
    }
    for (i=0; i<n_dist; i++) {
        if (mark[i] > 0) {
            mark[i]--;
            sol[pos] = dist_val[i];
            cnt=perm_r(pos+1,dist_val,sol,mark,n, n_dist,cnt);
            mark[i]++;
        }
    }
    return cnt;
}

int check(char *s,int n){
    if(s[0]!='R' && s[1]!='R' && s[n-1]!='R')
        return 1;
    return 0;
};
