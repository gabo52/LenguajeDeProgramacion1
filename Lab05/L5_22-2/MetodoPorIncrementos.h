/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoPorIncrementos.h
 * Author: cesar
 *
 * Created on 07 May 2023, 20:14
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>

void cargarCitas(const char*,char***&,double*&,char****&,int**&,double***&);
void pruebaDeCargaDeCitas(const char*,char***,double*,char****,int**,double***);
void reporteDeCitasPorMedico(const char*,char***,double*,char****,int**,double***);
int leerCadena(ifstream&,char*&);
void incrementarArrMed(char***&,double*&,char****&,int**&,double ***&,int&,int&);
void incrementarArrCitas(char***&,int*&,double**&,int&, int&);
void agregarDatos(char***&,char*,char*,int*&,double**&,int&,int,int,int,int,int,int,double);
void agregarMedico(char**&,double&,double,char*,char*,int&);
int noesrepetido(char*,char***,int);


#endif /* METODOPORINCREMENTOS_H */
