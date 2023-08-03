/* 
 * File:   ClienteA.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:44 AM
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H

#include "Cliente.h"


class ClienteA : public Cliente{
public:
    //ClienteA(const ClienteA& orig);
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    double descuento;
};

#endif /* CLIENTEA_H */

