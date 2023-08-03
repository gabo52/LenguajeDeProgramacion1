/* 
 * File:   PedidoEventual.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 04:59 PM
 */

#include "PedidoEventual.h"



void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}


void PedidoEventual::operator = (const PedidoEventual &c){
    SetCantidad(c.GetCantidad());
    SetCodigo(c.GetCodigo());
    SetDni(c.GetDni());
    SetFecha(c.GetFecha());
    char cad[80];
    c.GetNombre(cad);
    SetNombre(cad);
    SetTotal(c.GetTotal());
    SetFlete(c.GetFlete());
}

void PedidoEventual::lee(ifstream &arch){
    char c,nomb[150];
    int cant,dni,dd,mm,aa,fech;
    double monto,flet;
    double desc;
    arch>>flet>>c;
    arch.getline(nomb,150,',');
    arch>>cant>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    fech=dd+mm*100+aa*10000;
    SetCantidad(cant);
    SetDni(dni);
    SetFecha(fech);
    SetNombre(nomb);
    SetTotal(monto);
    SetFlete(flet);
}

void PedidoEventual::imprime(ofstream &arch){
    char cad[150];
    arch<<endl;
    imprimeFecha(arch,GetFecha());
    GetNombre(cad);
    arch<<endl<<setw(12)<<left<<GetCodigo()<<left<<cad<<endl;
    arch<<setw(15)<<left<<"DNI:"<<setw(12)<<right<<GetDni()<<endl;
    arch<<setw(15)<<left<<"MontoTotal:"<<setw(12)<<right<<GetTotal()<<endl;
    arch<<setw(15)<<left<<"Flete:"<<setw(12)<<right<<GetFlete()<<"%"<<endl;    
}

void PedidoEventual::actualizaFlete(){
    SetTotal(GetTotal()/(1+GetFlete()/100)*100);
    SetFlete(0);
}
