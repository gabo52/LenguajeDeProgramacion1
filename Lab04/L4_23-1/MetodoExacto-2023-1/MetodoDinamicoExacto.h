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
#define MAX_ALUMNO_CURSO 100 // 50 alumnos maximos
#define MAX_CURSO 50
#define MAX_LINEA 120
#define MAX_ESCALA 5
using namespace std;
// funciones de apertura de archivo
void  abrirArchivoLectura(ifstream &file,const char *nombre_archivo);
void abrirArchivoEscritura(ofstream &file,const char *nombre_archivo);

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
void lecturaCursos(const char *nombre_archivo, int * alumno_Codigo, int *alumno_Escala,
                   char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos);
void inicializarValoresCursos(const int cnt, char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos);
void agregarCurso(const char *curso,double credito,char **&curso_Nombre,double *curso_Credito,
                  int **&curso_Alumnos);
void agregarAlumno(int codigo,int *alumno_Codigo,int *alumno_Escala,int **&curso_Alumnos,
                   const char *curso, char **curso_nombre);
void insertarAlumno(int *&curso_Alumnos,int codigo,int escala);
void pruebaDeLecturaCursos(const char *nombre_archivo,
        char **curso_Nombre, double * curso_Credito,
        int **curso_Alumnos);
void imprimirAlumno(ofstream &file,int *curso_Alumnos);

void reporteDeRecaudacionPorModalidad(const char *nombre_archivo, int *alumno_Codigo,
        char *alumno_Modalidad, int *alumno_Porcentaje, char **alumno_Nombre,
        char **curso_Nombre, double *curso_Credito, int **curso_Alumnos);
void imprimirCurso(ofstream &file,const int cnt,const char *nombre,const double credito);
void imprimirAlumnosDelCurso(ofstream &file, int *curso_Alumnos, int *alumno_codigo, char **alumno_Nombre,
                             char *alumno_Modalidad, int *alumno_Porcentaje, double creditoCurso,double  *&pagoTotal);
void imprimirPago(ofstream &file, char modalidad, int porcentaje, double *escala, int escalaAlumno,
                  double creditoCurso,double *&pagoTotal,double *&pagoTotalCurso);
void imprimirPagoCurso(ofstream &file, double *pagoTotalCurso);
void obtenerEscalas(double *&escala);
void imprimirResultadoCurso(ofstream &file,double *pagoTotal);
#endif /* METODODINAMICOEXACTO_H */