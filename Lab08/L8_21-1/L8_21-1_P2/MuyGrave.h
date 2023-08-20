/* 
 * File:   MuyGrave.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:50 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H

#include "Infraccion.h"
#include "Falta.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class MuyGrave:public Infraccion, public Falta {
public:
    MuyGrave();
    virtual ~MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void operator = (const MuyGrave &c);
    void imprime(ofstream &arch);
private:
    int puntos;
    int meses;
};

#endif /* MUYGRAVE_H */

