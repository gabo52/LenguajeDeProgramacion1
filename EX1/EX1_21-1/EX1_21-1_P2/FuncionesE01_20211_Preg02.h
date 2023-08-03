/* 
 * File:   FuncionesE01_20211_Preg02.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de octubre de 2022, 08:12 PM
 */

#ifndef FUNCIONESE01_20211_PREG02_H
#define FUNCIONESE01_20211_PREG02_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void cargaDatos(void *&conductor,void *&falta);
void cargaConductor(void *&conduc);
void *leeConductor(ifstream &arch);
char *leerCadena(ifstream &arch,char c);
void cargaFaltas(void *&falt);
void leerDatos(int &licencia,int *&mm,int *&aa,int &infraccion,ifstream &arch);
void *leeRegFalta(ifstream &arch);
void registrafaltas(void *&consolidado,void *&conductor,void *&falta);
void imprime(void *consolidado);
void ordenaConsolidado(void **&consolidado);
void qSort(void **consolidado,int izq,int der);
int enDesorden(void *aux1,void *aux2);
void cambiar(void *&dato1,void *&dato2);
int obtieneLicencia(void *aux,char *&nomb);
void imprimeCabecera(int lic,char *nomb,ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);
void imprimeRegConsolidado(void *aux,ofstream &arch);
void creaConsolidado(void *&Consolidado,int licencia,int *mm,int *aa,
        int infraccion,void *conductor,void *falta);
void agregaMonto(void *&buff,int infraccion,void *falta);
double hallaCostoInfraccion(int infraccion,void *fault);
void buscaConductor(int licencia,void *conduct,char *&nomb,int *&licenciaP);
int buscaConsolidado(void **buffConsolidado,int nd,int licencia,int mm,int aa);
int comparaConsolidado(void *aux,int licencia,int mm,int aa);
int comparaConductor(int licencia,void *conduct,char *&nomb,int *&licenciaP);
int comparaInfraccion(int &infraccion,void *fault,double &monto);
#endif /* FUNCIONESE01_20211_PREG02_H */

