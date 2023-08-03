/* 
 * File:   Leve.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:36 PM
 */

#ifndef LEVE_H
#define LEVE_H

#include "Infraccion.h"


class Leve : public Infraccion{
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    double descuento;
};

#endif /* LEVE_H */

