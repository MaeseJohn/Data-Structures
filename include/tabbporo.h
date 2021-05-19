#ifndef _TABBPORO_H_
#define _TABBPORO_H_
#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"

class TNodoABB;


class TABBPoro
{
    private:

        // Puntero al nodo
        TNodoABB *nodo;
        // AUXILIAR : Devuelve el recorrido en inorden
        void InordenAux(TVectorPoro &, int &)const;
        // AUXILIAR : Devuelve el recorrido en preorden
        void PreordenAux(TVectorPoro &, int &)const;
        // AUXILIAR : Devuelve el recorrido en postorden
        void PostordenAux(TVectorPoro &, int &)const;
        // AUXILIAR : Devuelve true si borra y modifica la raiz
        TNodoABB* BorrarRaiz();
    
    public:

        // Constructor por defecto
        TABBPoro();
        // Constructor de copia
        TABBPoro(const TABBPoro &);
        // Destructor
        ~TABBPoro();

        // Sobrecarga del operador asignación
        TABBPoro & operator=(const TABBPoro &);


        /*****************
        ***** MÉTODOS*****
        ******************/

        // Sobrecarga del operador igualdad
        bool operator==(const TABBPoro &)const;

        // Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
        bool EsVacio()const;

        // Inserta el elemento en el árbol
        bool Insertar(const TPoro &);

        // Borra el elemento en el árbol
        bool Borrar(const TPoro &);

        // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
        bool Buscar(const TPoro &)const;

        // Devuelve el elemento en la raíz del árbol
        TPoro Raiz()const;

        // Devuelve la altura del árbol (la altura de un árbol vacío es 0)
        int Altura()const;

        // Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
        int Nodos()const;

        // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
        int NodosHoja()const;

        // Devuelve el recorrido en inorden
        TVectorPoro Inorden()const;

        // Devuelve el recorrido en preorden
        TVectorPoro Preorden()const;

        // Devuelve el recorrido en postorden
        TVectorPoro Postorden()const;

        // Devuelve el recorrido en niveles
        TVectorPoro Niveles()const;

        // Suma de dos ABB
        TABBPoro operator+(const TABBPoro &)const;

        // Resta de dos ABB
        TABBPoro operator-(const TABBPoro &)const;

        friend class TNodoABB;
        // Sobrecarga del operador salida
        friend std::ostream & operator<<(std::ostream &, const TABBPoro &);


};

class TNodoABB
{
    private:

        // El elemento del nodo
        TPoro item;
        // Subárbol izquierdo y derecho
        TABBPoro iz, de;
    
    public:

        // Constructor por defecto
        TNodoABB();
        // Constructor de copia
        TNodoABB(const TNodoABB &);
        // Constructor poro paramatreo
        TNodoABB(const TPoro &);
        // Destructor
        ~TNodoABB();
    
        // Sobrecarga del operador asignación
        TNodoABB & operator=(const TNodoABB &);
        
        friend class TABBPoro;

};

#endif