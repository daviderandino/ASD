void alloca_vett(int *V);

int main() {
    int *V;
    V=alloca_vett(V);
    printf("%d",V[0]);
}

int *alloca_vett(int *V){
    int vett = (int *) malloc(3*sizeof(int));
    vett[0] = 0; vett[1] = 1; vett[2] = 2;
    return vett;
}
