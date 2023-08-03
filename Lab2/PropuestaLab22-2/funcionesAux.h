/* 
 * File:   funcionesAux.h
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 * Created on 8 de septiembre de 2022, 08:16 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
using namespace std;

ofstream abrirArchivoE(const char *nombre,char modo);
ifstream abrirArchivoL(const char *nombre,char modo);
void crearCargarMedicosBin();
void verificarMedicosBin();
void crearCargarMedicinasBin();
void verificarMedicinasBin();
void crearCargarPacientesBin();
void imprimirFecha(int fecha,ofstream &arch);
void verificarPacientesBin();
void crearReporteMedicos();
void imprimeAtencionPaciente(char *nombre,int DNI,int fecha,int codMedicina,
        ifstream &archBinMedicamentos,ofstream &rep);
void hallarNombMedicamento(char *nomb,int cod,ifstream &arch);
void imprimeAtencionesMedico(char *codigo,ifstream &archBinPac,
        ifstream &archBinMedicamentos,ofstream &rep);
void imprimeCabeceraMedico(char *codigo,char *nombre,char *especialidad,
        ofstream &rep);

#endif /* FUNCIONESAUX_H */

