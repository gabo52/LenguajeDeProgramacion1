/* 
 * File:   funcionesAux.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

