/* 
 * File:   NLibro.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:38 PM
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"
#include "ALibro.h"

class NLibro {
public:
    NLibro();
    friend class ALibro;
private:
    Libro dlibro;
    NLibro *izq;
    NLibro *der;
};

#endif /* NLIBRO_H */

