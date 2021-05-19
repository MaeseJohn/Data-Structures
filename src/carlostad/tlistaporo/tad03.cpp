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

  cout << "******TESTING OPERATOR==, BORRAR, OBTENER, BUSCAR******" << endl;
  
  TListaPoro c(a);
  TListaPoro d;
  d = a;

  if(a == b) cout << "ERROR, son diferentes" << endl;
  if(a == c) cout << "Correcto, son iguales" << endl;
  if(a == d) cout << "Correcto, son iguales" << endl;
  if(d == b) cout << "ERROR, son diferentes" << endl;

  if(a.Borrar(p)) cout << "Correcto, debe borrarlo" << endl;
  if(a.Borrar(r)) cout << "ERROR, elemento no existe en la lista" << endl;
  if(a.Borrar(p)) cout << "ERROR, elemento ya ha sido borrado antes" << endl;

  cout << a << endl;

  TListaPoro e;
  if(e.Borrar(p)) cout << "ERROR, lista vacía, nada que borrar" << endl;

  cout << b.Obtener(b.Primera()) << endl;
  cout << b.Obtener(b.Primera().Anterior()) << endl;
  cout << b.Obtener(b.Primera().Siguiente()) << endl;

  if(!b.Buscar(r)) cout << "ERROR, si que está en la lista" << endl;
  if(b.Buscar(r)) cout << "Correcto, objeto encontrado" << endl;
  if(!b.Buscar(p)) cout << "Correcto, el objeto no está en la lista" << endl;
}
