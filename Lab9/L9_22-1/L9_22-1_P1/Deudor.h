/* 
 * File:   Deudor.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:51 AM
 */

#ifndef DEUDOR_H
#define DEUDOR_H
#include "Cliente.h"


class Deudor {
public:
    Deudor();
    virtual ~Deudor();
    void leer(ifstream &arch);
    int activo();
    void imprimir(ofstream &arch);
private:
    Cliente *Cdeudor;
};

#endif /* DEUDOR_H */

