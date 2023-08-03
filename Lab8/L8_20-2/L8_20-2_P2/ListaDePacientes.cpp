/* 
 * File:   ListaDePacientes.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:51 AM
 */

#include "ListaDePacientes.h"
#include "FuncionesLecturaEscritura.h"
#define MAXCANTLINEA 115
ListaDePacientes::ListaDePacientes() {
    lAmb = nullptr;
    lEmer = nullptr;
    lUrg = nullptr;
}


ListaDePacientes::~ListaDePacientes() {
    if(lAmb)delete lAmb;
    if(lEmer)delete lEmer;
    if(lUrg)delete lUrg;
}

void ListaDePacientes::operator+(const Ambulatorio& c) {
    Ambulatorio *aux;
    int n=numAmbulatorio();
    if(lAmb){
        aux = new  Ambulatorio[n+2];
        for(int i=0;i<n;i++){
            aux[i]=lAmb[i];
        }
        delete lAmb;
        aux[n] = c;
        lAmb = aux;
    }else{
        lAmb = new Ambulatorio[2];
        lAmb[0]=c;
    }
}

void ListaDePacientes::operator+(const Urgencia& c) {
    Urgencia *aux;
    int n=numUrgencia();
    if(lUrg){
        aux = new  Urgencia[n+2];
        for(int i=0;i<n;i++){
            aux[i]=lUrg[i];
        }
        delete lUrg;
        aux[n] =c;
        lUrg = aux;
    }else{
        lUrg = new Urgencia[2];
        lUrg[0]=c;
    }
}

void ListaDePacientes::operator+(const Emergencia& c) {
    Emergencia *aux;
    int n=numEmergencia();
    if(lEmer){
        aux = new  Emergencia[n+2];
        for(int i=0;i<n;i++){
            aux[i]=lEmer[i];
        }
        delete lEmer;
        aux[n] = c;
        lEmer = aux;
    }else{
        lEmer = new Emergencia[2];
        lEmer[0]=c;
    }
}





int ListaDePacientes::numAmbulatorio()const {
    if(lAmb==nullptr)return 0;
    int i;
    for(i=0;lAmb[i].GetDni();i++);
    return i;
}

int ListaDePacientes::numEmergencia()const {
    if(lEmer==nullptr)return 0;
    int i;
    for(i=0;lEmer[i].GetDni();i++);
    return i;
}


int ListaDePacientes::numUrgencia()const {
    if(lUrg==nullptr)return 0;
        int i;
        for(i=0;lUrg[i].GetDni();i++);
        return i;
}



void ListaDePacientes::setLEmer(Emergencia* arr) {
    int n;
    for(n=0;arr[n].GetDni();n++);
    if(lEmer) delete lEmer;
    for(int i=0;i<n;i++){
        lEmer[i]=arr[i];
    }
}

void ListaDePacientes::getLEmer(Emergencia* aux) const {
    int n=numEmergencia();
    if(lEmer==nullptr) aux=nullptr;
    for(int i=0;i<n;i++){
        aux[i]=lEmer[i];
    }
}

void ListaDePacientes::setLUrg(Urgencia* arr) {
    int n;
    for(n=0;arr[n].GetDni();n++);
    if(lUrg) delete lUrg;
    for(int i=0;i<n;i++){
        lUrg[i]=arr[i];
    }
}

void ListaDePacientes::getLUrg(Urgencia* aux) const {
    int n=numUrgencia();
    if(lUrg==nullptr) aux=nullptr;
    for(int i=0;i<n;i++){
        aux[i]=lUrg[i];
    }
}

void ListaDePacientes::setLAmb(Ambulatorio* arr) {
    int n;
    for(n=0;arr[n].GetDni();n++);
    if(lAmb) delete lAmb;
    for(int i=0;i<n;i++){
        lAmb[i]=arr[i];
    }
}

void ListaDePacientes::getLAmb(Ambulatorio* aux) const {
    int n=numAmbulatorio();
    if(lAmb==nullptr) aux=nullptr;
    for(int i=0;i<n;i++){
        aux[i]=lAmb[i];
    }
}

void ListaDePacientes::imprimeAmbulatorio(ofstream& arch) {
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(80)<<right<<"PACIENTES ATENDIDOS DE MANERA AMBULATORIA"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(20)<<left<<"No.     DNI"<<setw(49)<<left<<"Paciente"<<setw(16)<<left
            <<"Medico"<<"% por Seg."<<endl;
    int n=numAmbulatorio();
    for(int i=0;i<n;i++){
        arch<<setw(2)<<right<<i+1<<")     ";
        arch<<lAmb[i];
    }
        
}

void ListaDePacientes::imprimeEmergencias(ofstream& arch) {
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(75)<<right<<"PACIENTES ATENDIDOS POR EMERGENCIA"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(20)<<left<<"No.     DNI"<<setw(49)<<left<<"Paciente"<<setw(17)<<left
            <<"Medico"<<"    Referencia"<<endl;
    int n=numEmergencia();
    for(int i=0;i<n;i++){
        arch<<setw(2)<<right<<i+1<<")     ";
        arch<<lEmer[i];
    }
        
}

void ListaDePacientes::imprimeUrgencias(ofstream& arch) {
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(75)<<right<<"PACIENTES ATENDIDOS POR URGENCIA"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(20)<<left<<"No.     DNI"<<setw(49)<<left<<"Paciente"<<setw(16)<<left
            <<"Medico"<<setw(12)<<left<<"% por Seg."<<setw(12)<<left<<
            "% Urgencia"<<endl;
    int n=numUrgencia();
    for(int i=0;i<n;i++){
        arch<<setw(2)<<right<<i+1<<")     ";
        arch<<lUrg[i];
    }
}












