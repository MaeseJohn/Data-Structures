#include <iostream>

using namespace std;

#include "tabbporo.h"

int
main(void)
{
    TPoro p1(1, 1, 1, (char *)"rojo"), q1(2, 2, 25, (char *)"verde"), 
        r1(3, 3, 30, (char *)"amarillo"), s1(4, 4, 15), 
        t1(5, 5, -9, (char *)"azul");

    TPoro p2(1, 1, 1, (char *)"rojo"), q2(2, 2, 25, (char *)"verde"), 
        r2(3, 3, 35, (char *)"amarillo"), s2(4, 4, 13), 
        t2(5, 5, -15, (char *)"azul");

    TPoro p3(10, 10, 10, (char *)"rojo"), q3(20, 20, 22, (char *)"verde"), 
        r3(30, 30, 8, (char *)"amarillo"), s3(40, 40, 14), 
        t3(50, 50, -6, (char *)"azul");

    TABBPoro a5;
    a5.Insertar(s1);
    a5.Insertar(p1);
    a5.Insertar(q1);
    a5.Insertar(t1);
    a5.Insertar(t3);
    a5.Insertar(q3);
    a5.Insertar(r1);
   

    // =================================== RECORRIDOS ======================================
    cout << "Preorden: " << endl << a5.Preorden() << endl;
    cout << "Postorden: " << endl << a5.Postorden() << endl;
    cout << "Inorden: " << endl << a5.Inorden() << endl;
    cout << "Niveles: " << endl << a5.Niveles() << endl << endl;

    if(!a5.Borrar(s1)) cout << "s1 debería haberse borrado." << endl;

    cout << "Preorden: " << endl << a5.Preorden() << endl;
    cout << "Postorden: " << endl << a5.Postorden() << endl;
    cout << "Inorden: " << endl << a5.Inorden() << endl;
    cout << "Niveles: " << endl << a5.Niveles() << endl << endl;
}