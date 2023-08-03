/* 
 * File:   Nuevo.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:45 PM
 */

#ifndef NUEVO_H
#define NUEVO_H

#include "Renovacion.h"


class Nuevo : public Renovacion{
public:
    Nuevo();
    void SetExreglas(double exreglas);
    double GetExreglas() const;
    void leer(ifstream &arch,int lic);
    void imprimir(ofstream &arch);
private:
    double exreglas;
};

#endif /* NUEVO_H */

