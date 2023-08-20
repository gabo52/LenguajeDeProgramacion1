
/* 
 * File:   Funciones.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 18 de abril de 2023, 10:31 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

void leerarchivo();
void imprimereportenotas();
void completarcampos();
void insertanotas(ofstream &, int , int , int , char *, int , double , int , int);
void imprimereportealumnos();
void leerprimerarchivo(); 
void leersegundoarchivo();
void completarcamposfaltantes();
void imprimirLinea(ofstream &arch, char c, int n);
void imprimirreportefinal();

#endif /* FUNCIONES_H */

