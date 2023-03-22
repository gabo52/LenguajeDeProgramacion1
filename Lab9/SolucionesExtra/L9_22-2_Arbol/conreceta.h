/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conreceta.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 06:54 PM
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "medicamento.h"


class conreceta :public medicamento{
public:
    conreceta();
    virtual ~conreceta();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char* cad) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void asigna(int cod,char *nombreMed,int cant,double prec,
    int fech,int codmed,char *esp,int dni,char *nombrePac);
    void imprime(ofstream &arch);
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

