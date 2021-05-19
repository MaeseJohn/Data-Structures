#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, "rojo");

  TVectorPoro p;
  TVectorPoro v(5);
  TVectorPoro b(v);

  v[1] = a;
  v[2] = a;
  v[3] = a;

  TVectorPoro x(v);
  TVectorPoro z;

  cout << "******TESTING CONSTRUCTORS, OPERATOR[], OPERATOR= AND GETTERS******" << endl;

  cout << p.Longitud() << ", "<< p.Cantidad() << endl;
  cout << p << endl;

  cout << b.Longitud() << ", "<< b.Cantidad() << endl;
  cout << b << endl;

  cout << v.Longitud() << ", "<< v.Cantidad() << endl;
  v[4] = a;
  v[5] = a;
  cout << v.Longitud() << ", "<< v.Cantidad() << endl;
  cout << v << endl;

  cout << x.Longitud() << ", "<< x.Cantidad() << endl;
  cout << x << endl;

  z = v;
  cout << z.Longitud() << ", "<< z.Cantidad() << endl;
  cout << z << endl;

  cout << z[0] << endl;
  cout << z[6] << endl;
}
