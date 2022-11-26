/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promociones.h
 * Author: Gabo
 *
 * Created on 22 de noviembre de 2022, 05:06 PM
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "Lista.h"
class Promociones {
public:

    void leepedidos();
    void actualizapedidos();
    void imprimepedidos();
    Pedido *leePedido(ifstream &arch);
private:
    Lista lpedidos;
};

void imprimeLinea(ofstream &arch,int cant,char c);

#endif /* PROMOCIONES_H */

