/* 
 * File:   Renovacion.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:43 PM
 */

#include "Renovacion.h"


Renovacion::Renovacion(){
    exmedico=0;
    multa=0;
    tramite=0;
}
void Renovacion::SetExmedico(double exmedico) {
    this->exmedico = exmedico;
}

double Renovacion::GetExmedico() const {
    return exmedico;
}

void Renovacion::SetTramite(double tramite) {
    this->tramite = tramite;
}

double Renovacion::GetTramite() const {
    return tramite;
}

void Renovacion::SetMulta(double multa) {
    this->multa = multa;
}

double Renovacion::GetMulta() const {
    return multa;
}

