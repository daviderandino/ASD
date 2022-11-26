#include <stdio.h>
#include "complex.h"

int main() {
    Complex a,b,c;
    a = crea();
    b = crea();
    // ...
    c = prod(a,b);
    distruggi(a);
    distruggi(b);
    distruggi(c);

}
