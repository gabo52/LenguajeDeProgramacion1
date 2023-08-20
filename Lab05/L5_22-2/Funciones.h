
/* 
 * File:   Funciones.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 9 de mayo de 2023, 08:29 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

int buscarMedico(char ***medicoDatos, char *codigomedico);
void agregarMedico(char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago, char ***&medicoDatos, double *&medicoTarifaHora, char *codigomedico, char *nombremedico, double tarifa, int &numMed, int &capMed);
void incrementarEspaciosMedicos(char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago, char ***&medicoDatos, double *&medicoTarifaHora, int &cap, int &numMed);
void cargarCitas(char *nomarch, char ***&medicoDatos, double *&medicoTarifaHora, char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago);
char *leerCadena(ifstream &arch,char c);
int buscarPaciente(char ****citaPaciente, char *dni);
void AbrirArchivoEscritura(const char *nomb,ofstream &arch);
void AbrirArchivoLectura(const char *nomb,ifstream &arch);
void agregarCitas(char ***&citaPaciente, int *&citaCantidad, double **&citaTiempoYPago, int &capPac, int &numPac, char *dni, char *nombrepaciente, double tarifa,int Ihh, int Imm, int Iss, int Fhh, int Fmm, int Fss);
void incrementarEspaciosCitas(char ***&citaPaciente, int *&citaCantidad, double **&citaTiempoYPago, int &cap, int &numPac);
int buscarPaciente(char *dni,char ***citaPaciente,int numPac);
void imprimeLinea(ofstream &repo,int n,char c);
void ReporteDeCitasPorMedico(const char*nombArch,char ***medicoDatos,double *medicoTarifaHora,
        char ****citaPaciente,int **citaCantidad,double ***citaTiempoYPago);

#endif /* FUNCIONES_H */

