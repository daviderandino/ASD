#include<stdio.h>
#include<stdlib.h>

void matMax (int m[3][4], int r, int c);


int main(){
    int M[3][4] = {
            {5,2,3,1},
            {4,1,6,4},
            {3,0,5,2}
    };
    matMax(M,3,4);
}

void matMax (int m[3][4], int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 && j==0 && m[i][j]>m[i][j+1] && m[i][j]>m[i+1][j])
                printf("(%d,%d)",i,j);
            else if(i==r-1 && j==0 && m[i][j]>m[i-1][j] && m[i][j] > m[i][j+1])
                printf("(%d,%d)",i,j);
            else if(i==0 && j==c-1 && m[i][j]>m[i][j-1] && m[i][j]>m[i+1][j])
                printf("(%d,%d)",i,j);
            else if(i==0 && m[i][j]>m[i+1][j] && m[i][j]>m[i][j-1] && m[i][j]>m[i][j+1])
                printf("(%d,%d)",i,j);
            else if(i==r-1 && m[i][j]>m[i-1][j] && m[i][j]>m[i][j-1] && m[i][j]>m[i][j+1])
                printf("(%d,%d)",i,j);
            else if(j==0 && m[i][j]>m[i-1][j] && m[i][j]>m[i+1][j] && m[i][j]>m[i][j+1])
                printf("(%d,%d)",i,j);
            else if(j==c-1 && m[i][j]>m[i-1][j] && m[i][j]>m[i+1][j] && m[i][j]>m[i][j-1])
                printf("(%d,%d)",i,j);
            else if(m[i][j]>m[i-1][j] && m[i][j]>m[i+1][j] && m[i][j]>m[i][j+1] && m[i][j]>m[i][j-1]) // caso generale: fuori dai bordi
                printf("(%d,%d)",i,j);

        }
    }
}