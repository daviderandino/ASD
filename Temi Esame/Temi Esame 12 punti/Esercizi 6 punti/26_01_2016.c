#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Sia data una stringa str di al massimo 30 caratteri e un vettore lungh di num interi distinti che
    rappresentano la lunghezza delle sottostringhe in cui si vuole decomporre la stringa str. Si scriva una
    funzione ricorsiva in C void decomponi(char *str, int num, int *lungh);
    che visualizzi una delle possibili decomposizioni di str usando sottostringhe di lunghezza specificata nel
    vettore lungh.
    Esempi:
    se str= "tentativo", num = 3, lungh contiene 2, 5, 7, una delle possibili decomposizioni è
    "te" "nt" "ativo"
    se str= "tentativo", num = 2, lungh contiene 2, 4, non vi sono decomposizioni.
 */


/*
 La stringa si può decomporre secondo quanto richiesto dal problema solo se
 generando tutte le disp ripetute c'è almeno un insieme la cui somma è uguale alla lunghezza della stringa.
 Se ci sono più insiemi ne basta selezionare uno.
 Nell'esempio un sottoinsieme valido è {2,2,5} oppure {2,7}
 Trovato il sottoinsieme valido mi basta iterare
 */

int disp_rip(int pos,int *val,int *sol,int n,int k,int cnt,char *str,int len);

int main(){
    char *str = "tentativo";
    int lungh[] = {2,5,7},num=3,len= strlen(str);
    int *sol = malloc(num*sizeof(int));
    for(int i=0;i<num;i++) sol[i] = 0;
    int pos=0,cnt=0;

    for(int k=0;k<=num;k++)
        cnt = disp_rip(pos,lungh,sol,num,k,cnt,str,len);

}

int disp_rip(int pos,int *val,int *sol,int n,int k,int cnt,char *str,int len){
    int i,sum,p;
    if (pos >= k) {
        sum = 0;
        for (i=0; i<k; i++)
            sum+=sol[i];

        if(sum==len){
            for (i=0; i<k; i++){
                if(i==0) p = i;
                else p = sol[i-1];
                for(int j=p;j<sol[i]+p;j++)
                    printf("%c",str[j]);
                printf(" ");
            }
            exit(0);
        }
        return cnt+1;
    }
    for (i = 0; i < n; i++) {
        sol[pos] = val[i];
        cnt = disp_rip(pos+1, val, sol, n, k, cnt,str,len);
    }
    return cnt;
}