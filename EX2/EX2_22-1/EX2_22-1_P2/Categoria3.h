/* 
 * File:   Categoria3.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:09 PM
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H

#include "Producto.h"


class Categoria3 : public Producto{
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrioridad();    
private:
    int prioridad;
    double descuento;
};

#endif /* CATEGORIA3_H */

