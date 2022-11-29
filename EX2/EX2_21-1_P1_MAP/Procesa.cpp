/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 08:48 PM
 */



#include "Procesa.h"

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

void Procesa::lee(){
    leeConductores();
    leeConsultados();
}

void Procesa::leeConductores(){
    ifstream arch;
    AbrirArchivo("Conductores.csv",arch);
    Nodo nod;
    while(1){
        nod.leer(arch);
        if(arch.eof())break;
        lrenueva.push_back(nod);
    }
}

void Procesa::leeConsultados(){
    ifstream arch;
    AbrirArchivo("consulta.txt",arch);
    int lic;
    while(1){
        arch>>lic;
        if(arch.eof())break;
        verificarAgregarNodo(lic);
    }
}
        
void Procesa::verificarAgregarNodo(int lic){
    for(list<Nodo>::iterator it = lrenueva.begin();it!=lrenueva.end();it++){
        if((*it).licencia()==lic){
            if((*it).activo()){
                consultados[lic]=(*it);
            }
        }
    }
}
void Procesa::imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void Procesa::imprime(){
    imprimeLista();
    imprimeMapa();
}

void Procesa::imprimeLista(){
    ofstream arch;
    AbrirArchivo("ReporteRenovacion.txt",arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(80)<<right<<"Renovacion de Licencias"<<endl;
    imprimeLinea(arch,150,'=');
    arch<<setw(12)<<left<<"Licencia"<<setw(36)<<left<<"Nombre"<<setw(25)<<left<<
            "           Observacion"<<setw(10)<<right<<"Multas"<<setw(10)<<right
            <<"Tramites"<<setw(10)<<right<<"Ex.Med"<<setw(20)<<right<<"Manejo/Reglas"
            <<setw(15)<<right<<"Total"<<endl;
    lrenueva.sort();
    for(list<Nodo>::iterator it = lrenueva.begin();it!=lrenueva.end();it++){
        (*it).imprime(arch);
    }
}

void Procesa::imprimeMapa(){
    ofstream arch;
    AbrirArchivo("ReporteConsultados.txt",arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(80)<<right<<"Renovacion de Licencias"<<endl;
    imprimeLinea(arch,150,'=');
    arch<<setw(12)<<left<<"Licencia"<<setw(36)<<left<<"Nombre"<<setw(25)<<left<<
            "           Observacion"<<setw(10)<<right<<"Multas"<<setw(10)<<right
            <<"Tramites"<<setw(10)<<right<<"Ex.Med"<<setw(20)<<right<<"Manejo/Reglas"
                        <<setw(15)<<right<<"Total"<<endl;
    for(map<int,Nodo>::iterator it = consultados.begin();it!=consultados.end();it++){
        (*it).second.imprime(arch);
    }
}