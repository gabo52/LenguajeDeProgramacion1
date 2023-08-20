/* 
 * File:   Funciones.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 18 de abril de 2023, 10:30 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Funciones.h"
using namespace std;

void leerprimerarchivo(){
    int codigoAlumno, codAlu, anhoIngreso, codFacu, nota, aa, dd, mm, codigoFacultad;
    double numCred; 
    char codCurso[10], car;  
    
    ofstream archNotas("NotasFinales.bin", ios::out | ios::binary); 
    if(!archNotas){
        cout << "El archivo NotasFinales.bin no existe";
        exit(1); 
    }
    
    ifstream archDatos("Alumnos-Cursos.txt", ios::in); 
    if(!archDatos){
        cout << "El archivo Alumnos-Cursos.txt no existe";
        exit(1); 
    }
    
    while(1){
        archDatos >> codAlu; 
        if(archDatos.eof()) break; 
        if(archDatos.fail()){
            archDatos.clear();
            archDatos >> codCurso >> codigoFacultad >> numCred >> nota >> dd >> car >> mm >> car >> aa; 
            if(anhoIngreso <= aa){
                insertanotas(archNotas, codigoAlumno, anhoIngreso, codFacu, codCurso, codigoFacultad, numCred, nota, mm); 
                imprimereportenotas();
            }
        }else{
            codigoAlumno = codAlu; 
            archDatos >> car >> anhoIngreso >> car >> codFacu; 
        }
    }
}

void imprimereportealumnos(){
    int codigoAlumno, anhoIngreso, codFacultad, totCurReg, sumaAprob, sumaDesa;
    char nombre[100], facultad[100]; 
    double totCredAprob, totCredDesa, promGeneral, promAprob, credAprobTotales;
    ifstream archAlumnos("Alumnos.bin", ios::in | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe";
        exit(1); 
    }
    
    ofstream archReporte("ReporteAlumnos.txt", ios::out); 
    if(!archReporte){
        cout << "El archivo ReporteAlumnos.txt no existe";
        exit(1); 
    }
    
    archReporte.precision(2);
    archReporte << fixed;
    
    while(1){
        archAlumnos.read(reinterpret_cast< char *>(&codigoAlumno), sizeof(int));
        if(archAlumnos.eof()) break;
        archAlumnos.read(reinterpret_cast< char *>(&anhoIngreso), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&codFacultad), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archAlumnos.read(reinterpret_cast< char *>(facultad), sizeof(char)*100);
        archAlumnos.read(reinterpret_cast< char *>(&totCurReg), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&totCredAprob), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&totCredDesa), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&sumaAprob), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&sumaDesa), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&promGeneral), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&promAprob), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&credAprobTotales), sizeof(double));

        archReporte << setfill('0') << setw(4) << codigoAlumno << "-" << setw(4) << anhoIngreso << "-" << setw(4) << codFacultad << setfill(' ') << setw(50) << nombre
                    << setw(50) << facultad << setw(7) << totCurReg << setw(7) << totCredAprob << setw(7) << totCredDesa << setw(7) << sumaAprob << setw(7)
                    << sumaDesa << setw(7) << promGeneral << setw(7) << promAprob << setw(7) << credAprobTotales << endl; 
    }
}

void leersegundoarchivo(){
    int codigoAlumno, anhoIngreso, codFacultad, totCurReg = 0, sumaAprob = 0, sumaDesa = 0;
    double totCredAprob = 0, totCredDesa = 0, promGeneral = 0, promAprob = 0, credAprobTotales = 0;
    char nombre[100], facultad[100], car;
    
    ofstream archAlumnos("Alumnos.bin", ios::out | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe";
        exit(1); 
    }
    
    ifstream archDatos("Alumnos.txt", ios::in); 
    if(!archDatos){
        cout << "El archivo Alumnos.txt no existe";
        exit(1); 
    }
    
    while(1){
        archDatos >> codigoAlumno;
        if(archDatos.eof()) break;
        archDatos >> car >> anhoIngreso >> car >> codFacultad >> nombre >> facultad;
        archAlumnos.write(reinterpret_cast< const char *>(&codigoAlumno), sizeof(int));
        archAlumnos.write(reinterpret_cast< const char *>(&anhoIngreso), sizeof(int));
        archAlumnos.write(reinterpret_cast< const char *>(&codFacultad), sizeof(int));
        archAlumnos.write(reinterpret_cast< const char *>(nombre), sizeof(char)*100);
        archAlumnos.write(reinterpret_cast< const char *>(facultad), sizeof(char)*100);
        archAlumnos.write(reinterpret_cast< const char *>(&totCurReg), sizeof(int));
        archAlumnos.write(reinterpret_cast< const char *>(&totCredAprob), sizeof(double));
        archAlumnos.write(reinterpret_cast< const char *>(&totCredDesa), sizeof(double));
        archAlumnos.write(reinterpret_cast< const char *>(&sumaAprob), sizeof(int));
        archAlumnos.write(reinterpret_cast< const char *>(&sumaDesa), sizeof(int));
        archAlumnos.write(reinterpret_cast< const char *>(&promGeneral), sizeof(double));
        archAlumnos.write(reinterpret_cast< const char *>(&promAprob), sizeof(double));
        archAlumnos.write(reinterpret_cast< const char *>(&credAprobTotales), sizeof(double));
    }
    imprimereportealumnos();
}

void insertanotas(ofstream &archNotas, int codAlu, int anho, int codFacu, char *codCurso, int codigoFacultad, double numCred, int nota, int mm){
    int semestre; 
    
    if(mm == 1 || mm == 2) semestre = 0; 
    if(mm >= 3 || mm <= 7) semestre = 1; 
    if(mm >= 8 || mm == 12) semestre = 2; 
    
    archNotas.write(reinterpret_cast< const char *>(&codAlu), sizeof(int));
    archNotas.write(reinterpret_cast< const char *>(&anho), sizeof(int));
    archNotas.write(reinterpret_cast< const char *>(&codFacu), sizeof(int));
    archNotas.write(reinterpret_cast< const char *>(codCurso), sizeof(char)*10);
    archNotas.write(reinterpret_cast< const char *>(&codigoFacultad), sizeof(int));
    archNotas.write(reinterpret_cast< const char *>(&numCred), sizeof(double));
    archNotas.write(reinterpret_cast< const char *>(&nota), sizeof(int));
    archNotas.write(reinterpret_cast< const char *>(&semestre), sizeof(int));
}

void imprimereportenotas(){
    int codAlu, anhoIngreso, anho, semestre, codFacu, nota, aa, dd, mm, codigoFacultad;
    double numCred; 
    char codCurso[10]; 
    
    ifstream archNotas("NotasFinales.bin", ios::in | ios::binary); 
    if(!archNotas){
        cout << "El archivo NotasFinales.bin no existe";
        exit(1); 
    }
    
    ofstream archReporte("ReporteNotas.txt", ios::out); 
    if(!archReporte){
        cout << "El archivo ReporteNotas.txt no existe";
        exit(1); 
    }
    
    archReporte.precision(2);
    archReporte << fixed; 
    
    while(1){
        archNotas.read(reinterpret_cast< char *>(&codAlu), sizeof(int));
        if(archNotas.eof()) break; 
        archNotas.read(reinterpret_cast< char *>(&anho), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&codFacu), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(codCurso), sizeof(char)*10);
        archNotas.read(reinterpret_cast< char *>(&codigoFacultad), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&numCred), sizeof(double));
        archNotas.read(reinterpret_cast< char *>(&nota), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&semestre), sizeof(int));
        
        archReporte << setfill('0') << setw(4) << codAlu << "-" << setw(4) << anho << "-" << setw(4) << codFacu << setfill(' ') << setw(15) << codCurso 
                    << setw(15) << codigoFacultad << setw(5) << numCred << setw(5) 
                    << nota << setw(5) << semestre << endl;
        
    }
}

void completarcampos(){
    int anho, semestre, codigoAlumno, anhoIngreso, codFacultad, totCurReg = 0, sumaAprob = 0, sumaDesa = 0;
    double numCred, totCredAprob = 0, totCredDesa = 0, promGeneral = 0, promAprob = 0, credAprobTotales = 0;
    char nombre[100], facultad[100], car, codCurso[10];
    int codAlu, codFacu, nota, aa, dd, mm, codigoFacultad, i, j, numReg1, numReg2; 
    
    ifstream archNotas("NotasFinales.bin", ios::in | ios::binary); 
    if(!archNotas){
        cout << "El archivo NotasFinales.bin no existe";
        exit(1); 
    }
    
    fstream archAlumnos("Alumnos.bin", ios::out | ios::in | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe";
        exit(1); 
    }
    
    int tamReg1 = sizeof(int)*6 + sizeof(double)*1 + sizeof(char)*10;
    archNotas.seekg(0,ios::end); 
    int tamArch1 = archNotas.tellg(); 
    numReg1 = tamArch1/tamReg1; 
    
    int tamReg2 = sizeof(int)*6 + sizeof(char)*200 + sizeof(double)*5;
    archAlumnos.seekg(0,ios::end); 
    int tamArch2 = archAlumnos.tellg(); 
    numReg2 = tamArch2/tamReg2; 
    
    for(i=0;i<numReg1;i++){
        archNotas.seekg(i*tamReg1,ios::beg); 
        archNotas.read(reinterpret_cast< char *>(&codAlu), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&anho), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&codFacu), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(codCurso), sizeof(char)*10);
        archNotas.read(reinterpret_cast< char *>(&codigoFacultad), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&numCred), sizeof(double));
        archNotas.read(reinterpret_cast< char *>(&nota), sizeof(int));
        archNotas.read(reinterpret_cast< char *>(&semestre), sizeof(int));
        for(j=0;j<numReg2;j++){
            archAlumnos.seekg(j*tamReg2,ios::beg); 
            archAlumnos.read(reinterpret_cast< char *>(&codigoAlumno), sizeof(int));
            archAlumnos.read(reinterpret_cast< char *>(&anhoIngreso), sizeof(int));
            archAlumnos.read(reinterpret_cast< char *>(&codFacultad), sizeof(int));
            archAlumnos.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
            archAlumnos.read(reinterpret_cast< char *>(facultad), sizeof(char)*100);
            archAlumnos.read(reinterpret_cast< char *>(&totCurReg), sizeof(int));
            archAlumnos.read(reinterpret_cast< char *>(&totCredAprob), sizeof(double));
            archAlumnos.read(reinterpret_cast< char *>(&totCredDesa), sizeof(double));
            archAlumnos.read(reinterpret_cast< char *>(&sumaAprob), sizeof(int));
            archAlumnos.read(reinterpret_cast< char *>(&sumaDesa), sizeof(int));
            archAlumnos.read(reinterpret_cast< char *>(&promGeneral), sizeof(double));
            archAlumnos.read(reinterpret_cast< char *>(&promAprob), sizeof(double));
            archAlumnos.read(reinterpret_cast< char *>(&credAprobTotales), sizeof(double));
            if(codAlu == codigoAlumno){
                totCurReg = totCurReg + 1;
                if(nota > 10){
                    totCredAprob = totCredAprob + numCred;
                    sumaAprob = sumaAprob + nota*numCred; 
                }else{
                    totCredDesa = totCredDesa + numCred; 
                    sumaDesa = sumaDesa + nota*numCred; 
                } 
                archAlumnos.seekg(j*tamReg2,ios::beg); 
                archAlumnos.seekg(sizeof(int)*3 + sizeof(char)*200,ios::cur); 
                archAlumnos.write(reinterpret_cast< const char *>(&totCurReg), sizeof(int));
                archAlumnos.write(reinterpret_cast< const char *>(&totCredAprob), sizeof(double));
                archAlumnos.write(reinterpret_cast< const char *>(&totCredDesa), sizeof(double));
                archAlumnos.write(reinterpret_cast< const char *>(&sumaAprob), sizeof(int));
                archAlumnos.write(reinterpret_cast< const char *>(&sumaDesa), sizeof(int));
                break; 
            }
        }
    }
    imprimereportealumnos();
}

void completarcamposfaltantes(){
    int anho, semestre, codigoAlumno, anhoIngreso, codFacultad, totCurReg = 0, sumaAprob = 0, sumaDesa = 0;
    double numCred, totCredAprob = 0, totCredDesa = 0, promGeneral = 0, promAprob = 0, credAprobTotales = 0;
    char nombre[100], facultad[100], car, codCurso[10];
    int codAlu, codFacu, nota, aa, dd, mm, codigoFacultad, i, j, numReg1, numReg2; 
    
    fstream archAlumnos("Alumnos.bin", ios::out | ios::in | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe";
        exit(1); 
    }
    
    int tamReg2 = sizeof(int)*6 + sizeof(char)*200 + sizeof(double)*5;
    archAlumnos.seekg(0,ios::end); 
    int tamArch2 = archAlumnos.tellg(); 
    numReg2 = tamArch2/tamReg2; 
    
    for(j=0;j<numReg2;j++){
        archAlumnos.seekg(j*tamReg2,ios::beg);
        archAlumnos.seekg(sizeof(int)*3 + sizeof(char)*200,ios::cur); 
        archAlumnos.read(reinterpret_cast< char *>(&totCurReg), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&totCredAprob), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&totCredDesa), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&sumaAprob), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&sumaDesa), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&promGeneral), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&promAprob), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&credAprobTotales), sizeof(double));
        
        promGeneral = (double) (sumaAprob + sumaDesa) / (totCredAprob + totCredDesa);
        promAprob = (double) sumaAprob / totCredAprob;
        credAprobTotales = (double) promAprob / (totCredAprob + totCredDesa);
        
        
        archAlumnos.seekg(j*tamReg2,ios::beg); 
        archAlumnos.seekg(sizeof(int)*6 + sizeof(char)*200 + sizeof(double)*2,ios::cur); 
        archAlumnos.write(reinterpret_cast< const char *>(&promGeneral), sizeof(double));
        archAlumnos.write(reinterpret_cast< const char *>(&promAprob), sizeof(double));
        archAlumnos.write(reinterpret_cast< const char *>(&credAprobTotales), sizeof(double));
    }
    imprimereportealumnos();
}

void imprimirreportefinal(){
    int id = 1, codigoAlumno, anhoIngreso, codFacultad, totCurReg, sumaAprob, sumaDesa;
    char nombre[100], facultad[100]; 
    double totCredAprob, totCredDesa, promGeneral, promAprob, credAprobTotales;
    
    ifstream archAlumnos("Alumnos.bin", ios::in | ios::binary); 
    if(!archAlumnos){
        cout << "El archivo Alumnos.bin no existe";
        exit(1); 
    }
    
    ofstream archReporte("Reporte.txt", ios::out); 
    if(!archReporte){
        cout << "El archivo Reporte.txt no existe";
        exit(1); 
    }
    
    archReporte.precision(2);
    archReporte << fixed; 
    
    archReporte << setw(50) << " " << "INFORMACION ACADEMICA DE LOS ESTUDIANTES" << endl; 
    imprimirLinea(archReporte, '=', 150);
    
    while(1){
        archAlumnos.read(reinterpret_cast< char *>(&codigoAlumno), sizeof(int));
        if(archAlumnos.eof()) break;
        archAlumnos.read(reinterpret_cast< char *>(&anhoIngreso), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&codFacultad), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archAlumnos.read(reinterpret_cast< char *>(facultad), sizeof(char)*100);
        archAlumnos.read(reinterpret_cast< char *>(&totCurReg), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&totCredAprob), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&totCredDesa), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&sumaAprob), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&sumaDesa), sizeof(int));
        archAlumnos.read(reinterpret_cast< char *>(&promGeneral), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&promAprob), sizeof(double));
        archAlumnos.read(reinterpret_cast< char *>(&credAprobTotales), sizeof(double));
        archReporte << "No.    Codigo          Alumno                              A. de ingreso                   Facultad" << endl; 
        archReporte << right << setfill('0') << setw(2) << id << setfill(' ') << setw(5) << " " << setw(6) << setfill('0') 
                    << setw(6) << codigoAlumno << setfill(' ') << setw(10) << " " << left << setw(35) << nombre << right << setw(5) << " " << anhoIngreso << setw(15) << " " << setfill('0') 
                    << setw(5) << codFacultad << setfill(' ') << setw(5) << " " << facultad << endl;
        imprimirLinea(archReporte, '-', 150); 
        archReporte << left << setw(7) << " " << "RESUMEN: " << endl;
        archReporte << left << setw(7) << " " << setw(35) << "Cursos Registrados: " << setw(5) << totCurReg << setw(10) << "  " << setw(25) << "Total de Creditos" << totCredAprob + totCredDesa << endl;
        archReporte << left << setw(7) << " " << setw(35) << "Cursos Aprobados: " << setw(5) << totCredAprob << setw(10) << "  " << setw(25) << "Creditos desaprobados: " << totCredDesa << endl;
        archReporte << left << setw(7) << " " << setw(35) << "Cursos Aprobados/Matriculados: " << setw(5) << credAprobTotales << "%" << endl;       
        imprimirLinea(archReporte, '-', 150); 
        archReporte << left << setw(7) << " " << setw(35) << "Promedio general: " << setw(5) << promGeneral << endl; 
        archReporte << left << setw(7) << " " << setw(35) << "Promedio general de aprobados: " << promAprob << endl; 
        imprimirLinea(archReporte, '=', 150); 
        id++;   
    }
    archReporte << "TOTAL DE ALUMNOS REGISTRADOS: " << id << endl;
    
}

void imprimirLinea(ofstream &arch, char c, int n){
    for(int i=0;i<n;i++) arch << c;
    arch << endl; 
}