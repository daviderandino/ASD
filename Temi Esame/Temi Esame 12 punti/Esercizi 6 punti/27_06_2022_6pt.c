/*
     Si vogliono generare tutte le sequenze alfabetiche di k (parametro del programma) caratteri che rispettino i
    seguenti vincoli:
    • si possono usare solo lettere minuscole (da ‘a’ a ‘z’) e maiuscole (da ‘A’ a ‘Z’)
    • al massimo la metà dei caratteri possono essere lettere minuscole
    • lo stesso carattere, senza distinguere tra maiuscolo o minuscolo, non può apparire più di p (parametro del
    programma) volte consecutivamente.
    • Si scriva una funzione ricorsiva in C in grado di generare tutte le sequenze secondo le regole di cui sopra,
    stampando solo quelle accettabili.
    • Si giustifichi la scelta del modello combinatorio adottato.
    • Si descrivano i criteri di pruning adottato o il motivo della loro assenza.
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
    int V[57];
    for(int i=0;i<56;i++) V[i] = i;
    int K = 10,p=2;
}