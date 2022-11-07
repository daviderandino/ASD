/*
Es1 versione che non rispetta la consegna, ma stampa tutte le attività che non si intersecano con relativa lunghezza. Da utilizzare come base
per l'es1 ufficiale
*/


#include<stdio.h>
#include<stdlib.h>

struct activity{
    int inizio,fine;
};

int powerset(int pos,struct activity *val,int *sol,int n,int *cnt,int *el);

int main(){
    int num_activities,pos=0,cnt=0,el;
    struct activity *activities;
    FILE *fin = fopen("../es1input.txt","r");

    fscanf(fin,"%d",&num_activities);
    activities = (struct activity *) malloc(sizeof(struct activity)*(num_activities));
    for(int i=0;i<num_activities;i++){
        fscanf(fin,"%d",&activities[i].inizio);
        fscanf(fin,"%d",&activities[i].fine);
    }
    int *sol = (int*) malloc(num_activities*sizeof(int));
    powerset(pos,activities,sol,num_activities,&cnt,&el);
}

int powerset(int pos,struct activity *val,int *sol,int n,int *cnt,int *el){
    int j,intersection,count,len,len_max=0;
    if(pos>=n){
        intersection = 0; len = 0;
        for(j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(sol[j]!=0 && sol[k]!=0 && j!=k){
                    if(val[j].fine>val[k].inizio) intersection = 1;
                }
            }
        }
        if(intersection==0){
            for(j=0;j<n;j++) {
                if (sol[j] != 0) {
                    len+=val[j].fine - val[j].inizio;
                    printf("%d %d ",val[j].inizio,val[j].fine);
                }
            }
            if(len>0) printf("lunghezza: %d\n",len);
        }
        return (*cnt)+1;
    }
    sol[pos] = 0;
    *cnt = powerset(pos+1,val,sol,n,cnt,el);
    sol[pos] = 1;
    *cnt = powerset(pos+1,val,sol,n,cnt,el);
    
    return *cnt;
}
