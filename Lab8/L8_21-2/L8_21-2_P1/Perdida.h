/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Perdida.h
 * Author: Gabo
 *
 * Created on 10 de noviembre de 2022, 07:36 PM
 */

#ifndef PERDIDA_H
#define PERDIDA_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Perdida {
public:

    void operator = (const Perdida &c);
    void SetPrecio(double precio);
    double GetPrecio() const;
    void imprimePerdida(ofstream &arch);
private:
    double precio;
};

#endif /* PERDIDA_H */

