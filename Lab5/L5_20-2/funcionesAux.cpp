/* 
 * File:   funcionesAux.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de septiembre de 2022, 04:57 PM
 */

#include <iostream>
#include <iomanip> 
#include <fstream>
#include <cstring>
#include "funcionesAux.h"
#define MAXCANTLINEA 100
#define INCREMENTO 10
using namespace std;

//    char **codMed,**nombMed,***nomPac;
//    int **codPac,**veces;
//    double *tarifas,**porcPac;


void AbrirArchivoLectura(const char *nombre,ifstream &arch){
    arch.open(nombre,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

void AbrirArchivoEscritura(const char *nombre,ofstream &arch){
    arch.open(nombre,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[200];
    arch.getline(buff,200,c);
    aux=new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
//EN4313,Zamora Cabrera Carmen,Endocrinologia,445.12
void leerMedicos(char **&codMed,char **&nombMed,double *&tarifas){
    ifstream arch;
    AbrirArchivoLectura("RelacionMedicos.csv",arch);
    int numDat=0,cap=0;
    double tarif;
    char *nomb,*cod,buff[100];
    codMed=nullptr;
    while(1){
        cod=leerCadena(arch,',');
        if(arch.eof())break;
        nomb=leerCadena(arch,',');
        arch.getline(buff,100,',');
        arch>>tarif;
        arch.get();
        if(cap==numDat)incrementarEspacios(codMed,nombMed,tarifas,numDat,cap);
        //preguntar si es necesario el = 0 y = nullptr 
        codMed[numDat-1]=cod;
        nombMed[numDat-1]=nomb;
        tarifas[numDat-1]=tarif;
        numDat++;
    }
}
//no usar el & al pasar por referencia

//preguntar lineas
void incrementarEspacios(char **&codMed,char **&nombMed,double *&tarifas, 
        int &numDat,int &cap){
    char **auxCodMed,**auxNombMed;
    double *auxTarif;
    cap+=INCREMENTO;
    if(codMed==nullptr){
        codMed = new char *[cap]{};
        nombMed = new char *[cap]{};
        tarifas = new double[cap]{};
        numDat=1;
    }else{
        auxCodMed = new char *[cap]{};
        auxNombMed = new char *[cap]{};
        auxTarif = new double[cap]{};
        for(int i=0;i<numDat;i++){
            auxCodMed[i]=codMed[i];
            auxNombMed[i]=nombMed[i];
            auxTarif[i]=tarifas[i];
        }
        delete codMed;
        delete nombMed;
        delete tarifas;
        codMed=auxCodMed;
        nombMed=auxNombMed;
        tarifas=auxTarif;
    }
}
void repMedicos(char **codMed,char **nombMed,double *tarifas){
    ofstream arch;
    AbrirArchivoEscritura("ReporteMedicos.txt",arch);
    arch<<setw(10)<<left<<"CODIGO"<<setw(50)<<left<<"NOMBRE"<<setw(10)
        <<right<<"TARIFA"<<endl;
    for(int i=0;codMed[i];i++){
        arch<<setw(10)<<left<<codMed[i]<<setw(50)<<left<<nombMed[i]<<setw(10)
                <<right<<setprecision(2)<<fixed<<tarifas[i]<<endl;
    }
}

//1/01/2020,R,891472,Virginia Chumpitaz,9.33,GI8983,A,850963,Rafael Urbina,10.7
//fecha estado,codigo,nombre,porcentajeTarif,codMed
void leerAtenciones(char **&codMed,int **&codPac,char ***&nombPac,
        double **&porcPac,int **&veces){
    ifstream arch;
    AbrirArchivoLectura("Pacientes-Atencion.csv",arch);
    int fecha,i;
    codPac=nullptr;
    for(i=0;codMed[i];i++);
    int numDat[i+1]={0},cap[i+1]={0};
    codPac = new int *[i+1]{}; 
    nombPac = new char **[i+1]{}; 
    porcPac = new double *[i+1]{}; 
    veces = new int *[i+1]{};
    while(true){
        fecha=leerFecha(arch);
        arch.get();
        if(arch.eof())break;
        leerAtencionesFecha(codMed,codPac,nombPac,porcPac,veces,arch,numDat,cap,fecha);
    }
}
//preguntar si se puede hacer un ptrnull dentro del arreglo ya creado
void leerAtencionesFecha(char **codMed,int **&codPac,char ***&nombPac,double **&porcPac,
        int **&veces,ifstream &arch,int *numDat,int *cap,int fecha){
    char c,estado,codM[7],*nomb;
    int codigo,pos,aux,i,flag=0,dato;
    double porc;
    while(1){
        arch>>estado>>c;
        if(arch.eof()||flag)break;
        arch>>codigo>>c;
        nomb=leerCadena(arch,',');
        arch>>porc>>c;
        arch.get(codM,7,',');
        codM[6]=0;
        pos=buscarMed(codM,codMed);
        cargarAtencionPacienteAMedico(codPac[pos],nombPac[pos],porcPac[pos],
                veces[pos],codigo,nomb,estado,porc,numDat[pos],cap[pos]);
        if(arch.get()=='\n')break;
    }
}

void cargarAtencionPacienteAMedico(int *&codPac,char **&nombPac,double *&porcPac,
                int *&veces,int codigo,char *nomb,char estado,double porc,
        int &numDat,int &cap){
    if(numDat==cap)incrementarEspaciosPac(codPac,nombPac,porcPac,veces,numDat,cap);
    codPac[numDat-1]=codigo;
    nombPac[numDat-1]=nomb;
    porcPac[numDat-1]=porc;
    veces[numDat-1]++;
    numDat++;
}

void incrementarEspaciosPac(int *&codPac,char **&nombPac,double *&porcPac,
        int *&veces,int &numDat,int &cap){
    int *auxCodPac,*auxVeces;
    char **auxNombPac;
    double *auxPorcPac;
    cap+=INCREMENTO;
    if(codPac==nullptr){
        codPac = new int [cap]{};
        nombPac = new char *[cap]{};
        porcPac = new double[cap]{};
        veces = new int[cap]{};
        numDat=1;
    }else{
        auxCodPac = new int [cap]{};
        auxNombPac = new char *[cap]{};
        auxPorcPac = new double[cap]{};
        auxVeces = new int[cap]{};
        for(int i=0;i<numDat;i++){
            auxCodPac[i]=codPac[i];
            auxNombPac[i]=nombPac[i];
            auxPorcPac[i]=porcPac[i];
            auxVeces[i]=veces[i];
        }
        delete codPac;
        delete nombPac;
        delete porcPac;
        delete veces;
        codPac = auxCodPac;
        nombPac = auxNombPac;
        porcPac = auxPorcPac;
        veces = auxVeces;
    }
}

int buscarMed(char *codMedico,char **codMed){
    for(int i=0;codMed[i];i++){
        if(strcmp(codMedico,codMed[i])==0)return i;
    }
    cout<<"ERROR";
    return -1;
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    return dd+mm*100+aa*10000;
}

void imprimeMedico(char *codMed,char*nombMed,double tarifa,int *codPac,
        char **nomPac,double *porcPac,int *veces,ofstream &arch){
    int totCit=0;
    double recibido=0;
    arch<<"Medico:  "<<left<<nombMed<<endl;
    arch<<"Codigo:  "<<left<<codMed<<endl;
    arch<<"Honorarios por cita: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<tarifa<<endl;
    imprimirLinea(arch,MAXCANTLINEA,'=');
    arch<<"Pacientes atendidos: "<<endl;
    imprimirLinea(arch,MAXCANTLINEA,'-');
    arch<<"No."<<setw(15)<<"Paciente"<<setw(8)<<right<<"Veces"
            <<setw(8)<<right<<"Pago"<<setw(20)<<"Seguro"<<endl;
    for(int i=0;codPac[i];i++){
        arch<<setw(2)<<right<<i+1<<")"<<setw(15)<<right<<codPac[i]<<setw(10)<<
                right<<veces[i]<<setw(10)<<right<<setprecision(2)<<fixed<<
                tarifa*veces[i]<<setw(15)<<right<<setprecision(2)<<fixed<<
                tarifa*veces[i]-tarifa*veces[i]*porcPac[i]/100<<endl;
        totCit+=veces[i];
        recibido+=(tarifa*veces[i]*porcPac[i]/100);
    }
    imprimeResumen(totCit,totCit*tarifa,recibido,arch);
}

void imprimeResumen(int totCit,double pago,double recibido,ofstream &arch){
    imprimirLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(40)<<left<<"Monto total recibido por pacientes: "<<setw(10)
            <<right<<setprecision(2)<<fixed<<recibido<<endl;
    arch<<setw(40)<<left<<"Monto a solicitar al seguro: "<<setw(10)
            <<right<<setprecision(2)<<fixed<<pago-recibido<<endl;
    arch<<setw(40)<<left<<"Total de citas atendidas: "<<setw(7)
            <<right<<totCit<<endl;
    imprimirLinea(arch,MAXCANTLINEA,'=');
}

void repDeIngresos(char **codMed,char **nombMed,double *tarifas,int **codPac,
        char ***nomPac,double **porcPac,int **veces){
    ofstream archRep;
    ifstream arch;
    char codigo[10];
    int pos;
    AbrirArchivoEscritura("ReporteDeIngresos.txt",archRep);
    AbrirArchivoLectura("Medicos.csv",arch);
    while(1){
        arch>>codigo;
        if(arch.eof())break;
        pos=buscarMed(codigo,codMed);
        imprimeMedico(codMed[pos],nombMed[pos],tarifas[pos],codPac[pos],
                nomPac[pos],porcPac[pos],veces[pos],archRep);
    }
}

void imprimirLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
