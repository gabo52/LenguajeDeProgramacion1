/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 21 de agosto de 2022, 04:40 PM
 */

#include <iostream>
#include <iomanip>
#define MAXCANTLINEA 110
using namespace std;

/*
 * 
 */

void imprimeLinea(char c,int cant){
    for(int i=0;i<cant;i++)cout<<c;
    cout<<endl;
}
void imprimeCabecera(){
    cout<<setw(90)<<"INFORMACION ACADEMICA DE LOS ESTUDIANTES"<<endl;
}    

void arreglaNombre(char *nombre){
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='/')nombre[i]=' ';
    }
}

void imprimeDescripcionCurso(){
    cout<<"CODIGO  CREDITOS  NOTA     FECHA";
}
void imprimeCabeceraConductor(int codigo,int aa,char *nombre){
    imprimeLinea('=',MAXCANTLINEA);
    arreglaNombre(nombre);
    cout<<setw(15)<<right<<"Alumno: "<<setw(45)<<left<<nombre<<setw(8)<<left<<"Codigo: ";
    cout.fill('0');
    cout<<aa<<" - "<<setw(6)<<right<<codigo<<endl;
    cout<<setfill(' ');
    imprimeLinea('-',MAXCANTLINEA);
    cout<<setw(25)<<right<<"CURSOS APROBADOS"<<setw(50)<<right
            <<"CURSOS DESAPROBADOS"<<setw(35)<<right<<"OBSERVACION"<<endl<<"No.  ";
    imprimeDescripcionCurso();
    
    cout<<setw(10)<<" ";
    imprimeDescripcionCurso();
    cout<<endl;
    imprimeLinea('-',MAXCANTLINEA);
}

void imprimeDatosCurso(char *codCur,double creditos,int nota,int dd,int mm,int aa){
    cout.fill('0');
    cout<<codCur;
    cout<<setfill(' ');
    cout<<setw(8)<<right<<setprecision(2)<<fixed<<creditos;
    cout.fill('0');
    cout<<"     "<<setw(2)<<nota<<"    "<<right<<aa<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<dd;
    cout<<setfill(' ');
}

void imprimeCurso(int anio,char *codCur,double creditos,int nota,int dd,int mm,
        int aa,int &cantCurMat,int &cantCurAprob,double &totCred,
        double &totCredAprob,int &curError,int &sumNota,int &sumNotaAprob,int &i){
    i++;
    cout.fill('0');
    cout<<setw(3)<<i<<"  ";
    cout<<setfill(' ');

    if(nota>=11){
        
        imprimeDatosCurso(codCur,creditos,nota,dd,mm,aa);
        if(anio>aa){
            cout<<setw(70)<<right<<"ERROR FECHA";
            curError++;
        }else{
            cantCurAprob++;totCredAprob+=creditos;sumNotaAprob+=nota*creditos;
            totCred+=creditos;cantCurMat++;sumNota+=nota*creditos;
        }
    }else{
        cout<<setw(42)<<" ";
        imprimeDatosCurso(codCur,creditos,nota,dd,mm,aa);
        if(anio>aa){
            cout<<setw(28)<<right<<"ERROR FECHA";
            curError++;
        }else{
            totCred+=creditos;cantCurMat++;sumNota+=nota*creditos;
        }
    }
    cout<<endl;
}

void reseteaContadores(int &cantCurMat,int &cantCurAprob,double &totCred,
        double &totCredAprob,int &curError,int &sumNota,int &sumNotaAprob,int &i){
    i=cantCurMat=cantCurAprob=totCred=totCredAprob=curError=sumNota=sumNotaAprob=0;
}

void imprimeResumen(int cantCurMat,int cantCurAprob,double totCred,
        double totCredAprob,int curError,int sumNota,int sumNotaAprob){
    imprimeLinea('=',MAXCANTLINEA);
    cout<<setw(6)<<" "<<"RESUMEN:"<<endl;
    cout<<setw(6)<<" "<<setw(16)<<left<<"Cursos matriculados: "<<setw(23)<<left
            <<cantCurMat<<setw(20)<<left<<"Total de creditos: "<<setw(13)
            <<setprecision(2)<<fixed<<right<<totCred<<endl;
    cout<<setw(6)<<" "<<setw(16)<<left<<"Creditos aprobados: "<<setw(24)
            <<setprecision(2)<<fixed<<left<<totCredAprob<<setw(2)<<
            setprecision(2)<<fixed<<left<<"Creditos desaprobados: "<<setw(10)
            <<setprecision(2)<<fixed<<right<<totCred-totCredAprob<<endl;
    cout<<setw(6)<<" "<<setw(16)<<left<<"Creditos aprobados/matriculados: "<<
            setprecision(2)<<fixed<<totCredAprob/totCred*100<<"%"<<endl;
    imprimeLinea('-',MAXCANTLINEA);
    cout<<setw(6)<<" "<<setw(20)<<left<<"Promedio general: "<<setw(5)<<
            setprecision(2)<<fixed<<sumNota/totCred<<endl;
    cout<<setw(6)<<" "<<setw(20)<<left<<"Promedio general de aprobados: "<<setw(5)<<
            setprecision(2)<<fixed<<sumNotaAprob/totCredAprob<<endl;
    imprimeLinea('-',MAXCANTLINEA);
    cout.fill('0');
    cout<<"      "<<"Cursos con error no considerados: "<<setw(2)<<right<<curError<<endl;
    imprimeLinea('=',MAXCANTLINEA);
    cout<<setfill(' ');
}
int main(int argc, char** argv) {
    int cantAlumnos=0,codigo,aa,backup,dd,mm,aaIng,nota;
    char c,nombre[100],codCur[8];
    int cantCurMat=0,cantCurAprob=0,curError=0,flag=0,sumNota=0,sumNotaAprob=0,i=0;
    double creditos,totCred=0,totCredAprob=0;
    imprimeCabecera();
    while(1){
        cin>>codigo;
        if(cin.eof()){
            if(flag)imprimeResumen(cantCurMat,cantCurAprob,totCred,totCredAprob,curError,sumNota,sumNotaAprob);
            break;
        }
        if(cin.fail()){
            //Lee curso
            cin.clear();
            cin>>codCur>>creditos>>nota>>dd>>c>>mm>>c>>aaIng;
            imprimeCurso(aa,codCur,creditos,nota,dd,mm,aaIng,cantCurMat,
                    cantCurAprob,totCred,totCredAprob,curError,sumNota,sumNotaAprob,i);
            flag=1;
        }else{
            cin>>c>>aa>>nombre;cantAlumnos++;
            if(flag)imprimeResumen(cantCurMat,cantCurAprob,totCred,totCredAprob,curError,sumNota,sumNotaAprob);
            imprimeCabeceraConductor(codigo,aa,nombre);
            reseteaContadores(cantCurMat,cantCurAprob,totCred,totCredAprob,curError,sumNota,sumNotaAprob,i);
        }
    }
    cout<<"TOTAL DE ALUMNOS REGISTRADOS: "<<cantAlumnos;
    return 0;
}

