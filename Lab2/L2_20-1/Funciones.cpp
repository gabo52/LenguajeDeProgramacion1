/* 
 * File:   Funciones.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 19 de abril de 2023, 03:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define MAX_CAR 120
#include "Funciones.h"
using namespace std;

void leerarchivos(){
    leeralumnos();
    generaconsolidado();
    leercursos(); 
    imprimeconsolidado();
}

void imprimeconsolidado(){
    char tipo, nombre[100], facultad[10], especialidad[100];
    int codAlumno, carne, sumaNotas = 0, cantMaterias = 0, estado = 0;
    double cantCreditos = 0, cantCreditosAprob = 0;
    
    ifstream archConsolidado("Consolidado.bin", ios::in | ios::binary); 
    if(!archConsolidado){
        cout << "El archivo Consolidado.bin no existe"; 
        exit(1);
    }
    
    ofstream archReporte("Reporte.txt", ios::out); 
    if(!archReporte){
        cout << "El archivo Reporte.txt no existe"; 
        exit(1);
    }
    
    archReporte << "CONSOLIDADO DE NOTAS DE LOS ALUMNOS" << endl; 
    imprimirLinea('=', MAX_CAR, archReporte); 
    archReporte << "CODIGO   NOMBRE" << " " << "CARNE" << "    " << "CRED. CURSADOS  CRED. APROBADOS  PROMEDIO  ESTADO" << endl; 
    imprimirLinea('=', MAX_CAR, archReporte); 
    
    archReporte.precision(2); 
    archReporte<<fixed; 
    
    while(1){
        archConsolidado.read(reinterpret_cast< char *>(&codAlumno), sizeof(int));
        if(archConsolidado.eof()) break;
        archConsolidado.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archConsolidado.read(reinterpret_cast< char *>(&cantCreditos), sizeof(double));
        archConsolidado.read(reinterpret_cast< char *>(&cantCreditosAprob), sizeof(double));
        archConsolidado.read(reinterpret_cast< char *>(&sumaNotas), sizeof(int));
        archConsolidado.read(reinterpret_cast< char *>(&cantMaterias), sizeof(int));
        archConsolidado.read(reinterpret_cast< char *>(facultad), sizeof(char)*10);
        archConsolidado.read(reinterpret_cast< char *>(&estado), sizeof(int));

        archReporte << left << setw(9) << codAlumno << setw(35) << nombre << right;
        archReporte << setw(5) << cantCreditos << setw(10) << " " << setw(5) << cantCreditos << setw(10) << " " << setw(5) << (double) sumaNotas/cantMaterias << "  "; 
        if(estado == 1) 
            archReporte << "EGRESADO";
        else
            archReporte << "NO EGRESADO";
        archReporte << endl; 
    }
    imprimirLinea('=', MAX_CAR, archReporte); 
    
}

void generaconsolidado(){
    char tipo, nombre[100], facultad[10], especialidad[100];
    int codAlumno, carne, sumaNotas = 0, cantMaterias = 0, estado = 0;
    double cantCreditos = 0, cantCreditosAprob = 0;
    
    ifstream archAlumnos("Alumnos.bin", ios::in | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe"; 
        exit(1);
    }
    
    ofstream archConsolidado("Consolidado.bin", ios::out | ios::binary); 
    if(!archConsolidado){
        cout << "El archivo Consolidado.bin no existe"; 
        exit(1);
    }
    
    while(1){
        archAlumnos.read(reinterpret_cast< char *>(&codAlumno), sizeof(int));
        if(archAlumnos.eof()) break; 
        archAlumnos.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archAlumnos.read(reinterpret_cast< char *>(&tipo), sizeof(char));
        archAlumnos.read(reinterpret_cast< char *>(&carne), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(facultad), sizeof(char)*10);
        archAlumnos.read(reinterpret_cast< char *>(especialidad), sizeof(char)*100);
        
        archConsolidado.write(reinterpret_cast< const char *>(&codAlumno), sizeof(int));
        archConsolidado.write(reinterpret_cast< const char *>(nombre), sizeof(char)*100);
        archConsolidado.write(reinterpret_cast< const char *>(&cantCreditos), sizeof(double));
        archConsolidado.write(reinterpret_cast< const char *>(&cantCreditosAprob), sizeof(double));
        archConsolidado.write(reinterpret_cast< const char *>(&sumaNotas), sizeof(int));
        archConsolidado.write(reinterpret_cast< const char *>(&cantMaterias), sizeof(int));
        archConsolidado.write(reinterpret_cast< const char *>(facultad), sizeof(char)*10);
        archConsolidado.write(reinterpret_cast< const char *>(&estado), sizeof(int));
    }
}

void leeralumnos(){
    char tipo, nombre[100], facultad[10], especialidad[100];
    int codAlumno, carne;
    
    ifstream archAlumnos("Alumnos.txt", ios::in); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.txt no existe"; 
        exit(1);
    }
    
    ofstream archAluBin("Alumnos.bin", ios::out | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe"; 
        exit(1);
    }
    
    while(1){
        archAlumnos >> tipo; 
        if(archAlumnos.eof()) break;
        archAlumnos >> codAlumno >> nombre >> carne;
        if(archAlumnos.fail()){
            archAlumnos.clear();
            carne = 0; 
        }
        archAlumnos >> especialidad >> facultad; 
        cargaralumnos(archAluBin, codAlumno, tipo, nombre, carne, especialidad, facultad); 
    }
}

void cargaralumnos(ofstream &archAluBin, int codAlumno, char tipo, char *nombre, int carne, char *especialidad, char *facultad){
    
    archAluBin.write(reinterpret_cast< const char *>(&codAlumno), sizeof(int));
    archAluBin.write(reinterpret_cast< const char *>(nombre), sizeof(char)*100);
    archAluBin.write(reinterpret_cast< const char *>(&tipo), sizeof(char));
    archAluBin.write(reinterpret_cast< const char *>(&carne), sizeof(int));
    archAluBin.write(reinterpret_cast< const char *>(facultad), sizeof(char)*10);
    archAluBin.write(reinterpret_cast< const char *>(especialidad), sizeof(char)*100);
    archAluBin.flush(); 
    
}

void leercursos(){
    int codAlumno, nota, anho, ciclo, codigo, sumaNotas, cantMaterias, estado, numReg;
    double creditos, cantCreditos, cantCreditosAprob;
    char car, codCurso[10], nombre[100], facultad[10]; 
    
    ifstream archCursos("Cursos.txt", ios::in); 
    if(!archCursos){
        cout << "El archivo Cursos.txt no existe"; 
        exit(1);
    }
    
    fstream archConsolidado("Consolidado.bin", ios::in | ios::out | ios::binary); 
    if(!archConsolidado){
        cout << "El archivo Consolidado.bin no existe"; 
        exit(1);
    }
    
    int tamReg = sizeof(int)*4 + sizeof(double)*2 + sizeof(char)*110; 
    archConsolidado.seekg(0, ios::end);
    int tamArch = archConsolidado.tellg(); 
    numReg = tamArch / tamReg; 
     
    while(1){
        archCursos >> codAlumno;
        if(archCursos.eof()) break; 
        archCursos >> codCurso >> nota >> anho >> car >> ciclo >> creditos;  
       
        for(int i=0;i<numReg;i++){
            archConsolidado.seekg(i*tamReg, ios::beg);
            archConsolidado.read(reinterpret_cast< char *>(&codigo), sizeof(int));
            archConsolidado.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
            archConsolidado.read(reinterpret_cast< char *>(&cantCreditos), sizeof(double));
            archConsolidado.read(reinterpret_cast< char *>(&cantCreditosAprob), sizeof(double));
            archConsolidado.read(reinterpret_cast< char *>(&sumaNotas), sizeof(int));
            archConsolidado.read(reinterpret_cast< char *>(&cantMaterias), sizeof(int));
            archConsolidado.read(reinterpret_cast< char *>(facultad), sizeof(char)*10);
            archConsolidado.read(reinterpret_cast< char *>(&estado), sizeof(int));
            
            if(codAlumno == codigo){
                cantCreditos = cantCreditos + creditos;
                if(nota>10) cantCreditosAprob = cantCreditosAprob + creditos; 
                sumaNotas = sumaNotas + nota;
                cantMaterias = cantMaterias + 1; 
                if(cantCreditos >= 45) estado = 1; 
               
                archConsolidado.seekg(i*tamReg, ios::beg);
                archConsolidado.seekg(sizeof(int) + sizeof(char)*100, ios::cur);
                archConsolidado.write(reinterpret_cast< const char *>(&cantCreditos), sizeof(double));
                archConsolidado.write(reinterpret_cast< const char *>(&cantCreditosAprob), sizeof(double));
                archConsolidado.write(reinterpret_cast< const char *>(&sumaNotas), sizeof(int));
                archConsolidado.write(reinterpret_cast< const char *>(&cantMaterias), sizeof(int));
                archConsolidado.seekg(sizeof(char)*10, ios::cur);
                archConsolidado.write(reinterpret_cast< const char *>(&estado), sizeof(int));
            }
        }
    }
}

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i=0;i<n;i++) arch << c;
    arch << endl;
} 