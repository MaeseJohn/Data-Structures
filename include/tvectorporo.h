#ifndef _TVECTORPORO_H_
#define _TVECTORPORO_H_
#include <iostream>
#include "tporo.h"

class TVectorPoro {

    private:

        int dimension;
        TPoro *datos;
        TPoro error;
       

    public:

        ///////////////////
        ///Constructores///
        ///////////////////

        TVectorPoro();
        TVectorPoro(int);
        TVectorPoro(const TVectorPoro &);
        ~TVectorPoro();
        TVectorPoro & operator=(const TVectorPoro &);

        /////////////
        ///Metodos///
        /////////////

        bool operator==(TVectorPoro &);
        bool operator!=(TVectorPoro &);
        TPoro & operator[] (int);
        TPoro operator[] (int) const;
        int Longitud();
        int Cantidad();
        bool Redimensionar(int);

        friend std::ostream & operator<<(std::ostream &, const TVectorPoro &);


};



#endif