
/* 
 * File:   FuncionesLaboratorio02.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 03:50 PM
 */

#ifndef FUNCIONESLABORATORIO02_H
#define FUNCIONESLABORATORIO02_H
#include <fstream>
using namespace std;

char *leerCadena(ifstream &arch,char c); 
void *leeregistro(ifstream &arch); 
void imprimeregistro(void *dt, ofstream &arch); 
int hallaHoras(int &hh,int &ss,int &mm,int tiempo);

#endif /* FUNCIONESLABORATORIO02_H */

