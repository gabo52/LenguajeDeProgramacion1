/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emergencia.h
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 06:20 PM
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include "Paciente.h"


class Emergencia : public Paciente{
public:
    Emergencia();
    virtual ~Emergencia();
    void SetNombreRef(char* nombreRef);
    void GetNombreRef(char* cad) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int prioridad();
    void observacion(char *cad);
private:
    int telefonoRef;
    char *nombreRef;
};

#endif /* EMERGENCIA_H */

