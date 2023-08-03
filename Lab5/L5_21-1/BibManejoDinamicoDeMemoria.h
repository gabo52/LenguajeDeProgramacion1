/* 
 * File:   BibManejoDinamicoDeMemoria.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de septiembre de 2022, 02:37 PM
 */

#ifndef BIBMANEJODINAMICODEMEMORIA_H
#define BIBMANEJODINAMICODEMEMORIA_H
#include <fstream>
using namespace std;

void AbrirArchivoLectura(const char *nomb,ifstream &arch);
void AbrirArchivoEscritura(const char *nomb,ofstream &arch);
char *leerCadena(ifstream &arch,char ='\n');
void cargaConductores(int *&licencia,char **&conductor);
void incrementarEspacios(int *&lic,char **&conduc,int &numDat,int &cap);
void reporteConductores(int *licencia,char **&conductor);
void cargaFaltas(int *licencia,char ***&placa,int **&falta);
void reporteFaltas(int *licencia,char **conductor,char ***placa,int **falta);
void resumenFaltas(int *licencia,int **falta,double **&multa);
void reporteMultas(int *licencia,char **conductor,double **multa);
int buscarInt(int dato,int *arr);
void incrementarFaltas(char **&placa,int *&falta,int &numDat,int &cap);
void agregarFalta(char **&placa,int *&falta,int &numDat,int &cap,char *placas,
        int infrac);
void imprimeFaltas(char **placa,int *falta,ofstream &archRep);
void imprimeMultas(double *multa,ofstream &arch);
double buscarMulta(int codFalta,ifstream &arch,int &i);
void hallarMultasLicencia(int *falta,double *&multa,ifstream &arch);
#endif /* BIBMANEJODINAMICODEMEMORIA_H */

