#include "tvectorporo.h"
#include "tporo.h"
#include <string.h>




///////////////////
///Constructores///
///////////////////

TVectorPoro::TVectorPoro():dimension(0), datos(NULL){}

TVectorPoro::TVectorPoro(int x):dimension(x){

    if(dimension <= 0){
        datos = NULL;
    }else{
        //reservar memomoria tipo/TPoro /Dimension=Tamaño
        datos = new TPoro[dimension];
    }
}
TVectorPoro::TVectorPoro(const TVectorPoro &v){

    this->dimension = v.dimension;
    if(v.datos == NULL){
        this->datos = NULL;
    }else{  
    this->datos = new TPoro[dimension];

    for(int i=0;i<dimension;++i){
        this->datos[i] = v.datos[i]; 
    }
    }
}
TVectorPoro::~TVectorPoro(){
    if(datos != NULL){
       delete[] datos; 
       datos = NULL;
    }
    dimension = 0;
}

TVectorPoro& TVectorPoro::operator=(const TVectorPoro &v){

    if(this->dimension == v.dimension){
        for(int i=0;i<dimension;++i){
            this->datos[i] = v.datos[i];
        }
    }else{
        this->~TVectorPoro();
        this->dimension = v.dimension;
        this->datos = new TPoro[dimension];

        for(int i=0;i<dimension;++i){
            this->datos[i] = v.datos[i];
        }
    }
    return *this;
}


/////////////
///Metodos///
/////////////

bool TVectorPoro::operator==(TVectorPoro &v){

    if(this->dimension != v.dimension){
        return false;
    }

    for(int i=0;i<this->dimension;++i){
        if(this->datos[i] != v.datos[i]){
            return false;
        }
    }
    
    return true;


    //ESTO NO FUNCIONA
    // bool bandera = (this->dimension == v.dimension);
    // int i = 0;
    // if(bandera){
    //     do{
    //         bandera = this->datos[i] == v.datos[i]; 
    //         i++;
    //     }while(i < v.dimension);
    //     return bandera;
    // }else{
    //     return false;
    // }
} 

bool TVectorPoro::operator!=(TVectorPoro &v){

    return !(this->operator== (v));
}

TPoro& TVectorPoro::operator[] (int i){ 
    if(i < 1 || i > dimension){
        //Constructor por defecto
        return error;
    }
    return this->datos[i-1];
}
TPoro TVectorPoro::operator[] (int i) const{
    if(i < 1 || i > dimension){
        //Constructor por defecto
        TPoro e;
        return e;
    }
    return this->datos[i-1];
}

int TVectorPoro::Longitud(){
    return dimension;
}
int TVectorPoro::Cantidad(){
    int x = this->dimension;
    for(int i=0;i<this->dimension;++i){
        if(this->datos[i].EsVacio()){
            x-=1;
        }
    }
    return x;
}

bool TVectorPoro::Redimensionar(int x){

    if(x<=0 || x == this->dimension){
        return false;
    }
    
    if(x>this->dimension){

        TVectorPoro aux(x);
        for(int i=0;i<this->dimension;++i){
            aux[i+1] = this->datos[i];
        }
        *this = aux;
        aux.~TVectorPoro();
        return (this->dimension == x);
    }
    
    if(x<this->dimension){
        TVectorPoro aux(x);
        for(int i=0;i<=x;++i){
            aux[i] = this->datos[i];
        }
        *this = aux;
        // aux.~TVectorPoro();
        return (this->dimension == x);
    }

    return true;
}


std::ostream & operator<<(std::ostream &os, const TVectorPoro &vector){

    if(!vector.dimension == 0){
        os<<"[";
        for(int i=1;i<=vector.dimension;i++){
            if(vector[i].EsVacio()){
                os<<i<<" ()";
                if(i<vector.dimension){
                    os<<" ";
                }
            }else{
            os<<i<<" "<<vector[i];
                if(i<vector.dimension){
                    os<<" ";
                }
            }
        }
        os<<"]";
    }else{
    os<<"[]";
    }
    return os;
}