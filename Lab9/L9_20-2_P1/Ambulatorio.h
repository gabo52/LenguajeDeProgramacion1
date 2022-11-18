/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ambulatorio.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 11:32 AM
 */

#ifndef AMBULATORIO_H
#define AMBULATORIO_H

#include "Paciente.h"


class Ambulatorio : public Paciente{
public:
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void leePaciente(ifstream &arch);
    void operator = (const Ambulatorio &c);
    void imprime(ofstream &arch);
    int seguro();
    int prioridad();
private:
    double porcSeguro;
};

#endif /* AMBULATORIO_H */

