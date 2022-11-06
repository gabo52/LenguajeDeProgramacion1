/* 
 * File:   SobrecargaEntradaSalida.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de noviembre de 2022, 10:58 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "SobrecargaEntradaSalida.h"
#include "Infraccion.h"
#include "Falta.h"
#define MAXCANTLINEA 100
using namespace std;



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
//63736112,ZAMORA ZAVALETA RONAL MANUEL

char *leerCadena(ifstream &arch, char c){
    char buff[300],*aux;
    arch.getline(buff,300,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

ifstream & operator >>(ifstream &arch, Conductores &conductor){
    int codigo;
    arch>>codigo;
    if(arch.eof())arch;
    char nombre[100];
    arch.get();
    arch.getline(nombre,100);
    conductor.SetNombre(nombre);
    conductor.SetLicencia(codigo);
}
//15029228,C0P-895,10/12/2019,201
//codigo, descripcion, gravedad, multa
ifstream & operator >>(ifstream &arch, Infraccion &infrac){
    int codigo;
    char c;
    arch>>codigo>>c;
    if(arch.eof())return arch;
    char descripcion[300],gravedad[20];
    double multa;
    arch.getline(descripcion,300,',');
    arch.getline(gravedad,20,',');
    arch>>multa;
    infrac.SetCodigo(codigo);
    infrac.SetDescripcion(descripcion);
    infrac.SetGravedad(gravedad);
    infrac.SetMulta(multa);
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    return dd+mm*100+aa*10000;
}
//15029228,C0P-895,10/12/2019,201
ifstream & operator >>(ifstream &arch, Falta &falta){
    int licencia,fecha,codigo;
    char c;
    arch>>licencia>>c;
    if(arch.eof())return arch;
    char placa[12];
    arch.getline(placa,12,',');
    fecha = leerFecha(arch);
    arch.get();
    arch>>codigo;
    falta.SetFecha(fecha);
    falta.SetCodInf(codigo);
    falta.SetLicencia(licencia);
    falta.SetPlaca(placa);
}


void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}


void imprimirFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<setfill(' ');
}

ofstream & operator <<(ofstream &arch,Conductores &conduc){
    char *nomb,*placa,*gravedad;
    nomb = conduc.GetNombre();
    arch<<setw(15)<<left<<"Conductor"<<":"<<nomb<<endl;
    arch<<setw(15)<<left<<"Licencia No."<<":"<<conduc.GetLicencia()<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<"Infracciones cometidas:"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(8)<<left<<"No."<<setw(20)<<left<<"Fecha"<<setw(15)<<left<<"Placa"
            <<setw(18)<<left<<"Infraccion"<<setw(16)<<left<<"Gravedad"
            <<left<<"Multa"<<endl;
    FaltaCond *aux=conduc.GetLfaltas(conduc.GetNumFaltas());
    for(int i = 0;i<conduc.GetNumFaltas();i++){
        arch<<setw(2)<<right<<i+1<<")    ";
        placa = aux[i].GetPlaca();
        gravedad = aux[i].GetGravedad();
        imprimirFecha(arch,aux[i].GetFecha());
        arch<<"           "<<setw(18)<<left<<placa
            <<setw(15)<<left<<aux[i].GetCodInf()<<setw(12)<<left<<gravedad;
        arch.precision(2);
        arch<<fixed;
        arch<<setw(10)<<right<<aux[i].GetMulta()<<endl;
    }
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(50)<<right<<"Cantidad"<<setw(18)<<right<<"Total"<<endl;
    arch<<setw(46)<<left<<"Total de Infracciones:"<<setw(9)<<left<<conduc.GetNumFaltas()
            <<setw(14)<<right<<(++conduc)<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
}