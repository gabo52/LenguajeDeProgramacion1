/* 
 * File:   Alumno.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 09:46 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno: public Persona {
public:
    Alumno();
    virtual ~Alumno();
    void SetFacultad(char* cad);
    void GetFacultad(char *cad) const;
    void SetEspecialidad(char* cad);
    void GetEspecialidad(char *cad) const;
    void SetEscala(int escala);
    int GetEscala() const;
    void operator = (const Alumno &c);
private:
    int escala;
    char *especialidad;
    char *facultad;
};

#endif /* ALUMNO_H */

