/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Gabo
 * 
 * Created on 30 de octubre de 2022, 10:25 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Curso.h"

Curso::Curso() {
    inicializar();
}
Curso::~Curso() {
    inicializar();
}

void Curso::copia(const Curso &c){
    int longitud=strlen(c.ccurso);
    if(ccurso){
        ccurso = new char [longitud+1];
        strcpy(ccurso,c.ccurso);
    }
    ciclo=c.ciclo;
    credito=c.credito;
    nota=c.nota;
}

void Curso::inicializar(){
    ccurso = nullptr;
}

void Curso::asignar(const Curso &c){
    copia(c);
}
//cuando se usan operadores, el objeto va por defecto a la izquierda
//preguntar
void Curso::operator = (const Curso &c){
    asignar(c);
}

int Curso::compare(const Curso &c){
    return ciclo==c.ciclo && strcpy(ccurso,c.ccurso)==0;
}

int Curso::operator == (const Curso &c){
    compare(c);
}

void Curso::setCredito(int credito) {
    this->credito = credito;
}

int Curso::getCredito() const {
    return credito;
}

void Curso::setNota(int nota) {
    this->nota = nota;
}

int Curso::getNota() const {
    return nota;
}

void Curso::setCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Curso::getCiclo() const {
    return ciclo;
}

void Curso::setCcurso(char* ccurso) {
    this->ccurso = ccurso;
}

char* Curso::getCcurso() const {
    return ccurso;
}







