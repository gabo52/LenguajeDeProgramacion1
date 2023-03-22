/* 
 * File:   FuncionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:11 AM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#include "Libro.h"
#include "Usuario.h"
using namespace std;


void leerUsuarios(Usuario *usuarios){
    ifstream arch;
    int n=0;
    AbrirArchivo("Usuarios.csv",arch);
    while(1){
        arch>>usuarios[n];
        if(arch.eof())break;
        n++;
    }
    n=0;
}

void leerLibros(Libro *libros){
    ifstream arch;
    int n=0;
    AbrirArchivo("Libros.csv",arch);
    while(1){
        arch>>libros[n];
        if(arch.eof())break;
        n++;
    }
    n=0;
}


void cargarLibrosPrestados(Usuario *usuarios,Libro *libros){
    ifstream arch;
    AbrirArchivo("RegistroDePrestamos.csv",arch);
    
}


void imprimirLibros(Libro *libros){
    ofstream arch;
    AbrirArchivo("ReporteLibros.txt",arch);
    char cadena[10];
    libros[0].GetCodigo(cadena);
    for(int i=0;strcmp(cadena,"0");i++){
        arch<<libros[i];
        libros[i+1].GetCodigo(cadena);
    }
}
void imprimirUsuarios(Usuario *usuarios){
    ofstream arch;
    AbrirArchivo("ReporteUsusarios.txt",arch);
    char cadena[10];
    for(int i=0;usuarios[i].GetCarne();i++){
        arch<<usuarios[i];
    }
}
