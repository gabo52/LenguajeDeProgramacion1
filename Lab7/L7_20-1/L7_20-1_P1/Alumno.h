/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: alulab14
 *
 * Created on 31 de octubre de 2022, 10:43 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include "Curso.h"
#include "Acurso.h"
#include <fstream>
using namespace std;
class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    void SetNumCur(int numCur);
    int GetNumCur() const;
    void SetNombre(const char* nombre);
    char* GetNombre() const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void copia(const Alumno &c);
    void operator + (const Acurso &c);
    void operator * (const Acurso &c);
    void operator - (const Acurso &c);
    double operator / (int ciclo);
    double operator -- (void);
    double operator++();
    void SetLcurso(Curso *lcurso,int n);
    Curso* GetLcurso(int n) const;
private:
    int codigo;
    char tipo;
    char *nombre;
    class Curso lcurso[100];
    int numCur;
};

#endif /* ALUMNO_H */

