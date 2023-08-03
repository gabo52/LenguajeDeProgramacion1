/* 
 * File:   Biblioteca.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:43 PM
 */

#include <fstream>

#include "Biblioteca.h"

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

void Biblioteca::LeeLibros(){
    ifstream arch;
    AbrirArchivo("Libros.csv",arch);
    Libro lib;
    while(1){
        arch>>lib;
        if(arch.eof())break;
        AStock.insertar(lib);
    }
}

void Biblioteca::ImprimeLibros(){
    ofstream arch;
    AbrirArchivo("Reporte.txt",arch);
    AStock.imprimir(arch);
}

void Biblioteca::ActualizaLibros(){
    ifstream arch;
    AbrirArchivo("RegistroDePrestamos.csv",arch);
    char c,cod[20];
    int num,dd,mm,aa,fecha;
    while(1){
        arch>>num>>c>>c;
        if(arch.eof())break;
        arch.getline(cod,20,',');
        arch>>dd>>c>>mm>>c>>aa;
        fecha=dd+mm*100+aa*10000;
        AStock.actualiza(cod);
    }
}

