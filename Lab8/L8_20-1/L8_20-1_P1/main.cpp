/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 09:44 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
#include "Persona.h"
#include "Alumno.h"
#include "Miembro.h"
#include <cstring>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Persona per,personas[20];
    Alumno alu,alumnos[20],*palum;
    Profesor prof,profesores[20]{},*pprof;;
    Miembro miemb;
    ifstream arch;
    AbrirArchivo("Miembros.csv",arch);
    char cadena[200]="San Isidro";
    alu.SetCodigo(92419);
    alu.SetDistrito(cadena);
    alu.SetEscala(4);
    strcpy(cadena,"Ing. Mecanica");
    alu.SetEspecialidad(cadena);
    strcpy(cadena,"EEGGCC");
    alu.SetFacultad(cadena);
    strcpy(cadena,"LOZADA/YINO/MARTHA");
    alu.SetNombre(cadena);
    alumnos[0]=alu;
    
    strcpy(cadena,"CON");
    prof.SetCategoria(cadena);
    prof.SetCodigo(2506);
    strcpy(cadena,"Derecho civil");
    prof.SetDedicacion(cadena);
    strcpy(cadena,"Pachacamac");
    prof.SetDistrito(cadena);
    strcpy(cadena,"Bachiller");
    prof.SetGrado(cadena);
    strcpy(cadena,"SANTISTEBAN/MEZA/ROSA");
    prof.SetNombre(cadena);
    strcpy(cadena,"TP");
    prof.SetSeccion(cadena);
    profesores[0]=prof;
    char cad[80];
    alumnos[0].GetNombre(cad);
    cout<<setw(12)<<left<<alumnos[0].GetCodigo()<<setw(40)<<left<<cad;
    alumnos[0].GetEspecialidad(cad);
    cout<<left<<cad<<endl;
    
    profesores[0].GetNombre(cad);
    cout<<setw(12)<<left<<profesores[0].GetCodigo()<<setw(40)<<left<<cad;
    profesores[0].GetDedicacion(cad);
    cout<<left<<cad<<endl;
    
    
    miemb+alu;
    miemb+prof;
    return 0;
}

