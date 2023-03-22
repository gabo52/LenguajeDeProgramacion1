/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteB.h
 * Author: Gabo
 *
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
private:
    double descuento;
    double flete;
};

#endif /* CLIENTEB_H */

