/* 
 * File:   BibCargaFaltas.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de octubre de 2022, 04:44 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibCargaFaltas.h"
#define MAXCANTLINEA 100
using namespace std;

void AbrirArchivo(const char* nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo";
        exit(1);
    }
}

void AbrirArchivo(const char* nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo";
        exit(1);
    }
}
//81485316,J5T-691,24/12/2020,128
//licencia,placa,fecha,infraccion
void cargaFaltas(int*&licencia,char ***&placa,int ***&falta,int ***&fecha){
    int i=0,numLic,auxLicen,auxFech,auxInfrac,numPlac[200]{},pos;
    //REVISA LOS BUFFERS
    ifstream arch;
    gestaMemoria(numLic,numPlac,licencia,placa,falta,fecha);
    char *auxPlaca;
    AbrirArchivo("RegistroDeFaltas.csv",arch);
    while(1){
        leeDatos(arch,numLic,auxPlaca,auxFech,auxInfrac);
        if(arch.eof())break;
        pos=buscarLicencia(numLic,licencia);
        if(pos!=-1){
            asignaFaltaALicencia(placa[pos],falta[pos],fecha[pos],auxPlaca,auxFech,auxInfrac);
        }
    }
    for(i=0;licencia[i];i++){
        asignarEspacios(falta[i],fecha[i],numPlac[i]);
    }
}

void asignarEspacios(int **&falta,int **&fecha,int numPlac){
    for(int i=0;i<numPlac;i++){
        asignaEspaciosFalta(falta[i],fecha[i]);
    }
}

void asignaEspaciosFalta(int *&falta,int *&fecha){
    int num=falta[0];
    if(num==0)falta = nullptr;
    else{
        int *auxFalta,*auxFecha,i;
        auxFalta=new int [num+2]{};
        auxFecha=new int [num+1]{};
        for(i=0;i<num+1;i++){
            auxFalta[i]=falta[i];
            auxFecha[i]=fecha[i];
        }
        auxFalta[i]=falta[i];
        delete falta;
        delete fecha;
        falta=auxFalta;
        fecha=auxFecha;
    }
}
int buscarLicencia(int numLic,int *licencia){
    for(int i=0;licencia[i];i++)if(numLic==licencia[i])return i;
    cout<<"ERROR, no se encontró la licencia "<<numLic<<endl;
    return -1;
}

int buscarPlaca(char *auxPlaca,char **placa){
    for(int i=0;placa[i];i++)if(strcmp(auxPlaca,placa[i])==0)return i;
     cout<<"ERROR, no se encontró la placa "<<auxPlaca<<endl;
    return -1;
}

void asignaFaltaALicencia(char **placa,int **falta,int **fecha,char *auxPlaca,
        int auxFech,int auxInfrac){
    int pos;
    pos=buscarPlaca(auxPlaca,placa);
    if(pos!=-1){
        asignarFaltaAPlaca(falta[pos],fecha[pos],auxFech,auxInfrac);
    }
}

void asignarFaltaAPlaca(int *falta,int *fecha,int auxFech,int auxInfrac){
    int num;
    num=falta[0];
    falta[num+1]=auxInfrac;
    fecha[num]=auxFech;
    (falta[0])++;
}
void leeDatos(ifstream &arch,int &auxLicen,char *&auxPlaca,int &auxFech,
        int &auxInfrac){
    arch>>auxLicen;
    if(arch.eof())return;
    char c;
    arch>>c;
    auxPlaca=leerCadena(arch,',');
    int dd,mm,aa;
    arch>>dd>>c>>mm>>c>>aa>>c>>auxInfrac;
    auxFech=dd+mm*100+aa*10000;
    
}

char *leerCadena(ifstream &arch,char c){
    char buff[150],*aux;
    arch.getline(buff,150,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

int hallaCantPlac(char **placa){
    int i;
    for(i=0;placa[i];i++);
    return i;
}

void gestaMemoria(int &numLic,int *numPlac,int*&licencia,char ***&placa,
        int ***&falta,int ***&fecha){
    int i,j;
    for(i=0;licencia[i];i++){
        numPlac[i]=hallaCantPlac(placa[i]);
    }
    falta = new int **[i+1]{};
    fecha = new int **[i+1]{};
    for(i=0;licencia[i];i++){
        falta[i] = new int *[numPlac[i]+1]{};
        fecha[i] = new int *[numPlac[i]+1]{};
        creaBuffs(falta[i],fecha[i],numPlac[i]);
    }
}

void creaBuffs(int **&falta,int **&fecha,int nd){
    for(int i=0;i<nd;i++){
        falta[i]= new int [40]{};
        fecha[i]= new int [40]{};
    }
}

void cargaInfracciones(int *&codInfracc,double *&precio){
    ifstream arch;
    AbrirArchivo("Infracciones.csv",arch);
    int buffCod[200],nd=0;
    double buffPrec[200];
    char c,buff[300];
    while(1){
        arch>>buffCod[nd];
        if(arch.eof())break;
        arch.get();
        arch.getline(buff,300,',');
        arch.getline(buff,300,',');
        arch>>buffPrec[nd];
        nd++;
    }
    codInfracc = new int [nd+1]{};
    precio = new double [nd+1]{};
    for(int i=0;i<nd;i++){
        codInfracc[i]=buffCod[i];
        precio[i]=buffPrec[i];
    }
    cout<<"hOLAAAAA";
}
void reporteFaltas(int*licencia,char **conductor,char ***placa,int ***falta
    ,int ***fecha){
    ofstream arch;
    AbrirArchivo("ReporteFaltas.txt",arch);
    int *codInfracc;
    double *precio;
    cargaInfracciones(codInfracc,precio);
    for(int i=0;licencia[i];i++){
        imprimeCaberaConductor(licencia[i],conductor[i],arch);
        imprimeFaltas(placa[i],fecha[i],falta[i],arch,codInfracc,precio);
    }
}

void  imprimeCaberaConductor(int licencia,char *conductor,ofstream &arch){
    arch<<setw(15)<<left<<"Conductor :"<<left<<conductor<<endl;
    arch<<setw(15)<<left<<"Licencia No.:"<<left<<licencia<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<"Infracciones cometidas:"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(15)<<left<<"No."<<setw(15)<<left<<"Placa"<<setw(18)<<left<<"Cantidad"
            <<setw(28)<<left<<"Monto Total a Pagar"<<setw(15)<<left<<"Fecha 1"
            <<setw(15)<<left<<"Fecha N"<<endl;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeFaltas(char **placa,int **fecha,int **falta ,ofstream &arch,
        int *codInfracc,double *precio){
    double monto;
    int fecha1,fecha2,num;
    for(int i=0;placa[i];i++){
        arch<<setw(2)<<right<<i+1<<")          "<<setw(22)<<left<<placa[i];
        if(falta[i]==nullptr){
            arch<<"ESTA PLACA NO REGISTRA INFRACCIONES"<<endl;
        }else{
            hallaFechasMonto(fecha[i],falta[i],monto,fecha1,fecha2,num,codInfracc,precio);
            arch<<setw(13)<<num<<setw(10)<<right<<setprecision(2)<<fixed<<
                    monto<<"                 ";
            imprimeFecha(fecha1,arch);
            arch<<"   ";
            imprimeFecha(fecha2,arch);
            arch<<endl;
        }
    }
}


void hallaFechasMonto(int *fecha,int *falta,double &monto,int &fecha1,
        int &fecha2,int &num,int *codInfracc,double *precio){
    num=falta[0];
    fecha1=fecha[0];
    fecha2=fecha[num-1];
    double parcial=0;
    for(int i=0;i<=num;i++){
        parcial+=hallaPrecio(falta[i],codInfracc,precio);
    }
    monto=parcial;
}
double hallaPrecio(int falta,int *codInfracc,double *precio){
    for(int i=0;codInfracc[i];i++){
        if(falta=codInfracc[i]){
            return precio[i];
        }
    }
    cout<<"NOT UWU :(";
    return 0;
}
void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<setfill(' ');
}