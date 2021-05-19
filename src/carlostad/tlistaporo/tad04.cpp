#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, "rojo"), q(2, 2, 25, "verde"), 
        r(3, 3, 30, "amarillo"), s(4, 4, 15), 
        t(5, 5, -9, "azul");

  TListaPoro a;

  if(!a.Insertar(p)) cout << "ERROR" << endl;
  if(!a.Insertar(q)) cout << "ERROR" << endl;
  if(!a.Insertar(t)) cout << "ERROR" << endl;
  if(!a.Insertar(r)) cout << "ERROR" << endl;
  if(!a.Insertar(s)) cout << "ERROR" << endl;

  TListaPoro b(a);
  TListaPoro c(a);
  TListaPoro d(a);
  TListaPoro e(a);
  TListaPoro f(a);

  cout << "******TESTING EXTRAER_RANGO******" << endl;

  cout << a.ExtraerRango(1, 3) << endl;
  cout << a << endl << endl;

  cout << b.ExtraerRango(-1, 3) << endl;
  cout << b << endl << endl;

  cout << c.ExtraerRango(1, -3) << endl;
  cout << c << endl << endl;

  cout << d.ExtraerRango(2, 2) << endl;
  cout << d << endl << endl;

  cout << e.ExtraerRango(-1, 30) << endl;
  cout << e << endl << endl;

  cout << f.ExtraerRango(9, 25) << endl;
  cout << f << endl;
}
