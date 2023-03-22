/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 06:30 PM
 */

#ifndef LEVE_H
#define LEVE_H

#include "Infraccion.h"


class Leve :public Infraccion{
public:
    //Leve(const Leve& orig);
    void operator = (const Leve &c);
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    double descuento;
};

#endif /* LEVE_H */

