/* 
 * File:   Miembro.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 09:48 PM
 */

#include "Miembro.h"
#include "Alumno.h"
#include <cstring>
Miembro::Miembro() {
    lalumno = nullptr;
    lprofesor = nullptr;
}

//preguntar []
Miembro::~Miembro() {
    if(lalumno)delete lalumno;
    if(lprofesor)delete lprofesor;
}

void Miembro::operator + (const Alumno &alu){
    if(lalumno){
        int n=numeroAlumnos();
        Alumno *aux;
        aux=new Alumno[n+2];
        for(int i=0;i<n;i++)aux[i]=lalumno[i];
        lalumno[n]=alu;
        delete []lalumno;
        lalumno=aux;
    }else{
        lalumno = new Alumno[2];
        lalumno[0]=alu;
    }
}


void Miembro::operator + (const Profesor &c){
    if(lprofesor){
        int n=numeroProfesores();
        Profesor *aux;
        aux=new Profesor[n+2];
        for(int i=0;i<n;i++)aux[i]=lprofesor[i];
        lprofesor[n]=c;
        delete []lprofesor;
        lprofesor=aux;
    }else{
        lprofesor = new Profesor[2];
        lprofesor[0]=c;
    }
}

int Miembro::numeroAlumnos(){
    if(lalumno==nullptr)return 0;
    int i;
    for(i=0;lalumno[i].GetEscala();i++);
    return i;
}


int Miembro::numeroProfesores(){
    int i;
    if(lprofesor==nullptr)return 0;
    char cadena[200];
    lprofesor[0].GetCategoria(cadena);
    for(i=0;cadena;i++){
        lprofesor[i+1].GetCategoria(cadena);
    }
    return i;
}




