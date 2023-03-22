/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:09 PM
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H

#include "Producto.h"


class Categoria3 : public Producto{
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrioridad();    
private:
    int prioridad;
    double descuento;
};

#endif /* CATEGORIA3_H */

