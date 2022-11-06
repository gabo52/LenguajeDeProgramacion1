/* 
 * File:   funcionesP2.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de noviembre de 2022, 11:12 AM
 */

#ifndef FUNCIONESP2_H
#define FUNCIONESP2_H
#include "Acurso.h"
#include "Alumno.h"
#include "Curso.h"
#include <fstream>
using namespace std;
void leerAlumnos(Alumno *arr,int &n);
void imprimirAlumnos(Alumno *arr,int n);
void actualizarAlumnos(Alumno *arr,int n);
int buscarAlumno(Alumno *arr,int n,int busca);
void completarDatosAlumnos(Alumno *arr,int n);
void leerAlumnos(Alumno *arr,int &n);
#endif /* FUNCIONESP2_H */

