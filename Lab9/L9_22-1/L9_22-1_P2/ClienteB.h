/* 
 * File:   ClienteB.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:48 AM
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H

#include "Cliente.h"


class ClienteB : public Cliente{
public:
    //ClienteB(const ClienteB& orig);
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(double monto,int cantPed);
private:
    double descuento;
    double flete;
};

#endif /* CLIENTEB_H */

