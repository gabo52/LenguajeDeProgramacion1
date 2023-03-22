/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tienda.cpp
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:05 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Tienda.h"

Tienda::Tienda() {
}

Tienda::Tienda(const Tienda& orig) {
}

Tienda::~Tienda() {
}


void Tienda::carga(){
    
    ifstream arch("pedidos3.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir archivo pedidos3.csv";
        exit(1);
    }
    
    ifstream archCli("clientes2.csv",ios::in);
    if(!archCli){
        cout <<"No se puede abrir archivo clientes2.csv";
        exit(1);
    }
    int i=0;
    while(1){
        lpedidos[i].leepedido(arch);
        if(arch.eof()) break;
        i++;
    }
    lpedidos[i].SetCodigo(0);
    
    int j=0;
    
    while(1){
        lclientes[j].leeCliente(archCli);
        if(archCli.eof()) break;
        j++;
    }
    lclientes[j].SetDni(0);
}

void Tienda::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout <<"No hay archivo";
        exit(1);
    }    
    int i=0;
    arch<<left<<setw(10)<<"Fecha"<<setw(10)<<"Codigo"<<setw(50)<<
            "Descripcion del Prod."<<setw(10)<<"Cant."<<setw(10)<<"Precio"<<setw(10)<<"Total"<<setw(10)<<"Observaciones"<<endl;
    while(lpedidos[i].GetCodigo()!=0){
        lpedidos[i].imprimePedido(arch);
        i++;
    }
}

void Tienda::actualiza(int cantStock){
    int i=0,j=0;
    double descuento;
    while(lpedidos[i].GetCodigo()!=0){
        if(lpedidos[i].GetCodigo()/100000==4 && lpedidos[i].GetStock()>=cantStock){
            j=0;
            while(lclientes[j].GetDni()!=0){
                if(lclientes[j].GetDni()==lpedidos[i].GetDni()){
                    if(lclientes[j].GetCategoria()=='A') {
                        descuento=0.5;
                        char cad[]="Descuento especial del 50%";
                        lpedidos[i].SetObs(cad);
                    }
                    if(lclientes[j].GetCategoria()=='B') {
                        descuento=0.7; 
                        char cad[]="Descuento especial del 30%";
                        lpedidos[i].SetObs(cad);
                    }
                    if(lclientes[j].GetCategoria()=='C') {
                        descuento=0.9;
                        char cad[]="Descuento especial del 10%";
                        lpedidos[i].SetObs(cad);
                    }
                    break;
                }
                j++;
            }
            lpedidos[i].SetTotal(lpedidos[i].GetTotal()*descuento);
        }
        i++;
    }
}
