/* 
 * File:   Emergencia.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:47 AM
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include "Paciente.h"


class Emergencia : public Paciente{
public:
    Emergencia();
    virtual ~Emergencia();
    void SetNombreRef(char* nombreRef);
    void GetNombreRef(char*) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    void operator = (const Emergencia &c);
private:
    int telefonoRef;
    char *nombreRef;
};

#endif /* EMERGENCIA_H */

