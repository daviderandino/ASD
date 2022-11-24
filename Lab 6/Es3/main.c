#include <stdio.h>
#include<stdlib.h>
#include "personaggi.h"

// manca implementazione funzione calcolo stats

// gestire caso utente prova a riempire lista/vett due volte

// creare una funzione ItemSetVoid che setta un oggetto equipaggiato a void quando eliminato

// impedire all'utente di proseguire se lista o vettore sono vuoti

// modularizzare meglio

int main() {
    int choice = -1,num_pers=0,num_ogg=0;
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
                fp1 = fopen("../pg.txt","r");
                num_pers = carica_lista(fp1);
                fclose(fp1);
                break;
            case 2:
                fp2 = fopen("../inventario.txt","r");
                num_ogg = alloca_vettInv(fp2);
                fclose(fp2);
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
