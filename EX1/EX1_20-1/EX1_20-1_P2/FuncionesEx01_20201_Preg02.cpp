/* 
 * File:   FuncionesEx01_20201_Preg02.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de octubre de 2022, 06:36 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesEx01_20201_Preg02.h"
#include <cstring>
#include <fstream>
#define INCREMENTO  5
#define MAXCANTLINEA 100
using namespace std;
//MIN269    H0990   16           20065927   4   19:44   22:39   2   16:4    19:0
//codCur   codHor  cantAlum     codProf     (dia horaIni horaFin)
void leerSesiones(void *&sesi){
    ifstream arch;
    arch.open("Sesiones.txt",ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo Sesiones.txt";
        exit(1);
    }
    void **sesiones,*descSesiones;
    sesiones = (void **)sesi;
    sesiones = nullptr;
    char *codCur,*codHor;
    int cantAlum,codProf,numDat=0,cap=0;
    while(1){
        codCur=leerCadenaTxt(arch);
        if(arch.eof())break;
        codHor=leerCadenaTxt(arch);
        arch>>cantAlum>>codProf;
        if(numDat==cap)incrementarSesiones(sesiones,numDat,cap);
        descSesiones = hallarDescripcionSesiones(arch);
        asignarSesiones(sesiones[numDat-1],codCur,codHor,cantAlum,codProf,descSesiones);
        //imprimeReg(sesiones[numDat-1]);
        numDat++;
    }
    sesi=sesiones;
}

void imprimeReg(void *sesi){
    void **sesiones;
    char *codCur;
    sesiones=(void **)sesi;
    codCur=(char*)sesiones[0];
    cout<<codCur<<endl;
}
void asignarSesiones(void *&sesi,char *codCur,char *codHor,int cantAlum,
        int codProf, void *descSesiones){
    void **sesiones;
    sesiones = (void **)sesi;
    sesiones = new void *[5];
    int *cant1= new int,*cod = new int;
    *cant1=cantAlum;
    *cod=codProf;
    sesiones[0]=codCur;
    sesiones[1]=codHor;
    sesiones[2]=cant1;
    sesiones[3]=cod;
    sesiones[4]=descSesiones;
    cout<<codCur<<"   "<<codHor<<"   "<<*cant1<<"   "<<*cod<<endl;
    sesi=sesiones;
}
void incrementarEspacioDescripcionSesiones(void **&descSesiones,int &numDat,int &cap){
    void **aux;
    cap+=INCREMENTO;
    if(descSesiones==nullptr){
        descSesiones = new void *[cap]{};
        numDat=1;
    }else{
        aux = new void *[cap]{};
        for(int i=0;i<numDat;i++)aux[i]=descSesiones[i];
        delete descSesiones;
        descSesiones=aux;
    }
}
void *hallarDescripcionSesiones(ifstream &arch){
    int dia;
    int Hi,Mi,Hf,Mf;
    void **descSesiones;
    int numDat=0,cap=0;
    char c;
    descSesiones = nullptr;
    while((arch.get()!='\n')&&(!arch.eof())){
        arch>>dia;
        arch>>Hi>>c>>Mi>>Hf>>c>>Mf;
        if(numDat==cap)incrementarEspacioDescripcionSesiones(descSesiones,numDat,cap);
        asignarDescripcionASesion(dia,Hi,Mi,Hf,Mf,descSesiones[numDat-1]);
        numDat++;
    }
    return descSesiones;
}

void asignarDescripcionASesion(int &dia,int &Hi,int &Mi,int &Hf,int &Mf,
        void *&descSesiones){
    int *combinado= new int;
    *combinado=dia*100000000+Hi*1000000+Mi*10000+Hf*100+Mf;
    descSesiones=combinado;
}
void incrementarSesiones(void **&sesiones,int &numDat,int &cap){
    void **aux;
    cap+=INCREMENTO;
    if(sesiones==nullptr){
        sesiones = new void *[cap]{};
        numDat=1;
    }else{
        aux = new void *[cap]{};
        for(int i=0;i<numDat;i++)aux[i]=sesiones[i];
        delete sesiones;
        sesiones = aux;
    }
}

char * leerCadenaTxt(ifstream &arch){
    char buff[150],*aux;
    arch>>buff;
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void imprimirSesiones(void *&sesi){
    ofstream arch;
    arch.open("ReporteSesiones.txt",ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo ReporteSesiones.txt";
        exit(1);
    }
    void **sesiones=(void**)sesi;
    arch<<setw(60)<<right<<"SESIONES DE CLASE"<<endl;
    for(int i=0;sesiones[i];i++){
        imprimirSesion(sesiones[i],arch,i+1);
        arch<<endl;
    }
}

void imprimirSesion(void *sesi,ofstream &arch,int i){
    void **sesiones=(void**)sesi;
    imprimirCabeceraSesion(sesiones,arch,i);
    if(sesiones[4])imprimirClases(sesiones[4],arch);
    else arch<<"    No se registraron sesiones"<<endl;
    
}

void imprimirClases(void *sesi,ofstream &arch){
    int *num;
    void **sesiones=(void **)sesi;
    for(int i=0;sesiones[i];i++){
        num=(int *)sesiones[i];
        imprimeDiaSesion(*num,arch);
    }
}

void imprimeDiaSesion(int num,ofstream &arch){
    int dd,Hi,Hf,Mi,Mf;
    Mf=num%100;
    num/=100;
    Hf=num%100;
    num/=100;
    Mi=num%100;
    num/=100;
    Hi=num%100;
    num/=100;
    dd=num;
    arch<<"     ";
    imprimeDia(dd,arch);
    arch<<setfill('0')<<setw(2)<<right<<Hi<<":"<<setw(2)<<right<<Mi<<setfill(' ');
    arch<<"     ";
    arch<<setfill('0')<<setw(2)<<right<<Hf<<":"<<setw(2)<<right<<Mf<<setfill(' ');
    arch<<endl;
}
void imprimeDia(int dd,ofstream &arch){
    switch(dd){
        case 1:
            arch<<setw(10)<<left<<"DOMINGO";
            break;
        case 2:
            arch<<setw(10)<<left<<"LUNES";
            break;
        case 3:
            arch<<setw(10)<<left<<"MARTES";
            break;
        case 4:
            arch<<setw(10)<<left<<"MIERCOLES";
            break;
        case 5:
            arch<<setw(10)<<left<<"JUEVES";
            break;
        case 6:
            arch<<setw(10)<<left<<"VIERNES";
            break;
        case 7:
            arch<<setw(10)<<left<<"SABADO";
            break;
    }
}

void imprimirCabeceraSesion(void **sesiones,ofstream &arch,int i){
    char *codCur,*codHor;
    int *cantAlum,*codProf;
    codCur=(char*)sesiones[0];
    codHor=(char*)sesiones[1];
    cantAlum=(int*)sesiones[2];
    codProf=(int*)sesiones[3];
    arch<<setw(2)<<right<<i<<")  "<<setw(10)<<left<<"CODIGO:  "<<setw(10)<<left<<codCur
            <<setw(10)<<left<<"HORARIO:  "<<setw(10)<<left<<codHor
            <<setw(10)<<left<<"No.Alumnos:  "<<setw(10)<<left<<*cantAlum<<
            setw(10)<<left<<"PROFESOR  "<<setw(10)<<left<<*codProf<<endl;
    arch<<"     SESIONES:"<<endl;
}