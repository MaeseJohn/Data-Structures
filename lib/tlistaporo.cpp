#include "tlistaporo.h"
#include "tporo.h"
#include <string.h>


    //////////////////////
    //////TLISTANODO//////
    //////////////////////

    // Constructor por defecto
    TListaNodo::TListaNodo():anterior(NULL), siguiente(NULL), e(){}

    // Constructor de copia
    TListaNodo::TListaNodo(const TListaNodo &p):e(p.e), anterior(p.anterior), siguiente(p.siguiente){}

    // Destructor
    TListaNodo::~TListaNodo(){
        if(siguiente != NULL){
            siguiente->anterior = anterior;
        }
        if(anterior != NULL){
            anterior->siguiente = siguiente;
        }
        this->siguiente = NULL;
        this->anterior = NULL;
    }

    // Sobrecarga del operador asignación
    TListaNodo& TListaNodo::operator=(const TListaNodo &p){
        if(this != NULL){  
            this->siguiente = p.siguiente;
            this->anterior  = p.anterior;
            this->e         = p.e;    
            return *this;
        }
        return *this;
    }

    

    //////////////////////
    ////TLISTAPOSICION////
    //////////////////////

    // Constructor por defecto
    TListaPosicion::TListaPosicion():pos(NULL){}

    // Constructor de copia
    TListaPosicion::TListaPosicion (const TListaPosicion &p):pos(p.pos){}

    // Destructor
    TListaPosicion::~TListaPosicion(){
        pos = NULL;
    }

    // Sobrecarga del operador asignación
    TListaPosicion& TListaPosicion::operator=(const TListaPosicion &p){
        this->pos = p.pos;
        return *this;
    }

    //METODOS
    // Sobrecarga del operador igualdad
    bool TListaPosicion::operator==(const TListaPosicion &p){
        return (this->pos == p.pos);
    }
    // Devuelve la posicion anterior
    TListaPosicion TListaPosicion::Anterior()const{
        TListaPosicion p;
        if(pos == NULL){
            return p;
        }
        p.pos = pos->anterior;
        return p;
    }
    // Devuelde la posicion siguiente
    TListaPosicion TListaPosicion::Siguiente()const{
        TListaPosicion p;
        if(pos == NULL){
            p.pos = NULL;
            return p;
        }
        p.pos = pos->siguiente;
        return p;
    }
    // Devuelve TRUE si la posicion no apunta a una lista, FALSE en caso contrario
    bool TListaPosicion::EsVacia()const{
        if(pos == NULL){
            return true;
        }
        return ((this->pos->anterior == NULL) && (this->pos->siguiente == NULL));
    }

    //////////////////////
    //////TLISTAPORO//////
    //////////////////////


    // Constructor por defecto 
    TListaPoro::TListaPoro():primero(NULL), segundo(NULL){}

    // Contructor de copia
    TListaPoro::TListaPoro(const TListaPoro &p):primero(NULL), segundo(NULL){
        
        /*TListaPosicion auxpos;
        auxpos.pos = p.primero;
        bool b = true;
        do
        {  
            if(auxpos.pos->siguiente == NULL){
            b = false;
            }else{
            auxpos.pos = auxpos.pos->siguiente;
            } 
            this->Insertar(auxpos.pos->e);
        } while (b);
        */
       this->igualar(p);
    }

    // Destructor
    TListaPoro::~TListaPoro(){
        if(this->primero == NULL && this->segundo == NULL){
            return;
        }
        TListaPosicion aux;
        while(this->primero != NULL){
            aux.pos = this->primero;
            this->primero = aux.Siguiente().pos;
            //aux.pos->~TListaNodo();
            delete aux.pos;
        }
        this->segundo = NULL;
    }
    // Sobrecarga del operador asignación
    TListaPoro& TListaPoro::operator=(const TListaPoro &p){
        this->~TListaPoro();
        this->igualar(p);
        return *this;
    }
    TListaPoro& TListaPoro::igualar(const TListaPoro &p){

        TListaPosicion auxp;
        auxp.pos = p.primero;
        int l = p.Longitud();
        for(int i = 0;i<l;++i){
            this->Insertar(auxp.pos->e);
            auxp.pos = auxp.pos->siguiente;

        }

        return *this;
    }

    //METODOS

    // Sobrecarga del operador igualdad
    bool TListaPoro::operator==(const TListaPoro &p){
        int l = this->Longitud();

        if(this->EsVacia() && p.EsVacia()){
            return true;
        }
        //Si su longitud es diferente return F directamente
        if(l != p.Longitud()){
            return false;
        }

        //Si la longitud es 1 y son iguales true
        if(l == 1){
            return (this->primero == p.primero);
        }

        //Si el primero o el ultimo son distintos f
        if((this->primero->e != p.primero->e)||(this->segundo->e != p.segundo->e)){
            return false;
        }
  
        TListaPosicion auxt;
        TListaPosicion auxp;
        auxt.pos = this->primero->siguiente;
        auxp.pos = p.primero->siguiente;
        
        while(auxp.pos->siguiente != NULL){
            if(auxt.pos->e != auxp.pos->e){
                return false;
            }
            auxt.pos = auxt.pos->siguiente;
            auxp.pos = auxp.pos->siguiente;
        }
        return true;  
    }

    // Sobrecarga del operador suma
    TListaPoro TListaPoro::operator+(const TListaPoro &p){
        //Nueva lista con los nodos de las otras en orden
        //Copia una lista en la nueva lista, ahora añade los elementos de la otra 1 a 1 (fun insertar en bucle)
        if(this->EsVacia()){
            return p;
        }

        TListaPoro aux(*this);
        TListaPosicion pos;
        pos.pos = p.primero;
        do{
            aux.Insertar(pos.pos->e);
            pos.pos = pos.pos->siguiente;
        }while (pos.pos != p.segundo);

        aux.Insertar(p.segundo->e);

        return aux;
    }
    
    // Sobrecarga del operador resta
    TListaPoro TListaPoro::operator-(const TListaPoro &p){
       //Usa borrar, que busca y borra un elemento de la lista si es que está
       //hazlo repetidas veces
       if(*this == p){
           TListaPoro aux;
           return aux;
       }

        TListaPoro aux(*this);
        TListaPosicion pos;
        pos.pos = p.primero;

        do{
            aux.Borrar(pos.pos->e);
            pos.pos = pos.pos->siguiente;
        }while (pos.pos != p.segundo);

        this->Borrar(p.segundo->e);

        return aux;

    }

    // Devuelve true si la lista está vacia, false en caso contrario
    bool TListaPoro::EsVacia()const{
        return ((this->primero == NULL)&&(this->segundo == NULL));
    }
   
    // Inserta el elmento en la lista
    bool TListaPoro::Insertar(const TPoro &p){

         if(this->EsVacia()){
            TListaNodo *aux = new TListaNodo;
            aux->e = p;
            aux->siguiente = this->primero;
            this->primero = aux;
            this->segundo = aux;
            return true;

        }
        if(p.Volumen() > this->segundo->e.Volumen()){
            TListaNodo *aux = new TListaNodo;
            aux->e = p;
            aux->anterior = this->segundo;
            this->segundo->siguiente = aux;
            this->segundo = aux;
            return true;

        }
        if(p.Volumen() < this->primero->e.Volumen()){
            TListaNodo *aux = new TListaNodo;
            aux->e = p;
            aux->siguiente = this->primero;
            this->primero->anterior = aux;
            this->primero = aux;
            return true;

        }

        TListaPosicion posaux;
        posaux.pos = this->primero;
        int j = this->Longitud();

        for(int i=0;i<j;++i){

            if(posaux.pos->e == p){
                return false;
            }else{

                if(posaux.pos->e.Volumen() == p.Volumen()){
                    TListaNodo *aux = new TListaNodo;
                    aux->anterior = posaux.pos;
                    aux->siguiente = posaux.pos->siguiente;
                    posaux.pos->siguiente->anterior = aux;
                    posaux.pos->siguiente = aux;
                    aux->e = p;
                    return true;
                }
                if(posaux.pos->e.Volumen() > p.Volumen()){
                    TListaNodo *aux = new TListaNodo;
                    aux->siguiente = posaux.pos;
                    aux->anterior  = posaux.pos->anterior;
                    posaux.pos->anterior->siguiente = aux;
                    posaux.pos->anterior = aux;
                    aux->e = p;
                    return true;
                }
                if(posaux.pos->siguiente != NULL){
                    posaux.pos = posaux.pos->siguiente;
                }
            }
        }
        //HACER QUE BUSCAR BUSQUE EL ELEMENTO EN LA LISTA
        return false;
    }

    // Busca y borra el elemento
    bool TListaPoro::Borrar(const TPoro &p){
        if(this->EsVacia()){
            return false;
        }
        if(this->Longitud() == 1){
            if(this->primero->e == p){
                delete this->primero;
                //this->primero->~TListaNodo();
                this->primero = NULL;
                this->segundo = NULL;

                return true;
            }
            return false;
        }

        if(this->primero->e == p){
            TListaPosicion posauxp;
            posauxp.pos = this->primero->siguiente;
            delete this->primero;
            //this->primero->~TListaNodo();
            this->primero = posauxp.pos;
            if(this->primero->anterior != NULL){
                this->primero->anterior = NULL;
            }
            return (this->primero->e != p);
        }

        if(this->segundo->e == p){
            TListaPosicion posauxs;
            posauxs.pos = this->segundo->anterior;
            delete this->segundo;
            //this->segundo->~TListaNodo();
            this->segundo = posauxs.pos;
            if(this->segundo->siguiente != NULL){
                this->segundo->siguiente = NULL;
            }
            return (this->segundo->e != p);
        }

        TListaPosicion posaux;
        posaux.pos = this->primero->siguiente;
        int j = this->Longitud();

        for(int i=2;i<j;++i){
            if(posaux.pos->e == p){

                posaux.pos->anterior->siguiente = posaux.pos->siguiente;
                posaux.pos->siguiente->anterior = posaux.pos->anterior;
                delete posaux.pos;
                //posaux.pos->~TListaNodo();
                
                return true;
            }
            if(posaux.pos->siguiente == NULL){
                break;
            }
            posaux.pos = posaux.pos->siguiente;

        }

        return false;
    }
   
    // Borra el elmento que ocupa la posicion indicada
    bool TListaPoro::Borrar(const TListaPosicion &pos){
        
        if(this->EsVacia()){
            return false;
        }

        if(pos.pos == NULL){
            return false;
        }

        if(this->primero != pos.pos){
            pos.pos->anterior->siguiente = pos.pos->siguiente;
        }else{
            this->primero = primero->siguiente;
        }
        if(this->segundo != pos.pos){
            pos.pos->siguiente->anterior = pos.pos->anterior;
        }else{
            this->segundo = segundo->anterior;
        }
        //pos.pos->~TListaNodo();
        delete pos.pos;
        return true;
    }

    // Obtiene el elemento que ocupa la posicion indicada
    TPoro TListaPoro::Obtener(const TListaPosicion &p)const{
        if(p.pos == NULL){
            TPoro error;
            return error;
        }
        return p.pos->e;
    }
   
    // Devuelve true si el elemento está en la lista, false en caso contrario
    bool TListaPoro::Buscar(const TPoro &p)const{

        if((this->primero->e == p) || (this->segundo->e == p)){
            return true;
        }

        TListaPosicion posaux;
        if(this->primero->siguiente == NULL){
            return false;
        }
        posaux.pos = this->primero->siguiente;

        do
        {
            if(posaux.pos->e == p){
                return true;
            }

            if(posaux.pos->siguiente != NULL){
                posaux.pos = posaux.pos->siguiente;
            }
        } while (posaux.pos->siguiente != NULL);

        return false;
    }

    // Devuelve la longitud de la lista
    int TListaPoro::Longitud()const{
       
        if(this == NULL){
            return 0;
        }
        
        if(this->EsVacia()){
            return 0;
        }

        int i = 1;
        TListaPosicion auxt;
        auxt.pos = this->primero;
        
        while (auxt.pos->siguiente != NULL)
        {
            auxt.pos = auxt.pos->siguiente;
            ++i;
        }
        return i;
        
    }
    
    // Devuelve la primera posición de la lista
    TListaPosicion TListaPoro::Primera()const{
        TListaPosicion aux;
        aux.pos = this->primero;

        return aux;
    }
    
    // Devuelve la última posición de la lista
    TListaPosicion TListaPoro::Ultima()const{
        TListaPosicion aux;
        aux.pos = this->segundo;

        return aux;
    }
    
    // Extraer un rango de nodos de la lista
    TListaPoro TListaPoro::ExtraerRango(int n1, int n2){
        
        int l = this->Longitud();
        TListaPoro laux;

        if(this->EsVacia() || ((n1 > n2) || (n1 > l))){
            return laux;
        }

        TListaPosicion aux;
        aux.pos = this->primero;

        if(n1 == n2){
            for(int i=1;i<n1;++i){
                aux.pos = aux.pos->siguiente;
            }  
            laux.Insertar(aux.pos->e);
            this->Borrar(aux);
            return laux;
        }

        if(n1 <= 0){
            n1 = 1;
        }


        if(n2 > l){
            n2 = l;
        }


        for(int i=1;i<n1;++i){
            aux.pos = aux.pos->siguiente;
        }

        TListaPosicion pos;

        for(int i=-1;i<(n2-n1);++i){
            pos.pos = aux.pos->siguiente;
            laux.Insertar(aux.pos->e);
            this->Borrar(aux);
            aux.pos = pos.pos;
        }


        /*laux->primero = aux.pos;
        
        for(int i=0;i<(n2-n1);++i){
            aux.pos = aux.pos->siguiente;
        }
        laux->segundo = aux.pos;
        */
        return laux;

    }

    //FUNCIONES AMIGAS
    //Sobrecarga del operador salida
    std::ostream & operator<<(std::ostream &os, const TListaPoro &lista){

        if(lista.EsVacia()){
            os<<"()";
            return os;
        }
        os<<"(";
        TListaPosicion tp;
        tp = lista.Primera();
        int i = lista.Longitud();
        
        do{
            os<<lista.Obtener(tp);
            if(i > 1){
            os<<" ";
            }
            tp = tp.Siguiente();  
            --i;
        }while(i > 0);
        
        os<<")";
        return os;
    }



