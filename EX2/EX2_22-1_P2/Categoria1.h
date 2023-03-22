/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:06 PM
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H

#include "Producto.h"


class Categoria1 : public Producto{
public:
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrioridad();
private:
    int prioridad;
    int minimo;
};

#endif /* CATEGORIA1_H */

