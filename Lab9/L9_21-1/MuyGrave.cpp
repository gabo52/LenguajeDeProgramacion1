

/* 
 * File:   MuyGrave.cpp
 * Author: USER
 * 
 * Created on 20 de junio de 2023, 03:34 PM
 */

#include "MuyGrave.h"

MuyGrave::MuyGrave() {
}

MuyGrave::MuyGrave(const MuyGrave& orig) {
}

MuyGrave::~MuyGrave() {
}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

