/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acurso.h
 * Author: Gabo
 *
 * Created on 30 de octubre de 2022, 10:28 PM
 */

#ifndef ACURSO_H
#define ACURSO_H
#include "Curso.h"
class Acurso {
private:
    int codigo;
    class Curso clcurso;
    char operacion;
public:
    Acurso();
    virtual ~Acurso();
    void copia(const Acurso& c);
    class Curso obtieneCurso();
    void setOperacion(char operacion);
    char getOperacion() const;
    void setClcurso(Curso clcurso);
    Curso getClcurso() const;
    void setCodigo(int codigo);
    int getCodigo() const;
};

#endif /* ACURSO_H */

