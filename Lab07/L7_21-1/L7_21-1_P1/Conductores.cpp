/* 
 * File:   Conductores.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:22 PM
 */

#include "Conductores.h"
#include "Infraccion.h"
#include "Falta.h"
#include <cstring>
Conductores::Conductores() {
    numFaltas=0;
    nombre=nullptr;
    montoTotal = 0;
}


Conductores::~Conductores() {
    delete nombre;
}

void Conductores::SetMontoTotal(double montoTotal) {
    this->montoTotal = montoTotal;
}

double Conductores::GetMontoTotal() const {
    return montoTotal;
}

void Conductores::SetNumFaltas(int numFaltas) {
    this->numFaltas = numFaltas;
}

int Conductores::GetNumFaltas() const {
    return numFaltas;
}

void Conductores::SetLfaltas(FaltaCond* lf,int n) {
    //this->lfaltas = lfaltas;
    for(int i=0;i<n;i++){
        lfaltas[i].copia(lf[i]);
    }
}

FaltaCond* Conductores::GetLfaltas(int n) const{
    //llenar
    FaltaCond *aux;
    aux = new FaltaCond [100]{};
    for(int i=0;i<n;i++){
        aux[i].copia(lfaltas[i]);
    }
    return aux;
}

void Conductores::SetNombre(char* nomb) {
    if(nombre)delete nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char* Conductores::GetNombre() const {
    char *aux;
    aux = new char [strlen(nombre)+1];
    strcpy(aux,nombre);
    return aux;
}

void Conductores::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductores::GetLicencia() const {
    return licencia;
}

void Conductores::copia(const Conductores &c)  {
    FaltaCond *aux;
    licencia = c.GetLicencia();
    numFaltas = c.GetNumFaltas();
    aux = c.GetLfaltas(numFaltas);
    for(int i = 0;i<numFaltas;i++)lfaltas[i].copia(aux[i]);
    montoTotal = c.GetMontoTotal();
    nombre = c.GetNombre();
}

void Conductores::operator + (const Falta &f){
    int fecha = f.GetFecha();
    int cod=f.GetCodInf();
    char *placa = f.GetPlaca();
    int lic=f.GetLicencia();
    lfaltas[numFaltas].SetFecha(fecha);
    lfaltas[numFaltas].SetCodInf(cod);
    lfaltas[numFaltas].SetPlaca(placa);
    numFaltas++;
}

void Conductores::operator + (const Infraccion &f){
    int infrac=f.GetCodigo();
    double mul= f.GetMulta();
    char *aux = f.GetGravedad();
    for(int i=0;i<numFaltas;i++){
        if(lfaltas[i].GetCodInf()==infrac){
            lfaltas[i].SetMulta(mul);
            lfaltas[i].SetGravedad(aux);
        }
    }
    delete aux;
}


double Conductores::operator ++ (){
    double suma=0;
    for(int i=0;i<numFaltas;i++){
        suma+=lfaltas[i].GetMulta();
    }
    montoTotal=suma;
    return suma;
}

void Conductores::operator * (int fecha){
    int auxFe;
    double mul;
    char *aux;
    for(int i=0;i<numFaltas;i++){
        if(lfaltas[i].GetFecha()<fecha){
            mul = lfaltas[i].GetMulta();
            aux = lfaltas[i].GetGravedad();
            if(strcpy(aux,"Leve")==0){
                mul*=0.5;
            }else if(strcpy(aux,"Grave")==0){
                mul*=0.75;
            }else mul*=0.9;
            delete aux;
            lfaltas[i].SetMulta(mul);
        }
    }
}
