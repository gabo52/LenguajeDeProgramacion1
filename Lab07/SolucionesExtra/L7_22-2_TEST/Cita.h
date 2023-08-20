/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cita.h
 * Author: Gabo
 *
 * Created on 3 de noviembre de 2022, 09:32 PM
 */

#ifndef CITA_H
#define CITA_H
#include <cstring>
#include <fstream>
using namespace std;
#include "Medico.h"
class Cita {
public:
    Cita();
    virtual ~Cita();
    void eliminar();
    void setEspecialidad(char* especialidad);
    void getEspecialidad(char *cad) const;
    void setTarifaPorConsulta(double tarifaPorConsulta);
    double getTarifaPorConsulta() const;
    void setFecha(int fecha);
    int getFecha() const;
    void setCodMed(int codMed);
    int getCodMed() const;
    void operator = (const Cita &c);
    void imprimeCita(ofstream &arch);
    bool operator <= (Medico *arr);
private:
    int codMed;
    int fecha;
    double tarifaPorConsulta;
    char *especialidad;
};

#endif /* CITA_H */

