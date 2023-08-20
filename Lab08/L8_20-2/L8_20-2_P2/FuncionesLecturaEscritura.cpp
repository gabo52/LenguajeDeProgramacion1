/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 11:39 AM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
#include "ListaDePacientes.h"
using namespace std;


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
ifstream & operator >> (ifstream &arch, ListaDePacientes &lista){
    int dni;
    char c,nombre[200],tipo,codigo[20];
    arch>>dni>>c;
    if(arch.eof())return arch;
    Paciente aux;
    arch.getline(nombre,200,',');
    arch>>tipo>>c;
    aux.SetDni(dni);
    aux.SetNombre(nombre);
    arch.getline(codigo,200,',');
    aux.SetCodMed(codigo);
    if(tipo=='A'){
        Ambulatorio amb;
        amb.SetDni(dni);
        amb.SetCodMed(codigo);
        amb.SetNombre(nombre);
        arch>>amb;
        lista+amb;
    }else if(tipo=='E'){
        Emergencia emer;
        emer.SetDni(dni);
        emer.SetCodMed(codigo);
        emer.SetNombre(nombre);
        arch>>emer;
        lista+emer;
    }else{
        Urgencia urg;
        urg.SetDni(dni);
        urg.SetCodMed(codigo);
        urg.SetNombre(nombre);
        arch>>urg;
        lista+urg;
    }
    arch.get();
    return arch;
}

ifstream &operator >>(ifstream &arch, Ambulatorio &amb){
    double porc;
    arch>>porc;
    if(arch.eof())return arch;
    amb.SetProcSeguro(porc);
    return arch;
}

ifstream &operator >>(ifstream &arch, Emergencia &amb){
    int telef;
    char cadena[200],c;
    arch.getline(cadena,200,',');
    if(arch.eof())return arch;
    arch>>telef;
    amb.SetNombreRef(cadena);
    amb.SetTelefonoRef(telef);
    return arch;
}

ifstream &operator >>(ifstream &arch, Urgencia &amb){
    double porc1,porc2;
    char c;
    arch>>porc1>>c;
    if(arch.eof())return arch;
    arch>>porc2;
    amb.SetPorcSeguro(porc1);
    amb.SetPorcUrgencia(porc2);
    return arch;
}

ofstream &operator <<(ofstream &arch, ListaDePacientes &c){
    arch<<setw(70)<<right<<"INSTITUTO DE SALUD SA"<<endl;
    c.imprimeEmergencias(arch);
    c.imprimeUrgencias(arch);
    c.imprimeAmbulatorio(arch);
    return arch;
}

ofstream &operator <<(ofstream &arch,const Ambulatorio &amb){
    char cadena[200];
    amb.GetNombre(cadena);
    arch<<setw(12)<<left<<amb.GetDni()<<setw(50)<<cadena;
    amb.GetCodMed(cadena);
    arch<<setw(10)<<left<<cadena;
    arch<<setw(13)<<right<<amb.GetProcSeguro()<<endl;
    return arch;
}

ofstream &operator <<(ofstream &arch,const Emergencia &emer){
    char cadena[200];
    emer.GetNombre(cadena);
    arch<<setw(12)<<left<<emer.GetDni()<<setw(50)<<cadena;
    emer.GetCodMed(cadena);
    arch<<setw(10)<<left<<cadena;
    emer.GetNombreRef(cadena);
    arch<<setw(25)<<left<<cadena<<left<<emer.GetTelefonoRef()<<endl;
    return arch;
}

ofstream &operator <<(ofstream &arch,const Urgencia &urg){
    char cadena[200];
    urg.GetNombre(cadena);
    arch<<setw(12)<<left<<urg.GetDni()<<setw(50)<<cadena;
    urg.GetCodMed(cadena);
    arch<<setw(10)<<left<<cadena;
    arch<<setw(13)<<right<<urg.GetPorcSeguro()<<setw(12)<<right<<urg.GetPorcUrgencia()<<endl;
    return arch;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}