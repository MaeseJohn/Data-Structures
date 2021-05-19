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

    TABBPoro a4, a5, a6, a7, a8, a9, a10;
    a4 = a1 + a2;
    a5 = a1 + a3;
    a6 = a2 + a3;
    a7 = a4 + a3;
    a8 = a5 + a2;
    a9 = a6 + a1;
    a10 = a9 + a7;  

    // RAIZ Y ALTURA*/

    cout << a1.Raiz() << endl;
    cout << a2.Raiz() << endl;
    cout << a3.Raiz() << endl;
    cout << a4.Raiz() << endl;
    cout << a5.Raiz() << endl;
    cout << a6.Raiz() << endl;
    cout << a7.Raiz() << endl;
    cout << a8.Raiz() << endl;
    cout << a9.Raiz() << endl;
    cout << a10.Raiz() << endl << endl;

    cout << a1.Altura() << endl;
    cout << a2.Altura() << endl;
    cout << a3.Altura() << endl;
    cout << a4.Altura() << endl;
    cout << a5.Altura() << endl;
    cout << a6.Altura() << endl;
    cout << a7.Altura() << endl;
    cout << a8.Altura() << endl;
    cout << a9.Altura() << endl;
    cout << a10.Altura() << endl << endl;

    TABBPoro a11, a12, a13, a14;

    a12.Insertar(p1);
    a13.Insertar(p1); a13.Insertar(q1);
    a14.Insertar(p1); a14.Insertar(q1); a14.Insertar(t1); 

    cout << a11.Raiz() << endl;
    cout << a12.Raiz() << endl;
    cout << a13.Raiz() << endl;
    cout << a14.Raiz() << endl << endl;

    cout << a11.Altura() << endl;
    cout << a12.Altura() << endl;
    cout << a13.Altura() << endl;
    cout << a14.Altura() << endl;
}

/*
p1:
(1, 1) 1.00 rojo
p2:
(1, 1) 1.00 rojo
p3:
(10, 10) 10.00 rojo

q1:
(2, 2) 25.00 verde
q2:
(2, 2) 25.00 verde
q3:
(20, 20) 22.00 verde

r1:
(3, 3) 30.00 amarillo
r2:
(3, 3) 35.00 amarillo
r3:
(30, 30) 8.00 amarillo

s1:
(4, 4) 15.00 -
s2:
(4, 4) 13.00 -
s3:
(40, 40) 14.00 -

t1:
(5, 5) -9.00 azul
t2:
(5, 5) -15.00 azul
t3:
(50, 50) -6.00 azul
*/
