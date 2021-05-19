#include <iostream>

using namespace std;

#include "tabbporo.h"

int
main(void)
{
    TPoro p1(1, 1, 1, (char *) "rojo"), q1(2, 2, 25, (char *)"verde"), 
        r1(3, 3, 30, (char *)"amarillo"), s1(4, 4, 15), 
        t1(5, 5, -9, (char *)"azul");

    TPoro p2(1, 1, 1, (char *)"rojo"), q2(2, 2, 25, (char *)"verde"), 
        r2(3, 3, 30, (char *)"amarillo"), s2(4, 4, 15), 
        t2(5, 5, -9, (char *)"azul");

    TPoro p3(10, 10, 10, (char *)"rojo"), q3(20, 20, 250, (char *)"verde"), 
        r3(30, 30, 300, (char *)"amarillo"), s3(40, 40, 150), 
        t3(50, 50, -90, (char *)"azul");

    TABBPoro a1;
        a1.Insertar(s1);
        a1.Insertar(q1);
        a1.Insertar(p1);
        a1.Insertar(t1);
        a1.Insertar(r1);

    TABBPoro a2;
        a2.Insertar(s2);
        a2.Insertar(q2);
        a2.Insertar(p2);
        a2.Insertar(t2);
        a2.Insertar(r2);

    TABBPoro a3;
        a3.Insertar(r3);
        a3.Insertar(p3);
        a3.Insertar(q3);
        a3.Insertar(s3);
        a3.Insertar(t3);

    // OPERADOR +, =, RECORRIDOS.
    
    if(a1 == a3) cout << "ERROR: a1 != a3" << endl;    

    TABBPoro a4, a5, a6, a7, a8, a9, a10, a11;
    a4 = a1 + a2;
    a5 = a1 + a3;
    a6 = a2 + a3;
    a7 = a4 + a3;
    a8 = a9 + a10; // vacio
    a9 = a9 + a4; // a4 en inorden
    a10 = a4 + a10; // a4 en inorden
    a11 = a4 + a4;  // a4 en inorden

    // =================================== RECORRIDOS ======================================

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
    cout << "Niveles: " << endl << a10.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a11.Preorden() << endl;
    cout << "Postorden: " << endl << a11.Postorden() << endl;
    cout << "Inorden: " << endl << a11.Inorden() << endl;
    cout << "Niveles: " << endl << a11.Niveles() << endl << endl;

    cout << "Ostream: a4=a1+a2: " << endl << a1+a2 << endl;
}

