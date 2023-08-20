/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ventas_LP1.cpp
 * Author: cueva.r
 * 
 * Created on 13 de septiembre de 2022, 10:29 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
#include "Ventas_LP1.h"

using namespace std;

/*
   71984468   IPARRAGUIRRE_VILLEGAS_NICOLAS_EDILBERTO-B      935441620
  29847168    ALDAVE_ZEVALLOS_ROSARIO-A     6261108
  23132111    MIGUEL_HERNADEZ_MAURICIO     12321312
 */

ifstream &operator >>(ifstream &in,
            struct Estructura_ClienteRegistrado &c){
    int dni,telefono;
    char nombre[100],cat;
    
    in >> dni;
    if(in.eof()) return in;
    in >> nombre >> telefono;
    int largo = strlen(nombre);
    if(nombre[largo-2]=='-'){
        cat=nombre[largo-1];
        nombre[largo-2]='\0';
    }    
    else
        strcpy(c.categoria,"Cliente Nuevo");
    c.dni = dni;
    strcpy(c.nombre,nombre);
    c.montoTotalGastado = 0;
    c.numeroDePedidos = 0;
    if(cat=='A') strcpy(c.categoria,"Cliente Muy Frecuente");
    if(cat=='B') strcpy(c.categoria,"Cliente Frecuente");
    if(cat=='C') strcpy(c.categoria,"Cliente Ocasional");
    return in;
}


void operator += (struct Estructura_ClienteRegistrado *a,
        struct Estructura_ClienteRegistrado c){
    int i;
    for(i=0;a[i].dni;i++);
    strcpy(a[i].categoria,c.categoria);
    a[i].dni = c.dni;
    a[i].montoTotalGastado = c.montoTotalGastado;
    strcpy(a[i].nombre,c.nombre);
    a[i].numeroDePedidos=c.numeroDePedidos;
    a[i+1].dni = 0;
    
    
}


void operator += (struct Estructura_ClienteRegistrado &a,
        struct Estructura_PedidoRealizado c){
    a.pedidosRealizados[a.numeroDePedidos].cantidad = c.cantidad;
    a.pedidosRealizados[a.numeroDePedidos].fecha = c.fecha;
    strcpy(a.pedidosRealizados[a.numeroDePedidos].codigo,c.codigo);
    a.numeroDePedidos++;
}

void operator += (struct Estructura_ProductosEnAlmacen *a,
        struct Estructura_ProductosEnAlmacen c){
    
    int i;
    for(i=0;strcmp(a[i].codigo,"X");i++)
        if(!strcmp(a[i].codigo,c.codigo)) return;
    strcpy(a[i].codigo,c.codigo);
    strcpy(a[i].descripcion,c.descripcion);
    a[i].descuento = c.descuento;
    a[i].precioUnitario = c.precioUnitario;
    strcpy(a[i+1].codigo,"X");
}

ofstream &operator << (ofstream &out, struct Estructura_ClienteRegistrado c){
    out<<setw(10)<<c.dni<<setw(50)<<c.nombre<<setw(50)<<c.categoria<<endl;
    for(int i=0;i<c.numeroDePedidos;i++){
        out << setw(10)<<c.pedidosRealizados[i].codigo;
        out << setw(15)<<c.pedidosRealizados[i].fecha;
        out << setprecision(2)<<fixed<<setw(10)<<c.pedidosRealizados[i].cantidad;
        out << endl;
    }
}

ofstream &operator << (ofstream &out, struct Estructura_ProductosEnAlmacen *a){
    for(int i=0;strcmp(a[i].codigo,"X");i++){
        out << setw(10)<< a[i].codigo;
        out << setw (50)<<a[i].descripcion;
        out << setprecision(2) << fixed;
        out << setw(10)<<a[i].descuento;
        out << setw(10) << a[i].precioUnitario;
    }
    return out;
}
