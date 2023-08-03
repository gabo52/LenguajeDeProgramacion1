/* 
 * File:   Miembro.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 09:48 PM
 */

#ifndef MIEMBRO_H
#define MIEMBRO_H
#include "Alumno.h"
#include "Profesor.h"

class Miembro {
public:
    Miembro();
    virtual ~Miembro();
    void operator + (const Alumno &alu);
    int numeroAlumnos();
    int numeroProfesores();
    void operator + (const Profesor &c);
private:
    Alumno *lalumno;
    Profesor *lprofesor;
};

#endif /* MIEMBRO_H */

