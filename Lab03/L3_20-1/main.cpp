/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 10:55 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructura.h"
#include "sobrecarga.h"

using namespace std;

int buscarAlumno(struct Alumno *alumnos, int codigo, int n){
    int i;
    
    for(i=0;i<n;i++){
        if(alumnos[i].codigo == codigo) return i;
    }
    return -1; 
}

int main(int argc, char** argv) {
    int i = 0, j = 0, k = 0, posicion, codAlumno, codCurso, nota, anho, semestre;
    char opcion, car; 
    double creditos;
    
    struct Alumno alumnos[100];
    struct ACurso cursos[300]; 
    struct ACurso mod[300]; 
    
    ifstream archAlumnos("Alumnos.txt", ios::in);
    if(!archAlumnos){
        cout << "No existe el archivo Alumnos.txt";
        exit(1);
    }
    
    ifstream archCursos("Cursos.txt", ios::in);
    if(!archCursos){
        cout << "No existe el archivo Cursos.txt";
        exit(1);
    }
    
    ifstream archCorrecciones("Correcciones.txt", ios::in);
    if(!archCorrecciones){
        cout << "No existe el archivo Correcciones.txt";
        exit(1);
    }
    
    ofstream archReporte("Reporte.txt", ios::out);
    if(!archReporte){
        cout << "No existe el archivo Reporte.txt";
        exit(1);
    }
    
    while(1){
        archAlumnos >> alumnos[i];
        if(archAlumnos.eof()) break; 
        i++; 
    }
    
    while(1){
        archCursos >> cursos[j];
        if(archCursos.eof()) break;
        posicion = buscarAlumno(alumnos,cursos[j].codigo,i); 
        alumnos[posicion] + cursos[j];
        j++; 
    }
    
    while(1){
        archCorrecciones >> mod[k].codigo;
        if(archCorrecciones.eof()) break;
        archCorrecciones >> mod[k].curso >> mod[k].nota >> anho >> car >> semestre >> mod[k].credito >> mod[k].operacion;
        mod[k].ciclo = anho*10 + semestre;
        if(mod[k].operacion == 'A'){
            posicion = buscarAlumno(alumnos,mod[k].codigo,i);
            alumnos[posicion] * mod[k]; 
        }
        if(mod[k].operacion == 'E'){
            posicion = buscarAlumno(alumnos,mod[k].codigo,i);
            alumnos[posicion] - mod[k]; 
        }
        k++; 
    }
    
    for(int m=0;m<i;m++) archReporte << alumnos[m];
    
    return 0;
}

