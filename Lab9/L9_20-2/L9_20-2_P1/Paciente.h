/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 11:31 AM
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

class Paciente {
public:
    Paciente();
    virtual ~Paciente();
    void SetCodMed(char* codMed);
    void GetCodMed(char* cad) const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetDni(int dni);
    int GetDni() const;
    //virtual void operator = (const Paciente &c)=0;
    virtual void leePaciente(ifstream &arch)=0;
    virtual void imprime(ofstream &arch)=0;
    virtual int seguro()=0;
    virtual int prioridad()=0;
private:
    int dni;
    char *nombre;
    char *codMed;
};

#endif /* PACIENTE_H */

