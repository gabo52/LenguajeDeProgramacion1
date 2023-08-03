/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 14 de septiembre de 2022, 09:37 PM
 */

#include <iostream>
#include <iomanip>
#include "Estructuras.h"
#include "funcionesAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    struct Estructura_ClienteRegistrado clientes[100];
    struct Estructura_ProductosEnAlmacen productos[100];
    leerClientes(clientes);
    cargarClientesProductos(clientes,productos);
    imprimirReporte(clientes,productos);
    return 0;
}

