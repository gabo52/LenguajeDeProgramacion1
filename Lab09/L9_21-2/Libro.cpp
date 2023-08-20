

/* 
 * File:   Libro.cpp
 * Author: USER
 * 
 * Created on 21 de junio de 2023, 06:42 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Libro.h"
using namespace std; 

Libro::Libro() {
    codigo = nullptr;
    titulo = nullptr;
    autor = nullptr;
    cantidad = 0;
    anho = 0;
    precio = 0;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetAnho(int anho) {
    this->anho = anho;
}

int Libro::GetAnho() const {
    return anho;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}

void Libro::SetAutor(char *cad) {
    if(autor != nullptr) delete autor;
    autor = new char[strlen(cad)+1];
    strcpy(autor,cad);
}

void Libro::GetAutor(char *cad) const {
    strcpy(cad,autor);
}

void Libro::SetTitulo(char *cad) {
    if(titulo != nullptr) delete titulo;
    titulo = new char[strlen(cad)+1];
    strcpy(titulo,cad);
}

void Libro::GetTitulo(char *cad) const {
    strcpy(cad,titulo);
}

void Libro::SetCodigo(char *cad) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void Libro::GetCodigo(char *cad) const {
    strcpy(cad,codigo);
}

void Libro::imprimir(ofstream &arch){
    char cad[80];
    GetCodigo(cad);
    arch << "Codigo:" << cad << endl;
    GetTitulo(cad);
    arch << "Titulo:" << cad << endl;
    GetAutor(cad);
    arch << "Autor :" << cad << endl;
    arch << "Cantidad:" << setw(4) << right << GetCantidad() << endl;
}
