/* 
 * File:   BibliotecaControlDePrestamos.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de octubre de 2022, 04:56 PM
 */

#ifndef BIBLIOTECACONTROLDEPRESTAMOS_H
#define BIBLIOTECACONTROLDEPRESTAMOS_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void cargarPrestamos(int **&fechPrest,char ***&codLibPrest,int *carneUs);
void copiarDinamicamente(int *&fechPrest,char **&codLibPrest,int nd);
void agregaPrestamo(int *&fechPrest,char **&codLibPrest,int &nd,int fecha,
        char *codLib);
int buscarCarne(int carne,int *carneUs);
void leerDatos(int &carne,int &fecha,char &tipo,char *&codLib,ifstream &arch);
char *leerCadena(ifstream &arch,char c);
void imprimeCabeceraLibPrest(int carneUs,char tipoUs,ofstream &arch);
void mostrarLibrosPrestados(int **fechPrest,char ***codLibPrest,int *carneUs,
        char *tipoUs,const char *nomb);
void imprimeFecha(int fechPrest,ofstream &arch);
void imprimeLibrosUsuario(int *fechPrest,char **codLibPrest,ofstream &arch);
void procesarSolicitudes(int *&carneUs,char *&tipoUs,char **&nombreUs,
    int **&fechPrest,char ***&codLibPrest,char **&codLibro,int *&cantLibros);
int cuentaLibros(int *fechPrest);    
void asignarEspaciosDinamicamente(int *&fechPrest,char **&codLibPrest,int nd);
void creaBufferActualiza(int *&fechPrest,char **&codLibPrest,int &nd);
void procesaSolicitud(char tipo,char solicitud,char *codigo,
        int *&fechPest,char **&codLibPrest,char **&codLibro,int *&cantLibros,
        int &nd,ofstream &arch,int &contador,char *nomb);
void imprimirDevolucion(int pos,int *&cantLibros,int *&fechPest,
        char **&codLibPrest,int &nd,char *codigo,ofstream &arch,int pos2);
void imprimePrestamo(int cuentaStock,int noExcedePrestamos,int nohayRetrasosDevolucion,
                int noTieneLibro,int &fecha,char *&codLibPrest,int &nd,
        ofstream &arch,char *codigo,int contador,char *nomb);
int noHayRetrasosDevolucion(int *fechPest,char **codLibPrest);
int noExcedePrestamosPermitidos(int nd,char tipo);
void borraFecha(int fecha,int *&fechPest,char **&codLibPrest);
int buscarLibro(char *codigo,char **codLibPrest);
void leeDatos(int &carne,char &tipo,char &solicitud,char *codigo,ifstream &arch);
#endif /* BIBLIOTECACONTROLDEPRESTAMOS_H */

