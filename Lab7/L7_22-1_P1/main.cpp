/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 3 de noviembre de 2022, 10:42 AM
 */

#include <iostream>
#include <iomanip>
#include "Cliente.h"
#include "Pedido.h"
#include "FuncionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente clientes[200];
    Pedido  pedidos[200];
    cargarClientes(clientes);
    cargarPedidos(pedidos);
    agregarPedidos(clientes,pedidos);
    eliminarPedidos(clientes);
    aplicarDescuento(clientes,10);
    imprimirReporteClientes(clientes);
    return 0;
}

