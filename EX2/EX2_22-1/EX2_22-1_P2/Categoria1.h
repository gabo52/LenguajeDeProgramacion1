/* 
 * File:   Categoria1.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:06 PM
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H

#include "Producto.h"


class Categoria1 : public Producto{
public:
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrioridad();
private:
    int prioridad;
    int minimo;
};

#endif /* CATEGORIA1_H */

