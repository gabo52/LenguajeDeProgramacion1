/* 
 * File:   ListaDePacientes.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 12:52 PM
 */

#include "ListaDePacientes.h"
#define MAXCANTLINEA 120

void AbrirArchivo(const char *nomb, ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb, ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

ListaDePacientes::ListaDePacientes() {
    lista = nullptr;
}

ListaDePacientes::~ListaDePacientes() {
}


void ListaDePacientes::CreaLista(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    Paciente *pac;
    while(1){
        arch>>pac;
        if(arch.eof())break;
        insertar(pac);
    }
    
}

void ListaDePacientes::insertar(Paciente *&pac){
    Nodo *p=lista,*ant=nullptr;
    Nodo *nuevo = new Nodo;
    nuevo->pac = pac;
    int prio=pac->prioridad();
    while(p){
        if(p->pac->prioridad()>prio)break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig=p;
    if(ant!=nullptr)ant->sig=nuevo;
    else lista = nuevo;
}

void ListaDePacientes::imprimeLista(const char *nomb){
    ofstream arch;
    
    imprimeLinea(arch,MAXCANTLINEA,'=');
    AbrirArchivo(nomb,arch);
    Nodo *aux=lista;
    while(aux){
        aux->pac->imprime(arch);
        aux=aux->sig;
    }
}

void operator >>(ifstream &arch,Paciente *&pac){
    char tipo,c;
    arch>>tipo>>c;
    if(arch.eof())return;
    if(tipo=='A'){
        pac = new Ambulatorio;
    }else if(tipo=='E'){
        pac = new Emergencia;
    }else pac = new Urgencia;
    pac->leePaciente(arch);
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

