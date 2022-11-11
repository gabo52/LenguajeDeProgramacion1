/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 10:40 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
using namespace std;


void AbrirArchivo(const char *nomb, ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb, ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}