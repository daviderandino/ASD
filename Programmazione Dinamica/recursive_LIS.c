// Recursive LIS "Longest Increasing Subsequence". O(2^n)!

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int LIS(int *val);
int LISR(int *val, int i);

int max(int ris, int i);

int main(){
    int val[] = {11,7,3,15,8,14},len;
    len = LIS(val);
    printf("Length of longest increasing subsequence: %d\n",len);
}


int LIS(int *val) {
    int N = 6;
    return LISR(val, N-1);
}
int LISR(int *val, int i) {
    int j, ris;
    if (i == 0)
        return 1;
    ris = 1;
    for (j=0; j < i; j++)
        if (val[j] < val[i])
            ris = max(ris, 1 + LISR(val, j));
    return ris;
}

int max(int ris, int i) {
    if(ris>=i)
        return ris;
    return i;
}
