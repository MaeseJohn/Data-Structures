#include "tabbporo.h"
#include "tporo.h"
#include "tvectorporo.h"
#include "string.h"
#include "queue"

/***************
****TNODOABB****
***************/

TNodoABB::TNodoABB() : item(), iz(), de() {}

TNodoABB::TNodoABB(const TPoro &p) : item(p), iz(), de() {}

TNodoABB::TNodoABB(const TNodoABB &n) : item(n.item), iz(n.iz), de(n.de) {}

TNodoABB::~TNodoABB() 
{
    item.~TPoro();
    iz.nodo = NULL;
    de.nodo = NULL;

    /*iz.~TABBPoro();
    de.~TABBPoro();*/
}

TNodoABB & TNodoABB::operator=(const TNodoABB &n)
{

    if (!n.de.EsVacio())
        this->de = n.de;

    if (!n.iz.EsVacio())
        this->iz = n.iz;

    this->item = n.item;

    return *this;
}

/***************
****TABBPORO****
***************/

TABBPoro::TABBPoro() : nodo(NULL) {}

TABBPoro::TABBPoro(const TABBPoro &a)
{
    nodo = NULL;
    *this = a;
    
    /*if (!a.EsVacio())
        nodo = new TNodoABB();
        nodo = a.nodo;  */  
}

TABBPoro::~TABBPoro() 
{
    if (nodo != NULL)
    {
        this->nodo->de.~TABBPoro();
        this->nodo->iz.~TABBPoro();
    
        delete nodo;
        nodo = NULL;
    }
        
}

TABBPoro & TABBPoro::operator=(const TABBPoro &a)
{
    if (!this->EsVacio())
        this->~TABBPoro();
    
    if (a.EsVacio())
        return *this;

    this->nodo = new TNodoABB();
    *this->nodo = *a.nodo;

    return *this;
}

/*****************
**METODOSPRIVADOS*
*****************/

// AUXILIAR : Devuelve el recorrido en inorden
void TABBPoro::InordenAux(TVectorPoro &v, int &x)const
{
    if (!this->EsVacio())
    {
       this->nodo->iz.InordenAux(v, x);
       v[x] = this->nodo->item;
       ++x;
       this->nodo->de.InordenAux(v, x);  
    }
}

// AUXILIAR : Devuelve el recorrido en preorden
void TABBPoro::PreordenAux(TVectorPoro &v, int &x)const
{
    if (!this->EsVacio())
    {
        v[x] = this->nodo->item;
        ++x;
        this->nodo->iz.PreordenAux(v, x);
        this->nodo->de.PreordenAux(v, x);
    }


}

// AUXILIAR : Devuelve el recorrido en postorden
void TABBPoro::PostordenAux(TVectorPoro &v, int &x)const
{
    if (!this->EsVacio())
    {
        this->nodo->iz.PostordenAux(v, x);
        this->nodo->de.PostordenAux(v, x);
        v[x] = this->nodo->item;
        ++x;
    }
}
 

TNodoABB* TABBPoro::BorrarRaiz()
{
    TNodoABB *aux;

    if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio())
    { 
        this->~TABBPoro();
        return this->nodo;
    }

    if (this->nodo->iz.EsVacio())
    {
        aux = this->nodo;
        this->nodo = this->nodo->de.nodo;
        
        delete aux;

        return this->nodo;
    }

    if (this->nodo->de.EsVacio())
    {
        aux = this->nodo;
        this->nodo = this->nodo->iz.nodo;
       
        delete aux;

        return this->nodo;
    }

    if (this->nodo->iz.nodo->de.EsVacio())
    {
        aux = this->nodo;
        this->nodo = this->nodo->iz.nodo;
        this->nodo->de.nodo = aux->de.nodo;

        delete aux;

        return this->nodo;
    }

    TNodoABB *raiz;
    raiz = this->nodo;
    aux  = this->nodo->iz.nodo;

    while (!aux->de.nodo->de.EsVacio())
    {
        aux = aux->de.nodo;
    }

    this->nodo          = aux->de.nodo;
    aux->de.nodo        = aux->de.nodo->iz.nodo;
    this->nodo->de.nodo = raiz->de.nodo;
    this->nodo->iz.nodo = raiz->iz.nodo;

    delete raiz;
    
    return this->nodo;

}

/*****************
***** MÉTODOS*****
*****************/

bool TABBPoro::operator==(const TABBPoro &a) const
{

    if (this->EsVacio() && a.EsVacio())
        return true;

    if ((this->EsVacio() || a.EsVacio()) && (!this->EsVacio() || !a.EsVacio()))
        return false;

    if (this->Nodos() != a.Nodos())
        return false;

    TVectorPoro vec;
    vec = this->Postorden();

    int veclong = vec.Longitud();

    for (int i=1;i<=veclong;++i)
    {
        if (!a.Buscar(vec[i]))
            return false;
    }

    return true;
}

bool TABBPoro::EsVacio() const
{
    return (this->nodo == NULL);
}

bool TABBPoro::Insertar(const TPoro &p)
{
    if (this->EsVacio())
    {
        this->nodo = new TNodoABB(p);
        return true;
    }

    if (this->nodo->item == p)
        return false;

    if (this->nodo->item.Volumen() > p.Volumen())
        return this->nodo->iz.Insertar(p);

    if (this->nodo->item.Volumen() < p.Volumen())
        return this->nodo->de.Insertar(p);

    return false;
}

bool TABBPoro::Borrar(const TPoro &p)
{
    if (this->EsVacio())
        return false;

    if (this->nodo->item == p)
    {
        this->BorrarRaiz();
        return true;    
    }
    
    if (this->nodo->item.Volumen() < p.Volumen())
    {
        if (this->nodo->de.EsVacio())
            return false;

        if (this->nodo->de.nodo->item == p)
        {     
            this->nodo->de.nodo = this->nodo->de.BorrarRaiz();
            return true;
        }
        
        return this->nodo->de.Borrar(p);
    }

    if (this->nodo->item.Volumen() > p.Volumen())
    {
        if (this->nodo->iz.EsVacio())
            return false;

        if (this->nodo->iz.nodo->item == p)
        {
            this->nodo->iz.nodo = this->nodo->iz.BorrarRaiz();
            return true;
        }
        
        return this->nodo->iz.Borrar(p);
    }

    return false;
}

bool TABBPoro::Buscar(const TPoro &p)const
{
    if (this->EsVacio())
        return false;

    if (this->nodo->item == p)
        return true;

    if (this->nodo->item.Volumen() < p.Volumen())
        return this->nodo->de.Buscar(p);

    if (this->nodo->item.Volumen() > p.Volumen())
        return this->nodo->iz.Buscar(p);

    return false;
}

TPoro TABBPoro::Raiz()const
{
    if (this->EsVacio())
    {
        TPoro e;
        return e;
    }

    return this->nodo->item;
}

int TABBPoro::Altura()const
{
    int iz, de; 

    if (this->EsVacio())
        return 0;

    iz = 1 + this->nodo->iz.Altura();
    de = 1 + this->nodo->de.Altura();

    if (iz > de)
        return iz;

    return de;
}

int TABBPoro::Nodos()const
{
    int iz, de ;

    if (this->EsVacio())
        return 0;  

    iz = this->nodo->iz.Nodos();
    de = this->nodo->de.Nodos();

    return 1 + iz + de; 
}

int TABBPoro::NodosHoja()const
{
    int iz, de;

    if (this->EsVacio())
        return 0;

    if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        return 1;

    iz = this->nodo->iz.NodosHoja();
    de = this->nodo->de.NodosHoja();

    return iz + de;
}

// Devuelve el recorrido en inorde
TVectorPoro TABBPoro::Inorden()const
{
    int x = 1;
    TVectorPoro v(Nodos());

    InordenAux(v, x);
    return v;
}

// Devuelve el recorrido en preorden
TVectorPoro TABBPoro::Preorden()const
{
    int x = 1;
    TVectorPoro v(Nodos());

    PreordenAux(v, x);
    return v;
}

TVectorPoro TABBPoro::Postorden()const
{
    int x = 1;
    TVectorPoro v(Nodos());

    PostordenAux(v, x);
    return v;
}

TVectorPoro TABBPoro::Niveles()const
{

    TVectorPoro v(Nodos());
    int x = 1;

    if (this->EsVacio())
        return v;

    std::queue<TNodoABB*> q;
    q.push(this->nodo);

    while (!q.empty())
    {
        TNodoABB *n;
        n = q.front();
        q.pop();
        v[x] = n->item;
        ++x;

        if (!n->iz.EsVacio())
            q.push(n->iz.nodo);

        if (!n->de.EsVacio())
            q.push(n->de.nodo);

    }

    return v;
}

TABBPoro TABBPoro::operator+(const TABBPoro &a)const
{

    TABBPoro suma(*this);
    TVectorPoro v(a.Inorden());
    int x = 1;


    for (int i=1;i<=v.Longitud();++i)
        suma.Insertar(v[i]);

    return suma;
}

TABBPoro TABBPoro::operator-(const TABBPoro &a)const
{
    TABBPoro resta;
    TVectorPoro v(this->Inorden());
    int x = 1;

    for (int i=1;i<=v.Longitud();++i)
        if (!a.Buscar(v[i]))
            resta.Insertar(v[i]);
  

    return resta;
}

std::ostream & operator<<(std::ostream &os, const TABBPoro &a)
{
    os<<a.Niveles();
    return os;

}
