/* 
 * File:   ClienteC.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371 
 * Created on 16 de noviembre de 2022, 09:48 AM
 */

#include "ClienteC.h"



//ClienteC::ClienteC(const ClienteC& orig) {
//}

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}


void ClienteC::lee(ifstream &arch){
    double flete;
    int dni;
    char cad[80],c;
    arch>>flete>>c>>dni>>c;
    arch.getline(cad,80);
    SetDni(dni);
    SetNombre(cad);
    SetCategoria('B');
    SetFlete(flete);
}

void ClienteC::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(20)<<left<<GetDni()<<left<<cad<<endl;
    imprimeLinea(arch,100,'-');
    arch<<setw(12)<<left<<"Flete:"<<setw(4)<<right<<GetFlete()<<endl;
    arch<<setw(10)<<left<<"Total:"<<setw(6)<<right<<GetTotalped()<<endl;
    arch<<setw(25)<<left<<"Cantidad de Pedidos:"<<setw(3)<<right<<GetCantped()<<endl;
}
