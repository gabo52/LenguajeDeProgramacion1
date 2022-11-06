/* 
 * File:   FunPedidos.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:22 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "FunPedidos.h"
using namespace std;
#define MAXCANTLINEA 100

void imprimeFecha(int fecha,ofstream &arch);

char *leerCadena(ifstream &arch,char c){
    char buff[150],*aux;
    arch.getline(buff,150,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    return dd+mm*100+aa*10000;
}
//422763,GALLETAS SUAVICREMAS FRESA 158GR,2,17913944,23/09/2019
//codigo,descripcion,cantSOl,DNI,FECHA
void *leepedido(ifstream &arch){
    char *desc,c;
    int cod,*codP,fecha;
    arch>>cod>>c;
    if(arch.eof())return nullptr;
    desc = leerCadena(arch,',');
    int *cantSol,*DNIP,*fechaP;
    cantSol = new int;
    DNIP = new int;
    arch>>*cantSol>>c>>*DNIP>>c;
    fecha = leerFecha(arch);
    fechaP = new int;
    *fechaP = fecha;
    codP = new int;
    *codP = cod;
    void **aux;
    aux = new void *[5];
    aux[0] = codP;
    aux[1] = desc;
    aux[2] = cantSol;
    aux[3] = DNIP;
    aux[4] = fechaP;
    return aux;
}



int cmppedido(void *dt1,void *dt2){
    void **dato1=(void**)dt1,**dato2=(void**)dt2;
    int *d1=(int*)dato1[4],*d2=(int*)dato2[4];
    int *DNI1=(int*)dato1[3],*DNI2=(int*)dato2[3];
    if(*d1!=*d2)return *d1-*d2;
    return *DNI1 - *DNI2;
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    aa= fecha/100;
    arch.precision(2);
    arch.fixed;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<setfill(' ');
}

void imprimeLinea(ofstream &arch,int cant, char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeCabecera(ofstream &arch){
    arch<<setw(13)<<left<<"Fecha"<<setw(14)<<left<<"DNI"<<setw(10)<<left
            <<"Codigo"<<setw(50)<<left<<"Descripcion del Producto"
            <<setw(5)<<right<<"Cantidad"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
}

void imprimepedido(void *dt,ofstream &arch,void *&flag){
    if(!flag){
        imprimeCabecera(arch);
    }
    void **dato=(void**)dt;
    int *codP=(int *)dato[0];
    char *desc=(char *)dato[1];
    int *cantSol=(int *)dato[2];
    int *DNI=(int *)dato[3];
    int *fecha=(int *)dato[4];
    imprimeFecha(*fecha,arch);
    arch<<"   "<<setw(14)<<left<<*DNI<<setw(10)<<left<<*codP<<setw(50)<<left<<desc
            <<setw(5)<<right<<*cantSol<<endl;
}