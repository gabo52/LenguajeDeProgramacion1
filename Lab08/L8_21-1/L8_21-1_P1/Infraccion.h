/* 
 * File:   Infraccion.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:38 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include "Conductor.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Infraccion {
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(char* gravedad);
    void GetGravedad(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator = (const Infraccion &c);
private:
    int codigo;
    char *gravedad;
    double multa;
};

#endif /* INFRACCION_H */

