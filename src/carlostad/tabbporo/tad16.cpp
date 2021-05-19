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
   if(a.Borrar(p1) || a.Borrar(p2) || a.Borrar(p3) || a.Borrar(p4) || a.Borrar(p5) || a.Borrar(p6))
      cout << "ERROR borrado de arbol vacio" << endl;
   cout << a << endl;

   //-------- arbol con 1 elemento -------------------
   a.Insertar(p4);
   if(a.Borrar(p1) || a.Borrar(p2) || a.Borrar(p3) || a.Borrar(p5) || a.Borrar(p6))
      cout << "ERROR borrado de arbol con 1 elem" << endl;
   if(!a.Borrar(p4))
      cout << "ERROR no ha borrado el unico elemento" << endl;
   cout << a << endl;

   //-------- comprobar que elimina bien con 1 hijo izq -------------------
   a.Insertar(p5);
   a.Insertar(p2);
   a.Insertar(p1);
   a.Insertar(p3);
   a.Insertar(p4);
   cout << a << endl;

   a.Borrar(p5);
   cout << a << endl;

   a.Borrar(p2);
   cout << a << endl;

   a.Borrar(p3);
   cout << a << endl;

   a.Borrar(p1);
   cout << a << endl;

   a.Borrar(p4);
   cout << a << endl << endl;
   
   
   //-------- arbol con 3 elemento -------------------
   a.Insertar(p4);
   a.Insertar(p3);
   a.Insertar(p5);
   if(a.Borrar(p1) || a.Borrar(p2) || a.Borrar(p6))
      cout << "ERROR borrado de arbol con 3 elem" << endl;
   cout << a << endl;

   if(!a.Borrar(p4))
      cout << "ERROR no ha borrado con 2 hijos" << endl; 
   cout << a << endl;

   if(!a.Borrar(p3))
      cout << "ERROR no ha borrado con 1 der hijo" << endl;
   cout << a << endl;

   if(!a.Borrar(p5))
      cout << "ERROR no ha borrado siendo arbol hoja" << endl;
   cout << a << endl;


   //-------- arbol con varios elemento -------------------
   a.Insertar(p4);
   a.Insertar(p2);
   a.Insertar(p3);
   a.Insertar(p6);
   a.Insertar(p7);
   a.Insertar(p5);
   a.Insertar(p1);

   cout << a << endl;

   if(!a.Borrar(p4))
      cout << "ERROR no ha borrado cabeza (tiene 2 hijos)" << endl; 
   cout << a << endl;

   if(!a.Borrar(p3))
      cout << "ERROR no ha borrado cabeza (tiene 2 hijos) x2" << endl;
   cout << a << endl;

   if(!a.Borrar(p7))
      cout << "ERROR no ha borrado nodo hoja con padre" << endl;
   cout << a << endl;

   if(!a.Borrar(p6))
      cout << "ERROR no ha borrado nodo con padre e 1 hijo izq" << endl;
   cout << a << endl;

   if(!a.Borrar(p2))
      cout << "ERROR no ha borrado cabeza (tiene 2 hijos) x3" << endl;
   cout << a << endl;

   if(!a.Borrar(p1))
      cout << "ERROR no ha borrado cabeza (tiene 1 hijo der)" << endl;
   cout << a << endl;

   if(!a.Borrar(p5))
      cout << "ERROR no ha borrado cabeza siendo arbol hoja" << endl;
   cout << a << endl;

   cout << "Borrados to bien" << endl;

   return 1;
}
