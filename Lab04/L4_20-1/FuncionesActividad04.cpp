/* 
 * File:   FuncionesActividad04.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 18 de septiembre de 2022, 10:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesActividad04.h"
#define MAXCANTLINEA 100
using namespace std;

void abrirArchivosLectura(const char *nombre,ifstream &arch){
    arch.open(nombre,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

void abrirArchivosEscritura(const char *nombre,ofstream &arch){
    arch.open(nombre,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}



void leerAlumnos(int *&codigos,char **&nombres,char ***&cursos){
    ifstream arch;
    abrirArchivosLectura("Alumnos.csv",arch);
    char *bufNombre[100],**bufCurso[50];
    int codigo[100],numDat=0,cod;  
    char tipo;
    while(1){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        arch>>cod;
        codigo[numDat]=cod;
        arch.get();
        bufNombre[numDat]=leerCadena(arch,',');
        limpiaLinea(arch);
        numDat++;
    }
    codigos = new int  [numDat+1];
    nombres = new char *[numDat+1];
    cursos  = new char **[numDat+1];
    for(int i=0;i<numDat;i++){
        codigos[i] = codigo[i];
        nombres[i] = bufNombre[i];
    }
    codigos[numDat]=0;
    nombres[numDat]=nullptr;
    cursos[numDat] =nullptr;
}
void imprimirAlumnos(int *codigos,char **nombres){
    ofstream arch;
    abrirArchivosEscritura("ReporteAlumnos.txt",arch);
    for(int i=0;codigos[i];i++){
        arch<<setw(10)<<left<<codigos[i]<<left<<setw(40)<<nombres[i]<<endl;
    }
}

void limpiaLinea(ifstream &arch){
    char buff[50];
    arch.getline(buff,50);
}



//              7613,   FIS208, 17, 2015-1,3.5,N
//           codAlum,codCur,nota,ciclo,cantCred,letra   
//void leerCursos(int *codigos,char ***&cursos){
//    ifstream arch;
//    abrirArchivosLectura("Cursos.csv",arch);
//    int auxCod,nota,pos,aa,i;
//    char *buffCurso[100][20],*codCur,c;
//    for(i=0;codigos[i];i++);
//    int numDat[i]={};
//    while(1){
//        cout<<"Llegue";
//        arch>>auxCod;
//        if(arch.eof())break;
//        arch.get();
//        codCur=leerCadena(arch,',');
//        arch>>nota>>c;
//        arch>>aa;
//        aa*=1000;
//        if(nota>=11&&auxCod>=aa){
//            pos=buscarEntero(codigos,auxCod);
//            agregaCurso(buffCurso[pos],codCur,numDat[pos]);
//        }
//        cout<<"Llegue";
//        limpiaLinea(arch);
//    }
//    cout<<"uwu";
//    for(i=0;codigos[i];i++)strcpy(buffCurso[i][numDat[i]],"X");
//}


void leerCursos(int *codigos,char ***&cursos){
    ifstream arch;
    abrirArchivosLectura("Cursos.csv",arch);
    int auxCod,nota,pos,aa,i;
    char *codCur,c;
    for(i=0;codigos[i];i++)cursos[i]= new char *[50]{};
    int numDat[i+1]={};
    while(1){
        arch>>auxCod;
        if(arch.eof())break;
        arch.get();
        codCur=leerCadena(arch,',');
        arch>>nota>>c;
        arch>>aa;
        aa*=1000;
        if(nota>=11&&auxCod>=aa){
            pos=buscarEntero(codigos,auxCod);
            agregaCurso(cursos[pos],codCur,numDat[pos]);
        }
        limpiaLinea(arch);
    }
    cout<<"uwu";
    for(int j=0;j<i;j++){
        espaciosExactos(cursos[j],numDat[j]);
    }
    cout<<"llegue owo";
}
//revisar que no apunte al mismmo lugar
void agregaCurso(char **&cursos,char *codigo,int &numDat){
    cursos[numDat]=codigo;
    numDat++;
}

void espaciosExactos(char **&cursos, int nd){
    char **buffCur;
    int i;
    /*if(nd==0){
        cursos = nullptr;
        return;
    }*/
    buffCur = new char *[nd+1]{};
    for(i=0;i<nd;i++){
        buffCur[i]=cursos[i];
    }
    delete cursos;
    cursos = buffCur;
}
int buscarEntero(int *arr,int buscar){
    for(int i=0;arr[i];i++)if(arr[i]==buscar)return i;
    cout<<"ERROR, no se encontro el entero: ",buscar;
    exit(1);
}

char * leerCadena(ifstream &arch,char c){
    char buffer[100],*cadena;
    int numDat=0;
    arch.getline(buffer,100,c);
    cadena = new char [strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
void imprimeCursos(char **cursos,ofstream &arch){
    int i;
    arch<<setw(15)<<left<<"Cursos aprobados: ";
    for(i=0;cursos[i]!=nullptr;i++){
        arch<<setw(10)<<left<<cursos[i];
    }
    if(i==0)arch<<"El alumno no tiene cursos aprobados registrados";
    arch<<endl;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void imprimirReporte(int *codigos,char **nombres,char ***cursos){
    ofstream arch;
    abrirArchivosEscritura("ReporteCursos.txt",arch);
    for(int i=0;codigos[i];i++){
        imprimeLinea(arch,MAXCANTLINEA,'=');
        arch<<setw(20)<<left<<"Codigo:"<<setw(10)<<left<<codigos[i]<<setw(10)
                <<left<<"Nombre: "<<nombres[i]<<endl;
        imprimeLinea(arch,MAXCANTLINEA,'-');
        imprimeCursos(cursos[i],arch);
    }
    imprimeLinea(arch,MAXCANTLINEA,'=');
}