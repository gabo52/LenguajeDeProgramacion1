
/* 
 * File:   Medico.cpp
 * Author: USER
 * 
 * Created on 8 de junio de 2023, 03:36 PM
 */
#include <cstring>
#include <fstream>
#include "Medico.h"
using namespace std;

Medico::Medico() {
    numPac = 0;
    nombre = nullptr;
    especialidad = nullptr;
    codigo = nullptr;
    ingresosP = 0;
    ingresosP = 0;
    tarifa = 0;
}

Medico::Medico(const Medico& orig) {
}

Medico::~Medico() {
}

void Medico::SetIngresosS(double ingresosS) {
    this->ingresosS = ingresosS;
}

double Medico::GetIngresosS() const {
    return ingresosS;
}

void Medico::SetIngresosP(double ingresosP) {
    this->ingresosP = ingresosP;
}

double Medico::GetIngresosP() const {
    return ingresosP;
}

void Medico::SetNumPac(int numPac) {
    this->numPac = numPac;
}

int Medico::GetNumPac() const {
    return numPac;
}

void Medico::SetEstado(char *arr) {
    for(int i=0;i<numPac;i++) estado[i] = arr[i];

}

char *Medico::GetEstado() const {
    char *arr;
    arr = new char[100]{};
    for(int i=0;i<numPac;i++) arr[i] = estado[i]; 
    return arr;
}

void Medico::SetPrima(double *arr) {
    for(int i=0;i<numPac;i++) prima[i] = arr[i];
}

double* Medico::GetPrima() const {
    double *arr;
    arr = new double[100]{};
    for(int i=0;i<numPac;i++) arr[i] = prima[i]; 
    return arr;
}

void Medico::SetPacientes(int *arr) {
    for(int i=0;i<numPac;i++) pacientes[i] = arr[i];
}

int* Medico::GetPacientes() const {
    int *arr;
    arr = new int[100]{};
    for(int i=0;i<numPac;i++) arr[i] = pacientes[i]; 
    return arr;
}

void Medico::SetFechas(int *arr) {
    for(int i=0;i<numPac;i++) fechas[i] = arr[i];
}

int* Medico::GetFechas() const {
    int *arr;
    arr = new int[100]{};
    for(int i=0;i<numPac;i++) arr[i] = fechas[i]; 
    return arr;
}

void Medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double Medico::GetTarifa() const {
    return tarifa;
}

void Medico::SetEspecialidad(char* cad) {
    if(especialidad != nullptr) delete especialidad;
    nombre = new char[strlen(cad)+1];
    strcpy(this->especialidad,cad);
}

void Medico::GetEspecialidad(char *cad) const {
    strcpy(cad,especialidad); 
}

void Medico::SetNombre(char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(this->nombre,cad);
}

void Medico::GetNombre(char *cad) const {
    strcpy(cad,nombre); 
}

void Medico::SetCodigo(char* cad) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(this->codigo,cad);
}

void Medico::GetCodigo(char *cad) const {
    strcpy(cad,codigo); 
}

void Medico::copia(const Medico &c){
    int i; 
    c.GetCodigo(codigo);
    c.GetNombre(nombre);
    c.GetEspecialidad(especialidad);
    tarifa = c.GetTarifa(); 
    numPac = c.GetNumPac();
    ingresosP = c.GetIngresosP();
    ingresosS = c.GetIngresosS();
    
    for(i=0;i<numPac;i++){
        fechas = c.GetFechas();
        pacientes = c.GetPacientes();
        prima = c.GetPrima();
        estado = c.GetEstado();
    }
}

/*void Usuario::copia(const Usuario &c){
    int i; 
    carne = c.GetCarne();
    tipo = c.GetTipo();
    condicion = c.GetCondicion();
    for(i=0;libPrest[i].GetCarne();i++) libPrest[i].copia(c.libPrest[i]); 
    
}*/