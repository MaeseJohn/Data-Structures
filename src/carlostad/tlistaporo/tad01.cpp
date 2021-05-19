#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, "rojo"), q(2, 2, 25, "verde"), 
        r(3, 3, 30, "amarillo"), s(4, 4, 15), 
        t(5, 5, -9, "azul");

  TListaPoro a, b;

  if(!a.Insertar(p)) cout << "ERROR1" << endl; // inserta en lista vacía
  if(!a.Insertar(q)) cout << "ERROR2" << endl; // inserta en la cola
  if(!a.Insertar(r)) cout << "ERROR3" << endl; // inserta en la cola
  if(!a.Insertar(s)) cout << "ERROR4" << endl; // inserta por el centro
  if(!a.Insertar(t)) cout << "ERROR5" << endl; // inserta en la cabeza
  if(a.Insertar(t)) cout << "ERROR, no pueden haber repetidos" << endl;

  cout << "******TESTING CONSTRUCTORS, DESTRUCTOR, INSERTAR, GETTERS******" << endl;
  
  if(a.EsVacia()) cout << "ERROR, a no está vacia" << endl;
  if(!b.EsVacia()) cout << "ERROR, b si está vacía" << endl;

  cout << a.Longitud() << endl;
  cout << a << endl;

  cout << b.Longitud() << endl;
  cout << b << endl;

  cout << a.Obtener(a.Primera()) << endl;
  cout << a.Obtener(a.Ultima()) << endl;

  if(!b.Primera().EsVacia()) cout << "ERROR" << endl;
  if(!b.Ultima().EsVacia()) cout << "ERROR" << endl;

  TListaPoro x(a);

  cout << x.Longitud() << endl;
  cout << x.Obtener(x.Primera()) << endl;
  cout << x.Obtener(x.Ultima()) << endl;
  cout << x << endl;
}