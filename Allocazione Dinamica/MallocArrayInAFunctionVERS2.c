t *alloca_V(t *V,int *N);

t *alloca_V(t *V,int *N){
    *N = 5;
    V = (t*) malloc(*N*sizeof(t));
    V[0].val1 = 3; V[1].val2 = 4; //.....
    return V;
}

int main(){
    t *Vett;
    int N;
    Vett = alloca_V(Vett_tess,&N);
}
