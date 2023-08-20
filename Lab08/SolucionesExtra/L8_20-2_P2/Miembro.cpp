/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.cpp
 * Author: Gabo
 * 
 * Created on 6 de noviembre de 2022, 09:48 PM
 */

#include "Miembro.h"
#include "Alumno.h"
#include <cstring>
#include "FuncionesLecturaEscritura.h"
Miembro::Miembro() {
    lalumno = nullptr;
    lprofesor = nullptr;
}

//preguntar []
Miembro::~Miembro() {
    if(lalumno)delete lalumno;
    if(lprofesor)delete lprofesor;
}


void Miembro::operator = (const Miembro &c){
    lalumno = c.GetLalumno();
    lprofesor = c.GetLprofesor();
}

void Miembro::SetLprofesor(Profesor* lprofesor) {
    *this = lprofesor;
}

Profesor* Miembro::GetLprofesor() const {
    Profesor *aux;
    int i;
    if(lprofesor==nullptr){
        aux = new Profesor[2];
        return aux;
    }
    char cadena[200];
    lprofesor[0].GetCategoria(cadena);
    for(i=0;strcmp(cadena,"0");i++){
        lprofesor[i+1].GetCategoria(cadena);
    }
    aux = new Profesor [i+1];
    lprofesor[0].GetCategoria(cadena);
    for(i=0;strcmp(cadena,"0");i++){
        lprofesor[i+1].GetCategoria(cadena);
        aux[i]=lprofesor[i];
    }
    return aux;
}

void Miembro::SetLalumno(Alumno* arr) {
    *this = arr;
}

Alumno* Miembro::GetLalumno() const {
    Alumno *aux;
    int i;
    if(lalumno==nullptr){
        aux = new Alumno[2];
        return aux;
    }
    for(i=0;lalumno[i].GetEscala();i++);
    aux = new Alumno[i+1];
    for(i=0;lalumno[i].GetEscala();i++)aux[i]=lalumno[i];
    return aux;
}


void Miembro::operator = (Profesor* arr){
    int n,i;
    char cadena[200];
    if(arr){
        arr[0].GetCategoria(cadena);
        for(i=0;strcmp(cadena,"0");i++){
            arr[i+1].GetCategoria(cadena);
        }
        lprofesor = new Profesor[i+2];
        arr[0].GetCategoria(cadena);
        for(i=0;strcmp(cadena,"0");i++){
            lprofesor[i]=arr[i];
            arr[i+1].GetCategoria(cadena);
        }
    }else lprofesor = nullptr;
}

void Miembro::operator = (Alumno* arr){
    int i,n;
    if(lalumno)delete lalumno;
    if(arr){
        for(i=0;arr[i].GetEscala();i++);
        lalumno = new Alumno[i+2];
        for(i=0;arr[i].GetEscala();i++)lalumno[i]=arr[i];
    }else lalumno = nullptr;
}


void Miembro::operator + (const Alumno &alu){
    int n=numeroAlumnos();
    lalumno[n]=alu;
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


void Miembro::operator + (const Profesor &c){
    int n=numeroProfesores();
    lprofesor[n]=c;
}


void Miembro::imprimeProfesores(ofstream &arch){
    int n=numeroProfesores();
    for(int i=0;i<n;i++){
        arch<<lprofesor[i];
    }
}

void Miembro::imprimeAlumnos(ofstream &arch){
    int n=numeroAlumnos();
    for(int i=0;i<n;i++){
        arch<<lalumno[i];
    }
}

