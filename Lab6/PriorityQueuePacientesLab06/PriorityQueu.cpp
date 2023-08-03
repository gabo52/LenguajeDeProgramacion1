/* 
 * File:   PriorityQueu.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de octubre de 2022, 10:27 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueu.h"
using namespace std;
enum cola {INICIO,FIN};
enum datCol {DATO,ANT,SIG};


void agregarColaMitadRecorrido(void **recorrido,void **aux,
        int(*obtienePrioridad)(void *dato),void **sig,void **cola,int p2);
void agregarColaFinalRecorrido(void **aux,void **sig,void **recorrido,void **cola);
void agregarColaInicioRecorrido(void **aux,void **sig,void **recorrido,void **cola);

void crearCola(void *&cl,ifstream &arch,int (*obtienePrioridad)(void *dato),
        void *(*leeRegistro)(ifstream &arch)){
    void **cola,*reg;
    int i=0;
    cola = new void *[2];
    cola[INICIO]=nullptr;
    cola[FIN]=nullptr;
    cl = cola;
    while(1){
        reg=leeRegistro(arch);
        if(arch.eof())return;
        encolar(cl,reg,obtienePrioridad);
    }
}


void encolar(void *cl,void *dato,int (*obtienePrioridad)(void *dato)){
    void **aux,**cola=(void**)cl,**recorrido,**sig=nullptr,**colafin;
    aux = new void *[3];
    aux[DATO]=dato;
    aux[ANT] = nullptr;
    aux[SIG] = nullptr;
    if(es_cola_vacia(cl)){
        cola[INICIO]=aux;
        cola[FIN]=aux;
        return;
    }
    int i,p1,p2;
    recorrido = (void **)cola[FIN];
    p1=obtienePrioridad(dato);
    p2=obtienePrioridad(recorrido[0]);
    //validar ingreso desordenado
//    if(p1<p2){
//        agregarColaInicioRecorrido(aux,sig,recorrido,cola);
//        return;
//    }
    
    while(recorrido){
        p2=obtienePrioridad(recorrido[0]);
        if(p1<=p2){
            agregarColaMitadRecorrido(recorrido,aux,obtienePrioridad,sig,cola,p2);
            return;
        }
        sig=recorrido;
        recorrido=(void**)recorrido[1];
    }
    agregarColaFinalRecorrido(aux,sig,recorrido,cola);
}

void agregarColaInicioRecorrido(void **aux,void **sig,void **recorrido,void **cola){
    recorrido[SIG]=aux;
    aux[ANT]=recorrido;
    aux[SIG]=nullptr;
    cola[FIN]=aux;
}

void agregarColaMitadRecorrido(void **recorrido,void **aux,
        int(*obtienePrioridad)(void *dato),void **sig,void **cola,int p2){
    void **colafin;
    recorrido[SIG]=aux;
    aux[ANT]=recorrido;
    colafin = (void**)cola[FIN];
    
    if(p2==obtienePrioridad(colafin[0])){
        cola[FIN]=aux;
    }
    else{
        aux[SIG]=sig;
        sig[ANT]=aux;
    }
    return;
}
void agregarColaFinalRecorrido(void **aux,void **sig,void **recorrido,void **cola){
    aux[SIG]=sig;
    sig[ANT]=aux;
    cola[INICIO]=aux;
}

void *desencolar(void *cl){
    if(es_cola_vacia(cl))return nullptr;
    void **cola = (void **)cl,**aux,**colaini=(void**)cola[INICIO],*dato;
    if(cola[INICIO]==cola[FIN]){
        cola[INICIO]=nullptr;
        cola[FIN]=nullptr;
    }else{
        aux=(void**)colaini[2];
        cola[INICIO]=aux;
        aux[1]=nullptr;
    }
    dato = colaini[0];
    delete colaini;
    return dato;
}

int es_cola_vacia(void *cl){
    void **cola = (void **)cl;
    return cola[INICIO]==nullptr;
}


void prueba(void *cl,void (*imprimeReg)(void *dato,ofstream &arch),ofstream &arch){
    void **cola=(void**)cl,**recorrido,*dato;
    while(!es_cola_vacia(cl)){
        dato=desencolar(cl);
        imprimeReg(dato,arch);
    }
}