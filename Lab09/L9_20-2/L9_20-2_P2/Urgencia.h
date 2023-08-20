/* 
 * File:   Urgencia.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

