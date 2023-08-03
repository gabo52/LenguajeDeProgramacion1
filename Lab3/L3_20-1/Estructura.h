
/* 
 * File:   Estructura.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 10:57 AM
 */

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

struct Alumno{
    int codigo;
    char tipo;
    char nombre[300];
    int curso[100];
    int ciclo[100];
    int nota[100];
    double credito[100];
    int numCur;
};

struct ACurso{
    int codigo;
    int curso;
    int ciclo;
    int nota;
    double credito;
    char operacion;
};

#endif /* ESTRUCTURA_H */

