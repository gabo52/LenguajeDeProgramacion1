/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Gabo
 * 
 * Created on 30 de octubre de 2022, 10:28 PM
 */


#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"
#include "Curso.h"
#include "Acurso.h"
Alumno::Alumno() {
    inicializar();
}

Alumno::~Alumno() {
    
}

void Alumno::copia(const Alumno &c){
    codigo=c.codigo;
    if(c.nombre){
        nombre = new char [strlen(c.nombre)+1];
        strcpy(nombre,c.nombre);
    }
    for(int i=0;i<c.numcur;i++){
        lcurso[i].copia(c.lcurso[i]);
    }
    numcur=c.numcur;
    tipo=c.tipo;
}
//Preguntar
void Alumno::copiaCursos(const Curso *&arr,const int cant){
    for(int i=0;i<cant;i++){
        lcurso[i].copia(arr[i]);
    }
}

void Alumno::inicializar(){
    nombre=nullptr;
}

void Alumno::operator + (const class Acurso &c){
    int n;
    n = numcur;
    class Curso cur;
    cur = c.obtieneCurso();
//    lcurso[n].copia(cur);
}

void Alumno::setNumcur(int numcur) {
    this->numcur = numcur;
}

int Alumno::getNumcur() const {
    return numcur;
}

void Alumno::setLcurso(Curso[] lcurso) {
    this->lcurso = lcurso;
}

Curso[] Alumno::getLcurso() const{return lcurso;}

void Alumno::setNombre(char* nombre) {
    this->nombre = nombre;
}

char* Alumno::getNombre() const {
    return nombre;
}

void Alumno::setTipo(char tipo) {
    this->tipo = tipo;
}

char Alumno::getTipo() const {
    return tipo;
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::getCodigo() const {
    return codigo;
}


