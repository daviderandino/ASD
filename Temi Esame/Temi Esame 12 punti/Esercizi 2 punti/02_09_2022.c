#include<stdio.h>
#include<stdlib.h>

/*
    Una funzione riceve due vettori di interi ordinati, di dimensione nota. La funzione alloca un nuovo vettore v3 di
    dimensione opportuna per memorizzare i soli elementi di v1 che non appaiano anche in v2, conservando
    l'ordinamento. Eventuali elementi duplicati di v1 vanno inseriti in v3 una sola volta.
    Completare il prototipo a seguire, in modo che v3 e la sua dimensione effettiva siano disponibili a chi invoca la
    funzione, e implementare la funzione richiesta.
    ... f(int *v1, int *v2, int dim1, int dim2, ...)
 */

int f(int *v1, int *v2, int dim1, int dim2,int *v3);

int main(){
    int v1[] = {1,2,2,3,4,5}, dim1 = 6;
    int v2[] = {1,3}, dim2 = 2,dim3=0;

    int *v3 = malloc(sizeof(int)*(dim1+dim2));

    dim3 = f(v1,v2,dim1,dim2,v3);
    for(int i=0;i<dim3;i++)
        printf("%d\n",v3[i]);
}

int f(int *v1, int *v2, int dim1, int dim2,int *v3){
    int flag,cnt=0;

    for(int i=0;i<dim1;i++){
        flag = 1;
        for(int j=0;j<dim2;j++){
            if(v1[i]==v2[j]) flag = 0;
            if(v1[i]==v1[i-1] && i>=1) flag = 0;
        }

        if(flag==1){
            v3[cnt] = v1[i];
            cnt++;
        }
    }
    realloc(v3,cnt);
    return cnt;
}
