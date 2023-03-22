/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.h
 * Author: Gabo
 *
 * Created on 6 de noviembre de 2022, 09:48 PM
 */

#ifndef MIEMBRO_H
#define MIEMBRO_H
#include "Alumno.h"
#include "Profesor.h"
#include <fstream>
using namespace std;
class Miembro {
public:
    Miembro();
    virtual ~Miembro();
    void operator = (const Miembro &c);
    void SetLprofesor(Profesor* lprofesor);
    Profesor* GetLprofesor() const;
    void SetLalumno(Alumno* lalumno);
    Alumno* GetLalumno() const;
    void operator = (Profesor* lprofesor);
    void operator = (Alumno* lalumno);
    void operator + (const Alumno &alu);
    int numeroAlumnos();
    int numeroProfesores();
    void operator + (const Profesor &c);
    void imprimeProfesores(ofstream &arch);
    void imprimeAlumnos(ofstream &arch);
private:
    Alumno *lalumno;
    Profesor *lprofesor;
};

#endif /* MIEMBRO_H */

