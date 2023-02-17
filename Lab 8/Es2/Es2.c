#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main() {
    FILE *fin;
    int choice,fine=0;
    char filename[MAXC];
    Graph G=NULL;
    Listaadj adjL=NULL;
    int flagfile=0,flaglista=0;
    do {
        printf("Cosa vuoi fare?\n");
        printf("1.Leggi grafo da un file\n");
        printf("2.Stampa il grafo\n");
        printf("3.Implementa lista adiacenze\n");
        printf("4.Mostra lista adiacenze\n");
        printf("5.Stampa i vertici adiacenti utilizzando la matrice delle adiacenze\n");
        printf("6.Stampa i vertici adiacenti utilizzando la lista delle adiacenze\n");
        printf("7.Stampa vertici e archi (in ordine)\n");
        printf("8.Fine\n");
        scanf("%d",&choice);
            switch(choice) {
                case 1:
                    flagfile=1;
                    printf("Inserisci nome file:\n");
                    scanf("%s", filename);
                    fin = fopen(filename, "r");
                    if (fin == NULL){
                        printf("Errore nome file\n");
                        exit(-1);
                    }
                    G = GRAPHload(fin);
                    fclose(fin);
                    break;
                case 2:
                    if(flagfile==1) GRAPHstore(G);
                    else printf("File non ancora caricato!\n");
                    break;
                case 3:
                    if(flagfile==1){
                        flaglista=1;
                        adjL = LISTload(G);
                    }else printf("File non ancora caricato!\n");
                    break;
                case 4:
                    if(flagfile==1 && flaglista==1) LISTstore(adjL);
                    if(flagfile==0) printf("File non ancora caricato!\n");
                    if(flaglista==0) printf("Lista non ancora caricata!\n");
                    break;
                case 5:
                    if(flagfile==1) check_adiacenza_madj(G);
                    else printf("File non ancora caricato!\n");
                    break;
                case 6:
                    if(flagfile==1 && flaglista==1) check_adiacenza_listadj(adjL);
                    if(flagfile==0) printf("File non ancora caricato!\n");;
                    if(flaglista==0) printf("Lista non ancora caricata!\n");
                    break;
                case 7:
                    if(flagfile==1) stampaVerticiOrdinati(G);
                    else printf("File non ancora caricato!\n");
                    break;
                case 8:
                    fine = 1;
                    break;
                default:
                    printf("Scelta non valida\n");
                    exit(-1);
            }
        } while(fine!=1);
    GRAPHfree(G);
    exit(0);
}