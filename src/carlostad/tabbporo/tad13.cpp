#include <iostream>
#include "tabbporo.h"
using namespace std;


int main(void){

   TABBPoro a;

   TPoro p1(1,2,(double) 1,(char *) "rojo");
   TPoro p2(1,2,(double) 2,(char *) "rojo2");
   TPoro p3(1,2,(double) 3,(char *) "rojo3");
   TPoro p4(1,2,(double) 4,(char *) "rojo4");
   
   //-------- Arbol nulo -----------------
   
   TABBPoro b(a); 

   if(a.EsVacio() && b.EsVacio())
      cout << "Arbol A y B vacios: " << endl;
   cout << a << endl;
   cout << b << endl;
    
   
   //-------- Arbol con un elemento -----------------

   a.Insertar(p2);
   p2.~TPoro();
   TABBPoro c(a); 
   if(a.EsVacio() || c.EsVacio())
      cout <<  "ERROR, pone que esta vacio" << endl;
   cout << a << endl;
   cout << c << endl;
  
   //-------- Arbol con dos hijos -----------------

   a.Insertar(p1);
   p1.~TPoro();

   TABBPoro d(a); 
   if(a.EsVacio() || d.EsVacio())
      cout <<  "ERROR, pone que esta vacio 2" << endl;
   cout << a << endl;
   cout << d << endl;
   
   //-------- Arbol con varios hijos -----------------

   a.Insertar(p4);
   a.Insertar(p3);
   p4.~TPoro();
   p3.~TPoro();

   TABBPoro e(a); 
   if(a.EsVacio() || e.EsVacio())
      cout <<  "ERROR, pone que esta vacio 3" << endl;
   cout << a << endl;
   cout << e << endl;

   a.~TABBPoro();
   b.~TABBPoro();
   c.~TABBPoro();
   d.~TABBPoro();
   e.~TABBPoro();

   cout << "Constructores to guapos" << endl;

   return 1;
}
