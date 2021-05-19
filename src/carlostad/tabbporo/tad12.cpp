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

   //POR SI EL INSERTAR TE PETA EL OJETE 
   /*a.nodo = new TNodoABB(); 
     a.nodo->item = p1;

     a.nodo->de.nodo = new TNodoABB();
     a.nodo->de.nodo->item = p2; 

     a.nodo->de.nodo->de.nodo = new TNodoABB();
     a.nodo->de.nodo->de.nodo->item = p3; */

   //-------- arbol vacio -------------------
   if(a.Buscar(p1) || a.Buscar(p2) || a.Buscar(p3) || a.Buscar(p4) || a.Buscar(p5) || a.Buscar(p6))
      cout << "ERROR encontro algo en arbol vacio" << endl;
   cout << a << endl << endl;

   //-------- arbol con 1 elemento -------------------
   a.Insertar(p4);
   if(a.Buscar(p1) || a.Buscar(p2) || a.Buscar(p3) || a.Buscar(p5) || a.Buscar(p6))
      cout << "ERROR busqueda de arbol con 1 elem" << endl;
   if(!a.Buscar(p4))
      cout << "ERROR no ha encontrado el unico elemento" << endl;
   cout << a << endl << endl;

   //-------- arbol con 3 elemento -------------------
   a.Insertar(p4);
   a.Insertar(p3);
   a.Insertar(p5);
   
   cout << a << endl;
   
   if(a.Buscar(p1) || a.Buscar(p2) || a.Buscar(p6))
      cout << "ERROR busqueda de arbol con 3 elem" << endl;

   if(!a.Buscar(p4))
      cout << "ERROR no ha encontrado p4" << endl; 

   if(!a.Buscar(p3))
      cout << "ERROR no ha encontrado p3" << endl; 

   if(!a.Buscar(p5))
      cout << "ERROR no ha encontrado p5" << endl;

   cout << endl;

   //-------- arbol con varios elemento -------------------
   a.Insertar(p2);
   a.Insertar(p6);
   a.Insertar(p7);
   a.Insertar(p1);

   cout << a << endl;

   if(!a.Buscar(p4))
      cout << "ERROR no ha buscado cabeza (tiene 2 hijos)" << endl; 

   if(!a.Buscar(p3))
      cout << "ERROR no ha buscado cabeza (tiene 2 hijos) x2" << endl;

   if(!a.Buscar(p7))
      cout << "ERROR no ha buscado nodo hoja con padre" << endl;

   if(!a.Buscar(p6))
      cout << "ERROR no ha buscado nodo con padre e 1 hijo izq" << endl;

   if(!a.Buscar(p2))
      cout << "ERROR no ha buscado cabeza (tiene 2 hijos) x3" << endl;

   if(!a.Buscar(p1))
      cout << "ERROR no ha buscado cabeza (tiene 1 hijo der)" << endl;

   if(!a.Buscar(p5))
      cout << "ERROR no ha buscado cabeza siendo arbol hoja" << endl;

   cout << "Buscados to bien" << endl;

   return 1;
}
