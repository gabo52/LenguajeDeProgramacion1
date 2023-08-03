/* 
 * File:   Cliente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:43 AM
 */

#include <cstring>
#include "Cliente.h"
#include "FuncionesLecturaEscritura.h"
Cliente::Cliente() {
    dni =0;
    nombre = nullptr;
    numped = 0;
    total =0;
}

Cliente::~Cliente() {
    eliminar();
}

void Cliente::eliminar(){
    if(nombre!=nullptr)delete nombre;
}

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

void Cliente::SetNumped(int numped) {
    this->numped = numped;
}

int Cliente::GetNumped() const {
    return numped;
}

void Cliente::SetNombre(const char* cad) {
    if(nombre)delete nombre;
    if(cad!=nullptr){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char [2];
        strcpy(nombre,"0");
    }
}

void Cliente::GetNombre(char *cad) const {
    if(nombre==nullptr)strcpy(cad,"0");
    else strcpy(cad,nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator = (const Cliente &c){
    categoria = c.GetCategoria();
    dni = c.GetDni();
    char cadena[50];
    c.GetNombre(cadena);
    SetNombre(cadena);
    numped = c.GetNumped();
    total = c.GetTotal();
}

void Cliente::imprimePedidos(ofstream &arch){
    for(int i=0;i<GetNumped();i++){
        lped[i].imprimepedido(arch);
    }
}

void Cliente::operator =(const Pedido& c){
    lped[numped]=c;
    numped++;
    total+=c.GetPrecio()*c.GetCantidad();
}

void Cliente::operator -=(const Pedido& c){
    Pedido aux;
    for(int i=0;i<numped;i++){
        if(lped[i].GetDni()==c.GetDni()&&lped[i].GetFecha()==c.GetFecha()&&
                lped[i].GetCodigo()==c.GetCodigo()){
            aux=lped[i];
            lped[i]=lped[numped-1];
            lped[numped-1]=aux;
            total-=lped[numped-1].GetPrecio()*lped[numped-1].GetCantidad();
            lped[numped-1].eliminar();
            numped--;
            i--;
            return ;
        }
    }
}

void Cliente::operator / (double desc){
    double porcentaje;
    porcentaje=1-desc/100;
    for(int i=0;i<numped;i++){
        lped[i].SetPrecio(lped[i].GetPrecio()*porcentaje);
    }
    total*=porcentaje;
}

