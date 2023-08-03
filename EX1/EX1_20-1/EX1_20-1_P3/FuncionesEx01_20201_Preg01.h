/* 
 * File:   FuncionesEx01_20201_Preg01.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de octubre de 2022, 05:44 PM
 */

#ifndef FUNCIONESEX01_20201_PREG01_H
#define FUNCIONESEX01_20201_PREG01_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nombre, ifstream &arch);
void AbrirArchivo(const char *nombre, ofstream &arch);
void leerDatos(char ***&cursos,int *&codProfesores,char **&profesores);
void leerCargarProfesores(int *&codProfesores,char **&profesores);
void incrementarProfesores(int *&codProfesores,char **&profesores,int &numDat,
        int &cap);
void leerCargarCursos(char ***&cursos);
void agregaDatosCurso(char **&curso,char *cod,char *nombCur,char *esp);
void incrementarCursos(char ***&cursos,int &numDat,
        int &cap);
void imprimeCabeceraCursos(ofstream &arch);
void imprimeCurso(int i,char **cursos,ofstream &arch);
void imprimeCabeceraProfesores(ofstream &arch);
void imprimirDatos(char ***cursos,int *codProfesores,char **profesores);
void imprimeProfesor(int i,int codigo,char *nombProf,ofstream &arch);


char * leerCadena(ifstream &arch,char c);

char * leerCadena(ifstream &arch,char ='\n');

#endif /* FUNCIONESEX01_20201_PREG01_H */

