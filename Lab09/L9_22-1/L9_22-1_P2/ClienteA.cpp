/* 
 * File:   ClienteA.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:44 AM
 */

#include "ClienteA.h"



//ClienteA::ClienteA(const ClienteA& orig) {
//}


void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}


void ClienteA::lee(ifstream &arch){
    double descuento;
    int dni;
    char cad[80],c;
    arch>>descuento>>c>>dni>>c;
    arch.getline(cad,80);
    SetDni(dni);
    SetNombre(cad);
    SetDescuento(descuento);
    SetCategoria('A');
}

void ClienteA::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(20)<<left<<GetDni()<<left<<cad<<endl;
    imprimeLinea(arch,100,'-');
    arch<<setw(12)<<left<<"Descuento: "<<setw(8)<<right<<descuento<<"%"<<endl;
    arch<<setw(12)<<left<<"Total:"<<setw(8)<<right<<GetTotalped()<<endl;
    arch<<setw(25)<<left<<"Cantidad de Pedidos:"<<setw(3)<<right<<GetCantped()<<endl;
}


void ClienteA::actualiza(double monto,int cantPed){
    SetCantped(cantPed);
    SetTotalped(monto*(1-(GetDescuento()/100)));
}

