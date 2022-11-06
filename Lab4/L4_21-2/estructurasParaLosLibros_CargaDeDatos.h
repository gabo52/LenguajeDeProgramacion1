/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estructurasParaLosLibros_CargaDeDatos.h
 * Author: alulab14
 *
 * Created on 22 de septiembre de 2022, 08:25 AM
 */

#ifndef ESTRUCTURASPARALOSLIBROS_CARGADEDATOS_H
#define ESTRUCTURASPARALOSLIBROS_CARGADEDATOS_H
#include <fstream>
using namespace std;
void estructuraParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,
        int *&cantEnBibl,double *&precio);
void estructuraParaLosLibros_Reporte(char **codigo,char **titulo,
        int *cantEnBibl,double *precio);
void usuarioDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre);
void usuarioDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre);
void libroYUsuariosInhabilitados_Reporte(char **codigo,char **titulo,
        int *cantEnBibl,double *precio,int *carne,char *tipo,char **nombre);
char *leeCadena(ifstream &arch,char c);
void AbrirArchivoLectura(const char *nombre,ifstream &arch);
void AbrirArchivoEscritura(const char *nombre,ofstream &arch);
char *leeCadena(ifstream &arch);
void imprimeReporteTipo(int *carneDeuda,int *cantLibDeuda,double *montoDeuda,
        char **nombDeuda,char tip,ofstream &archRep);
void imprimeLinea(ofstream &arch,int cant,char c);
int buscarCarne(int dato,int *arr);
int buscarLibro(char *codLib,char **codigo);
void cargarDeudor(int *buffCarne,int *buffCantLib,char **buffNomb,
        double *buffDeuda,int &numDat,int auxCarne,char **codigo,double *precio,
        int *carne,char **nomb,double penalidad,char *codLib,int *&cantEnBibl);
int diasNoPermitidos(int datoFecha,int fecha,char tip,double &penalidad);
void elaborarReporteSegunTipo(char **&codigo,char **&titulo,
        int *&cantEnBibl,double *&precio,int *carne,char *tipo,char **nombre,
        char tip,ifstream &arch,ofstream &archRep);
void elaborarReporteLibros(char **codigo,char **titulo,int *cantEnBibl,
        double *precio,ofstream &archRep);
#endif /* ESTRUCTURASPARALOSLIBROS_CARGADEDATOS_H */

