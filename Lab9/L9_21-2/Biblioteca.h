
/* 
 * File:   Biblioteca.h
 * Author: USER
 *
 * Created on 21 de junio de 2023, 07:04 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Copia.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void GeneraCopias();
    void ActualizaLibros();
    void ImprimeCopias();
private:
    Copia llibros[500];
};

#endif /* BIBLIOTECA_H */

