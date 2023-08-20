/* 
 * File:   Emergencia.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

