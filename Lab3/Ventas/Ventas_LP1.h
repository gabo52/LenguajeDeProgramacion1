/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ventas_LP1.h
 * Author: cueva.r
 *
 * Created on 13 de septiembre de 2022, 10:29 AM
 */

#ifndef VENTAS_LP1_H
#define VENTAS_LP1_H
#include <fstream>
    using namespace std;
    
    ifstream &operator >>(ifstream &,
            struct Estructura_ClienteRegistrado &);
    void operator += (struct Estructura_ClienteRegistrado *,
        struct Estructura_ClienteRegistrado);
    void operator += (struct Estructura_ProductosEnAlmacen *,
        struct Estructura_ProductosEnAlmacen );
    ofstream &operator << (ofstream &out, struct Estructura_ClienteRegistrado c);
    ofstream &operator << (ofstream &out, struct Estructura_ProductosEnAlmacen *a);
#endif /* VENTAS_LP1_H */
