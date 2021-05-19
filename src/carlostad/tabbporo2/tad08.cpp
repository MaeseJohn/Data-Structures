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

    TABBPoro a4(a1);    

    //BORRAR NODO CON SOLO HIJO IZQUIERDA

    if(!a1.Borrar(p1)) cout << "ERROR: Si existe p1 y debe borrarse." << endl;    
    if(!a3.Borrar(q3)) cout << "ERROR: Si existe q3 y debe borrarse." << endl;

    cout << "Preorden: " << endl << a1.Preorden() << endl;
    cout << "Postorden: " << endl << a1.Postorden() << endl;
    cout << "Inorden: " << endl << a1.Inorden() << endl;
    cout << "Niveles: " << endl << a1.Niveles() << endl << endl;

    cout << "Preorden: " << endl << a3.Preorden() << endl;
    cout << "Postorden: " << endl << a3.Postorden() << endl;
    cout << "Inorden: " << endl << a3.Inorden() << endl;
    cout << "Niveles: " << endl << a3.Niveles() << endl << endl;    

    if(a1.Borrar(p1)) cout << "ERROR: No existe p1 y no debe borrar nada" << endl;
    if(a3.Borrar(q3)) cout << "ERROR: No existe q3 y no debe borrar nada" << endl;

    //BORRAR NODO CON SOLO HIJO DERECHA
    
    if(!a3.Borrar(p3)) cout << "ERROR: Si existe p3 y debe borrarse" << endl;   
    if(!a4.Borrar(q1)) cout << "ERROR: Si existe q1 y debe borrarse" << endl;      

    cout << "Preorden: " << endl << a3.Preorden() << endl;
    cout << "Postorden: " << endl << a3.Postorden() << endl;
    cout << "Inorden: " << endl << a3.Inorden() << endl;
    cout << "Niveles: " << endl << a3.Niveles() << endl << endl;   

    cout << "Preorden: " << endl << a4.Preorden() << endl;
    cout << "Postorden: " << endl << a4.Postorden() << endl;
    cout << "Inorden: " << endl << a4.Inorden() << endl;
    cout << "Niveles: " << endl << a4.Niveles() << endl;   
}
