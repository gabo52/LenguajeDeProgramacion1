/* 
 * File:   BibCargaFaltas.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de octubre de 2022, 04:44 PM
 */

#ifndef BIBCARGAFALTAS_H
#define BIBCARGAFALTAS_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char* nomb,ifstream &arch);
void AbrirArchivo(const char* nomb,ofstream &arch);
void cargaFaltas(int*&licencia,char ***&placa,int ***&falta,int ***&fecha);

void asignarEspacios(int **&falta,int **&fecha,int numPlac);
void asignaEspaciosFalta(int *&falta,int *&fecha);
int buscarLicencia(int numLic,int *licencia);
int buscarPlaca(char *auxPlaca,char **placa);
void asignaFaltaALicencia(char **placa,int **falta,int **fecha,char *auxPlaca,
        int auxFech,int auxInfrac);
void asignarFaltaAPlaca(int *falta,int *fecha,int auxFech,int auxInfrac);
void leeDatos(ifstream &arch,int &auxLicen,char *&auxPlaca,int &auxFech,
        int &auxInfrac);
char *leerCadena(ifstream &arch,char c);
int hallaCantPlac(char **placa);
void gestaMemoria(int &numLic,int *numPlac,int*&licencia,char ***&placa,
        int ***&falta,int ***&fecha);
void creaBuffs(int **&falta,int **&fecha,int nd);
void reporteFaltas(int*licencia,char **conductor,char ***placa,int ***falta
    ,int ***fecha);
void  imprimeCaberaConductor(int licencia,char *conductor,ofstream &arch);
void imprimeFaltas(char **placa,int **fecha,int **falta ,ofstream &arch,
        int *codInfracc,double *precio);
void hallaFechasMonto(int *fecha,int *falta,double &monto,int &fecha1,
        int &fecha2,int &num,int *codInfracc,double *precio);
double hallaPrecio(int falta,int *codInfracc,double *precio);
void imprimeFecha(int fecha,ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);



#endif /* BIBCARGAFALTAS_H */

