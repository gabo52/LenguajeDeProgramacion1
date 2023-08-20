/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Gabo
 *
 * Created on 30 de octubre de 2022, 10:28 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include "Curso.h"
#include "Acurso.h"
class Alumno {
private:
    int codigo;
    char tipo;
    char *nombre;
    class Curso lcurso[100];
    int numcur;
public:
    Alumno();
    void inicializar();
    virtual ~Alumno();
    void copia(const Alumno &c);
    void copiaCursos(const Curso *&arr,int cant);
    void operator + (const class Acurso &c);
    void setNumcur(int numcur);
    int getNumcur() const;
    void setNombre(char* nombre);
    char* getNombre() const;
    void setTipo(char tipo);
    char getTipo() const;
    void setCodigo(int codigo);
    int getCodigo() const;
};

#endif /* ALUMNO_H */

