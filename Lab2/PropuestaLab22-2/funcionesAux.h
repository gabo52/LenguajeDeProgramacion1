/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: Gabo
 *
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

