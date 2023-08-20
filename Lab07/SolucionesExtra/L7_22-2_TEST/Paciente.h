/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.h
 * Author: Gabo
 *
 * Created on 3 de noviembre de 2022, 09:33 PM
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include "Cita.h"
#include <cstring>
#include <fstream>
using namespace std;
class Paciente {
public:
    Paciente();
    virtual ~Paciente();
    void SetTotalGastado(double totalGastado);
    double GetTotalGastado() const;
    void SetNumCitas(int numCitas);
    int GetNumCitas() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const Paciente &c);
    void imprimeCitas (ofstream &arch);
    void operator += (const Cita &c);
    void operator ++();
private:
    int dni;
    char*nombre;
    int telefono;
    Cita citas[200];
    int numCitas;
    double totalGastado;
};

#endif /* PACIENTE_H */

