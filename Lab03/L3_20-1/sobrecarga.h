
/* 
 * File:   sobrecarga.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 10:57 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include "Estructura.h"
#include <fstream>
using namespace std;

void operator+(struct Alumno &alumno, const struct ACurso curso);
void operator*(struct Alumno &alumno, const struct ACurso curso);
int buscarCurso(const struct Alumno alumno, int codigo, int ciclo);
void operator-(struct Alumno &alumno, const struct ACurso curso);
double operator/(const struct Alumno alumno, int ciclo);
int operator --(const struct Alumno alumno, int b);
int operator ++(const struct Alumno alumno, int b);
ofstream &operator << (ofstream &out, const struct Alumno alumno);
ifstream &operator >> (ifstream &in, struct ACurso &curso);
ifstream &operator >> (ifstream &in,struct Alumno &alumno);
int buscarCiclo(int *arr, int n, int ciclo);
void imprimirLinea(ofstream &out, int n, char c);

#endif /* SOBRECARGA_H */

