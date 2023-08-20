/* 
 * File:   FuncionesAuxiliares.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 11:57 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
#include "Cliente.h"
#include "Pedido.h"
using namespace std;

void cargarClientes(Cliente *clientes);
void cargarPedidos(Pedido *pedidos);
void agregarPedidos(Cliente *clientes,Pedido *pedidos);
int buscarDni(Cliente *clientes,int dni);
void eliminarPedidos(Cliente *clientes);
void aplicarDescuento(Cliente *clientes,double descuento);
void imprimirReporteClientes(Cliente *clientes);

#endif /* FUNCIONESAUXILIARES_H */

