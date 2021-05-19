#include <iostream>
#include "tabbporo.h"
using namespace std;


int main(void){

   TABBPoro a;

   TPoro p1(1,2,(double) 1,(char *) "rojo");
   TPoro p2(1,2,(double) 2,(char *) "rojo2");
   TPoro p3(1,2,(double) 3,(char *) "rojo3");
   TPoro p4(1,2,(double) 4,(char *) "rojo4");
   TPoro p5(1,2,(double) 5,(char *) "rojo5");
   TPoro p6(1,2,(double) 6,(char *) "rojo6");
   TPoro p7(1,2,(double) 7,(char *) "rojo7");
   TPoro p8(1,2,(double) 8,(char *) "rojo8");
   
   //-------- Arbol nulo -----------------

   cout << a << endl;
   
   //-------- Arbol con un elemento -----------------

   a.Insertar(p2);
   if(a.Insertar(p2))
         cout << "ERROR doble poro insertado" << endl;
   
   cout << a << endl;
  
   //-------- Arbol con dos hijos -----------------

   a.Insertar(p1);
   if(a.Insertar(p2) || a.Insertar(p1))
         cout << "ERROR doble poro insertado 2" << endl;

   cout << a << endl;
   
   //-------- Arbol con varios hijos -----------------

   a.Insertar(p8);
   a.Insertar(p7);
   a.Insertar(p5);
   a.Insertar(p6);
   a.Insertar(p4);
   a.Insertar(p3);
   
   if(a.Insertar(p2) || a.Insertar(p1) || a.Insertar(p3) || a.Insertar(p4) || a.Insertar(p5) 
      || a.Insertar(p6) || a.Insertar(p7) || a.Insertar(p8))
         cout << "ERROR doble poro insertado 3" << endl;
   
   p8.~TPoro();
   p7.~TPoro();
   p5.~TPoro();
   p6.~TPoro();
   p4.~TPoro();
   p3.~TPoro();

   cout << a << endl;

   a.~TABBPoro();

   cout << "Insertados to bien" << endl;

   return 1;
}
