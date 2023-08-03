/* 
 * File:   LFalta.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:40 PM
 */

#include "LFalta.h"


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

LFalta::LFalta() {
    lfin=nullptr;
    lini=nullptr;
}



LFalta::~LFalta() {
    NFalta *sale,*p;
    p =lini;
    while(p){
        sale=p;
        p=p->sig;
        delete sale;
    }
}

void LFalta::leer(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    Falta falt;
    Infraccion *inf;
    while(1){
        lee(arch,falt,inf);
        if(arch.eof())break;
        insertar(falt,inf);
    }
}

void LFalta::lee(ifstream &arch,Falta &falt,Infraccion *&inf){
    falt.leer(arch);
    if(arch.eof())return;
    int cod;
    arch>>cod;
    if(cod/100 == 3){
        inf = new class MuyGrave;
    }else if(cod/100 == 2){
        inf = new class Leve;
    }else{
        inf = new class Grave;
    }
    inf->SetCodigo(cod);
    ifstream archInfrac;
    AbrirArchivo("Infracciones.csv",archInfrac);
    inf->leer(archInfrac);
}

void LFalta::insertar(Falta &falt,Infraccion *inf){
    NFalta *p=lini, *nuevo, *rec=nullptr;
    nuevo = new class NFalta;
    nuevo->pfalta=inf;
    nuevo->dfalta=falt;
    
    while(p){
        if(p->dfalta.GetFecha()<nuevo->dfalta.GetFecha())break;
        rec = p;
        p = p->sig;
    }
    
    nuevo->sig = p;
    
    if(rec==nullptr){
        if(p==nullptr)lfin=nuevo;
        lini = nuevo;
    }else{
        rec->sig=nuevo;
        if(rec==lfin)lfin=nuevo;
    }
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void LFalta::imprimir(const char *nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    arch.precision(2);
    arch<<fixed;
    NFalta *p=lini;
    arch<<setw(12)<<left<<"Fecha"<<setw(12)<<left<<"Licencia"<<setw(15)<<left
            <<"Placa"<<setw(16)<<left<<"Infraccion"<<setw(10)<<left<<
            "Monto"<<setw(11)<<left<<"Descuento"
        <<setw(10)<<left<<"Puntos"<<setw(10)<<left<<"Meses Susp"<<endl;
    imprimeLinea(arch,110,'-');
    while(p){
        arch<<p->dfalta;
        p->pfalta->imprimir(arch);
        p=p->sig;
    }
}

void LFalta::unir(LFalta &lista){
    if(lini==nullptr){
        lini=lista.lini;
        lfin=lista.lfin;
    }else{
        if(lista.lini==nullptr)return;
        lfin->sig=lista.lini;
        lfin=lista.lfin;
    }
}