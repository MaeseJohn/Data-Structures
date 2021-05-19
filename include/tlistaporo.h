#ifndef _TLISTAPORO_H_
#define _TLISTAPORO_H_
#include <iostream>
#include "tporo.h"

class TListaNodo{

    private:
        // El elemento del nodo
        TPoro e;
        // El nodo anterior
        TListaNodo *anterior;
        // El nodo anterior
        TListaNodo *siguiente;

    public:
        // Constructor por defecto
        TListaNodo();
        // Constructor de copia
        TListaNodo(const TListaNodo &);
        // Destructor
        ~TListaNodo();
        // Sobrecarga del operador asignación
        TListaNodo & operator=(const TListaNodo&);

        friend class TListaPosicion;
        friend class TListaPoro;
};

class TListaPosicion{

    private:
        // Para implementar la POSICIÓN a NODO de la LISTA de TPoro
        TListaNodo *pos;

    public:
        // Constructor por defecto
        TListaPosicion();
        // Constructor de copia
        TListaPosicion(const TListaPosicion &);
        // Destructor
        ~TListaPosicion();
        // Sobrecarga del operador asignación
        TListaPosicion & operator=(const TListaPosicion &);

        //METODOS
        // Sobrecarga del operador igualdad
        bool operator==(const TListaPosicion &);
        // Devuelve la posicion anterior
        TListaPosicion Anterior()const;
        // Devuelde la posicion siguiente
        TListaPosicion Siguiente()const;
        // Devuelve TRUE si la posicion no apunta a una lista, FALSE en caso contrario
        bool EsVacia()const;
        
        friend class TListaPoro;
        friend class TListaNodo;


};

class TListaPoro{

    private:
        // Primer elemento de la lista
        TListaNodo *primero;
        // Ultimo elmento de la lista
        TListaNodo *segundo;
        TListaPoro& igualar(const TListaPoro &);

    public:
        // Constructor por defecto 
        TListaPoro();
        // Contructor de copia
        TListaPoro(const TListaPoro &);
        // Destructor
        ~TListaPoro();
        // Sobrecarga del operador asignación
        TListaPoro & operator=(const TListaPoro &);

        //METODOS

        // Sobrecarga del operador igualdad
        bool operator==(const TListaPoro &);
        // Sobrecarga del operador suma
        TListaPoro operator+(const TListaPoro &);
        // Sobrecarga del operador resta
        TListaPoro operator-(const TListaPoro &);
        // Devuelve true si la lista está vacia, false en caso contrario
        bool EsVacia()const;
        // Inserta el elmento en la lista
        bool Insertar(const TPoro &);
        // Busca y borra el elemento
        bool Borrar(const TPoro &);
        // Borra el elmento que ocupa la posicion indicada
        bool Borrar(const TListaPosicion &);
        // Obtiene el elemento que ocupa la posicion indicada
        TPoro Obtener(const TListaPosicion &)const;
        // Devuelve true si el elemento está en la lista, false en caso contrario
        bool Buscar(const TPoro &)const;
        // Devuelve la longitud de la lista
        int Longitud()const;
        // Devuelve la primera posición de la lista
        TListaPosicion Primera()const;
        // Devuelve la última posición de la lista
        TListaPosicion Ultima()const;
        // Extraer un rango de nodos de la lista
        TListaPoro ExtraerRango(int n1, int n2);

        //FUNCIONES AMIGAS
        //Sobrecarga del operador salida
        friend std::ostream & operator<<(std::ostream &, const TListaPoro &);

};
#endif