/* 
 * File:   Cola.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:42 PM
 */

#include "Cola.h"
#include "Alumno.h"
#include "Profesor.h"

Cola::Cola() {
    fin=nullptr;
    ini=nullptr;
}


Cola::~Cola() {
    
}

void Cola::encola(Persona *per){
    NodoCola *nuevo;
    nuevo = new NodoCola;
    nuevo->sig=nullptr;
    nuevo->persona=per;
    if(ini==nullptr){ 
        ini=nuevo;
        fin=nuevo;
        return;
    }   
    fin->sig=nuevo;
    fin=nuevo;
}

void Cola::desencola(Persona *&per){
    if(ini==nullptr){
        per=nullptr;
        return;
    }
    NodoCola *aux=ini;
    per=ini->persona;
    if(fin==ini){
        fin=nullptr;
        ini=nullptr;
    }else{
        ini=ini->sig;
    }
    delete aux;
}

void Cola::imprime(const char *nomb){
    ofstream arch;
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
    Persona *per;
    while(ini){
        desencola(per);
        per->imprime(arch);
    }
}

void Cola::lee(const char *nomb){
    ifstream arch;
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
    Persona *per;
    char tipo,c;
    while(1){
        arch>>tipo>>c;
        if(arch.eof())break;
        if(tipo=='P'){
            per = new class Profesor;
        }else{
            per = new class Alumno;
        }
        per->leer(arch);
        encola(per);
    }
}
