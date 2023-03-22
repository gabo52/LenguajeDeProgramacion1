/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 11:00 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Cliente.h"
#include "FuncionesLecturaEscritura.h"
#define MAXCANTLINEA 100
using namespace std;

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

ifstream & operator >> (ifstream &arch, Cliente &clien){
    int codigo;
    char cadena[80],tipo,c;
    arch>>codigo>>c;
    if(arch.eof())return arch;
    arch.getline(cadena,80,',');
    arch>>tipo;
    clien.SetCategoria(tipo);
    clien.SetDni(codigo);
    clien.SetNombre(cadena);
    return arch;
}

ifstream & operator >> (ifstream &arch, Pedido &ped){
    int codigo,cant,dd,mm,aa,dni;
    char cadena[200],c;
    double precio;
    arch>>codigo>>c;
    if(arch.eof())return arch;
    arch.getline(cadena,200,',');
    arch>>cant>>c>>precio>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    ped.SetCantidad(cant);
    ped.SetCodigo(codigo);
    ped.SetDni(dni);
    ped.SetFecha(dd+mm*100+aa*10000);
    ped.SetNombre(cadena);
    ped.SetPrecio(precio);
    return arch;
}


void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

ofstream & operator << (ofstream &arch,Cliente &clien){
    char cadena[200];
    clien.GetNombre(cadena);
    arch<<setw(50)<<left<<clien.GetDni()<<cadena<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    clien.imprimePedidos(arch);
    arch<<"# de pedidos:"<<setw(8)<<right<<clien.GetNumped()<<endl;
    arch<<"Monto Total:  "<<setw(10)<<right<<clien.GetTotal()<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    return arch;
}