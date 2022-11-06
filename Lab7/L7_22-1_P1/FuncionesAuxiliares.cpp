/* 
 * File:   FuncionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 12:00 PM
 */

#include <iostream>
#include <iomanip>
#include "Cliente.h"
#include "FuncionesLecturaEscritura.h"
#include "FuncionesAuxiliares.h"
using namespace std;


void cargarClientes(Cliente *clientes){
    int n=0;
    ifstream arch;
    AbrirArchivo("Clientes2.csv",arch);
    while(1){
        arch>>clientes[n];
        if(arch.eof())break;
        n++;
    }
}
    
void cargarPedidos(Pedido *pedidos){
    int n=0;
    ifstream arch;
    AbrirArchivo("Pedidos2.csv",arch);
    while(1){
        arch>>pedidos[n];
        if(arch.eof())break;
        n++;
    }
}
    
void agregarPedidos(Cliente *clientes,Pedido *pedidos){
    int pos;
    for(int i=0;pedidos[i].GetDni();i++){
        pos=buscarDni(clientes,pedidos[i].GetDni());
        if(pos!=-1){
            clientes[pos]=pedidos[i];
        }
    }
}

int buscarDni(Cliente *clientes,int dni){
    for(int i=0;clientes[i].GetDni();i++){
        if(clientes[i].GetDni()==dni)return i;
    }
    return -1;
}

void eliminarPedidos(Cliente *clientes){
    ifstream arch;
    AbrirArchivo("eliminar2.csv",arch);
    int pos;
    Pedido aux;
    while(1){
        arch>>aux;
        if(arch.eof())break;
        pos=buscarDni(clientes,aux.GetDni());
        if(pos!=-1){
            clientes[pos]-=aux;
        }
    }
}
    

void aplicarDescuento(Cliente *clientes,double descuento){
    for(int i=0;clientes[i].GetDni();i++){
        clientes[i]/descuento;
    }
}
    
void imprimirReporteClientes(Cliente *clientes){
    ofstream arch;
    AbrirArchivo("ReporteClientes.txt",arch);
    for(int i=0;clientes[i].GetDni();i++){
        arch<<clientes[i];
    }
}