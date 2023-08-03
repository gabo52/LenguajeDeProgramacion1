/* 
 * File:   Alumno.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:12 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona{
public:
    Alumno();
    virtual ~Alumno();
    void SetFacultad(char* facultad);
    void GetFacultad(char* cad) const;
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char* cad) const;
    void SetEscala(int escala);
    int GetEscala() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);    
private:
    int escala;
    char *especialidad;
    char *facultad;
};

#endif /* ALUMNO_H */

