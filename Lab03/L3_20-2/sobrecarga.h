
/* 
 * File:   sobrecarga.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 26 de abril de 2023, 07:43 PM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include <fstream>
#include "Estructura.h"
using namespace std;

void imprimirLinea(ofstream &out, int n, char c);
void operator << (ofstream &out,const struct StMedico &medico);
void operator ++(struct StMedico &medico, int b);
void operator / (struct StMedico &medico, const int fecha);
void operator - (struct StMedico &medico, const int fecha);
void operator+(struct StMedico &medico, const int fecha);
void operator+(struct StMedico &medico, const struct StPaciente paciente);
ifstream &operator >> (ifstream &in,struct StPaciente &paciente);
void operator >> (ifstream &in, struct StMedico &medico);

#endif /* SOBRECARGA_H */

