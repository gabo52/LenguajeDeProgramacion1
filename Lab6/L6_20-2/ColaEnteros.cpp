/* 
 * File:   ColaEnteros.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de octubre de 2022, 05:18 PM
 */

#include <iostream>
#include <iomanip>
#include "ColaEnteros.h"
using namespace std;


void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void *leeRegistroEnteros(ifstream &arch){
    int prioridad,*dato;
    arch>>prioridad;
    if(arch.eof())return nullptr;
    int *prioridadP;
    prioridadP = new int;
    dato = new int;
    arch>>*dato;
    *prioridadP=prioridad;
    void **aux;
    aux = new void *[2];
    aux[0]=prioridadP;
    aux[1]=dato;
    return aux;
}

int obtienePrioridadEnteros(void *dt){
    void **dato = (void **)dt;
    int *prioridad;
    prioridad = (int*)dato[0];
    return *prioridad;
}

void imprimeRegEnteros(void *dt,ofstream &arch){
     void **dato = (void **)dt;
     int *prioridad,*valor;
     prioridad = (int*)dato[0];
     valor = (int*)dato[1];
     arch<<setw(10)<<left<<*prioridad<<setw(10)<<left<<*valor<<endl;
}
