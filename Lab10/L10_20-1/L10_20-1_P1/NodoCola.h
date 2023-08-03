/* 
 * File:   NodoCola.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:43 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Persona.h"
#include "Cola.h"

class NodoCola {
public:
    NodoCola();
    friend class Cola;
private:
    NodoCola *sig;
    Persona *persona;
};

#endif /* NODOCOLA_H */

