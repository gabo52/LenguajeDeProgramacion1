/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emergencia.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 11:33 AM
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include "Paciente.h"


class Emergencia : public Paciente{
public:
    Emergencia();
    virtual ~Emergencia();
    void SetNombreRef(const char* cad);
    void GetNombreRef(char* cad) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    void operator = (const Emergencia &c);
    void leePaciente(ifstream &arch);
    void imprime(ofstream &arch);
    int seguro();
    int prioridad();
private:
    int telefonoRef;
    char *nombreRef;
};

#endif /* EMERGENCIA_H */

