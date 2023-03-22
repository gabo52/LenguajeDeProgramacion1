/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.cpp
 * Author: Gabo
 * 
 * Created on 28 de noviembre de 2022, 04:16 PM
 */

#include "RegCliente.h"


void RegCliente::leer(ifstream &arch){
    cliente.leerDatos(arch);
    if(arch.eof())return;
    if(cliente.GetTipo()=='A'){
        cliente.SetDescuento(0.235);
    }else if(cliente.GetTipo()=='B'){
        cliente.SetDescuento(0.168);    
    }else cliente.SetDescuento(0.083);
}

void RegCliente::imprimir(ofstream &arch){
    arch<<setw(10)<<left<<"CODIGO"<<setw(30)<<left<<"NOMBRE"
            <<setw(15)<<left<<"CATEGORIA"<<setw(15)<<left<<"DESCUENTO"
            <<setw(15)<<left<<"TELEFONO"<<endl;
    cliente.imprimirDatos(arch);
    arch<<setw(15)<<left<<"FECHA"<<setw(15)<<left<<"CODIGO"
            <<setw(15)<<left<<"CANTIDAD"<<setw(15)<<left<<"SUBTOTAL"<<endl;
    for(list<class Pedido>::iterator it=pedidos.begin();it!=pedidos.end();it++){
        cout<<"Hola"<<endl;
        (*it).imprimirDatos(arch);
    }
}

int RegCliente::DNI(){
    return cliente.GetDni();
}

void RegCliente::asignaPedido(Pedido &ped){
    ped.SetSubTotal(ped.GetSubTotal()*(1-cliente.GetDescuento()));
    pedidos.push_back(ped);
}

void RegCliente::ordenar(){
    pedidos.sort();
}

