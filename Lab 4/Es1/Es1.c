#include<stdio.h>
#include<stdlib.h>

/*
    Utilizzo un vettore di struct di dimensione pari al numero di archi
    per memorizzare gli archi letti da file e una "matrice di connessione"
    che indica se il nodo i è connesso col nodo j.
    La matrice di connessione è quindi una matrice n*n con n = numero di nodi, inizializzata
    come una matrice identità perchè per definizione un nodo è connesso con
    se stesso (i==j). Leggendo da file gli archi la matrice A sarà, alla fine della lettura, una matrice simmetrica
    perchè se il nodo i è connesso col nodo j anche il nodo j è connesso col nodo i.

    Utilizzando il powerset delle disposizioni ripetute quando viene trovata una soluzione verifico che la disposizione
    è un vertex cover mediante le due strutture dati scelte. E' necessario a tal fine anche un vettore di booleani di
    dimensione pari al numero di archi, che contiene tutti 1 se la soluzione vede tutti gli archi, e in questo caso la soluzione
    viene stampata a video.
 */

struct archi{
    int nodo1,nodo2;
};

int powerset(int pos,int *val,int *sol,int n,int *cnt,int **M,struct archi *Vett_archi,int num_archi);

int main(){
    int **M,num_nodi,num_archi,pos=0,cnt=0;
    int e1,e2,k=0;
    FILE *fin = fopen("../grafo.txt","r");
    fscanf(fin,"%d%d",&num_nodi,&num_archi);
    struct archi *Vett_archi = malloc(num_archi*sizeof(int));
    M = (int **) malloc(num_nodi*(sizeof(int *)));
    for(int i=0;i<num_nodi;i++){
        M[i] = (int *) malloc(num_nodi*(sizeof(int)));
    }
    for(int i=0;i<num_nodi;i++){
        for(int j=0;j<num_nodi;j++){
            if(i==j) M[i][j] = 1;
            else M[i][j] = 0;
        }
    }
    while(!feof(fin)){
        fscanf(fin,"%d%d",&e1,&e2);
        Vett_archi[k].nodo1 = e1; Vett_archi[k].nodo2 = e2;
        k++;
        M[e1][e2] = 1; M[e2][e1] = 1;
    }
    fclose(fin);

    int *val = (int*) malloc(num_nodi*sizeof(int));
    for(int i=0;i<num_nodi;i++) val[i] = i;
    int *sol = (int*) malloc(num_nodi*sizeof(int));
    cnt = powerset(pos,val,sol,num_nodi,&cnt,M,Vett_archi,num_archi);
    free(sol);
    free(val);
}

int powerset(int pos,int *val,int *sol,int n,int *cnt,int **M,struct archi *Vett_archi,int num_archi) {
    int j,flag=1;
    int *archi_coperti = (int *) malloc(sizeof(int)*num_archi);
    for(int i=0;i<num_archi;i++) archi_coperti[i] = 0;
    if(pos>=n){
        for(j=0;j<n;j++){
            if(sol[j]!=0){
                for(int k=0;k<num_archi;k++){
                    if(Vett_archi[k].nodo1 == val[j] && M[val[j]][Vett_archi[k].nodo2]==1)
                        archi_coperti[k] = 1;
                    if(Vett_archi[k].nodo2 == val[j] && M[val[j]][Vett_archi[k].nodo1]==1)
                        archi_coperti[k] = 1;
                }
            }
        }
        for(int i=0;i<num_archi;i++){
            if(archi_coperti[i]==0) flag = 0;
        }
        if(flag==1){
            printf("{ ");
            for(j=0;j<n;j++){
                if(sol[j]!=0)
                    printf("%d ",val[j]);
            }
            printf("}\n");
        }
        return (*cnt)+1;
    }

    sol[pos] = 0;
    *cnt = powerset(pos+1,val,sol,n,cnt,M,Vett_archi,num_archi);
    sol[pos] = 1;
    *cnt = powerset(pos+1,val,sol,n,cnt,M,Vett_archi,num_archi);
    return *cnt;
}
