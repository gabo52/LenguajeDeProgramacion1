
/* 
 * File:   Funciones.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 18 de abril de 2023, 08:13 AM
 */

#include <fstream>
using namespace std; 
#ifndef FUNCIONES_H
#define FUNCIONES_H

void insertaconsultamed(ofstream &, int);
void imprimirmedicos(ofstream &, ifstream &);
void insertaconsultamed(ofstream &, int);
void imprimearchivo();
void leerarchivos(); 
int verifica(int, const char *);
void insertamedicamento(ofstream &, int, char *, double);
void sacaespecialidad(char *, char *);
void insertamedico(ofstream &, char *, char *);
void insertapaciente(ofstream &, int , char *);
void insertaconsultas(ofstream &, int , char *, int , int , int , int );

#endif /* FUNCIONES_H */

