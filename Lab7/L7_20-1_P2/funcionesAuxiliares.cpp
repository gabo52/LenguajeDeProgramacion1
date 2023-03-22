/* 
 * File:   funcionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de noviembre de 2022, 09:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesAuxiliares.h"
#include "Alumno.h"
#define MAXCANTLINEA 100
using namespace std;





void AbrirArchivo(const char *nomb, ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb, ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

ifstream& operator>>(ifstream& arch, Acurso &acur) {
    int cod,nt,cl,aa,ss;
    char op,CODCUR[20],c;
    double nCred;
    Curso cur;
    arch>>cod;
    if(arch.eof())return arch;
    arch>>CODCUR>>nt>>aa>>c>>ss>>nCred>>op;
    cur.SetCiclo(aa*100+ss);
    cur.SetCcurso(CODCUR);
    cur.SetCredito(nCred);
    cur.SetNota(nt);
    acur.SetCodigo(cod);
    acur.SetOperacion(op);
    acur.SetClcurso(cur);
}

ifstream& operator>>(ifstream& arch,Alumno &alum) {
    char tip,nomb[100],especialidad[30],facultad[10];
    int codigo;
    arch>>tip;
    if(arch.fail())return arch;
    arch>>codigo>>nomb>>especialidad>>facultad;
    alum.SetTipo(tip);
    alum.SetNombre(nomb);
    alum.SetNumCur(0);
    alum.SetCodigo(codigo);
}


ofstream & operator<<(ofstream & arch, Alumno &alum) {
    char *nomb=alum.GetNombre();
    char tipo=alum.GetTipo();
    int cod=alum.GetCodigo();
    int n=alum.GetNumCur();
    Curso *cur;
    cur = alum.GetLcurso(n);
    arch<< "Nombre: "<<nomb<<endl;
    arch<<"Codigo: "<<cod<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(20)<<right<<"CICLO"<<setw(35)<<right<<"PROMEDIO"<<endl;
    int cc,ss,ciclo,ciclos[50]{},nCiclos=0,pos,j=0;
    for(int i=0;i<n;i++){
        ciclo=cur[i].GetCiclo();
        pos=busca(ciclo,ciclos);
        if(pos==-1){
            ciclos[nCiclos]=ciclo;
            nCiclos++;
            ss=ciclo/100;
            cc=ciclo%10;
            arch<<setw(5)<<right<<nCiclos<<")"<<setw(13)<<right<<ss<<"-"<<cc;
            arch.precision(2);
            arch.fixed;
            arch<<setw(32)<<right<<alum/ciclo<<endl;
        }
    }
    //preguntar uso del arch.precision
    arch<<endl<<setprecision(1);
    arch.fixed;
    arch<<setw(20)<<left<<"Creditos Cursados:";
    arch<<setprecision(1)<<fixed<<setw(10)<<right<<--alum<<endl;
    arch<<setw(20)<<left<<"Creditos Aprobados:"<<setw(10)<<right<<++alum<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
}

void imprimeLinea(ofstream & arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}



int busca(int dato,int *arr){
    for(int i=0;arr[i];i++){
        if(dato==arr[i]){
            return i;
        }
    }
    return -1;
}