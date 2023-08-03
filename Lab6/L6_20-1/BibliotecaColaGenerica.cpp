/* 
 * File:   BibliotecaColaGenerica.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 03:15 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaColaGenerica.h"
using namespace std;

void creaCola(void *&cola,void *(*leer)(ifstream &arch)){
    void **auxcola,*reg;
    ifstream arch("Banco-Clientes.csv", ios::in); 

    auxcola = new void *[2];
    auxcola[0] = nullptr;
    auxcola[1] = nullptr;
    cola = auxcola;
    
    while(1){
        reg = leer(arch);
        if(arch.eof()) return;
        encola(cola,reg);
    }
}

void encola(void *cola,void *dato){
    int i, p1, p2; 
    void **aux = (void **) cola;
    void **nuevo, **rec, **ant = nullptr;
    
    nuevo = new void *[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    
    if(colaVacia(cola)){
        aux[0] = nuevo;
        aux[1] = nuevo;
        return;
    }
    
    rec = (void **) aux[1];
    rec[1] = nuevo; 
    aux[1] = nuevo; 
}

int colaVacia(void *cola){
    void **aux = (void **) cola;
    return aux[0] == nullptr;
}

void *desencola(void *cola){
    
    if(colaVacia(cola)) return nullptr;
    
    void **aux = (void **)cola;             //mi aux apuntara a la cabecera de la cola 
    void **colaini = (void **)aux[0];       //mi colaini apuntara al primer elemento del tad
    void **penultimo, *dato;        
    
    if(aux[0] == aux[1]){     //solo hay un elemento en la cola 
        aux[0] = nullptr;
        aux[1] = nullptr;
    }else{
        penultimo = (void**) colaini[1];
        aux[0] = penultimo;
        colaini[1] = nullptr;
    }
    dato = colaini[0];                      //tomo el dato del que antes era mi nodo inicial
    delete colaini;                         //elimino el que antes era mi nodo inicial 
    return dato;
}

void imprimeLinea(ofstream &arch, int n, char c){
    for(int i=0;i<n;i++) arch << c;
    arch << endl; 
}

void imprimir(void *cola,void (*imprime)(void *dato,ofstream &arch)){
    void *dato, **rec;
    void **aux = (void **)cola;

    ofstream arch("Reporte.txt", ios::out); 
    imprimeLinea(arch,150,'='); 
    
    rec = (void **)(aux[0]);
    while(rec){
        dato = rec[0];
        imprime(dato,arch);
        rec = (void **)(rec[1]); 
    }
    imprimeLinea(arch,150,'='); 
}

void atiendeNumero(void *cola){
    void *dato;
    while(!colaVacia(cola)) dato = desencola(cola);
}
