/* 
 * File:   FuncionesEx01_20201_Preg01.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de octubre de 2022, 05:43 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#define INCREMENTO 5
#define MAXCANTLINEA 100
using namespace std;
#include "FuncionesEx01_20201_Preg01.h"
//    char ***cursos,**profesores;
//    int *codProfesores;

void AbrirArchivo(const char *nombre, ifstream &arch){
    arch.open(nombre,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

void AbrirArchivo(const char *nombre, ofstream &arch){
    arch.open(nombre,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}
//IEE313,Microelectronica,Ingenieria Electronica
//Codcur,nomb,esp 
//20065927,Acuna Ayllon Blanca Luz
//CodProf, nombProf
void leerDatos(char ***&cursos,int *&codProfesores,char **&profesores){
    leerCargarProfesores(codProfesores,profesores);
    leerCargarCursos(cursos);
}

char * leerCadena(ifstream &arch,char c){
    char buff[150],*aux;
    arch.getline(buff,150,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
void leerCargarProfesores(int *&codProfesores,char **&profesores){
    int codigo,numDat=0,cap=0;
    char *nomb;
    ifstream arch;
    codProfesores= nullptr;
    AbrirArchivo("Profesores.csv",arch);
    while(1){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        nomb=leerCadena(arch);
        if(numDat==cap)incrementarProfesores(codProfesores,profesores,numDat,cap);
        codProfesores[numDat-1]=codigo;
        profesores[numDat-1]=nomb;
        numDat++;
    }
}

void incrementarProfesores(int *&codProfesores,char **&profesores,int &numDat,
        int &cap){
    cap+=INCREMENTO;
    if(codProfesores==nullptr){
        codProfesores = new int [cap]{};
        profesores = new char *[cap]{};
        numDat=1;
    }else{
        int *auxCodProf;
        char **auxProfesores;
        auxCodProf = new int [cap]{};
        auxProfesores = new char *[cap]{};
        for(int i=0;i<numDat;i++){
            auxCodProf[i]=codProfesores[i];
            auxProfesores[i]=profesores[i];
        }
        delete codProfesores;
        delete profesores;
        profesores=auxProfesores;
        codProfesores= auxCodProf;
    }
}

void leerCargarCursos(char ***&cursos){
    ifstream arch;
    char *cod,*nombCur,*esp;
    int numDat=0,cap=0;
    cursos = nullptr;
    AbrirArchivo("Cursos.csv",arch);
    while(1){
        cod=leerCadena(arch,',');
        if(arch.eof())break;
        nombCur=leerCadena(arch,',');
        esp=leerCadena(arch);
        if(numDat==cap)incrementarCursos(cursos,numDat,cap);
        agregaDatosCurso(cursos[numDat-1],cod,nombCur,esp);
        numDat++;
    }
}

void agregaDatosCurso(char **&curso,char *cod,char *nombCur,char *esp){
    char **aux;
    aux = new char *[3];
    aux[0]=cod;
    aux[1]=nombCur;
    aux[2]=esp;
    curso=aux;
}
void incrementarCursos(char ***&cursos,int &numDat,
        int &cap){
    cap+=INCREMENTO;
    if(cursos==nullptr){
        cursos = new char **[cap]{};
        numDat=1;
    }else{
        char ***auxCursos;
        auxCursos = new char **[cap]{};
        for(int i=0;i<numDat;i++){
            auxCursos[i]=cursos[i];
        }
        delete cursos;
        cursos=auxCursos;
    }
}

void imprimeCabeceraCursos(ofstream &arch){
    arch<<setw(70)<<right<<"CURSOS DE LA INSTITUCION"<<endl;
    arch<<"   "<<setw(10)<<left<<"CODIGO"<<setw(50)<<left<<"CURSO"<<left
            <<"ESPECIALIDAD"<<endl;
}

void imprimeCurso(int i,char **cursos,ofstream &arch){
    arch<<setw(2)<<right<<i<<") "<<setw(10)<<left<<cursos[0]<<setw(50)<<left<<cursos[1]<<left
            <<cursos[2]<<endl;
}
void imprimeCabeceraProfesores(ofstream &arch){
    arch<<setw(58)<<right<<"PROFESORES DE LA INSTITUCION"<<endl;
    arch<<"   "<<setw(10)<<left<<"CODIGO"<<left<<"NOMBRE"<<endl;
}
void imprimirDatos(char ***cursos,int *codProfesores,char **profesores){
    ofstream arch;
    AbrirArchivo("ReporteProfesoresYCursos.txt",arch);
    imprimeCabeceraCursos(arch);
    for(int i=0;cursos[i];i++){
        imprimeCurso(i+1,cursos[i],arch);
    }
    imprimeCabeceraProfesores(arch);
    for(int i=0;codProfesores[i];i++){
        imprimeProfesor(i+1,codProfesores[i],profesores[i],arch);
    }
}

void imprimeProfesor(int i,int codigo,char *nombProf,ofstream &arch){
     arch<<setw(2)<<right<<i<<") "<<setw(10)<<left<<codigo<<left<<nombProf<<endl;
}