/* 
 * File:   BibliotecaMemoriaDinamica.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 21 de septiembre de 2022, 09:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaMemoriaDinamica.h"
#define MAXCANTLINEA 70
using namespace std;


void AbrirArchivosLectura(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se encontro el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivosEscritura(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se encontro el archivo "<<nomb;
        exit(1);
    }
}

char *leeCadena(ifstream &arch){
    char *cad,buff[100];
    arch.getline(buff,100);
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char *leeCadena(ifstream &arch,char c){
    char *cad,buff[100];
    arch.getline(buff,100,c);
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
//63736112,ZAMORA ZAVALETA RONAL MANUEL
//licencia, nombre
void cargarConductores(int *&licencia,char **&conductor){
    ifstream arch;
    AbrirArchivosLectura("Conductores.csv",arch);
    int numDat=0,lic,buffLic[200];
    char *cad,*buffConduc[200];
    while(1){
        arch>>lic;
        if(arch.eof())break;
        arch.get();
        cad=leeCadena(arch);
        buffLic[numDat]=lic;
        buffConduc[numDat]=cad;
        numDat++;
    }
    licencia = new int [numDat+1];
    conductor = new char *[numDat+1];
    for(int i=0;i<numDat;i++){
        licencia[i]=buffLic[i];
        conductor[i]=buffConduc[i];
    }
    licencia[numDat]=0;
    conductor[numDat] = nullptr;
}

void reporteConductores(int *licencia,char **conductor){
    ofstream arch;
    AbrirArchivosEscritura("ReporteConductores.txt",arch);
    for(int i=0;licencia[i];i++){
        arch<<setw(12)<<left<<licencia[i]<<left<<conductor[i]<<endl;
    }
}

char hallaGravedad(char *cad){
    if(strcmp(cad,"Leve")==0)return 'L';
    if(strcmp(cad,"Grave")==0)return 'G';
    return 'M';
}
void cargaInfracciones(int *&infraccion,char *&gravedad,double *&multa){
    ifstream arch;
    AbrirArchivosLectura("Infracciones.csv",arch);
    int numDat=0,infrac,buffInfrac[200];
    char cad[300],grav,buffGrav[200];
    double buffMulta[200],mult;
    while(1){
        arch>>infrac;
        if(arch.eof())break;
        arch.get();
        arch.getline(cad,300,',');
        arch.getline(cad,20,',');
        arch>>mult;
        buffInfrac[numDat]=infrac;
        buffGrav[numDat]=hallaGravedad(cad);
        buffMulta[numDat]=mult;
        numDat++;
    }
    infraccion = new int [numDat+1];
    gravedad = new char [numDat+1];
    multa = new double [numDat+1];
    
    for(int i=0;i<numDat;i++){
        infraccion[i]=buffInfrac[i];
        gravedad[i]=buffGrav[i];
        multa[i]=buffMulta[i];
    }
    infraccion[numDat]=0;
    gravedad[numDat]=0;
    multa[numDat]=0;
}

void reporteInfracciones(int *infraccion,char *gravedad,double *multa){
    ofstream arch;
    AbrirArchivosEscritura("ReporteInfracciones.txt",arch);
    for(int i=0;infraccion[i];i++){
        arch<<setw(10)<<left<<infraccion[i]<<setw(10)<<left<<gravedad[i]<<
                setw(10)<<right<<setprecision(2)<<fixed<<multa[i]<<endl;
    }
}

void reporteDeFaltas(int *licencia,char **conductor,int *infraccion,
        char *gravedad,double *multa){
    ifstream arch;
    ofstream archRep;
    AbrirArchivosLectura("RegistroDeFaltas.csv",arch);
    AbrirArchivosEscritura("ReporteDeFaltas.txt",archRep);
    imprimeFaltas(arch,licencia,conductor,infraccion,gravedad,multa,'L',archRep);
    imprimeFaltas(arch,licencia,conductor,infraccion,gravedad,multa,'G',archRep);
    imprimeFaltas(arch,licencia,conductor,infraccion,gravedad,multa,'M',archRep);
}

int leeFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    return dd+mm*100+aa*10000;
}

//81485316,J5T-691,24/12/2020,128
//licencia,plca,fecha,
void imprimeFaltas(ifstream &arch,int *licencia,char **conductor,int *infraccion,
        char *gravedad,double *multa, char grav,ofstream &archRep){
    arch.seekg(0,ios::beg);
    int lic,fecha,numDat=0,infrac,buffLic[500],buffCant[500]={};
    double buffMonto[500]={},mult,*monto;
    char **buffPlaca,*placa,**placas;
    int *NLicencia,*cantidad;
    buffPlaca = new char *[500];
    while(1){
        arch>>lic;
        if(arch.eof())break;
        arch.get();
        placa=leeCadena(arch,',');
        fecha=leeFecha(arch);
        arch.get();
        arch>>infrac;
        if(infraccionAcordeGravedad(infrac,grav,mult,multa,infraccion,gravedad)){
            agregaInfraccion(buffLic,buffCant,buffMonto,buffPlaca,numDat,
                    lic,placa,infrac,mult);
        }
        else free(placa);
    }
    NLicencia = new int [numDat+1];
    placas = new char *[numDat+1];
    cantidad = new int [numDat+1];       
    monto = new double [numDat+1];
    
    for(int i=0;i<numDat;i++){
        NLicencia[i] = buffLic[i];
        placas[i] = buffPlaca[i];
        cantidad[i] = buffCant[i];
        monto[i] = buffMonto[i];
    }
    arch.clear();
    NLicencia[numDat]=0;
    imprimeReporteFalta(NLicencia,placas,cantidad,monto,grav,archRep);
    limpiaMemoria(NLicencia,placas,cantidad,monto,numDat,buffPlaca);
}

int infraccionAcordeGravedad(int infrac,char grav,double &mult,double *multa,
        int *infraccion,char *gravedad){
    for(int i=0;infraccion[i];i++){
        if(infraccion[i]==infrac && gravedad[i]==grav){
            mult=multa[i];
            return 1;
        }
    }
    return 0;
}

void agregaInfraccion(int *buffLic,int *buffCant,double *buffMonto,
        char **&buffPlaca,int &numDat,int lic,char *placa,int infrac,double mult){
    int pos;
    if(existePlaca(placa,buffPlaca,numDat,pos)){
        buffCant[pos]++;
        buffMonto[pos]+=mult;
    }else{
        buffLic[numDat]=lic;
        buffCant[numDat]=1;
        buffMonto[numDat]=mult;
        buffPlaca[numDat]=placa;
        numDat++;
    }
}

int existePlaca(char *placa,char **buffPlaca,int numDat,int &pos){
    for(int i=0;i<numDat;i++){
        if(strcmp(placa,buffPlaca[i])==0){
            pos=i;
            return 1;
        }
    }
    return 0;
}

void imprimeReporteFalta(int *licencia,char **placas,int *cantidad,double *monto,
        char grav,ofstream &archRep){
    imprimeCabecera(grav,archRep);
    for(int i=0;licencia[i];i++){
        archRep<<setw(3)<<right<<setfill('0')<<i+1<<setfill(' ')<<")      "<<
                setw(18)<<left<<licencia[i]<<setw(12)<<left<<placas[i]<<setw(8)
                <<right<<cantidad[i]<<setw(15)<<right<<setprecision(2)<<fixed<<
                monto[i]<<endl;
    }
    imprimeLinea(archRep,MAXCANTLINEA,'*');
}

void imprimeCabecera(char grav,ofstream &archRep){
    if(grav=='L')archRep<<"FALTAS LEVES"<<endl;
    else if(grav=='G')archRep<<"FALTAS GRAVES"<<endl;
    else archRep<<"FALTAS MUY GRAVES"<<endl;
    imprimeLinea(archRep,MAXCANTLINEA,'=');
    archRep<<"No."<<setw(15)<<right<<"Licencia"<<setw(15)<<right<<"Placa"
            <<setw(18)<<right<<"Cantidad"<<setw(12)<<right<<"Monto"<<endl;
    imprimeLinea(archRep,MAXCANTLINEA,'-');
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void limpiaMemoria(int *&licencia,char **&placas,int *&cantidad,
        double *&monto,int numDat,char **&buffPlaca){
    delete licencia;
    delete cantidad;
    delete monto;
    delete buffPlaca;
    for(int i=0;i<=numDat;i++)delete placas[i];
}