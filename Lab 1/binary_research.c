#include<stdio.h>

int iterativeBinarySearch(int array[], int start_index, int end_index, int element);

int main(){
    int V[] = {1,2,3,4,5,6,7,8,9,10},N=sizeof(V)/sizeof(V[0]);
    int x = iterativeBinarySearch(V,0,N,3);
    printf("%d\n",x);
}

int iterativeBinarySearch(int array[], int start_index, int end_index, int element){
    while (start_index <= end_index){
        int middle = start_index + (end_index- start_index )/2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    return -1;
}