#include <stdio.h>
#include<stdlib.h>
#include "personaggi.h"

// gestire caso utente prova a riempire la lista due volte
// risolvere conflitto vettore e lista...

int main() {
    int choice = -1,num_pers=0,num_ogg=0;
    char cod[7];
    FILE *fp1 = fopen("../pg.txt","r");
    FILE *fp2 = fopen("../inventario.txt","r");
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
                num_pers = carica_lista(fp1);
                break;
            case 2:
                num_ogg = alloca_vettInv(fp2);
                break;
            case 3:
                aggiungi_personaggio();
                num_pers++;
                break;
            case 4:
                printf("Inserisci il codice del personaggio che vuoi eliminare:\n");
                scanf("%s",cod);
                elimina_personaggio(cod);
                num_pers--;
                break;
            case 5:
                printf("Quale oggetto vuoi aggiungere?\n");
                stampa_vettInv(num_ogg);
                aggiungi_oggetto();
                break;
            default:
                exit(0);
        }
    fclose(fp1);
    fclose(fp2);
    }
    while(choice!=0);

}
