/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 10:40 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Miembro.h"
using namespace std;


void AbrirArchivo(const char *nomb, ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb, ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void operator >> (ifstream &arch, Alumno &alu){
    char cad[120],c;
    arch.getline(cad,120,',');
    if(arch.eof())return;
    alu.SetNombre(cad);
    int codigo;
    arch>>codigo>>c;
    arch.getline(cad,120,',');
    alu.SetDistrito(cad);
    arch>>codigo>>c;
    alu.SetEscala(codigo);
    arch.getline(cad,120,',');
    alu.SetEspecialidad(cad);
    arch.getline(cad,120,'\n');
    alu.SetFacultad(cad);
}

void operator >> (ifstream &arch, Profesor &prof){
    char cad[120],c;
    arch.getline(cad,120,',');
    if(arch.eof())return;
    prof.SetNombre(cad);
    int codigo;
    arch>>codigo>>c;
    arch.getline(cad,120,',');
    prof.SetDistrito(cad);
    arch.getline(cad,120,',');
    prof.SetCategoria(cad);
    arch.getline(cad,120,',');
    prof.SetDedicacion(cad);
    arch.getline(cad,120,',');
    prof.SetSeccion(cad);
    arch.getline(cad,120,'\n');
    prof.SetGrado(cad);
}

void operator >> (ifstream &arch, Miembro &miemb){
    char tipo,c;
    arch>>tipo>>c;
    if(arch.eof())return;
    if(tipo=='A'){
        Alumno alu;
        arch>>alu;
        miemb+alu;
    }else{
        Profesor prof;
        arch>>prof;
        miemb+prof;
    }
}