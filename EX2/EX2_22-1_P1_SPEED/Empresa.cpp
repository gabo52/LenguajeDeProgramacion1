/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.cpp
 * Author: Gabo
 * 
 * Created on 28 de noviembre de 2022, 04:19 PM
 */

#include "Empresa.h"


void Empresa::leerClientes(const char *nomb){
    ifstream arch;
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
    class RegCliente cli;
    while(1){
        cli.leer(arch);
        if(arch.eof())break;
        lstClientes.push_back(cli);
    }
}
void Empresa::imprimirClientes(const char *nomb){
    ofstream arch;
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<setw(60)<<right<<"REPORTE DE CLIENTES "<<endl;
    for(list<class RegCliente>::iterator it = lstClientes.begin();it!=lstClientes.end();it++){
        (*it).imprimir(arch);
    }
}
void Empresa::leerPedidos(const char *nomb){
    ifstream arch;
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
    Producto prod;
    int dni;
    Pedido ped;
    while(1){
        prod.leerDatos(arch);
        if(arch.eof())break;
        if(!existeProd(prod.GetCodigo())){
            lstProductos.push_back(prod);
        }
        dni=ped.leerDatos(arch);
        asignarPedido(dni,ped,prod);
    }
}

bool Empresa::existeProd(int cod){
    for(list<class Producto>::iterator it = lstProductos.begin();it!=lstProductos.end();it++){
        if((*it).GetCodigo()==cod)return true;
    }
    return false;
}

void Empresa::asignarPedido(int dni,Pedido &ped,Producto &prod){
    ped.SetCodigo(prod.GetCodigo());
    ped.SetSubTotal(prod.GetPrecioUnitario()*ped.GetCantidad()*(prod.GetDescuento()));
    cout<<prod.GetDescuento()<<endl;
    for(list<class RegCliente>::iterator it = lstClientes.begin();it!=lstClientes.end();it++){
        if((*it).DNI()==dni){
            (*it).asignaPedido(ped);
            cout<<"Llegue";
        }
    }
}

void Empresa::ordenarPedidos(){
    for(list<class RegCliente>::iterator it = lstClientes.begin();it!=lstClientes.end();it++){
        (*it).ordenar();
    }
}

void Empresa::imprimirProductos(const char *nomb){
    ofstream arch;
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    for(list<class Producto>::iterator it = lstProductos.begin();it!=lstProductos.end();it++){
        (*it).imprimirDatos(arch);
    }
}

