/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acurso.cpp
 * Author: Gabo
 * 
 * Created on 30 de octubre de 2022, 10:28 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Acurso.h"
#include "Curso.h"
Acurso::Acurso(){
    
}

Acurso::~Acurso(){
    
}


void Acurso::setOperacion(char operacion) {
    this->operacion = operacion;
}

char Acurso::getOperacion() const {
    return operacion;
}

void Acurso::setClcurso(Curso clcurso) {
    this->clcurso = clcurso;
}

Curso Acurso::getClcurso() const {
    return clcurso;
}

void Acurso::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Acurso::getCodigo() const {
    return codigo;
}

void Acurso::copia(const Acurso &c){
    clcurso=c.getClcurso();
    codigo=c.getCodigo();
    operacion=c.getOperacion();
}



