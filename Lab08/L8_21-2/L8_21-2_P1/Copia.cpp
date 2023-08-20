/* 
 * File:   Copia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:28 PM
 */

#include "Copia.h"
#include <cstring>

Copia::Copia() {
    estado = nullptr;
}

void Copia::SetEstado(char* cad) {
    if(estado)delete estado;
    if(cad){
        estado = new char[strlen(cad)+1];
        strcpy(estado,cad);
    }else{
        estado = new char[2];
        estado[0]=0;
    }
}

void Copia::GetEstado(char *cad) const {
    if(estado)strcpy(cad,estado);
    else cad[0]=0;
}

void Copia::SetNumero(int numero) {
    this->numero = numero;
}

int Copia::GetNumero() const {
    return numero;
}

Copia::~Copia() {
    if(estado)delete estado;
}

void Copia::SetDisponible(int zona){
    char cad[]="Disponible";
    Odisponible.SetZona(zona);
    SetEstado(cad);
}

void Copia::SetPrestamo(int dias,int fecha){
    char cad[]="Prestamo";
    Oprestamo.SetDias(dias);
    Oprestamo.SetFecha(fecha);
    SetEstado(cad);
}

void Copia::SetPerdida(double precio){
    char cad[]="Perdida";
    SetEstado(cad);
    Operdida.SetPrecio(precio);
}

void Copia::imprimeCopia(ofstream &arch){
    arch<<setw(3)<<left<<GetNumero();
    char cad[10];
    GetEstado(cad);
    if(strcmp(cad,"Disponible")==0){
        Odisponible.imprimeDisponible(arch);
    }else if(strcmp(cad,"Prestamo")==0){
        Oprestamo.imprimePrestamo(arch);
    }else Operdida.imprimePerdida(arch);
}

void Copia::operator = (const Copia &c){
    char cad[80];
    c.GetAutor(cad);
    SetAutor(cad);
    SetCantidad(c.GetCantidad());
    c.GetCodigo(cad);
    SetCodigo(cad);
    c.GetEstado(cad);
    SetEstado(cad);
    SetNumero(c.GetNumero());
    SetPrecio(c.GetPrecio());
    c.GetTitulo(cad);
    SetTitulo(cad);
}









