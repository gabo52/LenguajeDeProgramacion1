
/* 
 * File:   MemoriaDinamica.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 4 de mayo de 2023, 08:26 PM
 */

#ifndef MEMORIADINAMICA_H
#define MEMORIADINAMICA_H
#include <fstream>
using namespace std;

void cargarMedicos(char **&codigoMed, char **&medicos, double *&tarifas);
void reporteMedicos(char **codigoMed, char **medicos, double *tarifas);
void reporteDeIngresos(char **codigoMed, char **medicos, double *tarifas);
void cargarPacientes(char *codMed,int *&codigoPac, char **&pacientes, double *&porcentajes, int *&veces);
int buscarpaciente(int *auxpacientes,int numDat, int codigopaciente);
void reporteDelMedico(char *codMed, char **codigoMed, char **medicos, double *tarifas,int *codigoPac, char **pacientes, double *porcentajes, int *veces);
char *leeCadena(ifstream &arch);
char *leeCadena(ifstream &arch,char c);

#endif /* MEMORIADINAMICA_H */

