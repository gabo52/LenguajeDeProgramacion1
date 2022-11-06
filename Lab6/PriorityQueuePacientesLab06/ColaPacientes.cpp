/* 
 * File:   ColaPacientes.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de octubre de 2022, 04:23 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ColaPacientes.h"
using namespace std;

void *hallaRegistroA(int *DNIP,char *nombre,char *tipoP,double tarifa
,int *codigoP,double *pago);
void *hallaRegistroU(int *DNIP,char *nombre,char *tipoP,double seguro,
        double descuento,int *codigoP,double *pago);

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

char *leerCadena(ifstream &arch,char c){
    char buff[200],*aux;
    arch.getline(buff,200,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

//DNI/Nombre,tipoPac,CodESP
void *leeRegistroPaciente(ifstream &arch){
    int DNI,*DNIP;
    arch>>DNI;
    if(arch.eof())return nullptr;
    arch.get();
    char *nombre,c,tipo,*tipoP;
    nombre=leerCadena(arch,',');
    arch>>tipo>>c;
    DNIP = new int;
    tipoP = new char;
    *DNIP=DNI;
    *tipoP=tipo;
    //selectiva datos adicionales
    return hallaRegistroSegunTipo(DNIP,nombre,tipoP,arch);
}

void *hallaRegistroA(int *DNIP,char *nombre,char *tipoP,double tarifa,int *codigoP,double *pago){
    double *tarifaP;
    tarifaP = new double;
    void **aux;
    aux = new void *[6];
    *tarifaP=tarifa;
    aux[0]=DNIP;
    aux[1]=nombre;
    aux[2]=tipoP;
    aux[3]=codigoP;
    aux[4]=pago;
    aux[5]=tarifaP;
    return aux;
}

void *hallaRegistroU(int *DNIP,char *nombre,char *tipoP,double seguro,
        double descuento,int *codigoP,double *pago){
    void **aux;
    double *descuentoP,*seguroP;
    aux = new void *[7];
    descuentoP = new double;
    seguroP = new double;
    *descuentoP = descuento;
    *seguroP = seguro;
    aux[0]=DNIP;
    aux[1]=nombre;
    aux[2]=tipoP;
    aux[3]=codigoP;
    aux[4]=pago;
    aux[5]=seguroP;
    aux[6]=descuentoP;
    return aux;
}

void *hallaRegistroSegunTipo(int *DNIP,char *nombre,char *tipoP,ifstream &arch){
    void **aux;
    double tarifa,seguro,descuento,*pago;
    int *codigoP;
    codigoP = new int;
    char c;
    pago = new double;
    *pago=0;
    if(*tipoP=='A'){
        arch>>*codigoP>>c>>tarifa;
        arch.get();
        return hallaRegistroA(DNIP,nombre,tipoP,tarifa,codigoP,pago);
    }else if(*tipoP=='U'){
        arch>>*codigoP>>c>>descuento>>c>>seguro;
        arch.get();
        return hallaRegistroU(DNIP,nombre,tipoP,seguro,descuento,codigoP,pago);
    }else{
        aux = new void *[5];
        arch>>*codigoP;
        arch.get();
        aux[0]=DNIP;
        aux[1]=nombre;
        aux[2]=tipoP;
        aux[3]=codigoP;
        aux[4]=pago;
        return aux;
    }
}

int obtienePrioridadPaciente(void *dt){
    void **dato = (void **)dt;
    char *tipo = (char *)dato[2];
    if((*tipo)=='E'){
        return 3;
    }else if((*tipo)=='U'){
        return 2;
    }else return 1;
}

void imprimeRegPacientes(void *dt,ofstream &arch){
    void **dato=(void**)dt;
    int *DNIP,*codigo;
    char *tipo,*nombre;
    double *pago;
    DNIP=(int*)dato[0];
    nombre=(char*)dato[1];
    tipo=(char*)dato[2];
    codigo = (int *)dato[3];
    pago = (double *)dato[4];
    arch<<setw(10)<<left<<*DNIP<<setw(40)<<left<<nombre<<setw(10)<<left<<*codigo;
    arch.precision(2);
    arch.fixed;
    arch<<setw(12)<<right<<*pago;
    if(*tipo=='A'){
        arch<<"    "<<left<<"Ambulatorio"<<endl;
    }else if(*tipo=='U'){
        arch<<"    "<<left<<"Urgencia"<<endl;
    }else{
        arch<<"    "<<left<<"Emergencia"<<endl;
    }
}