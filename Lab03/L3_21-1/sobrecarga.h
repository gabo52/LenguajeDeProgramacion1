
/* 
 * File:   sobrecarga.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 04:15 PM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include <fstream>
using namespace std; 

void imprimirLinea(ofstream &out, int n, char c); 
void operator*(struct ConductorSt &conductor, int fecha);
void operator ++(struct ConductorSt &conductor, int b);
int buscarInfraccion(const struct ConductorSt conductor, int codigo);
void operator+(struct ConductorSt &conductor, const struct InfraccionEstabSt infraccion);
ofstream &operator << (ofstream &out, const struct ConductorSt &conductor);
void operator+(struct ConductorSt &conductor, const struct InfraccionSt infraccion);
bool operator >> (ifstream &in, struct InfraccionEstabSt &infraccion);
bool operator >> (ifstream &in, struct InfraccionSt &infraccion);
bool operator >> (ifstream &in, struct ConductorSt &conductor); 

#endif /* SOBRECARGA_H */

