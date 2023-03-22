/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 10:40 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
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
ifstream & operator >> (ifstream &arch,Alumno &alu){
    char cad[200],c;
    int codigo;
    arch.getline(cad,200,',');
    if(arch.eof())return arch;
    alu.SetNombre(cad);
    arch>>codigo>>c;
    alu.SetCodigo(codigo);
    arch.getline(cad,200,',');
    alu.SetDistrito(cad);
    arch>>codigo>>c;
    alu.SetEscala(codigo);
    arch.getline(cad,200,',');
    alu.SetEspecialidad(cad);
    arch.getline(cad,200,'\n');
    alu.SetFacultad(cad);
    return arch;
}

ifstream &operator >> (ifstream &arch,Profesor &prof){
    char cad[200],c;
    int codigo;
    arch.getline(cad,200,',');
    if(arch.eof())return arch;
    prof.SetNombre(cad);
    arch>>codigo>>c;
    prof.SetCodigo(codigo);
    arch.getline(cad,200,',');
    prof.SetDistrito(cad);
    arch.getline(cad,200,',');
    prof.SetCategoria(cad);
    arch.getline(cad,200,',');
    prof.SetDedicacion(cad);
    arch.getline(cad,200,',');
    prof.SetSeccion(cad);
    arch.getline(cad,200,'\n');
    prof.SetGrado(cad);
    return arch;
}

ifstream &operator >>(ifstream &arch,Miembro &miembro){
    char tipo,c;
    arch>>tipo>>c;
    if(arch.eof())return arch;
    int n;
    if(tipo=='A'){
        Alumno *auxAl,al;
        arch>>al;
        n=miembro.numeroAlumnos();
        auxAl=miembro.GetLalumno();
        auxAl[n]=al;
        miembro.SetLalumno(auxAl);
    }else{
        Profesor *auxProf,prof;
        arch>>prof;
        n=miembro.numeroProfesores();
        auxProf = miembro.GetLprofesor();
        auxProf[n]=prof;
        miembro.SetLprofesor(auxProf);
    }
    return arch;
}

ofstream &operator << (ofstream &arch,const Alumno &alum){
    int codigo=alum.GetCodigo();
    int escala=alum.GetEscala();
    char cadena[200];
    arch<<"Codigo alumno: "<<codigo<<endl;
    alum.GetNombre(cadena);
    arch<<"Nombre del alumno: "<<cadena<<endl;
    alum.GetDistrito(cadena);
    arch<<"Distrito: "<<cadena<<endl;
    arch<<"Escala de pago: "<<escala<<endl;
    alum.GetEspecialidad(cadena);
    arch<<"Especialidad: "<<cadena<<endl;
    alum.GetFacultad(cadena);
    arch<<"Facultad: "<<cadena<<endl;
    return arch;
}

ofstream &operator << (ofstream &arch,const Profesor &prof){
    int codigo=prof.GetCodigo();
    char cadena[200];
    arch<<"Codigo profeosr: "<<codigo<<endl;
    prof.GetNombre(cadena);
    arch<<"Nombre del profesor: "<<cadena<<endl;
    prof.GetDistrito(cadena);
    arch<<"Distrito: "<<cadena<<endl;
    prof.GetCategoria(cadena);
    arch<<"Categoria: "<<cadena<<endl;
    prof.GetDedicacion(cadena);
    arch<<"Dedicacion: "<<cadena<<endl;
    prof.GetSeccion(cadena);
    arch<<"Seccion: "<<cadena<<endl;
    prof.GetGrado(cadena);
    arch<<"Grado academico: "<<cadena<<endl;
    return arch;
}