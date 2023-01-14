#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 Si scriva una funzione ricorsiva in grado di generare tutte le stringhe di lunghezza N
 costituite dalle 5 vocali maiuscole A,E,I,O,U con i seguenti vincoli:
 - Ogni vocale compare almeno una volta
 - N parametro >=5
 */

int perm_r(int pos, char *dist_val, char *sol,int *mark,int n, int n_dist, int cnt);

int main(){
    char *s = "AAEIOU";
    int len = strlen(s),n_dist=5,cnt=0,pos=0;
    char *dist_val = malloc(n_dist);
    dist_val[0] = 'A'; dist_val[1] = 'E'; dist_val[2] = 'I'; dist_val[3] = 'O'; dist_val[4] = 'U';
    char *sol = malloc(len);
    int *mark = malloc(n_dist);
    mark[0] = 2; mark[1] = 1; mark[2] = 1; mark[3] = 1; mark[4] = 1;
    perm_r(pos,dist_val,sol,mark,len,n_dist,cnt);

}

int perm_r(int pos, char *dist_val, char *sol,int *mark,int n, int n_dist, int cnt){
    int i;
    if (pos >= n) {
            for (i=0; i<n; i++)
                printf("%c ", sol[i]);
            printf("\n");
            return cnt+1;
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