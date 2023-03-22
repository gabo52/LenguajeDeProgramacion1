/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.h
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 04:19 PM
 */

#ifndef EMPRESA_H
#define EMPRESA_H


#include <fstream>
#include <iostream>
#include <iomanip>

#include <iterator>
#include <algorithm>
#include <list>
#include "RegCliente.h"
#include "Pedido.h"
#include "Producto.h"
using namespace std;

class Empresa {
public:
    void leerClientes(const char *nomb);
    void imprimirClientes(const char *nomb);
    void leerPedidos(const char *nomb);
    void ordenarPedidos();
    void imprimirProductos(const char *nomb);
    void asignarPedido(int dni,Pedido &ped,Producto &prod);
    bool existeProd(int cod);
private:
    list<class Producto>lstProductos;
    list<class RegCliente>lstClientes;
};

#endif /* EMPRESA_H */

