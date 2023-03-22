/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.h
 * Author: Gabo
 *
 * Created on 8 de noviembre de 2022, 06:42 PM
 */

#ifndef LEVE_H
#define LEVE_H

#include "Infraccion.h"
#include "Falta.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Leve : public Infraccion,public Falta {
public:
    Leve();
    virtual ~Leve();
    void operator = (const Leve &c);
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void imprime(ofstream &arch);
private:
    double descuento;
};

#endif /* LEVE_H */

