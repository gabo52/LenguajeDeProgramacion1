/*
 * File:   BiblitecaFunc.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
using namespace std;

//84468   IPARRAGUIRRE_VILLEGAS_NICOLAS_EDILBERTO-B      935441620
ifstream &operator >> (ifstream &in,struct Estructura_ClienteRegistrado &cliente){
    int dni,telefono;
    char nombre[100];
    in>>dni>>nombre>>telefono;
    if(in.eof())return in;
    int cant=strlen(nombre);
    char cat='0';
    if(nombre[cant-2]=='-'){
        nombre[cant-2]=0;
        cat=nombre[cant-1];
    }
    cliente.dni=dni;
    cliente.montoTotalGastado=0;
    strcpy(cliente.nombre,nombre);
    cliente.numeroDePedidos=0;
    if(cat=='0')strcpy(cliente.categoria,"Cliente nuevo");
    else if(cat=='A')strcpy(cliente.categoria,"Cliente muy frecuente");
    else if(cat=='B')strcpy(cliente.categoria,"Cliente frecuente");
    else strcpy(cliente.categoria,"Cliente nuevo");
    return in;
}

void operator += (struct Estructura_ClienteRegistrado *clien1, 
        struct Estructura_ClienteRegistrado clien2){
    int i;
    for(i=0;clien1[i].dni;i++);
    clien1[i].dni=clien2.dni;
    clien1[i].montoTotalGastado=clien2.montoTotalGastado;
    strcpy(clien1[i].categoria,clien2.categoria);
    clien1[i].numeroDePedidos=clien2.numeroDePedidos;
    strcpy(clien1[i].nombre,clien2.nombre);
    clien1[i+1].dni=0;
}

void operator += (struct Estructura_ClienteRegistrado &clien, 
        struct Estructura_PedidoRealizado ped){
    int i=clien.numeroDePedidos;
    strcpy(clien.pedidosRealizados[i].codigo,ped.codigo);
    clien.pedidosRealizados[i].cantidad=ped.cantidad;
    clien.pedidosRealizados[i].fecha=ped.fecha;
    clien.numeroDePedidos++;
    clien.montoTotalGastado+=ped.cantidad;
}

void operator += (struct Estructura_ProductosEnAlmacen *prod1,
        struct Estructura_ProductosEnAlmacen prod2){
    int i;
    for(i=0;strcmp(prod1[i].codigo,"X");i++){
        if(strcmp(prod1[i].codigo,prod2.codigo)==0)return;
    }
    strcpy(prod1[i].codigo,prod2.codigo);
    strcpy(prod1[i].descripcion,prod2.descripcion);
    prod1[i].descuento=prod2.descuento;
    prod1[i].precioUnitario=prod2.precioUnitario;
    strcpy(prod1[i+1].codigo,"X");
}

void imprimirFecha(ofstream &out,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    out<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}

ofstream & operator << (ofstream &out, 
        struct Estructura_ClienteRegistrado c){
    out<<left<<setw(15)<<c.dni<<left<<c.nombre<<endl<<left<<c.categoria<<endl;
    out<<"No.  CODIGO"<<right<<setw(23)<<"CANTIDAD"<<right<<setw(13)<<"FECHA"<<endl;
    for(int i=0;i<c.numeroDePedidos;i++){
        out<<i+1<<")     "<<setw(10)<<left<<c.pedidosRealizados[i].codigo<<
                setw(15)<<right<<setprecision(2)<<fixed
                <<c.pedidosRealizados[i].cantidad<<setw(10)<<" ";
        imprimirFecha(out,c.pedidosRealizados[i].fecha);
        out<<endl;
    }
    out<<"Monto total comprado: "<<setw(12)<<right<<setprecision(2)<<fixed<<
            c.montoTotalGastado<<endl;
}

ofstream &operator <<(ofstream &out, struct Estructura_ProductosEnAlmacen *arr){
    out<<"No ."<<setw(12)<<right<<"Codigo"<<setw(20)<<right<<"Descripcion"<<
            setw(20)<<right<<"Precio unitario"<<setw(12)<<right<<"Descuento"<<endl;
    for(int i=0;strcmp(arr[i].codigo,"X");i++){
        out<<i<<")      "<<setw(14)<<left<<arr[i].codigo<<setw(40)<<left
                <<arr[i].descripcion<<setw(10)<<right<<setprecision(2)<<fixed<<
                arr[i].precioUnitario<<setw(14)<<right<<setprecision(2)<<fixed
                <<arr[i].descuento<<endl;
    }
    return out;
}





 