/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docentes.cpp
 * Author: Gabo
 * 
 * Created on 26 de noviembre de 2022, 08:34 PM
 */

#include "Docentes.h"

//Docentes::Docentes(const Docentes& orig) {
//    
//}

void Docentes::SetAnexo(int anexo) {
    this->anexo = anexo;
}

int Docentes::GetAnexo() const {
    return anexo;
}

void Docentes::leer(ifstream &arch){
    int anex;
    arch>>anex;
    SetAnexo(anex);
}

void Docentes::imprime(ofstream &arch){
    int carne;
    char cad[80];
    GetNombre(cad);
    arch<<setw(10)<<left<<"Carne:"<<left<<carne<<endl;
    arch<<setw(10)<<left<<"Nombre:"<<left<<cad<<endl;
    
    arch<<setw(10)<<left<<"Anexo:"<<left<<GetAnexo()<<endl;
}