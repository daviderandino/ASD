#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#define MAXC 30

int main() {
    char name[MAXC];
    Graph G;
    FILE *fin;
    Edge *dagedge;
    int flag_choice1=0,flag_choice3=0,flag_choice4=0,flag_arco_back=0,cnt=0;
    int countbackedge=0;
    int choice;
    while(1) {
        printf("Cosa vuoi fare?\n");
        printf("1.Carica grafo da file\n");
        printf("2.Stampa grafo\n");
        printf("3.Inviduazione di archi a cardinalita' minima per creare un DAG (Richiede prima 1)\n");
        printf("4.Costruzione DAG rimuovendo l'insieme di archi a peso massimo (Richiede prima 3)\n");
        printf("5.Distanze massime da ogni nodo sorgente verso ogni nodo del DAG (Richiede prima 4)\n");
        printf("6.Fine\n");
        scanf("%d",&choice);
            switch(choice) {
                case 1:
                    flag_choice1 = 1;
                    printf("Inserisci nome file: \n");
                    cnt=0;
                    scanf("%s", name);
                    fin = fopen(name, "r");
                    if (fin == NULL) exit(-1);
                    G = GRAPHload(fin);
                    fclose(fin);
                    flag_arco_back=0;
                    break;
                case 2:
                    if(flag_choice1==0){
                        printf("Devi prima caricare il grafo!\n");
                        break;
                    }
                    GRAPHstore(G,stdout);
                    break;
                case 3:
                    if(flag_choice1==0){
                        printf("Devi prima caricare il grafo!\n");
                        break;
                    }
                    flag_choice3 = 1;
                    dagedge=malloc(GRAPHfvertexdim(G)*sizeof(Edge));
                    for(int i=0;i< GRAPHfvertexdim(G);i++){
                        GRAPHdfs(G,i,&flag_arco_back,&dagedge,&cnt,&countbackedge);
                    }
                    if(flag_arco_back==0) printf("Il Grafo e' gia un DAG\n");
                    break;
                case 4:
                    if(flag_choice3==0){
                        printf("Devi prima effettuare la scelta 3!\n");
                        break;
                    }
                    if(flag_arco_back==0) printf("Il Grafo e' gia un DAG\n");
                    flag_choice4 = 1;
                    if(flag_arco_back!=0) EDGEdag(G,dagedge,cnt,countbackedge);
                    break;
                case 5:
                    if(flag_choice4==0){
                        printf("Devi prima effettuare la scelta 4!\n");
                        break;
                    }
                    DAGrts(G);
                    break;
                case 6:
                    GRAPHfree(G);
                    return 0;
                default:
                    printf("Scelta non valida, riprovare\n");
        }
    }
}