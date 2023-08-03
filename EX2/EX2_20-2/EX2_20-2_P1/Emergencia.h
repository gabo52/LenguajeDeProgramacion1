/* 
 * File:   Emergencia.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:20 PM
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include "Paciente.h"


class Emergencia : public Paciente{
public:
    Emergencia();
    virtual ~Emergencia();
    void SetNombreRef(char* nombreRef);
    void GetNombreRef(char* cad) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int prioridad();
    void observacion(char *cad);
private:
    int telefonoRef;
    char *nombreRef;
};

#endif /* EMERGENCIA_H */

