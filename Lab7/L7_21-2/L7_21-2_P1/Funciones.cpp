/* 
 * File:   Funciones.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 8 de junio de 2023, 01:46 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Sobrecargas.h"
#include "Usuario.h"
#include "LibroPrestado.h"
#include "Libro.h"
using namespace std;

void cargarUsuarios(Usuario *arr){
    int i = 0; 
    ifstream arch("Usuarios.csv", ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo Usuarios.csv" << endl;
        exit(1);
    }
    
    while(1){
        arch >> arr[i];
        if(arch.eof()) break; 
        i++; 
    }
}

void cargarLibros(Libro *arr){
    int i = 0; 
    ifstream arch("Libros.csv", ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo Libros.csv" << endl;
        exit(1);
    }
    
    while(1){
        arch >> arr[i];
        if(arch.eof()) break; 
        i++; 
    }
}

int buscarLibro(char *codigo, Libro *lib){
    int i; 
    char *codLib; 
    for(i=0;lib[i].GetPrecio();i++){
        codLib = lib[i].GetCodigo(); 
        if(strcmp(codigo,codLib) == 0) return i;
    }
    return -1; 
}

int buscarUsuario(int carne, Usuario *usu){
    int i; 

    for(i=0;usu[i].GetCarne();i++){
        if(usu[i].GetCarne() == carne) return i;
    }
    return -1; 
}

void cargarActualizarPrestamos(LibroPrestado *arr, Libro *lib, Usuario *usu){
    int i = 0, pos1, pos2; 
    ifstream arch("RegistroDePrestamos.csv", ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo RegistroDePrestamos.csv" << endl;
        exit(1);
    }
    
    while(1){
        arch >> arr[i];
        if(arch.eof()) break;
        pos1 = buscarLibro(arr[i].GetCodigoLib(),lib);
        pos2 = buscarUsuario(arr[i].GetCarne(),usu);  
        if(pos1 != -1) lib[pos1] += arr[i]; 
        if(pos2 != -1) usu[pos2] += arr[i];
        i++; 
    }
}

void imprimirUsuarios(Usuario *arr){
    int i; 
    ofstream arch("ReporteUsuario.txt", ios::out);
    if(!arch){
        cout << "No se puede abrir el archivo ReporteUsuario.txt" << endl;
        exit(1);
    }
    
    for(i=0;arr[i].GetCarne();i++) arch << arr[i]; 
}

void determinarDeudas(int fecha, Usuario *arr){
    int i; 
    for(i=0;arr[i].GetCarne();i++) arr[i] * fecha;  
}

void imprimirLibros(Libro *arr){
    int i; 
    ofstream arch("ReporteLibros.txt", ios::out);
    if(!arch){
        cout << "No se puede abrir el archivo ReporteLibros.txt" << endl;
        exit(1);
    }
    
    for(i=0;arr[i].GetPrecio();i++) arch << arr[i]; 
    
}
