/* 
 * File:   NUsuario.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:37 PM
 */

#include "NUsuario.h"

NUsuario::NUsuario() {
    pusuario=nullptr;
}

NUsuario::~NUsuario() {
    if(pusuario)delete &pusuario;
}

void NUsuario::leer(ifstream &arch){
    int cod;
    char tipo,c,cad[100];
    arch>>cod>>tipo>>c;
    if(arch.eof())return;
    if(tipo=='A'){
        pusuario = new class Administrativo;
    }else if(tipo=='E'){
        pusuario = new class Estudiante;
    }else{
        pusuario = new class Docentes;
    }
    arch.getline(cad,100,',');
    pusuario->SetCarne(cod);
    pusuario->SetTipo(tipo);
    pusuario->SetNombre(cad);
    pusuario->leer(arch);
}

int NUsuario::carne(){
    return pusuario->GetCarne();
}

void NUsuario::imprime(ofstream &arch){
    pusuario->imprime(arch);
}