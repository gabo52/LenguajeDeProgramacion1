/* 
 * File:   Estudiante.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:36 PM
 */

#include "Estudiante.h"

//Estudiante::Estudiante(const Estudiante& orig) {
//}

void Estudiante::SetCelular(int celular) {
    this->celular = celular;
}

int Estudiante::GetCelular() const {
    return celular;
}

void Estudiante::leer(ifstream &arch){
    int telf;
    arch>>telf;
    SetCelular(telf);
}

void Estudiante::imprime(ofstream &arch){
    int carne;
    char cad[80];
    GetNombre(cad);
    arch<<setw(10)<<left<<"Carne:"<<left<<carne<<endl;
    arch<<setw(10)<<left<<"Nombre:"<<left<<cad<<endl;
    arch<<setw(10)<<left<<"Celular:"<<left<<GetCelular()<<endl;
    
}
