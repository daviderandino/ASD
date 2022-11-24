#include <stdio.h>
#include<stdlib.h>
#include "personaggi.h"

// risolvere bug ricalcolo statistiche (non toglie punti dopo aver eliminato un oggetto e ricalcolato le stats, ma li aggiunge)

// aggiungere struct wrapper che contiene num_personaggi e i puntatori a head e tail della lista
// idem per gli oggetti
// quindi num_ogg,num_pers non devono essere visibili al main.

int main() {
    int choice = -1,num_pers=0,num_ogg=0,lista_caricata=0,vett_caricato=0;
    FILE *fp1,*fp2;
    do {
        printf("Cosa vuoi fare?\n"
               "0.Esci\n"
               "1.Caricare in una lista l'elenco di personaggi\n"
               "2.Caricare l'elenco di oggetti\n"
               "3.Aggiungere un personaggio\n"
               "4.Eliminare un personaggio\n"
               "5.Aggiungere un oggetto all'equipaggiamento di un personaggio\n"
               "6.Rimuovere un oggetto dall'equipaggiamento di un personaggio\n"
               "7.Calcolare le statistiche di un personaggio\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                if(lista_caricata==0){
                    fp1 = fopen("../pg.txt","r");
                    num_pers = carica_lista(fp1);
                    fclose(fp1);
                    lista_caricata++;
                }
                else
                    printf("Hai gia' caricato la lista!\n");
                break;
            case 2:
                if(vett_caricato==0){
                    fp2 = fopen("../inventario.txt","r");
                    num_ogg = alloca_vettInv(fp2);
                    fclose(fp2);
                    vett_caricato++;
                }
                else
                    printf("Hai gia' caricato il vettore!\n");
                break;
            case 3:
                aggiungi_personaggio();
                num_pers++;
                break;
            case 4:
                elimina_personaggio();
                num_pers--;
                break;
            case 5:
                aggiungi_oggetto(num_ogg);
                break;
            case 6:
                rimuovi_oggetto(num_ogg);
                break;
            case 7:
                calcola_stats();
                break;
            default:
                exit(0);
        }
    }
    while(choice!=0);

}
