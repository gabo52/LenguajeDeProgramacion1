/* 
 * File:   PriorityQueu.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 05:20 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ColaEnteros.h"
#include "PriorityQueu.h"
using namespace std;

void crearCola(void *&cola,ifstream &arch,int (*obtienePrioridad)(void *dato),void *(*leeRegistro)(ifstream &arch)){
    
    void **auxcola,*reg;
    
    auxcola = new void *[2];
    auxcola[0] = nullptr;
    auxcola[1] = nullptr;
    cola = auxcola;
    
    while(1){
        reg = leeRegistro(arch);
        if(arch.eof()) return;
        encolar(cola,reg,obtienePrioridad);
    }
}

void encolar(void *cola,void *dato,int (*obtienePrioridad)(void *dato)){
    int i, p1, p2; 
    void **aux = (void **) cola, **nuevo, **rec, **ant = nullptr;
    
    nuevo = new void *[3];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    nuevo[2] = nullptr;
    
    if(es_cola_vacia(cola)){
        aux[0] = nuevo;
        aux[1] = nuevo;
        return;
    }
    
    rec = (void **) aux[1];
    p1 = obtienePrioridad(dato);
    while(rec){
        p2 = obtienePrioridad(rec[0]);
        if(p1 <= p2){
            agregar(rec,nuevo,obtienePrioridad,ant,aux,p2);
            return;
        }
        ant = rec;
        rec = (void**)(rec[1]);
    }
    
    nuevo[2] = ant; 
    ant[1] = nuevo; 
    aux[0] = nuevo; 
}

void agregar(void **rec,void **nuevo,int(*obtienePrioridad)(void *dato),void **ant,void **cola,int p2){
    void **fincola;
    
    fincola = (void **) cola[1];
    
    rec[2] = nuevo;
    nuevo[1] = rec;
    
    if(p2 == obtienePrioridad(fincola[0])){     //si debe ser atendido al final de la cola 
        cola[1] = nuevo;
    }else{                                      //si debe agregarse al final de la cola 
        nuevo[2] = ant;
        ant[1] = nuevo;
    }
    return;
}

int es_cola_vacia(void *cola){
    void **aux = (void **) cola;
    return aux[0] == nullptr;
}

void *desencolar(void *cola){
    
    if(es_cola_vacia(cola)) return nullptr;
    
    void **aux = (void **)cola;             //mi aux apuntara a la cabecera de la cola 
    void **colaini = (void **)aux[0];       //mi colaini apuntara al primer elemento del tad
    void **penultimo, *dato;        
    
    if(aux[0] == aux[1]){     //solo hay un elemento en la cola 
        aux[0] = nullptr;
        aux[1] = nullptr;
    }else{
        penultimo = (void**) colaini[2];
        aux[0] = penultimo;
        penultimo[1] = nullptr;
    }
    
    dato = colaini[0];                      //tomo el dato del que antes era mi nodo inicial
    delete colaini;                         //elimino el que antes era mi nodo inicial 
    return dato;
}

void imprimeLinea(ofstream &arch, int n, char c){
    for(int i=0;i<n;i++) arch << c;
    arch << endl; 
}

void prueba(void *cola,void (*imprime)(void *dato,ofstream &arch),ofstream &arch){
    void *dato;
    
    imprimeLinea(arch,150,'='); 
    while(!es_cola_vacia(cola)){
        dato = desencolar(cola);
        imprime(dato,arch);
    }
    imprimeLinea(arch,150,'='); 
}
