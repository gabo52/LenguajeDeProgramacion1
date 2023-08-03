/* 
 * File:   Administrativo.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:34 PM
 */

#include <cstring>

#include "Administrativo.h"

Administrativo::Administrativo() {
    area=nullptr;
}


Administrativo::~Administrativo() {
    if(area)delete area;
}

void Administrativo::SetArea(char* cad) {
    if(area)delete area;
    area = new char [strlen(cad)+1];
    strcpy(area,cad);
}

void Administrativo::GetArea(char* cad) const {
    if(area)strcpy(cad,area);
    else cad[0]=0;
}

void Administrativo::leer(ifstream &arch){
    char cad[80];
    arch.getline(cad,80,'\n');
    SetArea(cad);
}

void Administrativo::imprime(ofstream &arch){
    int carne;
    char cad[80];
    GetNombre(cad);
    arch<<setw(10)<<left<<"Carne:"<<left<<carne<<endl;
    arch<<setw(10)<<left<<"Nombre:"<<left<<cad<<endl;
    
    GetArea(cad);
    arch<<setw(10)<<left<<"Area:"<<left<<cad<<endl;
}

