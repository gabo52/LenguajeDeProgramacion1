/* 
 * File:   BibliotecaPilaGenerica.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 30 de mayo de 2023, 08:18 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaPilaGenerica.h"
using namespace std;

void generapila(void *&pila){
    int *num; 
    void **auxpila; 
    auxpila = new void*[2]; 
    auxpila[0] = nullptr;
    
    num = new int;              //no olvidad que debe ser un puntero!! 
    *num = 0; 
    auxpila[1] = num;
    
    pila = auxpila;
}

void push(void *&pila, void *dato){
    void **aux = (void **)pila; 
    void **nuevo;
    int *cont; 
    
    nuevo = new void*[2];
    nuevo[0] = aux[0];
    nuevo[1] = dato;
    
    aux[0] = nuevo; 
    cont = (int*)aux[1];
    (*cont)++; 
    
}

void hanoi(int n, void *ini, void *aux, void *fin){ 
    if(n == 1){
        push(fin,pop(ini)); 
        return;
    }else{
        hanoi(n-1,ini,fin,aux); 
        push(fin,pop(ini)); 
        hanoi(n-1,aux,ini,fin);
    }
}

void muevepila(void *pilaini, void *&pilafin){
    void *pilaux; 
    void **dupla = (void**)pilaini;
    generapila(pilafin);
    generapila(pilaux);
    
    int *n = (int*)dupla[1];
    
    hanoi(*n,pilaini,pilaux,pilafin);
}

int pilavacia(void *pila){
    void **aux = (void **)pila; 
    if(aux[0] == nullptr) return 1; 
    return 0; 
}

void *pop(void *pila){
    int *cont; 
    void **dupla = (void **)pila, *dato = nullptr; 
    
    if(!pilavacia(pila)){
        void **aux = (void **)(dupla[0]); 
        dato = aux[1]; 
        dupla[0] = aux[0];
        cont = (int*)(dupla[1]);
        (*cont)--; 
        delete aux; 
    }
    return dato; 
}

void cargaarreglo(void *&arreglo, int(*cmp)(const void *,const void *), void*(*lee)(ifstream &),const char *nombre){
    void *buffer[200], **aux;
    int nd = 0; 
    
    ifstream arch(nombre,ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo";
        exit(1);
    }
    
    while(1){
        buffer[nd] = lee(arch); 
        if(buffer[nd] == nullptr) break;
        nd++; 
    }
    
    aux = new void*[nd+1];
    for(int j=0;j<=nd;j++) aux[j] = buffer[j];
    qsort(aux,nd,sizeof(int),cmp);
    arreglo = aux; 
}

void cargapila(void *&pila, void *arreglo){
    void **aux = (void **)arreglo;
    int i = 0; 
    
    generapila(pila);
    while(aux[i]){
        push(pila, aux[i]); 
        i++; 
    }
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    