// O(n^2) using Dynamic Programming 

#include<stdio.h>

void LISDP(int *val);
void LISprint(int *val, int *P, int i);

int main(){
    int val[] = {11,7,3,15,8,14};
    LISDP(val);
}

void LISDP(int *val) {
    int N=6;
    int i, j, ris=1, L[N], P[N], last=1;
    L[0] = 1; P[0] = -1;
    for (i=1; i<N; i++) {
        L[i] = 1; P[i] = -1;
        for (j=0; j<i; j++)
            if ((val[j] < val[i]) && (L[i] < 1 + L[j])) {
                L[i] = 1 + L[j]; P[i] = j;
            }
        if (ris < L[i]) {
            ris = L[i]; last = i;
        }
    }
    printf("One of the Longest Increasing Sequences is ");
    LISprint(val, P, last);
    printf("and its length is %d\n", ris);
}

void LISprint(int *val, int *P, int i) {
    if (P[i]==-1) {
        printf("%d ", val[i]);
        return;
    }
    LISprint(val, P, P[i]);
    printf("%d ", val[i]);
}
