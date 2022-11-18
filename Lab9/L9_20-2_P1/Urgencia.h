/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Urgencia.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 11:32 AM
 */

#ifndef URGENCIA_H
#define URGENCIA_H

#include "Paciente.h"


class Urgencia : public Paciente{
public:
    void SetPorcUrgencia(double porcUrgencia);
    double GetPorcUrgencia() const;
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void operator = (const Urgencia &c);
    void leePaciente(ifstream &arch);
    void imprime(ofstream &arch);
    int seguro();
    int prioridad();
private:
    double porcSeguro;
    double porcUrgencia;
};

#endif /* URGENCIA_H */

