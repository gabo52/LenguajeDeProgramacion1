/* 
 * File:   funcionesAuxiliares.h
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 * Created on 4 de septiembre de 2022, 12:35 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

void verificarLibrosBin();
void crearCargarLibrosBin();
void cargarLibrosBin(ofstream &archLibBin);
ofstream abrirArchivoE(const char *nombre,char modo);
ifstream abrirArchivoL(const char *nombre,char modo);
void crearLibrosBin(ofstream &archLibBin);
void crearCargarPrestamosUsuariosBin();
void verificarUsuariosBin();
void actualizarLibrosBin();
void imprimeReporteLibrosBin();
void imprimeCabeceraLibros(ofstream &librosRep);
void imprimeCabeceraPrestamos(ofstream &archBin);
void imprimirFecha(ofstream &archRep,int fecha);
void verificarPrestamosBin();
void cargaUsuario(int carnet,char digito,char *nombre,int contador,ofstream &usuariosBin);
void leeDigitoYNombre(ifstream &archRegPrestamos,char &digito,int &contador,
        char *nombre);
void leeCargaPrestamoLibro(ifstream &arch,ofstream &libBin,int carnet,int &contador,
        int &flag);
void leerFecha(int &fecha,ifstream &arch);
#endif /* FUNCIONESAUXILIARES_H */

