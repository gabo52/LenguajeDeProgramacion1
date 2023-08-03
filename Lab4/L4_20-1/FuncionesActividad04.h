/* 
 * File:   FuncionesActividad04.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 18 de septiembre de 2022, 10:11 PM
 */

#ifndef FUNCIONESACTIVIDAD04_H
#define FUNCIONESACTIVIDAD04_H

#include <fstream>
using namespace std;

void abrirArchivosLectura(const char *nombre,ifstream &arch);
void abrirArchivosEscritura(const char *nombre,ofstream &arch);
char * leerCadena(ifstream &arch,char c);
void leerAlumnos(int *&codigos,char **&nombres,char ***&cursos);
void imprimirAlumnos(int *codigos,char **nombres);
void limpiaLinea(ifstream &arch);
void agregaCurso(char **&cursos,char *codigo,int &numDat);
int buscarEntero(int *arr,int buscar);
void leerCursos(int *codigos,char ***&cursos);
void imprimeCursos(char **cursos,ofstream &arch);
void imprimirReporte(int *codigos,char **nombres,char ***cursos);
void espaciosExactos(char **&cursos, int nd);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* FUNCIONESACTIVIDAD04_H */

