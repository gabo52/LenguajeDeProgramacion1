/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 02:57 PM
 */

#ifndef REGCLIENTE_H
#define REGCLIENTE_H
#include <list>
#include <iterator>
#include <algorithm>
#include "Cliente.h"
#include "Pedido.h"
using namespace std;
class RegCliente {
public:
    //preguntar
//    RegCliente();
//    RegCliente(const RegCliente& orig);
//    virtual ~RegCliente();
    void operator = (const Cliente &c);
    void imprime(ofstream &arch);
    int DNI();
    void agregaPedido( Pedido &c);
    void ordena();
    void leerDatosCliente(ifstream &arch);
private:
    class Cliente cliente;
    list <class Pedido> pedidos;
};

ofstream &operator << (ofstream &arch, RegCliente &);
#endif /* REGCLIENTE_H */

