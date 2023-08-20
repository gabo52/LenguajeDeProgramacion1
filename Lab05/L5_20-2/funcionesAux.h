/* 
 * File:   funcionesAux.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de septiembre de 2022, 04:57 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
using namespace std;
void AbrirArchivoLectura(const char *nombre,ifstream &arch);
void AbrirArchivoEscritura(const char *nombre,ofstream &arch);
char *leerCadena(ifstream &arch,char c);
void leerMedicos(char **&codMed,char **&nombMed,double *&tarifas);
void incrementarEspacios(char **&codMed,char **&nombMed,double *&tarifas, 
        int &numDat,int &cap);
void repMedicos(char **codMed,char **nombMed,double *tarifas);
void leerAtenciones(char **&codMed,int **&codPac,char ***&nombPac,double **&porcPac,int **&veces);
void repDeIngresos(char **codMed,char **nombMed,double *tarifas,int **codPac,
        char ***nomPac,double **porcPac,int **veces);
void leerAtencionesFecha(char **codMed,int **&codPac,char ***&nombPac,double **&porcPac,
        int **&veces,ifstream &arch,int *numDat,int *cap,int fecha);
void cargarAtencionPacienteAMedico(int *&codPac,char **&nombPac,double *&porcPac,
                int *&veces,int codigo,char *nomb,char estado,double porc,
        int &numDat,int &cap);
void incrementarEspaciosPac(int *&codPac,char **&nombPac,double *&porcPac,
        int *&veces,int &numDat,int &cap);
int buscarMed(char *codMedico,char **codMed);
int leerFecha(ifstream &arch);
void imprimeMedico(char*codMed,char*nombMed,double tarifa,int *codPac,
        char **nomPac,double *porcPac,int *veces,ofstream &arch);
void imprimirLinea(ofstream &arch,int cant,char c);
void imprimeResumen(int totCit,double pago,double recibido,ofstream &arch);
#endif /* FUNCIONESAUX_H */

