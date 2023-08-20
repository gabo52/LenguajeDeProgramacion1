/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:04 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente() {
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::SetNombre(char* cad) { 
    if(nombre!=NULL) delete[]nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
void Cliente::GetNombre(char *nom) const {
    strcpy(nom,nombre);
}

//71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO,A
void Cliente::leeCliente(ifstream &arch){
    int dniCli;
    char cad[200],cat;
    
    arch>>dniCli;
    if(arch.eof()) return;
    arch.get();
    arch.getline(cad,200,',');
    arch>>cat;
    arch.get(); //leer el cambio de linea
    
    SetDni(dniCli);
    SetNombre(cad);
    SetCategoria(cat);
}

