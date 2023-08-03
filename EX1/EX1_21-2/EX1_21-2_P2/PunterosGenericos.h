/* 
 * File:   PunterosGenericos.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de octubre de 2022, 07:43 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void cargalibros(void *&st);
void *leerRegLib(ifstream &arch);
void *crea3erNivel(int numStock);
void *creaDinamico4toNivel(int num);
char *leerCadena(ifstream &arch,char c);
void actualiza(void *&st);
void actualiza4toNivel(void *&nivel3,int fecha,double precio);
int obtieneMes(int fecha);
int buscarCodLib(char *codLib,void **stock,int *&disponible,void *&nivel3,
        int nCopia,double &precio);
int comparaLibro(char *codLib,void *st,int *&disponible,void *&nivel3,int nCopia,
        double &precio);
void *buscaNCopia(void *st,int nCopia);
int leerFecha(ifstream &arch);
void imprimestock(void *&st);
void imprimeStockLibro(void *&st,ofstream &arch);
void imprimeDetalleCopias(void *st,ofstream &arch);
void imprimeDetalleUnaCopia(void *st,int i,ofstream &arch);
void imprimeFecha(int fecha,ofstream &arch);

#endif /* PUNTEROSGENERICOS_H */

