#include <iostream>

using namespace std;

#include "tabbporo.h"

int
main(void)
{
    TPoro p(1, 1, 1, (char *)"rojo"), q(2, 2, 25, (char *)"verde"), 
            r(3, 3, 30, (char *)"amarillo"), s(4, 4, 15), 
            t(5, 5, -9, (char *)"azul");

    TABBPoro a1;
    a1.Insertar(p);
    a1.Insertar(q);
    a1.Insertar(r);
    a1.Insertar(s);
    a1.Insertar(t);

    cout << "Preorden: " << endl << a1.Preorden() << endl;
    cout << "Postorden: " << endl << a1.Postorden() << endl;
    cout << "Inorden: " << endl << a1.Inorden() << endl;
    cout << "Niveles: " << endl << a1.Niveles() << endl;
}