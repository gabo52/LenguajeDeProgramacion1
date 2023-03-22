/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.h
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 04:16 PM
 */

#ifndef REGCLIENTE_H
#define REGCLIENTE_H
#include <list>
#include <iterator>
#include "Cliente.h"
#include "Pedido.h"
using namespace std;

class RegCliente {
public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int DNI();
    void asignaPedido(Pedido &ped);
    void ordenar();
private:
    class Cliente cliente;
    list<class Pedido>pedidos;
};

#endif /* REGCLIENTE_H */

