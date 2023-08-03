/* 
 * File:   PedidoUsual.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 04:57 PM
 */

#include "PedidoUsual.h"


void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::operator = (const PedidoUsual &c){
    SetCantidad(c.GetCantidad());
    SetCodigo(c.GetCodigo());
    SetDescuento(c.GetDescuento());
    SetDni(c.GetDni());
    SetFecha(c.GetFecha());
    char cad[80];
    c.GetNombre(cad);
    SetNombre(cad);
    SetTotal(c.GetTotal());
    SetFlete(c.GetFlete());
}

void PedidoUsual::lee(ifstream &arch){
    char c,nomb[150];
    int cant,dni,dd,mm,aa,fech;
    double monto,flet;
    double desc;
    arch>>desc>>c>>flet>>c;
    arch.getline(nomb,150,',');
    arch>>cant>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    fech=dd+mm*100+aa*10000;
    SetCantidad(cant);
    SetDescuento(desc);
    SetDni(dni);
    SetFecha(fech);
    SetNombre(nomb);
    SetTotal(monto);
    SetFlete(flet);
}

void PedidoUsual::imprime(ofstream &arch){
    char cad[150];
    arch<<endl;
    imprimeFecha(arch,GetFecha());
    GetNombre(cad);
    arch<<endl<<setw(12)<<left<<GetCodigo()<<left<<cad<<endl;
    arch<<setw(15)<<left<<"DNI:"<<setw(12)<<right<<GetDni()<<endl;
    arch<<setw(15)<<left<<"MontoTotal:"<<setw(12)<<right<<GetTotal()<<endl;
    arch<<setw(15)<<left<<"Descuento:"<<setw(12)<<right<<GetDescuento()<<endl;
    arch<<setw(15)<<left<<"Flete:"<<setw(12)<<right<<GetFlete()<<"%"<<endl;
}

