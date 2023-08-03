/* 
 * File:   NodoCola.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:39 PM
 */

#include <cstring>

#include "NodoCola.h"

NodoCola::NodoCola() {
    sig=nullptr;
}

NodoCola::~NodoCola(){
    if(libsol)delete libsol;    
}

void NodoCola::SetCarne(int carne) {
    this->carne = carne;
}

int NodoCola::GetCarne() const {
    return carne;
}

void NodoCola::SetLibsol(char* cad) {
    if(libsol)delete libsol;
    libsol= new char [strlen(cad)+1];
    strcpy(libsol,cad);
}

void NodoCola::GetLibsol(char* cad) const {
    if(libsol)strcpy(cad,libsol);
    else cad[0]=0;
}
