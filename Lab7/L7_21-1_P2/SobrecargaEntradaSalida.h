/* 
 * File:   SobrecargaEntradaSalida.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de noviembre de 2022, 10:58 PM
 */

#ifndef SOBRECARGAENTRADASALIDA_H
#define SOBRECARGAENTRADASALIDA_H
#include "Conductores.h"
#include "Falta.h"
#include <fstream>
using namespace std;


void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
int leerFecha(ifstream &arch);
char *leerCadena(ifstream &arch, char c);
void imprimirFecha(ofstream &arch,int fecha);
ifstream& operator >>(ifstream &arch, Conductores &conductor);
ifstream & operator >>(ifstream &arch, Falta &falta);
ifstream & operator >>(ifstream &arch, Infraccion &infrac);
ofstream & operator <<(ofstream &arch,Conductores &conduc);
#endif /* SOBRECARGAENTRADASALIDA_H */

