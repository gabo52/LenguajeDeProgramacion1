/* 
 * File:   Libro.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:33 PM
 */

#include <cstring>

#include "Libro.h"

Libro::Libro() {
    codigo=nullptr;
    titulo=nullptr;
    autor=nullptr;
    anho=0;
}


Libro::~Libro() {
    if(codigo)delete codigo;
    if(titulo)delete titulo;
    if(autor)delete autor;
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

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}

void Libro::SetAutor(char* cad) {
    if(autor)delete autor;
    autor = new char [strlen(cad)+1];
    strcpy(autor,cad);
}


void Libro::GetAutor(char* cad) const {
    if(autor)strcpy(cad,autor);
    else cad[0]=0;
}

void Libro::SetTitulo(char* cad) {
    if(titulo)delete titulo;
    titulo = new char [strlen(cad)+1];
    strcpy(titulo,cad);
}

void Libro::GetTitulo(char* cad) const {
    if(titulo)strcpy(cad,titulo);
    else cad[0]=0;
}

void Libro::SetCodigo(char* cad) {
    if(codigo)delete codigo;
    codigo = new char [strlen(cad)+1];
    strcpy(codigo,cad);
}

void Libro::GetCodigo(char* cad) const {
    if(codigo)strcpy(cad,codigo);
    else cad[0]=0;
}

void Libro::operator = (const Libro &c){
    char cad[100];
    SetAnho(c.GetAnho());
    SetCantidad(c.GetCantidad());
    SetPrecio(c.GetPrecio());
    SetStock(c.GetStock());
    c.GetAutor(cad);
    SetAutor(cad);
    c.GetCodigo(cad);
    SetCodigo(cad);
    c.GetTitulo(cad);
    SetTitulo(cad);
}

void operator >> (ifstream &arch,Libro &lib){
    char cad[80],c;
    arch.getline(cad,80,',');
    if(arch.eof())return;
    int aa,cant;
    double precio;
    lib.SetCodigo(cad);
    arch.getline(cad,80,',');
    lib.SetTitulo(cad);
    arch.getline(cad,80,',');
    lib.SetAutor(cad);
    arch>>aa>>c>>cant>>c>>precio;
    lib.SetCantidad(cant);
    lib.SetAnho(aa);
    lib.SetPrecio(precio);
    lib.SetStock(cant);
    arch.get();
}

void operator << (ofstream &arch,Libro &lib){
    char cad[100];
    lib.GetCodigo(cad);
    arch<<setw(10)<<left<<"Codigo:"<<left<<cad<<endl;
    lib.GetTitulo(cad);
    arch<<setw(10)<<left<<"Titulo:"<<left<<cad<<endl;
    lib.GetAutor(cad);
    arch<<setw(10)<<left<<"Autor:"<<left<<cad<<endl;
    arch<<setw(10)<<left<<"Cantidad:"<<setw(8)<<right<<lib.GetCantidad()<<endl;
    arch<<setw(10)<<left<<"Stock:"<<setw(8)<<right<<lib.GetStock()<<endl;
    imprimeLinea(arch,100,'-');
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

int Libro::operator > (const Libro &c){
    char cad[100],cad2[100];
    GetCodigo(cad);
    c.GetCodigo(cad2);
    return strcmp(cad,cad2);
}

void Libro::actualiza(){
    if(GetStock()!=0){
        SetStock(GetStock()-1);
    }
    
}
