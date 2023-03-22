/* 
 * File:   BibliotecaColaGenerica.cpp
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 06:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "ColaBanco-Clientes.h"
#include "BibliotecaColaGenerica.h"
enum CreacionCola {INICIO,FIN};
enum DatosCola {DATO,SIG};


void creaCola(void *&cl, void*(*leenumero)(ifstream &),ifstream &arch){
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
    if(colaVacia(cl))return nullptr;
    void **inicola=(void**)cola[INICIO],*sig,**fincola=(void**)cola[FIN];
    sig=inicola[SIG];
    cola[INICIO]=sig;
    if(cola[INICIO]==cola[FIN])cola[FIN]=nullptr;
    return inicola[DATO];
}

int colaVacia(void *cl){
    void **cola=(void **)cl;
    return (cola[INICIO]==nullptr);
}

void imprimir(void *col,void (*imprimenumero)(ofstream &arch,void *dato),ofstream &arch){
    //preguntar
    if(colaVacia(col))return;
    void **cola=(void **)col,**recorrido;
    recorrido=(void **)cola[INICIO];
    while(recorrido){
        imprimenumero(arch,recorrido[DATO]);
        recorrido=(void**)recorrido[SIG];
    }
}


