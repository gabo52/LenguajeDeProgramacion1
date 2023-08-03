/* 
 * File:   FuncionesEx01_20201_Preg03.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 5 de octubre de 2022, 08:47 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20201_Preg01.h"
#include "FuncionesEx01_20201_Preg02.h"
#include "FuncionesEx01_20201_Preg03.h"
#define MAXCANTLINEA 100
using namespace std;


void reporteDeCargaHorariaDeProf(char ***cursos,int *codProfesores,
        char **profesores,void *sesiones){
    ofstream arch;
    char *codProf;
    AbrirArchivo("ReporteCargaHorariaDeProf.txt",arch);
    arch<<setw(70)<<right<<"CARGA HORARIA DE PROFESORES"<<endl;
    int horasSemana,cantAl;
    for(int i=0;codProfesores[i];i++){
        imprimeCabeceraProf(profesores[i],codProfesores[i],arch);
        imprimeCursos(profesores[i],arch,sesiones,horasSemana,cantAl,cursos,
                codProfesores[i]);
    }
}

void imprimeCabeceraProf(char *profesor,int cod,ofstream &arch){
    arch<<"Codigo: "<<setw(15)<<left<<cod<<"Nombre: "<<profesor<<endl;
    arch<<"Horarios asignados:"<<endl;
    
}
void imprimeCursos(char *profesor,ofstream &arch,void *sesiones,
        int &horas,int &cantAl,char ***cursos,int codProf){
    horas=cantAl=0;
    char *codHorario,*codCur;
    int *cant;
    int nd=1;
    void **sesionesCurso=(void **)sesiones;
    void *horarios;
    for(int i=0;sesionesCurso[i];i++){
        if(sesionPerteneceAProfesor(sesionesCurso[i],codProf,codCur,codHorario,
                cant,horarios)){
            imprimeHorario(arch,horarios,horas,cantAl,nd,codCur,codHorario,cursos,cant);
        }
    }
    imprimeResumen(horas,cantAl,arch);
    imprimeLinea(arch,MAXCANTLINEA,'=');
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

int sesionPerteneceAProfesor(void *sesi,int codProf,char *&codCur,
        char *&codHorario,int *&cant,void *&horarios){
    int *aux;
    void **sesiones=(void **)sesi;
    aux=(int*)sesiones[3];
    if(codProf==*aux){
        codCur=(char*)sesiones[0];
        codHorario=(char*)sesiones[1];
        cant = (int*)sesiones[2];
        horarios=sesiones[4];
        return 1;
    }
    return 0;
}

int imprimeHorarioEspecifico(void *&sesiones,ofstream &arch,int i){
    int *aux,num;
    aux=(int *)sesiones;
    num=*aux;
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
    arch<<"      ";
    arch<<left<<setw(1)<<i<<") ";
    imprimeDia2(dd,arch);
    arch<<"     ";
    arch<<setfill('0')<<setw(2)<<right<<Hi<<":"<<setw(2)<<right<<Mi<<setfill(' ');
    arch<<"     ";
    arch<<setfill('0')<<setw(2)<<right<<Hf<<":"<<setw(2)<<right<<Mf<<setfill(' ');
    arch<<endl;
    return (Hf*60)-(Hi*60)+Mf-Mi;
}

void imprimeDia2(int dd,ofstream &arch){
       switch(dd){
        case 1:
            arch<<setw(10)<<left<<"Domingo";
            break;
        case 2:
            arch<<setw(10)<<left<<"Lunes";
            break;
        case 3:
            arch<<setw(10)<<left<<"Martes";
            break;
        case 4:
            arch<<setw(10)<<left<<"Miercoles";
            break;
        case 5:
            arch<<setw(10)<<left<<"Jueves";
            break;
        case 6:
            arch<<setw(10)<<left<<"Viernes";
            break;
        case 7:
            arch<<setw(10)<<left<<"Sabado";
            break;
    }
}

void imprimeHorario(ofstream &arch,void *horarios,int &horas,int &cantAl,int &nd
        ,char *codCur,char *codHorario,char ***cursos, int *cant){
    void **aux=(void**)horarios;
    char *nombre,*esp;
    
    buscarProd(codCur,cursos,nombre,esp);
    if(nombre){
        arch<<"Nro.  Curso"<<setw(31)<<right<<"Codigo"<<setw(20)<<right
            <<"Especialidad"<<endl;
        arch<<setw(2)<<right<<nd<<")   "<<setw(30)<<left<<nombre<<setw(14)<<left
                <<codCur<<left<<esp<<endl;
        arch<<"      Horario:  "<<codHorario<<endl;
        int tiempo=0;
        for(int i=0;aux[i];i++){
            tiempo+=imprimeHorarioEspecifico(aux[i],arch,i+1);
        }
        arch<<"      Horas dictadas: "<<setfill('0')<<setw(2)<<right<<tiempo/60<<
                ":"<<setw(2)<<right<<tiempo%60<<setfill(' ')<<endl;
        arch<<"      Matriculados: "<<setw(4)<<right<<(*cant)<<endl;
        horas+=tiempo;
        nd++;
    }
    arch<<endl;
    cantAl+=(*cant);
}

void buscarProd(char *codCur,char ***cursos,char *&nombre,char *&esp){
    for(int i=0;cursos[i];i++){
        if(comparaCursos(cursos[i],codCur,nombre,esp)){
            return;
        }
    }
    nombre = nullptr;
    esp = nullptr;
    return;
}

int comparaCursos(char **cursos,char *codCur,char *&nombre,char *&esp){
    cout<<cursos[0]<<"   "<<codCur<<"111"<<endl;
    if(strcmp(cursos[0],codCur)==0){
        cout<<"Llegue";
        nombre=cursos[1];
        esp=cursos[2];
        return 1;
    }
    return 0;
}
void imprimeResumen(int &horas,int &cantAl,ofstream &arch){
    int min,hor;
    min=horas%60;
    hor=horas/60;
    arch<<setw(50)<<left<<"Total de horas asignadas por semana: "<<setw(2)<<
            right<<hor<<":"<<setw(2)<<right<<min<<endl;
    arch<<setw(50)<<left<<"Total de alumnos a su cargo: "<<setw(4)<<right<<
            cantAl<<endl;
}
