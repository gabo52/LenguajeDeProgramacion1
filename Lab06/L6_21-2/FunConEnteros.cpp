/* 
 * File:   FunConEnteros.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 05:29 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int prioridadnumero(void *dato){
    int *prioridad;
    prioridad = (int*)dato; 
    
    if(*prioridad < 50) return 3; 
    if(*prioridad >= 50 && *prioridad <= 100) return 2; 
    if(*prioridad > 100) return 1; 
}

void *leenumero(ifstream &arch){
    int dato, *auxdato; 
    
    arch >> dato;
    if(arch.eof()) return nullptr; 
    auxdato = new int;
    *auxdato = dato;
    
    return auxdato; 
}

void imprimirnum(void *cola, const char *nomarch){
    int *num, i = 0; 
    void *dato, **rec;
    void **aux = (void **)cola;
    
    num = new int; 
    ofstream arch(nomarch, ios::out); 
    
    rec = (void **)(aux[0]);
    while(rec){
        dato = rec[0];
        num = (int*) dato; 
        arch << *num << endl; 
        rec = (void **)(rec[1]); 
    }
    
    while(i<3){
        rec = (void **)(aux[i+1]); 
        dato = rec[0];
        num = (int*) dato; 
        arch << "Prioridad " << i + 1 << ": " << *num << endl;  
        i++; 
    }
    
    delete num; 
}