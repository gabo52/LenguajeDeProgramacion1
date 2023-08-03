/* 
 * File:   BibliotecaMemoriaDinamica.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 21 de septiembre de 2022, 09:09 PM
 */

#ifndef BIBLIOTECAMEMORIADINAMICA_H
#define BIBLIOTECAMEMORIADINAMICA_H
#include <fstream>
using namespace std;
void AbrirArchivosLectura(const char *nomb,ifstream &arch);
void AbrirArchivosEscritura(const char *nomb,ofstream &arch);
char *leeCadena(ifstream &arch);
char *leeCadena(ifstream &arch,char c);
void cargarConductores(int *&licencia,char **&conductor);
void reporteConductores(int *licencia,char **conductor);
void cargaInfracciones(int *&infraccion,char *&gravedad,double *&multa);
void reporteInfracciones(int *infraccion,char *gravedad,double *multa);
void reporteDeFaltas(int *licencia,char **conductor,int *infraccion,
        char *gravedad,double *multa);
void limpiaMemoria(int *&licencia,char **&placas,int *&cantidad,
        double *&monto,int numDat,char **&buffPlaca);
void imprimeLinea(ofstream &arch,int cant,char c);
void imprimeCabecera(char grav,ofstream &archRep);
void imprimeReporteFalta(int *licencia,char **placas,int *cantidad,double *monto,
        char grav,ofstream &archRep);
int existePlaca(char *placa,char **buffPlaca,int numDat,int &pos);
void agregaInfraccion(int *buffLic,int *buffCant,double *buffMonto,
        char **&buffPlaca,int &numDat,int lic,char *placa,int infrac,double mult);
int infraccionAcordeGravedad(int infrac,char grav,double &mult,double *multa,
        int *infraccion,char *gravedad);
void imprimeFaltas(ifstream &arch,int *licencia,char **conductor,int *infraccion,
        char *gravedad,double *multa, char grav,ofstream &archRep);
int leeFecha(ifstream &arch);
#endif /* BIBLIOTECAMEMORIADINAMICA_H */

