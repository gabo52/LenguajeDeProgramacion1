/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPaciente.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:35 PM
 */

#ifndef NPACIENTE_H
#define NPACIENTE_H

#include "Paciente.h"
#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"

class NPaciente {
public:
    NPaciente();
    virtual ~NPaciente();
    void leer(ifstream &arch);
    int activo();
    int prioridad();
    void imprimir(ofstream &arch);
    bool operator < (const NPaciente &c);
    bool operator == (const NPaciente &c);
    void setNull();
    void actualizaObservaciones(int &pacR,int &pacM);
private:
    Paciente *pac;
};

#endif /* NPACIENTE_H */

