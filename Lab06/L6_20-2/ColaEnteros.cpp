/* 
 * File:   ColaEnteros.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 08:48 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ColaEnteros.h"
using namespace std;

void *leeRegistroEnteros(ifstream &arch){
    int prioridad, *auxprioridad, dato, *auxdato;
    void **aux; 
    
    arch >> prioridad;
    if(arch.eof()) return nullptr;
    arch >> dato; 
    
    aux = new void *[2];
    auxprioridad = new int;
    auxdato = new int;
    
    *auxdato = dato;
    *auxprioridad = prioridad; 
    aux[0] = auxprioridad;
    aux[1] = auxdato;
    return aux;
}

int hallarprioridad(void *dato){
    void **info = (void **)dato;
    int *prioridad;
    prioridad = (int*)info[0];
    return *prioridad;
}

void imprimeRegEnteros(void *dt,ofstream &arch){
    void **dato = (void **)dt;
    int *prioridad, *valor;
    
    prioridad = (int*)dato[0];
    valor = (int*)dato[1];
    
    arch << "(" << *prioridad << " - " << *valor << ")" << endl;
}