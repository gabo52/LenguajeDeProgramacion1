/* 
 * File:   BibGenerica.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 04:35 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "BibGenerica.h"
using namespace std;

void crearcola(void *&cola,void *(*leer)(ifstream &arch),int (*prioridad)(void *),const char *nomarch){
    void **auxcola,*reg;
    ifstream arch(nomarch, ios::in); 

    auxcola = new void *[5];
    auxcola[0] = nullptr;
    auxcola[1] = nullptr;
    auxcola[2] = nullptr;
    auxcola[3] = nullptr;
    auxcola[4] = nullptr;
    cola = auxcola;
    
    while(1){
        reg = leer(arch);
        if(arch.eof()) return;
        encola(cola,reg,prioridad);
    }
}

void encola(void *cola,void *dato,int(*obtienePrioridad)(void *)){
    int i, p1, p2; 
    void **aux = (void **) cola;
    void **nuevo, **rec, **sig = nullptr, **fin = nullptr;
    
    nuevo = new void *[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    
    p1 = obtienePrioridad(dato);
    
    if(colaVacia(cola)){
        aux[0] = nuevo;
        aux[p1] = nuevo; 
        aux[4] = nuevo;
        return;
    }
    
    if(p1 == 1){
        if(aux[p1] == nullptr){
            rec = (void **)(aux[0]);
            nuevo[1] = rec; 
            aux[0] = nuevo; 
            aux[p1] = nuevo; 
        }else{
            rec = (void **)(aux[p1]);
            if(rec[1] == nullptr){
                aux[4] = nuevo;             //actualizo el final de la cola
            }else{
                sig = (void **)(rec[1]);    //sig apunta al siguiente elemento despues del puntero prioridad
                nuevo[1] = sig; 
            }
            rec[1] = nuevo;                 //lo agrego en el lugar
            aux[p1] = nuevo;                //actualizo la prioridad
        }
    }
    if(p1 == 2){
        if(aux[p1] == nullptr){
            if(aux[1] == aux[4]){           //si el ultimo elemento de la cola es de primera prioridad
                rec = (void **)(aux[4]);
                rec[1] = nuevo; 
                aux[4] = nuevo;
                aux[p1] = nuevo; 
            }
            if(aux[3] == aux[4]){           //si el ultimo elemento de la cola es de tercera prioridad
                if(aux[1] == nullptr){      //si no hay puntero a primera prioridad
                    rec = (void **)(aux[0]);    //apunta a la cabeza
                    nuevo[1] = rec; 
                    aux[p1] = nuevo;
                    aux[0] = nuevo; 
                }else{
                    rec = (void **)(aux[1]);    //apunta a la primera prioridad
                    nuevo[1] = rec[1]; 
                    rec[1] = nuevo; 
                    aux[p1] = nuevo;
                }
            }
        }else{
            rec = (void **)(aux[p1]);
            if(aux[p1] == aux[4]){          //si el ultimo elemento de la cola es de segunda prioridad 
                rec[1] = nuevo; 
                aux[4] = nuevo;
                aux[p1] = nuevo; 
            }else{
                sig = (void **)(rec[1]);
                nuevo[1] = sig;
                rec[1] = nuevo; 
                aux[p1] = nuevo; 
            }
        }
    }
    if(p1 == 3){
        rec = (void **)(aux[4]);
        rec[1] = nuevo;                     //se anexa el nuevo nodo al final de la cola 
        aux[p1] = nuevo;                    //se actualiza la prioridad
        aux[4] = nuevo;                     //el ultimo elemento sera el nuevo nodo
    }
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
