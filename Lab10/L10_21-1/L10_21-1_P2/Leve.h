/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.h
 * Author: Gabo
 *
 * Created on 23 de noviembre de 2022, 06:36 PM
 */

#ifndef LEVE_H
#define LEVE_H

#include "Infraccion.h"


class Leve : public Infraccion{
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    double descuento;
};

#endif /* LEVE_H */

