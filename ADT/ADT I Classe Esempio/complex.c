#include "complex.h"
#include<stdlib.h>

struct complex_s{
    float Re, Im;
};

Complex crea(){
    Complex c = malloc(sizeof *c);
    return c;
}

void distruggi(Complex c){
    free(c);
}

Complex prod(Complex c1, Complex c2){
    Complex c = crea();
    c->Re = c1->Re * c2->Re - c1->Im * c2->Im;
    c->Im = c1->Re * c2->Im + c2->Re * c1->Im;
    return c;
}