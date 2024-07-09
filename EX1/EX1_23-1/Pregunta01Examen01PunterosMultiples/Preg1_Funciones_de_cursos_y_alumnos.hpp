/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_HPP
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
using namespace std;

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,const char *curso_name,const char *escala_name);
//void pruebaDeCargaDeCursos(cursos, cursos_cred, "PruebaCursos.txt");
//void cargarAlumnos(alumnos_cod, alumnos, alumnos_nom _mod, "Alumnos.csv");
//void pruebaDeCargaDeAlumnos(alumnos_cod, alumnos, alumnos_nom _mod, "PruebaAlumnos.txt");
#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_HPP */

