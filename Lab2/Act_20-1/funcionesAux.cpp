/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iomanip>
#include <iostream>
#include <fstream>

#include "funcionesAux.h"
#define MAXCANTLINEA 140
using namespace std;

ofstream AbrirArchE(const char *nombre,char modo){
    ofstream arch;
    if(modo=='T')arch.open(nombre,ios::out);
    else arch.open(nombre,ios::out|ios::binary);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo: "<<nombre;
        exit(1);
    }
    return arch;
}

ifstream AbrirArchL(const char *nombre,char modo){
    ifstream arch;
    if(modo=='T')arch.open(nombre,ios::in);
    else arch.open(nombre,ios::in|ios::binary);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo: "<<nombre;
        exit(1);
    }
    return arch;
}

fstream AbrirArchA(const char *nombre,char modo){
    fstream arch;
    if(modo=='T')arch.open(nombre,ios::in|ios::out);
    else arch.open(nombre,ios::in|ios::binary|ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo: "<<nombre;
        exit(1);
    }
    return arch;
}

void cargaRegAlumnosBin(ofstream &arch,char tipo,int carnet,char *nombre,
        int carnetExtranjeria,char *especialidad,char *facultad){
    arch.write(reinterpret_cast<const char*>(&tipo),sizeof(char));
    arch.write(reinterpret_cast<const char*>(&carnet),sizeof(int));
    arch.write(reinterpret_cast<const char*>(nombre),sizeof(char)*50);
    arch.write(reinterpret_cast<const char*>(&carnetExtranjeria),sizeof(int));
    arch.write(reinterpret_cast<const char*>(especialidad),sizeof(char)*30);
    arch.write(reinterpret_cast<const char*>(facultad),sizeof(char)*5);
}

void crearCargarAlumnosBin(){
    ifstream arch=AbrirArchL("Alumnos.txt",'T');
    ofstream archBin=AbrirArchE("Alumnos.bin",'B');
    char tipo,nombre[50],facultad[5],especialidad[30];
    int carnetExtranjeria,carnet,dato;
    while(1){
        arch>>tipo>>carnet>>nombre;
        if(arch.eof())break;
        arch>>dato;
        if(arch.fail()){
            arch.clear();
            carnetExtranjeria=0;
        }
        carnetExtranjeria=dato;
        arch>>especialidad>>facultad;
        cargaRegAlumnosBin(archBin,tipo,carnet,nombre,carnetExtranjeria,
                especialidad,facultad);
    }
}

void obtenerDatosAlumnos(int &carnet,char *nombre,char *facultad,int &codigo,
        ifstream &archBin){
    char tipo,especialidad[30];
    int carnetExtranjeria,codigo1;
    archBin.seekg(0,ios::beg);
    while(1){
        leerRegAlumBin(archBin,tipo,codigo1,nombre,carnetExtranjeria,especialidad,
                facultad);
        if(archBin.eof())break;
        if(codigo==codigo1){
            archBin.seekg(0,ios::beg);
            carnet=carnetExtranjeria;
            return ;
        }
    }
    archBin.seekg(0,ios::beg);
}

void cargaRegConsolidadoBin(int codigo,char *nombre,double cantCredCur,
        double cantCredAprob,int sumNot,int cantCurMat,char *facultad,int estado,
        fstream &arch){
    arch.seekg(0,ios::end);
    arch.clear();
    arch.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
    arch.write(reinterpret_cast<const char*>(nombre),sizeof(char)*50);
    arch.write(reinterpret_cast<const char*>(&cantCredCur),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&cantCredAprob),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&sumNot),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantCurMat),sizeof(int));
    arch.write(reinterpret_cast<const char*>(facultad),sizeof(char)*5);
    arch.write(reinterpret_cast<const char*>(&estado),sizeof(int));
    arch.flush();
    arch.seekg(0,ios::beg);
}

void leerRegConsolidadoBin(ifstream &arch,int &codigo,char *nombre,
        double &cantCredCur,double &cantCredAprob,
                int &sumNot,int &cantMat,char *facultad,int &estado){
    arch.read(reinterpret_cast<char *>(&codigo),sizeof(int));
    arch.read(reinterpret_cast<char *>(nombre),sizeof(char)*50);
    arch.read(reinterpret_cast<char *>(&cantCredCur),sizeof(double));
    arch.read(reinterpret_cast<char *>(&cantCredAprob),sizeof(double));
    arch.read(reinterpret_cast<char *>(&sumNot),sizeof(int));
    arch.read(reinterpret_cast<char *>(&cantMat),sizeof(int));
    arch.read(reinterpret_cast<char *>(facultad),sizeof(char)*5);
    arch.read(reinterpret_cast<char *>(&estado),sizeof(int));
}

void leerRegConsolidadoBinActu(fstream &arch,int &codigo,char *nombre,
        double &cantCredCur,double &cantCredAprob,
                int &sumNot,int &cantMat,char *facultad,int &estado){
    cout<<" 2";
    arch.read(reinterpret_cast<char *>(&codigo),sizeof(int));
    arch.read(reinterpret_cast<char *>(nombre),sizeof(char)*50);
    arch.read(reinterpret_cast<char *>(&cantCredCur),sizeof(double));
    arch.read(reinterpret_cast<char *>(&cantCredAprob),sizeof(double));
    arch.read(reinterpret_cast<char *>(&sumNot),sizeof(int));
    arch.read(reinterpret_cast<char *>(&cantMat),sizeof(int));
    arch.read(reinterpret_cast<char *>(facultad),sizeof(char)*5);
    arch.read(reinterpret_cast<char *>(&estado),sizeof(int));
    cout<<" 1";
}

int buscarCodigo(int cod,fstream &arch){
    int codigo,nota,cantAlumReg=0,cantAlumInter=0,cantAlumIntSC=0,cantEgresados=0;
    int sumNot,cantMat,estado,i=0;
    double cantCredCur,cantCredAprob;
    char codCur[10],ciclo[8],facultad[5],nombre[50];
    arch.seekg(0,ios::beg);
    arch.clear();
    while(1){
        cout<<"Llegue";
        leerRegConsolidadoBinActu(arch,codigo,nombre,cantCredCur,cantCredAprob,
                sumNot,cantMat,facultad,estado);
        cout<<codigo<<endl;
        if(arch.eof())break;
        if(codigo==cod){
            arch.seekg(0,ios::beg);
            return i;
        }
        i++;
    }
    arch.seekg(0,ios::beg);
    return -1;
}

void actualizaReg(fstream &arch,int pos,int nota,double creditos){
    int size=sizeof(int)*4+sizeof(char)*55+sizeof(double)*2;
    arch.seekg(size*pos,ios::beg);
    int codigo,cantAlumReg=0,cantAlumInter=0,cantAlumIntSC=0,cantEgresados=0;
    int sumNot,cantMat,estado,i=0;
    double cantCredCur,cantCredAprob;
    char codCur[10],ciclo[8],facultad[5],nombre[50];
    leerRegConsolidadoBinActu(arch,codigo,nombre,cantCredCur,cantCredAprob,
                sumNot,cantMat,facultad,estado);
    arch.seekg(size*pos,ios::beg);
    if(nota>=11)cantCredAprob+=creditos;
    cantCredCur+=creditos;
    sumNot+=nota;
    cantMat++;
    if(cantCredAprob>45)estado=1;
    arch.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
    arch.write(reinterpret_cast<const char*>(nombre),sizeof(char)*50);
    arch.write(reinterpret_cast<const char*>(&cantCredCur),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&cantCredAprob),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&sumNot),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantMat),sizeof(int));
    arch.write(reinterpret_cast<const char*>(facultad),sizeof(char)*5);
    arch.write(reinterpret_cast<const char*>(&estado),sizeof(int));
    arch.flush();
}

void abrirArch(){
    ofstream arch1=AbrirArchE("Consolidado.bin",'B');
    arch1.close();
}
void crearCargarConsolidadosBin(){
    ifstream arch=AbrirArchL("Cursos.txt",'T');
    ifstream archAlumBin=AbrirArchL("Alumnos.bin",'B');
    abrirArch();
    fstream archBin=AbrirArchA("Consolidado.bin",'B');
    int codigo,nota,carnet,pos;
    double cantCred;
    char codCur[10],ciclo[8],nombre[50],facultad[5];
    archBin.seekg(0,ios::beg);
    while(1){
        arch>>codigo;
        if(arch.eof())break;
        arch>>codCur>>nota>>ciclo>>cantCred;
        obtenerDatosAlumnos(carnet,nombre,facultad,codigo,archAlumBin);
        pos=buscarCodigo(codigo,archBin);
        if(pos!=-1){
            actualizaReg(archBin,pos,nota,cantCred);
        }else{
            cargaRegConsolidadoBin(codigo,nombre,0,0,0,0,facultad,0,archBin);
        }
    }
}

void imprimeLinea(char c,int cantidad,ofstream &arch){
    for(int i=0;i<cantidad;i++)arch<<c;
    arch<<endl;
}
void imprimeCabeceraRep(ofstream &archRep){
    archRep<<left<<"CONSOLIDAD DE NOTAS DE LOS ALUMNOS"<<endl;
    imprimeLinea('=',MAXCANTLINEA,archRep);
    archRep<<setw(10)<<left<<"CODIGO"<<setw(50)<<left<<"NOMBRE"<<setw(15)<<left<<
            "CARNE"<<setw(16)<<left<<"CRED. CURSADOS"<<setw(18)<<left
            <<"CRED. APROBADOS"<<setw(15)<<left<<"PROMEDIO"<<left<<"ESTADO"<<endl;
    imprimeLinea('=',MAXCANTLINEA,archRep);
}

void imprimeResumen(int cantAlumReg,int cantAlumInter,int cantAlumIntSC,
        int cantEgresados,ofstream &arch){
    imprimeLinea('=',MAXCANTLINEA,arch);
    arch<<"RESUMEN :"<<endl;
    arch<<setw(35)<<left<<"TOTAL DE ALUMNOS REGULARES:"<<setw(5)<<right
            <<cantAlumReg<<endl;
    arch<<setw(35)<<left<<"TOTAL DE ALUMNOS DE INTERCAMBIO:"<<setw(5)<<right
            <<cantAlumInter<<endl<<endl;
    arch<<setw(35)<<left<<"EGRESADOS:"<<setw(5)<<right
            <<cantEgresados<<endl;
    arch<<setw(35)<<left<<"ALUMNOS DE INTERCAMBIO SIN CARNE:"<<setw(5)<<right
            <<cantAlumIntSC<<endl;
    imprimeLinea('=',MAXCANTLINEA,arch);
}



void leerRegAlumBin(ifstream &arch,char &tipo,int &carnet,char *nombre,
        int &carnetExtranjeria,char *especialidad,char *facultad){
    arch.read(reinterpret_cast<char*>(&tipo),sizeof(char));
    arch.read(reinterpret_cast<char*>(&carnet),sizeof(int));
    arch.read(reinterpret_cast<char*>(nombre),sizeof(char)*50);
    arch.read(reinterpret_cast<char*>(&carnetExtranjeria),sizeof(int));
    arch.read(reinterpret_cast<char*>(especialidad),sizeof(char)*30);
    arch.read(reinterpret_cast<char*>(facultad),sizeof(char)*5);
}

int hallarCarnet(ifstream &arch,int codigo,char &tipo){
    char nombre[50],facultad[5],especialidad[30];
    int carnetExtranjeria,carnet;
    arch.seekg(0,ios::beg);
    while(1){
        leerRegAlumBin(arch,tipo,carnet,nombre,carnetExtranjeria,especialidad,
                facultad);
        if(arch.eof())break;
        if(carnet==codigo){
            arch.seekg(0,ios::beg);
            if(carnetExtranjeria!=0)return carnetExtranjeria;
            else return 0;
        }
    }
    arch.clear();
    arch.seekg(0,ios::beg);
    return 0;
}
void imprimeRegConsolidadoBin(ofstream &arch,int &codigo,char *nombre,
        double &cantCredCur,double &cantCredAprob,int &sumNot,int &cantMat,
        char *facultad,int estado,ifstream &archAlum,int &cantAlumReg,
        int &cantAlumInt,int &cantAlumIntSC){
    int carnet;
    double valor;
    char tipo;
    if(cantCredCur==0)valor=0;
    else valor=sumNot/((double)cantCredCur);
    arch<<setw(10)<<left<<codigo<<setw(50)<<left<<nombre;
    carnet=hallarCarnet(archAlum,codigo,tipo);
    if(tipo=='I')cantAlumInt++;
    else cantAlumReg++;
    
    if(carnet!=0){
        arch<<setw(10)<<left<<carnet;
        if(tipo=='I')cantAlumIntSC++;
    }
    else {
        arch<<setw(10)<<left<<" ";
        
    }
    arch<<setw(14)<<right<<setprecision(2)<<fixed<<cantCredCur;
    arch<<setw(16)<<right<<setprecision(2)<<fixed<<cantCredAprob;
    arch<<setw(16)<<right<<setprecision(2)<<fixed<<valor;
    arch<<"      ";
    if(estado==0)arch<<left<<"NO EGRESADO"<<endl;
    else arch<<left<<"EGRESADO"<<endl;
}

void  imprimeRepConsolidadoBin(){
    ifstream arch=AbrirArchL("Consolidado.bin",'B');
    ifstream archAlum=AbrirArchL("Alumnos.bin",'B');
    ofstream archRep=AbrirArchE("ReporteConsolidado.txt",'T');
    int codigo,nota,cantAlumReg=0,cantAlumInter=0,cantAlumIntSC=0,cantEgresados=0;
    int sumNot,cantMat,estado;
    double cantCredCur,cantCredAprob;
    char codCur[10],ciclo[8],facultad[5],nombre[50];
    imprimeCabeceraRep(archRep);
    while(1){
        leerRegConsolidadoBin(arch,codigo,nombre,cantCredCur,cantCredAprob,
                sumNot,cantMat,facultad,estado);
        if(estado==1)cantEgresados++;
        if(arch.eof())break;
        imprimeRegConsolidadoBin(archRep,codigo,nombre,cantCredCur,cantCredAprob,
                sumNot,cantMat,facultad,estado,archAlum,cantAlumReg,cantAlumInter,cantAlumIntSC);
    }
    imprimeResumen(cantAlumReg,cantAlumInter,cantAlumIntSC,cantEgresados,archRep);
}