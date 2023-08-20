/* 
 * File:   funcionesAuxiliares.h
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 * Created on 5 de septiembre de 2022, 10:33 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;
ofstream abrirArchiE(const char*nombre,char modo);
ifstream abrirArchiL(const char*nombre,char modo);
void leeFalta(char *placa,int &fecha,char *codigo,ifstream &arch);
void cargarGravedadCodigo(char *cod,ofstream &arch);
void cargaFaltaCometidaBin(ofstream &arch,char *placa,int licencia,
        int fecha,char *cod,double monto,int &flag);
void cargaRegConductorBin(int licencia,char *nombre,int cantFaltL,int cantFaltG,
        int cantFaltM,double pagarL,double pagarG,double pagarMG,double totPagar,
        ofstream &arch);
void crearCargarConductorFaltasCometidasBin();
void leerRegConductoresBin(ifstream &arch,int &licencia,int &nFL,int &nFG,
        int &nFMG,double &montFL,double &montFG,double &montFMG,double &totPag,
        char *nombre);
void verificarConductoresBin();
void imprimeFecha(int fecha,ofstream &archRep);
void leerFaltasBin(char  *placa,int &licencia,int &fecha,char *gravedad,int &codigo,
        double &monto,ifstream &arch);
void verificarFaltasCometidasBin();
void crearCargarListadoInfracciones();
void verificarListadoInfracciones();
void completarConductoresFaltasCometidasBin();
void actualizarConductoresFaltasCometidasBin();
#endif /* FUNCIONESAUXILIARES_H */

