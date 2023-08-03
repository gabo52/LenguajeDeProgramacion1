/* 
 * File:   Empresa.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

