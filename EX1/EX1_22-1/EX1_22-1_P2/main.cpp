/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

