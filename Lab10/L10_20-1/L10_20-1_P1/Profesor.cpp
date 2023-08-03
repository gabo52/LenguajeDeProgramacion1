/* 
 * File:   Profesor.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:15 PM
 */

#include <cstring>

#include "Profesor.h"

Profesor::Profesor() {
    categoria=nullptr;
    dedicacion=nullptr;
    grado=nullptr;
    seccion=nullptr;
}


Profesor::~Profesor() {
    if(grado)delete grado;
}

void Profesor::SetGrado(char* cad) {
    if(grado)delete grado;
    grado = new char [strlen(cad)+1];
    strcpy(grado,cad);
}

void Profesor::GetGrado(char* cad) const {
    if(grado)strcpy(cad,grado);
    else cad[0]=0;
}

void Profesor::SetSeccion(char* cad) {
    if(seccion)delete seccion;
    seccion = new char [strlen(cad)+1];
    strcpy(seccion,cad);
}

void Profesor::GetSeccion(char* cad) const {
    if(seccion)strcpy(cad,seccion);
    else cad[0]=0;
}

void Profesor::SetDedicacion(char* cad) {
    if(dedicacion)delete dedicacion;
    dedicacion = new char [strlen(cad)+1];
    strcpy(dedicacion,cad);
}

void Profesor::GetDedicacion(char* cad) const {
    if(dedicacion)strcpy(cad,dedicacion);
    else cad[0]=0;
}

void Profesor::SetCategoria(char* cad) {
    if(categoria)delete categoria;
    categoria = new char [strlen(cad)+1];
    strcpy(categoria,cad);
}

void Profesor::GetCategoria(char* cad) const {
    if(categoria)strcpy(cad,categoria);
    else cad[0]=0;
}


void Profesor::leer(ifstream &arch){
    char cad[100];
    lee(arch);
    arch.getline(cad,100,',');
    SetCategoria(cad);
    arch.getline(cad,100,',');
    SetDedicacion(cad);
    arch.getline(cad,100,',');
    SetSeccion(cad);
    arch.getline(cad,100,'\n');
    SetGrado(cad);
    
}

void Profesor::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetCodigo()<<setw(40)<<left<<cad;
    GetDistrito(cad);
    arch<<setw(40)<<left<<cad;
    
    GetCategoria(cad);
    arch<<setw(40)<<left<<cad;
    GetDedicacion(cad);
    arch<<setw(40)<<left<<cad;
    GetSeccion(cad);
    arch<<setw(40)<<left<<cad;
    GetGrado(cad);
    arch<<setw(40)<<left<<cad;
    arch<<endl;
}
