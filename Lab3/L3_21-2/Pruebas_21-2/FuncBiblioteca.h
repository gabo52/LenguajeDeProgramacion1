/* 
 * File:   FuncBiblioteca.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de septiembre de 2022, 12:27 AM
 */

#ifndef FUNCBIBLIOTECA_H
#define FUNCBIBLIOTECA_H
#include <fstream>
#include "Estructuras.h"
using namespace std;
bool operator >> (ifstream &in, Libro &lib);
bool operator >> (ifstream &in, Usuario &usuario);
void operator += (Usuario &usuario,LibroPrestado lib );
void operator += (Libro &lib,UsuarioPrestamo usuario);
void operator <= (Usuario &usuario, int fecha);
void imprimeFecha(ofstream &arch,int fecha);
void imprimeLibro(ofstream &arch,LibroPrestado lib);
void imprimeLinea(ofstream &arch,int cant,char c);
void operator << (ofstream &arch,const Usuario &usuario);
void imprimePrestamos(ofstream &arch,const char *cadena,const UsuarioPrestamo *arr,
        int cant);
void operator << (ofstream &arch,const  Libro &lib);
int numeroDeDias(int fecha1,int fecha2);
void fTodma(int fecha, int &dd, int &mm, int &aa);
int diasDelMes(int mm, int aa);
ofstream abrirArchivoE(const char *nombre,char modo);
ifstream abrirArchivoL(const char *nombre,char modo);

#endif /* FUNCBIBLIOTECA_H */

