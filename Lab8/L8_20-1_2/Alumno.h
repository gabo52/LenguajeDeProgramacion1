/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Gabo
 *
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

