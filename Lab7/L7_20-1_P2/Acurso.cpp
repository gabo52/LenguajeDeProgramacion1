/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acurso.cpp
 * Author: alulab14
 * 
 * Created on 31 de octubre de 2022, 10:43 AM
 */

#include "Acurso.h"
#include <iostream>
using namespace std;
Acurso::Acurso() {
    operacion = 'N';
}

Acurso::~Acurso() {

}

void Acurso::SetOperacion(char operacion) {
    this->operacion = operacion;
}

char Acurso::GetOperacion() const {
    return operacion;
}

void Acurso::SetClcurso(Curso &lcur) {
    this->clcurso.copia(lcur);
}

Curso Acurso::GetClcurso() const {
    Curso aux;
    aux.copia(clcurso);
    return aux;
}

void Acurso::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Acurso::GetCodigo() const {
    return codigo;
}

void Acurso::copia(const Acurso& c) {
    codigo = c.GetCodigo();
    clcurso.copia(c.clcurso);
    operacion = c.GetOperacion();
}





