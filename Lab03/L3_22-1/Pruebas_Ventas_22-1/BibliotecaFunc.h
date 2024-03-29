/* 
 * File:   Funciones.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 14 de septiembre de 2022, 05:20 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
ifstream &operator >> (ifstream &in, struct Estructura_ClienteRegistrado &cliente);
ofstream & operator << (ofstream &out, 
        struct Estructura_ClienteRegistrado c);
void imprimirFecha(ofstream &out,int fecha);
void operator += (struct Estructura_ProductosEnAlmacen *prod1,
        struct Estructura_ProductosEnAlmacen prod2);
void operator += (struct Estructura_ClienteRegistrado &clien, 
        struct Estructura_PedidoRealizado ped);
void operator += (struct Estructura_ClienteRegistrado *clien1, 
        struct Estructura_ClienteRegistrado clien2);
ofstream &operator <<(ofstream &out, struct Estructura_ProductosEnAlmacen *arr);
#endif /* FUNCIONES_H */
