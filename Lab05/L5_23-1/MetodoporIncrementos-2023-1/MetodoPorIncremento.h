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

void cargarCursos(const char *nombreArchivo, char ***&cursos_datos, int *&cursos_credito, char ****&cursos_alumnos,
                  double **&cursos_informacion_economica);

void leerCurso(ifstream &file, char ***&cursos_datos, int &cntCursos);

bool existeCurso(char ***&cursos_datos, const int cntCursos, const char *nombreCurso);

bool compararCurso(char **curso_datos, const char *nombreCurso);

void incrementarCursos(char ***&cursos_datos, const int cntCursos);

void agregarCurso(char **&cursos_datos, const char *codigoCurso, const char *nombreCurso);

void agregarCodigoCurso(char *&cursos_datos, const char *codigoCurso);

void agregarNombreCurso(char *&cursos_datos, const char *nombreCurso);

void leerCredito(ifstream &file, int *&cursos_credito, int cntCursos);

void leerAlumnos(ifstream &file, char ****&cursos_alumno, const int cntCurso);

void incrementarAlumnos(char ****&cursos_alumno, int cntCurso);

void agregarAlumno(char ***&cursos_alumno, int cntAlumnos, const char *nombreAlumno, const char *codigoEscalaStr);

void insertarAlumno(char **&cursos_alumno, const char *nombreAlumno, const char *codigoEscalaStr);

void pruebaCursos(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito, char ****cursos_alumnos,
                  double **cursos_informacion_economica);

void calcularInformacionEconomica(double **&cursos_informacion_economica, char ***&cursos_alumnos, int cntCursos,
                                  int *creditos);

void incrementarInformacionEconomica(double **&cursos_informacion_economica, int cntCursos);

int obtenerEscalaAlumno(char **cursos_alumnos);

void imprimirCodCurso(ofstream &file, char **cursos_datos, int credito);

void imprimirAlumnos(ofstream &file, char ***cursos_alumnos);

void imprimirAlumno(ofstream &file, char **cursos_alumnos);

void imprimirInformacionEconomica(ofstream &file, double *cursos_informacion_economica);
void reporteDeAlumnosPorCurso(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito,
    char ****cursos_alumnos,double **cursos_informacion_economica);
void imprimirCabecerReporte(ofstream &file, int credito);
void imprimirNameCodCurso(ofstream &file,char **cursos_datos);
void
imprimirAlumnosReporte(ofstream &file, char ***cursos_alumnos, double *cursos_informacion_economica, int credito);
int obtenerCodigoAlumno(char **cursos_alumnos);
char *obtenerNombreAlumno(char **cursos_alumnos);
double obtenerPagoAlumno(char **cursos_alumnos, int credito);
void imprimirTotalReporte(ofstream &file, double *cursos_informacion_economica);
#endif //METODOPORINCREMENTOS_2023_1_METODOPORINCREMENTO_H
