

/* 
 * File:   Copia.cpp
 * Author: USER
 * 
 * Created on 21 de junio de 2023, 06:42 PM
 */

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Libro.h"
#include "FuncionesFecha.h"
#include "Disponible.h"
#include "Perdida.h"
#include "Prestamo.h"
#include "Copia.h"
using namespace std;

Copia::Copia() {
    numero = 0;
    Olibro = nullptr; 
    estado = nullptr; 
}

Copia::Copia(const Copia& orig) {
}

Copia::~Copia() {
}

void Copia::SetEstado(char *cad) {
    if(estado != nullptr) delete estado;
    estado = new char[strlen(cad)+1];
    strcpy(estado,cad);
}

void Copia::GetEstado(char *cad) const {
    strcpy(cad,estado); 
}

void Copia::SetNumero(int numero) {
    this->numero = numero;
}

int Copia::GetNumero() const {
    return numero;
}

void Copia::copiar(char *codlib, char *tit, char *aut, int cant, double prec, int num, int zone){
    char cad[20] = "Disponible";
    
    Olibro = new Disponible; 
    Olibro->cargadatos(codlib, tit, aut, cant, prec, zone); 
    
    this->SetEstado(cad); 
    this->SetNumero(num);
}

int Copia::existe(){
    if(Olibro == nullptr) return 0;
    return 1;
}

void Copia::actualizar(){
    double precio = Olibro->GetPrecio();
    char cad[20], codigo[20], c;
    int dd, mm, aa, cant, fecha, dias, ref = 20211115, flag = 0; 
    
    ifstream arch("RegistroDePrestamos2.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo RegistroDePrestamos2.csv";
        exit(1);
    }
    
    Olibro->GetCodigo(codigo);
    while(1){
        arch.getline(cad,20,',');
        if(arch.eof()) break;
        arch.getline(cad,20,',');
        arch >> cant >> c >> dd >> c >> mm >> c >> aa;
        fecha = dd + mm*100 + aa*10000;
        if(strcmp(cad,codigo) == 0 && this->numero == cant){
            flag = 1; 
            break; 
        }
    }
    
    if(flag == 1){
        dias = numeroDeDias(fecha,ref);
        if(dias < 60){
            char cad[20] = "Prestamo";
            delete Olibro; 
            Olibro = new Prestamo;
        }else{
            char cad[20] = "Perdida";
            delete Olibro;
            Olibro = new Perdida; 
        }

        Olibro->actualiza(dias,fecha,precio); 
        this->SetEstado(cad); 
    }
}

void Copia::imprimelibros(ofstream &arch){
    Olibro->imprimir(arch);
}
