/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: Gabo
 *
 * Created on 6 de noviembre de 2022, 09:47 PM
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"


class Profesor : public Persona{
public:
    Profesor();
    virtual ~Profesor();
    void SetGrado(char* grado);
    void GetGrado(char *) const;
    void SetSeccion(char* seccion);
    void GetSeccion(char *) const;
    void SetDedicacion(char* dedicacion);
    void GetDedicacion(char *) const;
    void SetCategoria(char* categoria);
    void GetCategoria(char *) const;
    void operator = (const Profesor &c);
private:
    char *categoria;
    char *dedicacion;
    char *seccion;
    char *grado;
};

#endif /* PROFESOR_H */

