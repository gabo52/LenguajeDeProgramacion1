/* 
 * File:   BibliotecaColaGenerica.cpp
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 04:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaColaGenerica.h"
enum CreacionCola {INICIO,FIN,LONGITUD};
enum DatosCola {DATO,SIG};

void ordenaColaRecursivo(void *cl,int (*cmpnumero)(void *dato1,void *dato2),
        int longitud);

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

void creaCola(void *&cl, void*(*leenumero)(ifstream &),const char *nomb){
    ifstream arch;
    AbrirArchivo(arch,nomb);
    void *aux,**cola;
    cola = new void *[3];
    int *longitud = new int;
    *longitud = 0;
    cola[0]=nullptr;
    cola[1]=nullptr;
    cola[2]=longitud;
    
    cl=cola;
    while(1){
        aux=leenumero(arch);
        if(arch.eof())break;
        encola(cl,aux);
    }
}


void encola(void *&cl,void *elemento){
    void **cola=(void**)cl,**aux ;
    int *longitud = (int*)cola[2];
    aux = new void *[2];
    aux[DATO]=elemento;
    aux[SIG]=nullptr;
    if(colaVacia(cl)){
        (*longitud)++;
        cola[INICIO]=aux;
        cola[FIN]=aux;
        return;
    }
    void **finCola;
    (*longitud)++;
    finCola=(void**)cola[FIN];
    finCola[1]=(void*)aux;
    cola[FIN]=aux;
}

void *desencola(void *&cl){
    void **cola=(void**)cl;
    if(colaVacia(cl))return nullptr;
    int *longitud = (int*)cola[2];
    (*longitud)--;
    void **inicola=(void**)cola[INICIO],*sig;
    sig=inicola[SIG];
    if(cola[INICIO]==cola[FIN])cola[FIN]=nullptr;
    cola[INICIO]=sig;
    return inicola[DATO];
}

int colaVacia(void *cl){
    void **cola=(void **)cl;
    return (cola[FIN]==nullptr);
}

void imprimir(void *col,void (*imprime)(ofstream &arch,void *dato,void *&condicion),
        const char *nomb){
    void **cola=(void **)col,**recorrido,*condicion;
    ofstream arch;
    AbrirArchivo(arch,nomb);
    recorrido=(void **)cola[INICIO];
    condicion = nullptr;
    while(recorrido){
        imprime(arch,recorrido[DATO],condicion);
        recorrido=(void**)recorrido[SIG];
    }
}

void atiendeNumero(void *&col){
    void **cola=(void **)col,**recorrido,**aux,*dato;
    recorrido=(void **)cola[INICIO];
    if(colaVacia(col))return;
    while(cola[FIN]){
        dato=desencola(col);
        delete aux;
    }
    cola[INICIO]=nullptr;
    cola[FIN]=nullptr;
    //preguntar
    //delete cola;
}

void ordenaCola(void *cl,int (*cmpnumero)(void *dato1,void *dato2)){
    void **cola=(void **)cl;
    int *longitud = (int *)cola[2];
    ordenaColaRecursivo(cl,cmpnumero,*longitud);
}

void ordenaColaRecursivo(void *cl,int (*cmp)(void *dato1,void *dato2),
        int longitud){
    if(longitud<=1)return;
    void *aux,*dato;
    aux = desencola(cl);
    for(int i=0;i<longitud-1;i++){
        dato=desencola(cl);
        if(cmp(aux,dato)>0){
            encola(cl,aux);
            aux=dato;
        }else encola(cl,dato);
    }
    ordenaColaRecursivo(cl,cmp,longitud-1);
    encola(cl,aux);
}