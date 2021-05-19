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
   TPoro p9(1,2,(double) 9,(char *) "rojo9");
   TPoro p10(1,2,(double) 10,(char *) "rojo10");
   TPoro p11(1,2,(double) 11,(char *) "rojo11");
   TPoro p12(1,2,(double) 12,(char *) "rojo12");
   TPoro p25(1,2,(double) 2.5,(char *) "rojo2.5");
   TPoro p35(1,2,(double) 3.5,(char *) "rojo3.5");

   //POR SI EL INSERTAR TE PETA EL OJETE 
   /*a.nodo = new TNodoABB(); 
     a.nodo->item = p1;

     a.nodo->de.nodo = new TNodoABB();
     a.nodo->de.nodo->item = p2; 

     a.nodo->de.nodo->de.nodo = new TNodoABB();
     a.nodo->de.nodo->de.nodo->item = p3; */

   //-------- arbol vacio -------------------
   cout << "Nodos arbol vacio: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   //-------- arbol con 1 elemento -------------------
   a.Insertar(p4);
   cout << "Nodos arbol hoja: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   //-------- arbol con 3 elemento -------------------
   a.Insertar(p3);
   a.Insertar(p5);
   
   cout << "Nodos arbol con 2 hojas: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   //-------- arbol con varios elemento -------------------
   a.Insertar(p2);
   
   cout << "Nodos arbol +complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   a.Insertar(p7);
   
   cout << "Nodos arbol ++complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;
   
   a.Insertar(p6);   
      
   cout << "Nodos arbol +++complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;
   
   a.Insertar(p1);
      
   cout << "Nodos arbol ++++complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;
  
   a.Insertar(p8);
   
   cout << "Nodos arbol complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   a.Insertar(p12);
   
   cout << "Nodos arbol complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   a.Insertar(p10);
   
   cout << "Nodos arbol complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   a.Insertar(p11);
   a.Insertar(p9);
   
   cout << "Nodos arbol complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;

   a.Insertar(p25);
   a.Insertar(p35);
   
   cout << "Nodos arbol complejo: " << a.NodosHoja() << endl;
   cout << a << endl << endl;





   cout << "Contados to bien" << endl;

   return 1;
}
