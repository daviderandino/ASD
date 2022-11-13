#include<stdio.h>
#include<stdlib.h>

struct activity{
    int inizio,fine;
} typedef att;

void attSel(int N, att *v);

int powerset(int pos,struct activity *val,int *sol,int n,int *cnt,int *el,struct activity *max,int *len_max);

int main(){
    int num_activities=6;
    att *activities;
    activities = (struct activity *) malloc(sizeof(struct activity)*(num_activities));
    attSel(num_activities,activities);
}

void attSel(int N, att *v){
    int pos=0,cnt=0,el,len_max=-1;
    FILE *fin = fopen("../es1input.txt","r");
    for(int i=0;i<N;i++){
        fscanf(fin,"%d",&v[i].inizio);
        fscanf(fin,"%d",&v[i].fine);
    }
    fclose(fin);
    int *sol = (int*) malloc(N*sizeof(int));
    att *max = (att *) malloc(sizeof(struct activity)*(N));
    powerset(pos,v,sol,N,&cnt,&el,max,&len_max);
    printf("Un insieme di attivita' che non si intersecano e che massimizza la durata e':\n");
    for(int i=0;i<=el;i++)
        printf("(%d,%d) ",max[i].inizio,max[i].fine);
}

int powerset(int pos,att *val,int *sol,int n,int *cnt,int *el,struct activity *max,int *len_max){
    int j,intersection,count,len;
    if(pos>=n){
        intersection = 0; len = 0;
        for(j=0;j<n && intersection == 0;j++){
            for(int k=j+1;k<n && intersection==0;k++){
                if(sol[j]!=0 && sol[k]!=0 && j!=k && val[j].fine>val[k].inizio) intersection = 1;
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
