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

    TABBPoro a1;
        a1.Insertar(s1);
        a1.Insertar(q1);
        a1.Insertar(p1);
        a1.Insertar(t1);
        a1.Insertar(r1);

    TABBPoro a2;
        a2.Insertar(q2);
        a2.Insertar(p2);
        a2.Insertar(t2);
        a2.Insertar(r2);
        a2.Insertar(s2);

    TABBPoro a3;
        a3.Insertar(r3);
        a3.Insertar(p3);
        a3.Insertar(q3);
        a3.Insertar(s3);
        a3.Insertar(t3);

    TABBPoro a4, a5, a6;
    a4 = a1;
    a5 = a2;
    a6 = a3;

    // BORRAR HOJAS IZQUIERDAS

    if(!a1.Borrar(t1)) cout << "ERROR: Si existe t1 y debe borrarse." << endl;
    if(!a2.Borrar(t2)) cout << "ERROR: Si existe t2 y debe borrarse." << endl;
    if(!a3.Borrar(t3)) cout << "ERROR: Si existe t3 y debe borrarse." << endl;

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

    if(a1.Borrar(t1)) cout << "ERROR: No existe t1 y no debe borrar nada" << endl;
    if(a2.Borrar(t2)) cout << "ERROR: No existe t2 y no debe borrar nada" << endl;
    if(a3.Borrar(t3)) cout << "ERROR: No existe t3 y no debe borrar nada" << endl;

    //BORRAR HOJAS DERECHA

    if(!a4.Borrar(r1)) cout << "ERROR: Si existe r1 y debe borrarse" << endl;

    cout << "Preorden: " << endl << a4.Preorden() << endl;
    cout << "Postorden: " << endl << a4.Postorden() << endl;
    cout << "Inorden: " << endl << a4.Inorden() << endl;
    cout << "Niveles: " << endl << a4.Niveles() << endl << endl;

    if(!a4.Borrar(q1)) cout << "ERROR: Si existe q1 y debe borrarse" << endl;
    if(!a5.Borrar(r2)) cout << "ERROR: Si existe r2 y debe borrarse" << endl;      

    cout << "Preorden: " << endl << a4.Preorden() << endl;
    cout << "Postorden: " << endl << a4.Postorden() << endl;
    cout << "Inorden: " << endl << a4.Inorden() << endl;
    cout << "Niveles: " << endl << a4.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a5.Preorden() << endl;
    cout << "Postorden: " << endl << a5.Postorden() << endl;
    cout << "Inorden: " << endl << a5.Inorden() << endl;
    cout << "Niveles: " << endl << a5.Niveles() << endl;    
}
