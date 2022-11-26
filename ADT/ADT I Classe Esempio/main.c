#include <stdio.h>
#include "complex.h"

int main() {
    Complex a,b,c;
    a = crea();
    b = crea();
    // ...
    c = prod(a,b);
    
    // Il client può solo manipolare dei puntatori: a,b,c NON SONO struct ma puntatori
    
    distruggi(a);
    distruggi(b);
    distruggi(c);

}
