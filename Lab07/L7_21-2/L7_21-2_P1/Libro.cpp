
/* 
 * File:   Libro.cpp
 * Author: USER
 * 
 * Created on 7 de junio de 2023, 10:21 AM
 */

#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include "Libro.h"
#include "LibroPrestado.h"
using namespace std; 

Libro::Libro(){
    codigo = nullptr; 
    titulo = nullptr; 
    autor = nullptr;
    stock = 0;
    precio = 0; 
    prestados = 0;
    cantEst = 0;
    cantDoc = 0;
    cantAdm = 0; 
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetCantAdm(int cantAdm) {
    this->cantAdm = cantAdm;
}

int Libro::GetCantAdm() const {
    return cantAdm;
}

void Libro::SetCantDoc(int cantDoc) {
    this->cantDoc = cantDoc;
}

int Libro::GetCantDoc() const {
    return cantDoc;
}

void Libro::SetCantEst(int cantEst) {
    this->cantEst = cantEst;
}

int Libro::GetCantEst() const {
    return cantEst;
}

void Libro::SetPrestados(int prestados) {
    this->prestados = prestados;
}

int Libro::GetPrestados() const {
    return prestados;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetAutor(char* cad) {
    if(autor != nullptr) delete autor;
    autor = new char[strlen(cad)+1];
    strcpy(this->autor,cad);
}

char* Libro::GetAutor() const {
    char *aux;
    int longitud = strlen(autor);
    aux = new char[longitud+1];
    strcpy(aux,autor);
    return aux;
}

void Libro::SetTitulo(char* cad) {
    if(titulo != nullptr) delete titulo;
    titulo = new char[strlen(cad)+1];
    strcpy(this->titulo,cad);
}

char* Libro::GetTitulo() const {
    char *aux;
    int longitud = strlen(titulo);
    aux = new char[longitud+1];
    strcpy(aux,titulo);
    return aux;
}

void Libro::SetCodigo(char* cad) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(this->codigo,cad);
}

char* Libro::GetCodigo() const {
    char *aux;
    int longitud = strlen(codigo);
    aux = new char[longitud+1];
    strcpy(aux,codigo);
    return aux;
}

void Libro::copia(const Libro &c){
    codigo = c.GetCodigo(); 
    titulo = c.GetTitulo(); 
    autor = c.GetAutor();
    stock = c.GetStock();
    precio = c.GetPrecio(); 
    prestados = c.GetPrestados();
    cantEst = c.GetCantEst();
    cantDoc = c.GetCantDoc();
    cantAdm = c.GetCantAdm(); 
}

void Libro::operator += (const LibroPrestado &c){
    if(c.GetTipo() == 'A') cantAdm++;
    if(c.GetTipo() == 'E') cantEst++;
    if(c.GetTipo() == 'D') cantDoc++;
    prestados++; 
}