/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medico.cpp
 * Author: cueva
 * 
 * Created on 11 de junio de 2023, 11:29 AM
 */
#include <cstring>
#include "medico.h"

using namespace std;

medico::medico() {
    codigo=0;
    nombre=nullptr;
    especialidad=nullptr;
    
    
}

medico::medico(const medico& orig) {
}

medico::~medico() {
}

void medico::SetEspecialidad(char* cad) {
    if(especialidad!=nullptr) delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void medico::GetEspecialidad(char* cad) const {
    strcpy(cad,especialidad);
}

void medico::SetNombre(char* cad) {
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void medico::GetNombre(char* cad) const {
    strcpy(cad,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}
/*
50611,EDGAR  MUNOZ VERGEL,Urologia
15092,LUZ SOFIA JAUREGUI BRAVO,Dermatologia
60184,SURAMI HELI PRECIADO PINTO,Traumatologia
 */ 
void medico::leemedico(ifstream&arch){
    int cod;
    char nom[100],esp[50];
    
    arch >> cod;
    if(!arch.eof()){
        codigo=cod;
        arch.get();
        arch.getline(nom,100,',');
        arch.getline(esp,50);
        SetNombre(nom);
        SetEspecialidad(esp);
    }

}