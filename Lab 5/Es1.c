/*
Da completare modularizzando bene e aggiungendo funzione wrapper
*/


#include<stdio.h>
#include<stdlib.h>

struct activity{
    int inizio,fine;
};

int powerset(int pos,struct activity *val,int *sol,int n,int *cnt,int *el,struct activity *max,int *len_max);

int main(){
    int num_activities,pos=0,cnt=0,el,len_max=-1;
    struct activity *activities;
    FILE *fin = fopen("../es1input.txt","r");

    fscanf(fin,"%d",&num_activities);
    activities = (struct activity *) malloc(sizeof(struct activity)*(num_activities));
    for(int i=0;i<num_activities;i++){
        fscanf(fin,"%d%",&activities[i].inizio);
        fscanf(fin,"%d",&activities[i].fine);
    }
    int *sol = (int*) malloc(num_activities*sizeof(int));
    struct activity *max = (struct activity *) malloc(sizeof(struct activity)*(num_activities));
    powerset(pos,activities,sol,num_activities,&cnt,&el,max,&len_max);

    printf("Un insieme di attivita' che non si intersecano e che massimizza la durata e':\n");
    for(int i=0;i<=el;i++)
        printf("(%d,%d) ",max[i].inizio,max[i].fine);

}

int powerset(int pos,struct activity *val,int *sol,int n,int *cnt,int *el,struct activity *max,int *len_max){
    int j,intersection,count,len;
    if(pos>=n){
        intersection = 0; len = 0;
        for(j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(sol[j]!=0 && sol[k]!=0 && j!=k){
                    if(val[j].fine>val[k].inizio) intersection = 1;
                }
            }
        }
        count=0;
        if(intersection==0){
            for(j=0;j<n;j++)
                if (sol[j] != 0) len+=val[j].fine-val[j].inizio;
            if(len>*len_max){
                *len_max = len;
                for(j=0;j<n;j++) {
                    if (sol[j] != 0) {
                        max[count].inizio = val[j].inizio; max[count].fine = val[j].fine;
                        *el = count;
                        count++;
                    }
                }
            }
        }
        return (*cnt)+1;
    }
    sol[pos] = 0;
    *cnt = powerset(pos+1,val,sol,n,cnt,el,max,len_max);
    sol[pos] = 1;
    *cnt = powerset(pos+1,val,sol,n,cnt,el,max,len_max);
    return *cnt;
}
