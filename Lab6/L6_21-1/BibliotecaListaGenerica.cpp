/* 
 * File:   BibliotecaListaGenerica.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:16 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaListaGenerica.h"

using namespace std;

enum lista {INI,FIN};
enum nodo {DATO,SIG};

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void creaLista(void *&ls,void *(*lee)(ifstream &),int (*cmp)(void *,void *)
    ,const char *nomb){
    void **lista,*reg;
    lista = new void *[2];
    lista[0]=nullptr;
    lista[1]=nullptr;
    ls = lista;
    ifstream arch;
    AbrirArchivo(nomb,arch);
    while(1){
        reg=lee(arch);
        if(arch.eof())break;
        insertaLista(ls,reg,cmp);
    }
}

void insertaLista(void *ls,void *dato,int (*cmp)(void *dato1,void *dato2)){
    void **lista=(void **)ls,**aux,**ant=nullptr,**lsfin,**recorrido;
    aux = new void *[2];
    aux[0]=dato;
    aux[1]=nullptr;
    if(listaVacia(ls)){
        lista[INI]=aux;
        lista[FIN]=aux;
        return ;
    }
    recorrido=(void**)lista[INI];
    while(recorrido){
        if(cmp(recorrido[0],dato)>0)break;
        ant=recorrido;
        recorrido=(void**)recorrido[1];
    }
    //no olvidar cuando se llega al final
    
    if(ant==nullptr){
        lista[INI]=aux;
        aux[SIG]=recorrido;
    }else{
        if(recorrido){
            ant[SIG]=aux;
            aux[SIG]=recorrido;
        }else{
            lsfin=(void**)lista[FIN];
            lsfin[SIG]=aux;
            lista[FIN]=aux;
        }
    }
}

int listaVacia(void *ls){
    void **lista=(void **)ls;
    return lista[INI]==nullptr;
}

void uneLista(void *ls1,void *ls2){
    void **lista1=(void**)ls1,**lista2=(void**)ls2,**finls1;
    if(listaVacia(ls1)||listaVacia(ls2)){
        if(listaVacia(ls1)){
            lista1[INI]==lista2[INI];
            lista1[FIN]==lista2[FIN];
        }else return;
    }else{
        finls1=(void**)lista1[FIN];
        finls1[SIG]=lista2[INI];
        lista1[FIN]=lista2[FIN]; 
    }
    lista2[INI]=nullptr;
    lista2[FIN]=nullptr;
}

void imprimeLista(void *ls,void (*imprime)(void *,ofstream &,void *&),
        const char *nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    void **lista=(void**)ls,**recorrido,*cabecera=nullptr;
    recorrido=(void**)lista[INI];
    while(recorrido){
        imprime(recorrido[0],arch,cabecera);
        recorrido=(void**)recorrido[1];
    }
}