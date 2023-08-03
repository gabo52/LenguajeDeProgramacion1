/* 
 * File:   Cola.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:42 PM
 */

#ifndef COLA_H
#define COLA_H

#include "NodoCola.h"


class Cola {
public:
    Cola();
    virtual ~Cola();
    void encola(Persona *per);
    void desencola(Persona *&per);
    void imprime(const char *nomb);
    void lee(const char *nomb);
private:
    class NodoCola *ini;
    class NodoCola *fin;
};

#endif /* COLA_H */

