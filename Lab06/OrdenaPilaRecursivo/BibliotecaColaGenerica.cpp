/* 
 * File:   BibliotecaColaGenerica.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de octubre de 2022, 04:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "BibliotecaColaGenerica.h"
enum CreacionCola {INICIO,FIN};
enum DatosCola {DATO,SIG};

void AbrirArchivo(ifstream &arch,const char *nomb){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(ofstream &arch,const char *nomb){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void creaCola(void *&cl, void*(*leenumero)(ifstream &)){
    ifstream arch;
    AbrirArchivo(arch,"Banco-Clientes.csv");
    void *aux,**cola;
    cola = new void *[2];
    cola[0]=nullptr;
    cola[1]=nullptr;
    cl=cola;
    while(1){
        aux=leenumero(arch);
        if(arch.eof())break;
        encola(cl,aux);
    }
}


void encola(void *&cl,void *elemento){
    void **cola=(void**)cl,**aux;
    aux = new void *[2];
    aux[DATO]=elemento;
    aux[SIG]=nullptr;
    if(colaVacia(cola)){ 
        cola[INICIO]=aux;
        cola[FIN]=aux;
        return;
    }
    void **finCola;
    finCola=(void**)cola[FIN];
    finCola[1]=(void*)aux;
    cola[FIN]=aux;
}

void *desencola(void *&cl){
    void **cola=(void**)cl;
    if(colaVacia(cola))return nullptr;
    void **inicola=(void**)cola[INICIO],*sig;
    sig=inicola[SIG];
    if(cola[INICIO]==cola[FIN])cola[FIN]=nullptr;
    cola[INICIO]=sig;
    return inicola[DATO];
}

int colaVacia(void **colaAux){
    return (colaAux[FIN]==nullptr);
}

void imprimir(void *col,void (*imprimenumero)(ofstream &arch,void *dato)){
    void **cola=(void **)col,**recorrido;
    ofstream arch;
    AbrirArchivo(arch,"ImpresionCola.txt");
    recorrido=(void **)cola[INICIO];
    while(recorrido){
        imprimenumero(arch,recorrido[DATO]);
        recorrido=(void**)recorrido[SIG];
    }
}

void atiendeNumero(void *&col){
    void **cola=(void **)col,**recorrido,**aux,*dato;
    recorrido=(void **)cola[INICIO];
    if(colaVacia(cola))return;
    while(cola[FIN]){
        dato=desencola(col);
        delete aux;
    }
    cola[INICIO]=nullptr;
    cola[FIN]=nullptr;
    //preguntar
    //delete cola;
}