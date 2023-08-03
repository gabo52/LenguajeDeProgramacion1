/* 
 * File:   FuncionesEx01_20201_Preg02.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de octubre de 2022, 06:36 PM
 */

#ifndef FUNCIONESEX01_20201_PREG02_H
#define FUNCIONESEX01_20201_PREG02_H

#include <fstream>
using namespace std;
void leerSesiones(void *&sesi);
void incrementarEspacioDescripcionSesiones(void **&descSesiones,int &numDat,int &cap);
void *hallarDescripcionSesiones(ifstream &arch);
void asignarDescripcionASesion(int &dia,int &Hi,int &Mi,int &Hf,int &Mf,
        void *&descSesiones);
void incrementarSesiones(void **&sesiones,int &numDat,int &cap);
char * leerCadenaTxt(ifstream &arch);
void imprimirSesiones(void *&sesiones);
void imprimirSesion(void *sesi,ofstream &arch,int i);
void imprimirCabeceraSesion(void **sesiones,ofstream &arch,int i);
void asignarSesiones(void *&sesi,char *codCur,char *codHor,int cantAlum,
        int codProf, void *descSesiones);
void imprimeReg(void *sesi);
void imprimirClases(void *sesi,ofstream &arch);
void imprimeDiaSesion(int num,ofstream &arch);
void imprimeDia(int dd,ofstream &arch);
#endif /* FUNCIONESEX01_20201_PREG02_H */

