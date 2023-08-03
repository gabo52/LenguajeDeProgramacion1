/* 
 * File:   PedidoEspecial.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 04:54 PM
 */

#include "PedidoEspecial.h"



void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}


void PedidoEspecial::operator = (const PedidoEspecial &c){
    SetCantidad(c.GetCantidad());
    SetCodigo(c.GetCodigo());
    SetDescuento(c.GetDescuento());
    SetDni(c.GetDni());
    SetFecha(c.GetFecha());
    char cad[80];
    c.GetNombre(cad);
    SetNombre(cad);
    SetTotal(c.GetTotal());
}

void PedidoEspecial::lee(ifstream &arch){
    char c,nomb[150];
    int cant,dni,dd,mm,aa,fech;
    double monto;
    double desc;
    arch>>desc>>c;
    arch.getline(nomb,150,',');
    arch>>cant>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    fech=dd+mm*100+aa*10000;
    SetCantidad(cant);
    SetDescuento(desc);
    SetDni(dni);
    SetFecha(fech);
    SetNombre(nomb);
    SetTotal(monto);
}

void PedidoEspecial::imprime(ofstream &arch){
    char cad[150];
    arch<<endl;
    imprimeFecha(arch,GetFecha());
    GetNombre(cad);
    arch<<endl<<setw(12)<<left<<GetCodigo()<<left<<cad<<endl;
    arch<<setw(15)<<left<<"DNI:"<<setw(12)<<right<<GetDni()<<endl;
    arch<<setw(15)<<left<<"MontoTotal:"<<setw(12)<<right<<GetTotal()<<endl;
    arch<<setw(15)<<left<<"Descuento:"<<setw(12)<<right<<GetDescuento()<<"%"<<endl;
}

void PedidoEspecial::actualizaFlete(){
    
}