/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Yisus
 *
 * Created on 27 de enero de 2024, 04:26 PM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

//variables generales
#define MAX_ALUMNO 100
#define MAX_ALUMNO_CURSO 50
#define MAX_CURSO 50


using namespace std;
// funciones de apertura de archivo
ifstream abrirArchivoLectura(const char *nombre_archivo);
ofstream abrirArchivoEscritura(const char *nombre_archivo);

// Funciones para la Lectura del alumno
void lecturaAlumnos(const char *nombre_archivo, int *&alumno_Codigo, char **&alumno_Nombre,
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala);
void funcionLeerModalidad(ifstream &file, char &modalidad, int &escala, int &porcentaje);
void recorteLecturaAlumno(int cnt, int *&alumno_Codigo, char **&alumno_Nombre,
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala);
void inicializarValoresAlumno(int cnt, int *&alumno_Codigo, char **&alumno_Nombre,
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala);
void borrarValoresAlumno(int *&alumno_Codigo, char **&alumno_Nombre,
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala);
void pruebaLecturaAlumnos(const char *nombre_archivo,
        int *alumno_Codigo, char ** alumno_Nombre,
        char *alumno_Modalidad, int *alumno_Porcentaje,
        int *alumno_Escala);
// Funciones para la Lectura de Cursos
void lecturaCursos(const char *nombre_archivo, int * alumno_Codigo,
        int *alumno_Escala, char ** curso_Nombre,
        double *curso_Credito, int ** curso_Alumnos);
void inicializarValoresCursos(const int cnt, char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos);
bool existeCurso(const char *curso, char **&curso_Nombre);




void pruebaDeLecturaCursos(const char *nombre_archivo,
        char **curso_Nombre, double * curso_Credito,
        int **curso_Alumnos);

void reporteDeRecaudacionPorModalidad(const char *nombre_archivo, int *alumno_Codigo,
        char *alumno_Modalidad, int *alumno_Porcentaje, char **alumno_Nombre,
        char **curso_Nombre, double *curso_Credito, int **curso_Alumnos);
#endif /* METODODINAMICOEXACTO_H */