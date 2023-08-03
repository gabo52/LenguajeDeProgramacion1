/* 
 * File:   sobrecarga.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 10:57 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "sobrecarga.h"
#include "Estructura.h"
using namespace std;

void operator+(struct Alumno &alumno, const struct ACurso curso){
    alumno.curso[alumno.numCur] = curso.curso;
    alumno.ciclo[alumno.numCur] = curso.ciclo;
    alumno.nota[alumno.numCur] = curso.nota;
    alumno.credito[alumno.numCur] = curso.credito;
    alumno.numCur++;
}

void operator*(struct Alumno &alumno, const struct ACurso curso){
    int posicion = buscarCurso(alumno, curso.curso, curso.ciclo);
    if(posicion != -1){
        alumno.nota[posicion] = curso.nota; 
    }
}

int buscarCurso(const struct Alumno alumno, int codigo, int ciclo){
    int i; 
    for(i=0;i<alumno.numCur;i++){
        if(alumno.ciclo[i] == ciclo && alumno.curso[i] == codigo) return i;
    }
    return -1; 
}

void operator-(struct Alumno &alumno, const struct ACurso curso){
    int j;
    int posicion = buscarCurso(alumno, curso.curso, curso.ciclo);
    if(posicion != -1){
        for(j=posicion;j<alumno.numCur-1;j++){
            alumno.curso[j] = alumno.curso[j+1];
            alumno.ciclo[j] = alumno.ciclo[j+1];
            alumno.nota[j] = alumno.nota[j+1];
            alumno.credito[j] = alumno.credito[j+1];     
        }
        alumno.numCur--; 
    }
}

double operator/(const struct Alumno alumno, int ciclo){
    int i, contador = 0, suma = 0;
    double promedio = 0;
    
    for(i=0;i<alumno.numCur;i++){
        if(alumno.ciclo[i] == ciclo){
            suma = suma + alumno.nota[i];
            contador++;
        }
    }
    promedio = (double) suma/contador;
    return promedio;
}

int operator --(const struct Alumno alumno, int b){
    int i;
    double suma = 0;
    
    for(i=0;i<alumno.numCur;i++) suma = suma + alumno.credito[i];
    
    return suma; 
}

int operator ++(const struct Alumno alumno, int b){
    int i;
    double suma = 0;
    
    for(i=0;i<alumno.numCur;i++){
        if(alumno.nota[i] > 10) suma = suma + alumno.credito[i];
    }
    return suma; 
}

ifstream &operator >> (ifstream &in,struct Alumno &alumno){
    char especialidad[100], facultad[50];
    int carne;
    
    in >> alumno.tipo;
    if(in.eof()) return in;
    in >> alumno.codigo >> alumno.nombre >> carne;
    if(in.fail()){
        in.clear(); 
    }
    in >> especialidad >> facultad;
    return in; 
}

ifstream &operator >> (ifstream &in, struct ACurso &curso){
    int anho, semestre;
    char car;
    in >> curso.codigo;
    if(in.eof()) return in;
    in >> curso.curso >> curso.nota >> anho >> car >> semestre >> curso.credito >> curso.operacion;
    curso.ciclo = anho*10 + semestre;
    return in;
}

ofstream &operator << (ofstream &out, const struct Alumno alumno){
    int i, j, flag;
    double promedio, credCursados, credAprobados;
    out.precision(2);
    out <<fixed;
    out << "Nombre: " << alumno.nombre << endl; 
    out << "Codigo: " << alumno.codigo << endl;
    imprimirLinea(out,50,'=');
    out << "        CICLO                 PROMEDIO" << endl; 
    int arrCiclos[alumno.numCur]; 
    j = 0; 
    for(i=0;i<alumno.numCur;i++){
        flag = buscarCiclo(arrCiclos, j, alumno.ciclo[i]);
        if(flag == 1){
            arrCiclos[j] = alumno.ciclo[i]; 
            promedio = alumno / alumno.ciclo[i]; 
            out << "   " << setw(2) << j+1 << ")  " << alumno.ciclo[i]/10 << "-" << alumno.ciclo[i]%10 << setw(15) << " " << setw(6) << promedio << endl;
            j++; 
        }
    }
    credCursados = alumno--;
    credAprobados = alumno++;
    imprimirLinea(out,50,'-');
    out << "Creditos Cursados:  " << setw(5) << credCursados << endl;
    out << "Creditos Aprobados: " << setw(5) << credAprobados << endl;
    imprimirLinea(out,50,'=');
    return out; 
}

int buscarCiclo(int *arr, int n, int ciclo){
    //1: no esta en el arreglo
    //0: esta en el arreglo
    int i; 
    for(i=0;i<n;i++){
        if(arr[i] == ciclo) return 0; 
    }
    return 1; 
}

void imprimirLinea(ofstream &out, int n, char c){
    int i;
    for(i=0;i<n;i++) out << c;
    out << endl;
}