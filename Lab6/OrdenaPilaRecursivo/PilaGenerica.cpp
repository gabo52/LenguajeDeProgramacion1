/* 
 * File:   PilaGenerica.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de octubre de 2022, 04:46 PM
 */

#include <iostream>
#include <iomanip>
#include "PilaGenerica.h"
#include "BibliotecaColaGenerica.h"
using namespace std;
enum pila {INI,LONG};
enum nodo {DATO,SIG};

void insertaOrdenado(void *pl,void *dato,int (*cmp)(void *dato1,void *dato2));
void ordenaRecursivo(void *pl,int longitud,int (*cmp)(void *dato1,void *dato2));

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
//   1
//   1 2
//   1 2 3 
void creaPila(void *&pl,void *(*lee)(ifstream &arch),const char *nomb){
    void **pila=new void *[2],*dato;
    int *longitud;
    longitud = new int;
    *longitud = 0;
    pila[INI]=nullptr;
    pila[LONG]=longitud;
    pl=pila;
    ifstream arch;
    AbrirArchivo(nomb,arch);
    while(1){
        dato = lee(arch);
        if(arch.eof())break;
        apila(pl,dato);
    }
}

int pilavacia(void *pl){
    return longitudPila(pl)==0;
}

void apila(void *pl,void *dato){
    void **pila=(void**)pl;
    void **aux;
    int *longitud=(int*)pila[1];
    aux = new void *[2];
    aux[0] = dato;
    aux[1] = nullptr;
    (*longitud)++;
    if(pilavacia(pl)){
        pila[INI]=aux;
        return ;
    }
    aux[1] = pila[INI];
    pila[INI]=aux;
}

void *desapila(void *pl){
    if(pilavacia(pl)){
        return nullptr;
    }
    void *aux,**pila=(void **)pl,**ini,*dato;
    ini=(void **)pila[INI];
    dato = ini[0];
    int *longitud=(int *)pila[1];
    if(longitudPila(pl)==1){
        pila[INI] = nullptr;
    }else{
        pila[INI]=ini[1];
    }
    (*longitud)--;
    delete ini;
    return dato;
}

int longitudPila(void *pl){
    void **pila=(void**)pl;
    return *(int *)pila[LONG];
}

void imprimePila(void *pl,void (*imprime)(void *dato,ofstream &arch,void*&),
        const char *nomb){
    if(pilavacia(pl))return;
    ofstream arch;
    AbrirArchivo(nomb,arch);
    void **recorrido,**pila=(void**)pl;
    recorrido = (void **)pila[INI];
    void *condicion = nullptr;
    while(recorrido){
        imprime(recorrido[0],arch,condicion);
        recorrido = (void **)recorrido[1];
    }
}

void ordenaPila(void *pl,int (*cmp)(void *dato1,void *dato2)){
    int longitud=longitudPila(pl);
    ordenaRecursivo(pl,longitud,cmp);
}
void ordenaRecursivo(void *pl,int longitud,int (*cmp)(void *dato1,void *dato2)){
    if(longitud<=1)return;
    void *cola,*aux,*dato,*valor,**cl=new void *[2];
    dato = desapila(pl);
    cl[0]=nullptr;
    cl[1]=nullptr;
    cola=cl;
    for(int i=0;i<longitud-1;i++){
        aux=desapila(pl);
        if(cmp(dato,aux)>0){
            encola(cola,dato);
            dato=aux;
        }else encola(cola,aux);
    }
    apila(pl,dato);
    for(int i=0;i<longitud-1;i++){
        aux=desencola(cola);
        apila(pl,aux);
    }
    delete cl;
    ordenaRecursivo(pl,longitud-1,cmp);
}

void ordenaPilaAux(void *pl,int (*cmp)(void *dato1,void *dato2)){
    if(pilavacia(pl))return;
    void *dato;
    dato = desapila(pl);
    ordenaPilaAux(pl,cmp);
    insertaOrdenado(pl,dato,cmp);
}
void insertaOrdenado(void *pl,void *dato,int (*cmp)(void *dato1,void *dato2)){
    void **pila=(void **)pl,*aux,*cima;
    cima = cimaPila(pl);
    if(pilavacia(pl) || cmp(dato,cima)>0){
        apila(pl,dato);
        return;
    }
    aux = desapila(pl);
    insertaOrdenado(pl,dato,cmp);
    
    apila(pl,aux);
}

void *cimaPila(void *pl){
    void **pila=(void **)pl,**cima;
    if(pilavacia(pl))return nullptr;
    cima = (void **)pila[0];
    return cima[0];
} 




