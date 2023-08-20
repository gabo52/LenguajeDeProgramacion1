/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: alulab14
 *
 * Created on 7 de septiembre de 2022, 03:18 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>

using namespace std;

ofstream AbrirArchE(const char *nombre,char modo);
ifstream AbrirArchL(const char *nombre,char modo);
fstream AbrirArchA(const char *nombre,char modo);
void cargaRegAlumnosBin(ofstream &arch,char tipo,int carnet,char *nombre,
        int carnetExtranjeria,char *especialidad,char *facultad);
void  imprimeRepConsolidadoBin();
void imprimeRegConsolidadoBin(ofstream &arch,int &codigo,char *nombre,
        double &cantCredCur,double &cantCredAprob,int &sumNot,int &cantMat,
        char *facultad,int estado,ofstream &archAlum,int &cantAlumReg,
        int &cantAlumInt,int &cantAlumIntSC);
int hallarCarnet(ifstream &arch,int codigo,char &tipo);
void leerRegAlumBin(ifstream &arch,char &tipo,int &carnet,char *nombre,
        int &carnetExtranjeria,char *especialidad,char *facultad);
void leerRegConsolidadoBin(ifstream &arch,int &codigo,char *nombre,
        double &cantCredCur,double &cantCredAprob,
                int &sumNot,int &cantMat,char *facultad,int &estado);
void imprimeResumen(int cantAlumReg,int cantAlumInter,int cantAlumIntSC,
        int cantEgresados,ofstream &arch);
void imprimeCabeceraRep(ofstream &archRep);
void imprimeLinea(char c,int cantidad,ofstream &arch);
void crearCargarConsolidadosBin();
void crearCargarAlumnosBin();
void cargaRegAlumnosBin(ofstream &arch,char tipo,int carnet,char *nombre,
        int carnetExtranjeria,char *especialidad,char *facultad);
void cargaRegConsolidadoBin(int codigo,char *nombre,double cantCredCur,
        double cantCredAprob,int sumNot,int cantCurMat,char *facultad,int estado,
        fstream &arch);
int buscarCodigo(int codigo,fstream &archBin);
void actualizaReg(fstream &arch,int pos,int nota,double creditos);
void leerRegConsolidadoBinActu(fstream &arch,int &codigo,char *nombre,
        double &cantCredCur,double &cantCredAprob,
                int &sumNot,int &cantMat,char *facultad,int &estado);
void abrirArch();
#endif /* FUNCIONESAUX_H */

