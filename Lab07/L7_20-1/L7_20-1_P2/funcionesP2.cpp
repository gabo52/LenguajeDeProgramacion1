/* 
 * File:   funcionesP2.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de noviembre de 2022, 11:12 AM
 */

#include <iostream>
#include <iomanip>
#include "funcionesAuxiliares.h"
#include "funcionesP2.h"
using namespace std;


void leerAlumnos(Alumno *arr,int &n){
    ifstream arch;
    Alumno aux;
    AbrirArchivo("Alumnos.txt",arch);
    while(1){
        arch>>arr[n];
        if(arch.eof())break;
        n++;
    }
}



void completarDatosAlumnos(Alumno *arr,int n){
    ifstream arch;
    int pos;
    AbrirArchivo("Cursos.txt",arch);
    Acurso acur;
    while(1){
        arch>>acur;
        if(arch.eof())break;
        pos=buscarAlumno(arr,n,acur.GetCodigo());
        if(pos!=-1){
            arr[pos]+acur;
        }
    }
}

int buscarAlumno(Alumno *arr,int n,int busca){
    for(int i=0;i<n;i++){
        if(arr[i].GetCodigo()==busca)return i;
    }
    return -1;
}
void actualizarAlumnos(Alumno *arr,int n){
    ifstream arch;
    int pos;
    AbrirArchivo("Correcciones.txt",arch);
    Acurso acur;
    while(1){
        arch>>acur;
        if(arch.eof())break;
        pos=buscarAlumno(arr,n,acur.GetCodigo());
        if(pos!=-1){
            if(acur.GetOperacion()=='A'){
                arr[pos]*acur;
            }else arr[pos]-acur;
        }
    }
}
void imprimirAlumnos(Alumno *arr,int n){
    ofstream arch;
    AbrirArchivo("Consolidado.txt",arch);
    for(int i=0;i<n;i++){
        arch<<arr[i];
    }
}

