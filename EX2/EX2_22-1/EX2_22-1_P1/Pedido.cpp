/* 
 * File:   Pedido.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 02:56 PM
 */

#include <iomanip>

#include "Pedido.h"


//Pedido::Pedido(){
//    codigo=0;
//}

//Pedido::Pedido(const Pedido& orig) {
//    *this = orig;
//}


int Pedido::leerDatos(ifstream &arch){
    int dd,mm,aa,dni;
    char c;
    double cant;
    arch>>cant>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    setCantidad(cant);
    setFecha(dd+mm*100+aa*10000);
    setSubTotal(0);
    return dni;
}

void Pedido::imprimeFecha(ofstream &arch){
    int dd,mm,aa,fec;
    fec=getFecha();
    dd=fec%100;
    fec/=100;
    mm=fec%100;
    aa=fec/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}
void Pedido::imprimirDatos(ofstream &arch){
    arch<<setw(12)<<left<<getCodigo()<<setw(8)<<left<<getCantidad();
    imprimeFecha(arch);
    arch<<"     "<<setw(10)<<right<<getSubTotal()<<endl;
}

void Pedido::setSubTotal(double subTotal) {
    this->subTotal = subTotal;
}

double Pedido::getSubTotal() const {
    return subTotal;
}

void Pedido::setFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::getFecha() const {
    return fecha;
}

void Pedido::setCantidad(double cantidad) {
    this->cantidad = cantidad;
}

double Pedido::getCantidad() const {
    return cantidad;
}

void Pedido::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::getCodigo() const {
    return codigo;
}

void Pedido::operator = (const Pedido &c){
    setCantidad(c.getCantidad());
    setCodigo(c.getCodigo());
    setFecha(c.getFecha());
    setSubTotal(c.getSubTotal());
}
ofstream &operator <<(ofstream & arch, Pedido &c){
    c.imprimirDatos(arch);
}

bool Pedido::operator < (const Pedido &c){
    return -getFecha()>c.getFecha();
}

bool Pedido::operator > (const Pedido &c){
    return getFecha()>c.getFecha();
}