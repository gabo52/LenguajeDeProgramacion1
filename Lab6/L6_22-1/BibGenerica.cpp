/* 
 * File:   BibGenerica.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:21 PM
 */

#include <iostream>
#include <iomanip>
#include "BibGenerica.h"
enum arbolGenerico {DATO,IZQ,DER};
using namespace std;


void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

int arbolvacio(void *arb){
    return arb==nullptr;
}


void creaarbol(void *&arb,void *(*lee)(ifstream &arch),
        int (*cmpnumero)(void *dato1,void *dato2),const char *nomb){
    void *dato;
    ifstream arch;
    AbrirArchivo(nomb,arch);
    arb=nullptr;
    while(1){
        dato = lee(arch);
        if(arch.eof())break;
        insertanodo(arb,dato,cmpnumero);
    }
}

void insertanodo(void *&arb,void *dato,int (*cmpnumero)(void *dato1,void *dato2)){
    void **aux;
    if(arbolvacio(arb)){
        aux = new void *[3];
        aux[DATO]=dato;
        aux[DER]=nullptr;
        aux[IZQ]=nullptr;
        arb=aux;
        return;
    }
    void **arbol=(void**)arb;
    if(cmpnumero(dato,arbol[DATO])>0){
        insertanodo(arbol[DER],dato,cmpnumero);
    }else{
        insertanodo(arbol[IZQ],dato,cmpnumero);
    }
}

void muestraarbol(void *arbol,void (*imprime)(void *dato,ofstream &arch,void *&dato2),
        const char *nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    void *flag=nullptr;
    enorden(arbol,imprime,arch,flag);
}


void enorden(void *arb,void (*imprime)(void *dato,ofstream &arch,void *&dato2),
        ofstream &arch,void *&flag){
    if(arbolvacio(arb)){       
        return;
    }
    void **arbol=(void **)arb;
    enorden(arbol[IZQ],imprime,arch,flag);
    imprime(arbol[DATO],arch,flag);
    flag=arbol[DATO];
    enorden(arbol[DER],imprime,arch,flag);
   
}
