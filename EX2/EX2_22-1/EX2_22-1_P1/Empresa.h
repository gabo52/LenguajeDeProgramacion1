/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 02:58 PM
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include <iterator>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Pedido.h"
#include "Producto.h"
#include <algorithm>
#include <list>
#include "RegCliente.h"
using namespace std;
class Empresa {
public:
//    Empresa();
//    Empresa(const Empresa& orig);
//    virtual ~Empresa();
    void leerClientes(const char *);
    void imprimirClientes(const char *);
    void leerPedidos(const char *);
    void ordenarPedidos();
    void imprimirProductos(const char *);
    void agregarPedido(int dni,class Pedido &ped);
    void agregarProducto(class Producto &prod);
    void asignaValoresPedido(class Pedido &ped,int dni,int codProd);
    
private:
    list <class Producto> lstProducto;
    list <class RegCliente> lstClientes;
};

#endif /* EMPRESA_H */

