/* 
 * File:   Profesor.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 09:47 PM
 */

#include <cstring>

#include "Profesor.h"

Profesor::Profesor() {
    categoria = nullptr;
    dedicacion = nullptr;
    grado = nullptr;
    seccion = nullptr;
}

Profesor::~Profesor() {
    delete categoria;
    delete dedicacion;
    delete grado;
    delete seccion;
}

void Profesor::SetGrado(char* cad) {
    if(grado)delete grado;
    if(cad){
        grado =  new char [strlen(cad)+1];
        strcpy(grado,cad);
    }else{
        grado =  new char [2];
        strcpy(grado,"0");
    }
}

void Profesor::GetGrado(char *cad) const {
    if(grado)strcpy(grado,seccion);
    else strcpy(cad,"0");
}

void Profesor::SetSeccion(char* cad) {
    if(seccion)delete seccion;
    if(cad){
        seccion =  new char [strlen(cad)+1];
        strcpy(seccion,cad);
    }else{
        seccion =  new char [2];
        strcpy(seccion,"0");
    }
}

void Profesor::GetSeccion(char *cad) const {
    if(seccion)strcpy(cad,seccion);
    else strcpy(cad,"0");
}

void Profesor::SetDedicacion(char* cad) {
    if(dedicacion)delete seccion;
    if(cad){
        dedicacion =  new char [strlen(cad)+1];
        strcpy(dedicacion,cad);
    }else{
        dedicacion =  new char [2];
        strcpy(dedicacion,"0");
    }
}

void Profesor::GetDedicacion(char *cad) const {
    if(dedicacion)strcpy(cad,dedicacion);
    else strcpy(cad,"0");
}

void Profesor::SetCategoria(char* cad) {
    if(categoria)delete categoria;
    if(cad){
        categoria =  new char [strlen(cad)+1];
        strcpy(categoria,cad);
    }else{
        categoria =  new char [2];
        strcpy(categoria,"0");
    }
}

void Profesor::GetCategoria(char *cad) const {
    if(categoria)strcpy(cad,categoria);
    else strcpy(cad,"0");
}

void Profesor::operator = (const Profesor &c){
    char cad[200];
    c.GetCategoria(cad);
    SetCategoria(cad);
    c.GetDedicacion(cad);
    SetDedicacion(cad);
    c.GetGrado(cad);
    SetGrado(cad);
    c.GetSeccion(cad);
    SetSeccion(cad);
    c.GetNombre(cad);
    SetNombre(cad);
    c.GetDistrito(cad);
    SetDistrito(cad);
    SetCodigo(c.GetCodigo());
}

