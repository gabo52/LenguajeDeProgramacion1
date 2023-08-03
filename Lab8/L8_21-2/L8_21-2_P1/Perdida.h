/* 
 * File:   Perdida.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:36 PM
 */

#ifndef PERDIDA_H
#define PERDIDA_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Perdida {
public:

    void operator = (const Perdida &c);
    void SetPrecio(double precio);
    double GetPrecio() const;
    void imprimePerdida(ofstream &arch);
private:
    double precio;
};

#endif /* PERDIDA_H */

