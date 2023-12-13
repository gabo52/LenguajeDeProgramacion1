/* 
 * File:   funciones.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
// librerias
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "operadoresSobrecargados.hpp"
using namespace std;
// funciones
void leerCursos(struct StCurso *);
void leerAlumnos(struct StAlumno * );
void leerMatricula(struct StCurso *,struct StAlumno *);
void calcularIngresosYCostos(struct StCurso *arregloCurso,struct StAlumno *arregloAlumno);
void llenarEscalas(double *arregloEscala);
int escalaDelAlumno(struct StAlumno *arregloAlumno,int codigoAlumno);
double buscarCreditoDelCurso(struct StCurso *arregloCurso,char *codigoCurso);
void realizarReporte(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno);
#endif /* FUNCIONES_HPP */

