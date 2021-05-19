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
    a1.Insertar(s);
    a1.Insertar(q);
    a1.Insertar(p);
    a1.Insertar(t);
    a1.Insertar(r);

    TABBPoro a2(a1);

    TABBPoro a3;

    // OPERADORES ==, =, RECORRIDOS.

    if(!(a1 == a2)) cout << "ERROR: a1 == a2" << endl;
    if(a1 == a3) cout << "ERROR: a1 != a3" << endl;
    if(a2 == a3) cout << "ERROR: a1 != a2" << endl;

    a3.Insertar(q);
    a3.Insertar(p);
    a3.Insertar(t);
    a3.Insertar(r);
    a3.Insertar(s);

    if(!(a1 == a3)) cout << "ERROR: a1 == a3" << endl;

    TABBPoro a4;
    a4.Insertar(r);
    a4.Insertar(p);
    a4.Insertar(q);
    a4.Insertar(s);
    a4.Insertar(t);

    if(!(a1 == a4)) cout << "ERROR: a1 == a4" << endl;
    if(!(a2 == a4)) cout << "ERROR: a2 == a4" << endl;
    if(!(a3 == a4)) cout << "ERROR: a3 == a4" << endl;

    TABBPoro a5;
    a5.Insertar(t);
    a5.Insertar(s);
    a5.Insertar(q);
    a5.Insertar(r);
    a5.Insertar(p);

    if(!(a1 == a5)) cout << "ERROR: a1 == a5" << endl;
    if(!(a2 == a5)) cout << "ERROR: a2 == a5" << endl;
    if(!(a3 == a5)) cout << "ERROR: a3 == a5" << endl;
    if(!(a4 == a5)) cout << "ERROR: a4 == a5" << endl;    

    TABBPoro a6, a7, a8, a9, a10, a11, a12, a13;
    a6 = a1;
    a7 = a2;
    a8 = a3;
    a9 = a4;
    a10 = a5;

    if(!(a1 == a1)) cout << "ERROR: a1 == a1" << endl;
    if(!(a2 == a2)) cout << "ERROR: a2 == a2" << endl;
    if(!(a1 == a6)) cout << "ERROR: a1 == a6" << endl;
    if(!(a2 == a7)) cout << "ERROR: a2 == a7" << endl;
    if(!(a3 == a8)) cout << "ERROR: a3 == a8" << endl;
    if(!(a4 == a9)) cout << "ERROR: a4 == a9" << endl;
    if(!(a5 == a10)) cout << "ERROR: a4 == a10" << endl;

    if(!(a2 == a6)) cout << "ERROR: a2 == a6" << endl;
    if(!(a1 == a7)) cout << "ERROR: a1 == a7" << endl;
    if(!(a4 == a8)) cout << "ERROR: a4 == a8" << endl;
    if(!(a5 == a9)) cout << "ERROR: a5 == a9" << endl;
    if(!(a3 == a10)) cout << "ERROR: a3 == a10" << endl;
    
    if(!(a3 == a6)) cout << "ERROR: a3 == a6" << endl;
    if(!(a4 == a7)) cout << "ERROR: a4 == a7" << endl;
    if(!(a5 == a8)) cout << "ERROR: a5 == a8" << endl;
    if(!(a2 == a9)) cout << "ERROR: a2 == a9" << endl;
    if(!(a1 == a10)) cout << "ERROR: a1 == a10" << endl;

    if(!(a11 == a12)) cout << "ERROR: a11 == a12" << endl;
    if(!(a11 == a13)) cout << "ERROR: a11 == a13" << endl;
    if(!(a11 == a11)) cout << "ERROR: a11 == a11" << endl;

    if(a11 == a1) cout << "ERROR: a11 != a1" << endl;
    if(a12 == a1) cout << "ERROR: a12 != a1" << endl;
    if(a13 == a1) cout << "ERROR: a13 != a1" << endl;

    if(a11 == a6) cout << "ERROR: a11 != a6" << endl;
    if(a12 == a7) cout << "ERROR: a12 != a7" << endl;
    if(a13 == a8) cout << "ERROR: a13 != a8" << endl;

    // =================================== RECORRIDOS ======================================
    
    cout << "Preorden: " << endl << a1.Preorden() << endl;
    cout << "Postorden: " << endl << a1.Postorden() << endl;
    cout << "Inorden: " << endl << a1.Inorden() << endl;
    cout << "Niveles: " << endl << a1.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a2.Preorden() << endl;
    cout << "Postorden: " << endl << a2.Postorden() << endl;
    cout << "Inorden: " << endl << a2.Inorden() << endl;
    cout << "Niveles: " << endl << a2.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a3.Preorden() << endl;
    cout << "Postorden: " << endl << a3.Postorden() << endl;
    cout << "Inorden: " << endl << a3.Inorden() << endl;
    cout << "Niveles: " << endl << a3.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a4.Preorden() << endl;
    cout << "Postorden: " << endl << a4.Postorden() << endl;
    cout << "Inorden: " << endl << a4.Inorden() << endl;
    cout << "Niveles: " << endl << a4.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a5.Preorden() << endl;
    cout << "Postorden: " << endl << a5.Postorden() << endl;
    cout << "Inorden: " << endl << a5.Inorden() << endl;
    cout << "Niveles: " << endl << a5.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a6.Preorden() << endl;
    cout << "Postorden: " << endl << a6.Postorden() << endl;
    cout << "Inorden: " << endl << a6.Inorden() << endl;
    cout << "Niveles: " << endl << a6.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a7.Preorden() << endl;
    cout << "Postorden: " << endl << a7.Postorden() << endl;
    cout << "Inorden: " << endl << a7.Inorden() << endl;
    cout << "Niveles: " << endl << a7.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a8.Preorden() << endl;
    cout << "Postorden: " << endl << a8.Postorden() << endl;
    cout << "Inorden: " << endl << a8.Inorden() << endl;
    cout << "Niveles: " << endl << a8.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a9.Preorden() << endl;
    cout << "Postorden: " << endl << a9.Postorden() << endl;
    cout << "Inorden: " << endl << a9.Inorden() << endl;
    cout << "Niveles: " << endl << a9.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a10.Preorden() << endl;
    cout << "Postorden: " << endl << a10.Postorden() << endl;
    cout << "Inorden: " << endl << a10.Inorden() << endl;
    cout << "Niveles: " << endl << a10.Niveles() << endl;
}

