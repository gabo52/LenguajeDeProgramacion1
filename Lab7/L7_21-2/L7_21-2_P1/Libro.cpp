/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: Gabo
 * 
 * Created on 2 de noviembre de 2022, 11:42 PM
 */

#include "Libro.h"
#include "LibroPrestado.h"
#include <cstring>

Libro::Libro() {
    autor=nullptr;
    codigo=nullptr;
    titulo=nullptr;
    cantAdm=0;
    cantDoc=0;
    cantEst=0;
    prestados=0;
}

Libro::~Libro() {
    delete autor;
    delete codigo;
    delete titulo;
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

void Libro::SetAutor(const char* cad) {
    if(autor)delete autor;
    if(cad==nullptr){
        autor = nullptr;
    }else{
        autor = new char [strlen(cad)+1];
        strcpy(autor,cad);
    }
}

void Libro::GetAutor(char *cad) const {
    if(autor==nullptr)strcpy(cad,"0");
    else{
        strcpy(cad,autor);
    }
}

void Libro::SetTitulo(const char* cad) {
    if(titulo)delete titulo;
    if(cad==nullptr){
        titulo = nullptr;
    }else{
        titulo = new char [strlen(cad)+1];
        strcpy(titulo,cad);
    }
}

void Libro::GetTitulo(char *cad) const {
    if(titulo==nullptr)strcpy(cad,"0");
    else{
        strcpy(cad,titulo);
    }
}

void Libro::SetCodigo(const char* cad) {
    if(codigo)delete codigo;
    if(cad==nullptr){
        codigo = nullptr;
    }else{
        codigo = new char [strlen(cad)+1];
        strcpy(codigo,cad);
    }
}

void Libro::GetCodigo(char *cad) const {
    if(codigo==nullptr)strcpy(cad,"0");
    else{
        strcpy(cad,codigo);
    }
}

void Libro::copia(const Libro &c){
    char cadena[200];
    c.GetAutor(cadena);
    SetAutor(cadena);
    c.GetCodigo(cadena);
    SetCodigo(cadena);
    c.GetTitulo(cadena);
    SetTitulo(cadena);
    SetPrecio(c.GetPrecio());
    SetPrestados(c.GetPrestados());
    SetStock(c.GetStock());
}

void Libro::operator += (const LibroPrestado &prest){
    char c=prest.GetTipo();
    if(c=='A'){
        SetCantAdm(GetCantAdm()+1);
    }else if(c=='E'){
        SetCantEst(GetCantEst()+1);
    }else{
        SetCantDoc(GetCantDoc()+1);
    }
    SetPrestados(GetPrestados()+1);
}

