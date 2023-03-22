/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: Gabo
 *
 * Created on 14 de septiembre de 2022, 09:42 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include "Estructuras.h"
void leerClientes(struct Estructura_ClienteRegistrado *c);
void cargarClientesProductos(struct Estructura_ClienteRegistrado *c,
        struct Estructura_ProductosEnAlmacen *p);
void llenarClientesAlmacen(struct Estructura_ClienteRegistrado *c,
        struct Estructura_ProductosEnAlmacen *p,char *codigo,char *descripcion,
        double porcentaje,double cant,double precio,int DNI,int fecha);
void cargaPedidoCliente(struct Estructura_ClienteRegistrado &c,
                    char *codigo,double cant,int fecha);
void imprimirReporte(struct Estructura_ClienteRegistrado *c,
        struct Estructura_ProductosEnAlmacen *p);

#endif /* FUNCIONESAUX_H */

