/* 
 * File:   ListaConRegistro.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:17 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "BibliotecaListaGenerica.h"
#define MAXCANTLINEA 100
using namespace std;
char *leeCadena(ifstream &arch,char c);
void imprimeFecha(ofstream &arch,int fecha,void *&cabecera);
char *buscaConductor(int licencia);
void imprimeLinea(ofstream &arch,int cant,char c);
//35912665,O2Z-308,22/07/2019,156
//licencia,placa,fecha,infracción

void *leeregistro(ifstream &arch){
    int licencia;
    arch>>licencia;
    if(arch.eof())return nullptr;
    char *placa,c;
    arch.get();
    placa=leeCadena(arch,',');
    int *fecha,dd,mm,aa,*licenciaP,*falta;
    fecha = new int;
    licenciaP = new int;
    falta = new int;
    arch>>dd>>c>>mm>>c>>aa>>c>>*falta;
    *fecha = dd + mm*100 + aa*10000;
    *licenciaP = licencia;
    void **aux;
    aux = new void *[4];
    aux[0]=licenciaP;
    aux[1]=placa;
    aux[2]=fecha;
    aux[3]=falta;
    return aux;
}


char *leeCadena(ifstream &arch,char c){
    char buff[150],*aux;
    arch.getline(buff,150,c);
    aux= new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
int cmpregistro(void *dt1,void *dt2){
    void **dato1=(void**)dt1,**dato2=(void**)dt2;
    int *n1=(int *)dato1[2],*n2=(int *)dato2[2];
    return *n1-*n2;
}

void imprimeregistro(void *dt,ofstream &arch,void *&cabecera){
    int *fecha,*licencia,*falta;
    char *placa,*nomb;
    void **dato=(void **)dt;
    licencia=(int*)dato[0];
    placa=(char*)dato[1];
    fecha=(int*)dato[2];
    falta=(int*)dato[3];
    nomb = buscaConductor(*licencia);
    imprimeFecha(arch,*fecha,cabecera);
    arch<<setw(10)<<right<<*licencia<<"         "<<setw(45)<<left<<nomb<<setw(10)
            <<right<<*falta<<endl;
}


void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeCabecera(int mm,int aa,ofstream &arch){
    arch<<"Anio"<<setw(7)<<aa<<setw(7)<<right<<"Mes:  "<<setfill('0')<<setw(2)
            <<right<<mm<<setfill(' ')<<endl;
    arch<<setw(12)<<left<<"FECHA"<<setw(30)<<left<<"LICENCIA"<<setw(38)
            <<left<<"NOMBRE"<<"FALTA"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
}
void imprimeFecha(ofstream &arch,int fecha,void *&cabecera){
    int *cab = (int *)cabecera,flag=0;
    if(!cab){
        flag=1;
        cab = new int;
        *cab=0;
        cabecera=cab;
    }
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    if(*cab!=(mm+aa*10000)){
        if(flag==0)arch<<endl;
        imprimeCabecera(mm,aa,arch);
        *cab=(mm+aa*10000);
    }
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right
            <<mm<<"/"<<setw(4)<<right<<aa<<setfill(' ');
}

char *buscaConductor(int licencia){
    ifstream arch;
    AbrirArchivo("Conductores.csv",arch);
    int lic;
    char nombre[100],c,*aux;
    while(1){
        arch>>lic>>c;
        if(arch.eof())break;
        arch.getline(nombre,150);
        if(lic==licencia){
            aux = new char [strlen(nombre)+1];
            strcpy(aux,nombre);
            return aux;
        }
    }
    cout<<"ERROR, no se encontro la licencia "<<licencia;
    exit(1);
}