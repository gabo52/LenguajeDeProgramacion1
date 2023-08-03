/* 
 * File:   Leve.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:42 PM
 */

#ifndef LEVE_H
#define LEVE_H

#include "Infraccion.h"
#include "Falta.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Leve : public Infraccion,public Falta {
public:
    Leve();
    virtual ~Leve();
    void operator = (const Leve &c);
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void imprime(ofstream &arch);
private:
    double descuento;
};

#endif /* LEVE_H */

