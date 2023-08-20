/* 
 * File:   Urgencia.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:44 AM
 */

#ifndef URGENCIA_H
#define URGENCIA_H

#include "Paciente.h"


class Urgencia : public Paciente{
public:
    Urgencia();
    virtual ~Urgencia();
    void SetPorcUrgencia(double porcUrgencia);
    double GetPorcUrgencia() const;
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void operator = (const Urgencia &c);
private:
    double porcSeguro;
    double porcUrgencia;
};

#endif /* URGENCIA_H */

