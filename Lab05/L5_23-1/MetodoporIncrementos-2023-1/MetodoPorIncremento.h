#ifndef METODOPORINCREMENTOS_2023_1_METODOPORINCREMENTO_H
#define METODOPORINCREMENTOS_2023_1_METODOPORINCREMENTO_H
// Librerias
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

//Define
#define MAX_LINEA 110
#define INCREMENTO 5
#define MAX_CODIGO_CURSO 7
#define MAX_NOMBRE_CURSO 50
#define MAX_NOMBRE_ALUMNO 50
#define MAX_CODIGO_ESCALA 11
// Escalas
#define  ESCALA1 282.3
#define  ESCALA2 362
#define  ESCALA3 454.2
#define  ESCALA4 556.7
#define  ESCALA5 666.9

using namespace std;

//Funciones de Apertura de Archivo;
void abrirArchivoLectura(ifstream &file, const char *nombre);

void abrirArchivoEscritura(ofstream &file, const char *nombre);

void cargarCursos(const char *nombreArchivo, char ***&cursos_datos, int *&cursos_credito, char ***&cursos_alumnos,
                  double **&cursos_informacion_economica);

void leerCurso(ifstream &file, char ***&cursos_datos, int &cntCursos);

bool existeCurso(char ***cursos_datos, const int cntCursos, const char *nombreCurso);

bool compararCurso(char **curso_datos, const char *nombreCurso);

void incrementarCursos(char ***&cursos_datos, const int cntCursos);

void agregarCurso(char **&cursos_datos, const char *codigoCurso, const char *nombreCurso);

void agregarCodigoCurso(char *&cursos_datos, const char *codigoCurso);

void agregarNombreCurso(char *&cursos_datos, const char *nombreCurso);

void leerCredito(ifstream &file, int *&cursos_credito, int cntCursos);

void leerAlumnos(ifstream &file, char ***&cursos_alumno, const int cntCurso);

void incrementarAlumnos(char ***&cursos_alumnos, int cntCurso);

void agregarAlumno(char **&cursos_alumno, int cntAlumnos, char *nombreAlumno, char *codigoEscalaStr);

void pruebaCursos(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito, char ***cursos_alumnos,
                  double **cursos_informacion_economica);

void imprimirCodNombreCurso(ofstream &file, char **codNombreCurso, int credito);
//void
//reporteDeAlumnosPorCurso(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito, char ***cursos_alumnos,
//                         double **cursos_informacion_economica);

#endif //METODOPORINCREMENTOS_2023_1_METODOPORINCREMENTO_H
