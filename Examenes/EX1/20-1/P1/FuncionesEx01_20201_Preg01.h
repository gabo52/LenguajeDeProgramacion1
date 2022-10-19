/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEx01_20201_Preg01.h
 * Author: alulab14
 *
 * Created on 3 de octubre de 2022, 05:44 PM
 */

#ifndef FUNCIONESEX01_20201_PREG01_H
#define FUNCIONESEX01_20201_PREG01_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *, ifstream &);
void AbrirArchivo(const char *, ofstream &);
void leerDatos(char ***&,int *&,char **&);
void leerCargarProfesores(int *&,char **&);
void incrementarProfesores(int *&,char **&,int &,int &);
void leerCargarCursos(char ***&);
void agregaDatosCurso(char **&,char *,char *,char *);
void incrementarCursos(char ***&,int &,int &);
void imprimeCabeceraCursos(ofstream &);
void imprimeCurso(int ,char **,ofstream &);
void imprimeCabeceraProfesores(ofstream &);
void imprimirDatos(char ***,int *,char **);
void imprimeProfesor(int ,int ,char *,ofstream &);
char * leerCadena(ifstream &,char );
char * leerCadena(ifstream &,char ='\n');

#endif /* FUNCIONESEX01_20201_PREG01_H */

