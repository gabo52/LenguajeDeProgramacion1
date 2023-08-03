/* 
 * File:   Libro.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:22 PM
 */

#include <cstring>
#include "Libro.h"

Libro::Libro() {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    cantidad = 0;
    precio = 0;
}


Libro::~Libro() {
    if(autor)delete autor;
    if(titulo)delete titulo;
    if(codigo)delete codigo;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}

void Libro::SetAutor(char* cad) {
    if(autor)delete autor;
    if(cad){
        autor = new char[strlen(cad)+1];
        strcpy(autor,cad);
    }else{
        autor = new char[2];
        autor[0]=0;
    }
}

void Libro::GetAutor(char* cad) const {
    if(autor)strcpy(cad,autor);
    else cad[0]=0;
}

void Libro::SetTitulo(char* cad) {
    if(titulo)delete titulo;
    if(cad){
        titulo = new char[strlen(cad)+1];
        strcpy(titulo,cad);
    }else{
        titulo = new char[2];
        titulo[0]=0;
    }
}

void Libro::GetTitulo(char* cad) const {
    if(titulo)strcpy(cad,titulo);
    else cad[0]=0;
}

void Libro::SetCodigo(char* cad) {
    if(codigo)delete codigo;
    if(cad){
        codigo = new char[strlen(cad)+1];
        strcpy(codigo,cad);
    }else{
        codigo = new char[2];
        codigo[0]=0;
    }
}

void Libro::GetCodigo(char* cad) const {
    if(codigo)strcpy(cad,codigo);
    else cad[0]=0;
}


void Libro::imprimeLibro(ofstream &arch){
    char cad[80];
    GetCodigo(cad);
    arch<<"Codigo:"<<cad<<endl;
    GetTitulo(cad);
    arch<<"Titulo:"<<cad<<endl;
    GetAutor(cad);
    arch<<"Autor :"<<cad<<endl;
    arch<<"Cantidad:"<<setw(4)<<right<<GetCantidad()<<endl;
}



