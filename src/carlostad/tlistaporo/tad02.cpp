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

  if(!a.Insertar(p)) cout << "ERROR" << endl;
  if(!a.Insertar(q)) cout << "ERROR" << endl;
  if(!a.Insertar(t)) cout << "ERROR" << endl;

  if(!b.Insertar(r)) cout << "ERROR" << endl;
  if(!b.Insertar(s)) cout << "ERROR" << endl;
  if(!b.Insertar(t)) cout << "ERROR" << endl;

  cout << "******TESTING DESTRUCTOR, OPERATOR=, OPERATOR+, OPERATOR-******" << endl;
  
  TListaPoro x;
  TListaPoro d(a);

  cout << x.Longitud() << endl;
  if(!x.Primera().EsVacia()) cout << "ERROR" << endl;
  if(!x.Ultima().EsVacia()) cout << "ERROR" << endl;
  cout << x << endl;

  x = a;

  cout << x.Longitud() << endl;
  cout << x.Obtener(x.Primera()) << endl;
  cout << x.Obtener(x.Ultima()) << endl;
  cout << x << endl;

  x = x + b;

  cout << x.Longitud() << endl;
  cout << x.Obtener(x.Primera()) << endl;
  cout << x.Obtener(x.Ultima()) << endl;
  cout << x << endl;

  a = a - b;

  cout << a.Longitud() << endl;
  cout << a.Obtener(a.Primera()) << endl;
  cout << a.Obtener(a.Ultima()) << endl;
  cout << a << endl;

  a = a - a;

  cout << a.Longitud() << endl;
  if(!a.Primera().EsVacia()) cout << "ERROR" << endl;
  if(!a.Ultima().EsVacia()) cout << "ERROR" << endl;
  cout << a << endl;

  a = a + a;
  cout << a << endl;

  a = a - a;
  cout << a << endl;

  TListaPoro e(d);
  d.~TListaPoro();
  cout << e.Longitud() << endl;
  cout << e.Obtener(e.Primera()) << endl;
  cout << e.Obtener(e.Ultima()) << endl;
  cout << e << endl;

  cout << d.Longitud() << endl;
  if(!d.Primera().EsVacia()) cout << "ERROR" << endl;
  if(!d.Ultima().EsVacia()) cout << "ERROR" << endl;
  cout << d << endl;
}
