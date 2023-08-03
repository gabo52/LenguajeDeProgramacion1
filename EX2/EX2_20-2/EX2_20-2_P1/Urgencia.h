/* 
 * File:   Urgencia.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:20 PM
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
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int prioridad();
    void observacion(char *cad);
private:
    double porcSeguro;
    double porcUrgencia;
};

#endif /* URGENCIA_H */

