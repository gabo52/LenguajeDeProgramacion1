/* 
 * File:   Programa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:14 PM
 */

#include "Programa.h"

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void Programa::carga(){
    CargaProductos();
    CargaLista();
}

void Programa::CargaProductos(){
    ifstream arch;
    AbrirArchivo("Productos4.csv",arch);
    NProductos prod;
    while(1){
        prod.leer(arch);
        if(arch.eof())break;
        vproductos.push_back(prod);
    }
}

void Programa::CargaLista(){
    ifstream arch;
    AbrirArchivo("Pedidos4.csv",arch);
    Pedido ped;
    while(1){
        ped.leer(arch);
        if(arch.eof())break;
        lpedidos.inserta(ped);
    }
}

void Programa::actualiza(){
    int prioridad,cod;
    for(vector<NProductos>::iterator it=vproductos.begin();it!=vproductos.end();it++){
        (*it).GetPrioridad(prioridad,cod);
        lpedidos.actualizaPrioridad(prioridad,cod);
    }
    lpedidos.reordenar();
}

void Programa::muestra(){
    ImprimeProductos();
    ImprimeLista();
}

void Programa::ImprimeProductos(){
    ofstream arch;
    arch.precision(2);
    arch<<fixed;
    AbrirArchivo("ReporteProductos.txt",arch);
    for(vector<NProductos>::iterator it=vproductos.begin();it!=vproductos.end();it++){
        (*it).imprime(arch);
    }
}

void Programa::ImprimeLista(){
    ofstream arch;
    AbrirArchivo("ReportePedidos.txt",arch);
    lpedidos.imprime(arch);
}
