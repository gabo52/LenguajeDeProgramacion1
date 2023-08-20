/* 
 * File:   BibManejoDinamicoDeMemoria.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de septiembre de 2022, 02:37 PM
 */


#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "BibManejoDinamicoDeMemoria.h"
#define INCREMENTO 5
#define MAXCANTLINEA 50
using namespace std;
//    char **conductor,***placa;
//    int *licencia,**falta;
//    double **multa;


void AbrirArchivoLectura(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivoEscritura(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){s
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[100];
    arch.getline(buff,100,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
//63736112,ZAMORA ZAVALETA RONAL MANUEL
//licencia, nombre
void cargaConductores(int *&licencia,char **&conductor){
    ifstream arch;
    AbrirArchivoLectura("Conductores.csv",arch);
    int numDat=0,cap=0,lic;
    char *nomb;
    licencia= nullptr;
    while(1){
        arch>>lic;
        if(arch.eof())break;
        arch.get();
        nomb=leerCadena(arch);
        if(numDat==cap)incrementarEspacios(licencia,conductor,numDat,cap);
        licencia[numDat-1]=lic;
        conductor[numDat-1]=nomb;
        numDat++;
    }
    
}

void incrementarEspacios(int *&lic,char **&conduc,int &numDat,int &cap){
    int *auxLic;
    char **auxConduc;
    cap+=INCREMENTO;
    if(lic==nullptr){
        lic=new int[cap]{};
        conduc=new char*[cap]{};
        numDat=1;
    }else{
        auxLic = new int[cap]{};
        auxConduc = new char*[cap]{};
        for(int i=0;i<numDat;i++){
            auxLic[i] =  lic[i];
            auxConduc[i] =  conduc[i];
        }
        delete lic;
        delete conduc;
        lic=auxLic;
        conduc=auxConduc;
    }
}
void reporteConductores(int *licencia,char **&conductor){
    ofstream archRep;
    AbrirArchivoEscritura("ReporteConductores.txt",archRep);
    archRep<<setw(12)<<left<<"LICENCIA"<<left<<"CONDUCTOR"<<endl;
    for(int i=0;licencia[i];i++){
        archRep<<setw(12)<<left<<licencia[i]<<left<<conductor[i]<<endl;
    }
}

// 81485316,J5T-691,24/12/2020,128
// licencia, placa , fecha, infraccion
void cargaFaltas(int *licencia,char ***&placa,int **&falta){
    ifstream arch;
    AbrirArchivoLectura("RegistroDeFaltas.csv",arch);
    int i,lic,infrac,pos;
    char buff[50],c,*placas;
    for(i=0;licencia[i];i++);
    placa = new char **[i+1]{};
    falta = new int *[i+1]{};
    int numDat[i+1]{},cap[i+1]{};
    while(1){
        arch>>lic>>c;
        if(arch.eof())break;
        placas=leerCadena(arch,',');
        arch.getline(buff,50,',');
        arch>>infrac;
        pos=buscarInt(lic,licencia);
        agregarFalta(placa[pos],falta[pos],numDat[pos],cap[pos],placas,infrac);
    }
    
}

int buscarInt(int dato,int *arr){
    for(int i=0;arr[i];i++)if(dato==arr[i])return i;
    cout<<"ERROR, no se encontro el dato"<<dato;
    exit(1);
}

void agregarFalta(char **&placa,int *&falta,int &numDat,int &cap,char *placas,
        int infrac){
    if(numDat==cap)incrementarFaltas(placa,falta,numDat,cap);
    placa[numDat-1]=placas;
    falta[numDat-1]=infrac;
    numDat++;
}

void incrementarFaltas(char **&placa,int *&falta,int &numDat,int &cap){
    char **auxPlac;
    int *auxFalta;
    cap+=INCREMENTO;
    if(placa==nullptr){
        placa = new char *[cap]{};
        falta = new int [cap]{};
        numDat=1;
    }else{
        auxPlac=new char *[cap]{};
        auxFalta=new int [cap]{};
        for(int i=0;i<numDat;i++){
            auxPlac[i]=placa[i];
            auxFalta[i]=falta[i];
        }
        delete placa;
        delete falta;
        falta=auxFalta;
        placa=auxPlac;
    }
}

void reporteFaltas(int *licencia,char **conductor,char ***placa,int **falta){
    ofstream archRep;
    AbrirArchivoEscritura("ReporteFaltas.txt",archRep);
    for(int i=0;licencia[i];i++){
        archRep<<setw(12)<<left<<"LICENCIA"<<left<<"CONDUCTOR"<<endl;
        archRep<<setw(12)<<left<<licencia[i]<<left<<conductor[i]<<endl;
        if(placa[i]){
            
            imprimeFaltas(placa[i],falta[i],archRep);
        }
    }
}

void imprimeFaltas(char **placa,int *falta,ofstream &archRep){
    archRep<<"No. "<<setw(10)<<left<<"PLACA"<<left<<"INFRACCION"<<endl;
    for(int i=0;placa[i];i++){
        archRep<<setw(3)<<right<<i+1<<" "<<setw(10)<<left<<placa[i]<<setw(10)<<left<<falta[i]<<endl;
    }
}



void resumenFaltas(int *licencia,int **falta,double **&multa){
    ifstream arch;
    AbrirArchivoLectura("Infracciones.csv",arch);
    int i;
    for(i=0;licencia[i];i++);
    multa = new double *[i+1]{};
    for(i=0;licencia[i];i++){
        hallarMultasLicencia(falta[i],multa[i],arch);
    }
}

void hallarMultasLicencia(int *falta,double *&multa,ifstream &arch){
    int i,j;
    if(falta==nullptr)return;
    multa=new double [3]{};
    double pago;
    for(i=0;falta[i];i++){
        pago=buscarMulta(falta[i],arch,j);
        multa[j]+=pago;
    }
}
//101,Adelantar o sobrepasar en forma indebida a otro vehículo.,Grave,316.00
//infracion,descripcion,gravedad,monto
double buscarMulta(int codFalta,ifstream &arch,int &i){
    arch.seekg(0,ios::beg);
    int infrac;
    char c;
    double valor;
    while(1){
        arch>>infrac>>c;
        if(arch.eof())break;
        if(infrac==codFalta){
            char buff[250];
            arch.getline(buff,250,',');
            arch.getline(buff,250,',');
            arch>>valor;
            if(strcmp(buff,"Leve")==0)i=0;
            else if(strcmp(buff,"Grave")==0)i=1;
            else i=2;
            return valor;
        }else while(arch.get()!='\n');
    }
    cout<<"ERROR, no se encontro la infraccion ", codFalta;
    exit(1);
}

void imprimeLinea(ofstream &archRep,int cant,char c){
    for(int i=0;i<cant;i++)archRep<<c;
    archRep<<endl;
}
void reporteMultas(int *licencia,char **conductor,double **multa){
    ofstream archRep;
    AbrirArchivoEscritura("ReporteMultas.txt",archRep);
    imprimeLinea(archRep,MAXCANTLINEA,'=');
    for(int i=0;licencia[i];i++){
        archRep<<setw(12)<<left<<"LICENCIA"<<left<<"CONDUCTOR"<<endl;
        imprimeLinea(archRep,MAXCANTLINEA,'=');
        archRep<<setw(12)<<left<<licencia[i]<<left<<conductor[i]<<endl;
        imprimeLinea(archRep,MAXCANTLINEA,'-');
        if(multa[i])imprimeMultas(multa[i],archRep);
        else archRep<<"No se registraron multas"<<endl;
        imprimeLinea(archRep,MAXCANTLINEA,'=');
    }
}
//Preguntar set precision
void imprimeMultas(double *multa,ofstream &arch){
    arch<<setw(20)<<left<<"Multas leves: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<multa[0]<<endl;
    arch<<setw(20)<<left<<"Multas graves: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<multa[1]<<endl;
    arch<<setw(20)<<left<<"Multas muy graves: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<multa[2]<<endl;
}