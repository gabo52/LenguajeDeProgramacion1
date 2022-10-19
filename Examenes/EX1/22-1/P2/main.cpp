/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 5 de octubre de 2022, 12:01 AM
 */

#include <iostream>
#include <iomanip>
#include "funcionesAux.h"
#include "MuestraPunteros.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *productos,*pedidos,*clientes;
    cargaProductos(productos);
    cargaPedidos(pedidos);
    procesaClientes(productos,pedidos,clientes);
    imprimeReporte(clientes);
    return 0;
}

