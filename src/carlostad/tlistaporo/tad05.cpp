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

  cout << "******TESTING BORRAR(TListaPosicion &)******" << endl;
  TListaPosicion x(a.Primera());
  if(a.Borrar(x)) cout << a << endl;

  x = a.Ultima();
  if(a.Borrar(x)) cout << a << endl;

  x = a.Primera().Siguiente();
  if(a.Borrar(x)) cout << a << endl;

  x = a.Primera();
  if(a.Borrar(x)) cout << a << endl;

  x = a.Ultima();
  if(a.Borrar(x)) cout << a << endl;

  x = a.Primera();
  if(!a.Borrar(x)) cout << a << endl;

  x = a.Ultima();
  if(!a.Borrar(x)) cout << a << endl << endl;
  
  x = b.Primera().Siguiente().Siguiente();
  if(b.Borrar(x)) cout << b << endl;

  //################################################################3

  x = b.Ultima();
  if(b.Borrar(x)) cout << b << endl;

  x = b.Primera();
  if(b.Borrar(x)) cout << b << endl;

  x = b.Ultima();
  if(b.Borrar(x)) cout << b << endl;

  x = b.Primera();
  if(b.Borrar(x)) cout << b << endl;

  x = b.Primera();
  if(!b.Borrar(x)) cout << b << endl;

  x = b.Primera();
  if(!b.Borrar(x)) cout << b << endl;
}
