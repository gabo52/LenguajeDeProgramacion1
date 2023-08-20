/* 
 * File:   ColaPacientes.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de octubre de 2022, 04:23 PM
 */

#ifndef COLAPACIENTES_H
#define COLAPACIENTES_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
char *leerCadena(ifstream &arch,char c);
void *leeRegistroPaciente(ifstream &arch);
void *hallaRegistroSegunTipo(int *DNIP,char *nombre,char *tipoP,ifstream &arch);
int obtienePrioridadPaciente(void *dt);
void imprimeRegPacientes(void *dt,ofstream &arch);
#endif /* COLAPACIENTES_H */

