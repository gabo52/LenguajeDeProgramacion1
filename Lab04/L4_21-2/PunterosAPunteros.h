/* 
 * File:   PunterosAPunteros.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de septiembre de 2022, 04:52 PM
 */

#ifndef PUNTEROSAPUNTEROS_H
#define PUNTEROSAPUNTEROS_H
#include <fstream>
using namespace std;

void estructuraParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,
        int *&cantEnBibl,double *&precio);
void estructuraParaLosLibros_Reporte(char **codigo,char **titulo,
        int *cantEnBibl,double *precio);
void usuarioDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre);
void usuarioDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre);
void libroYUsuariosInhabilitados_Reporte(char **&codigo,char **&titulo,
        int *&cantEnBibl,double *&precio,int *carne,char *tipo,char **nombre);
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
        int *carne,char **nomb,double penalidad,char *codLib,int *&cantEnBibl,
        double *&deudaLib);
void elaborarReporteSegunTipo(char **codigo,char **titulo,
        int *&cantEnBibl,double *precio,int *carne,char *tipo,char **nombre,
        char tip,ifstream &arch,ofstream &archRep,double *&deudaLib);
void elaborarReporteLibros(char **codigo,char **titulo,int *cantEnBibl,
        double *precio,ofstream &archRep,double *deudaLib);
int diasNoPermitidos(int datoFecha,int fecha,char tip,double &penalidad);
int buscarCarne(int carne,int *buff,int numDat);
#endif /* PUNTEROSAPUNTEROS_H */

