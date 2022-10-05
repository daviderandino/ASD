#include<stdio.h>

void show(int x[], int l, int r);

int main(){
    int x[] = {1,2,3,4,5,6,7,8};
    int l=0,r=7;
    show(x,l,r);
}

void show(int x[], int l, int r) {
int i, c;
if (l >= r)
    return;
c = (r+l)/2;
printf("xs = ");
for (i=l; i <= c; i++)
    printf("%d", x[i]);
printf("\n");
show(x, l, c);
printf("xd = ");
for (i=c+1; i <= r; i++)
    printf("%d", x[i]);
printf("\n");
show(x, c+1, r);
return;
}