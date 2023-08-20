
/* 
 * File:   Funciones.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 19 de abril de 2023, 03:13 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

void leerarchivos();
void generaconsolidado();
void leeralumnos();
void leercursos();
void imprimeconsolidado();
void imprimirLinea(char c, int n, ofstream &arch);
void cargaralumnos(ofstream &archAluBin, int codAlumno, char tipo, char *nombre, int carne, char *especialidad, char *facultad);

#endif /* FUNCIONES_H */

