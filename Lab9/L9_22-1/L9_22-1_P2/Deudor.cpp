/* 
 * File:   Deudor.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:51 AM
 */

#include "Deudor.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"

Deudor::Deudor() {
    Cdeudor=nullptr;
}

Deudor::~Deudor() {
    if(Cdeudor)delete &Cdeudor;
}

void Deudor::leer(ifstream &arch){
    char c,tipo;
    arch>>tipo>>c;
    if(arch.eof())return;
    if(tipo=='A'){
        Cdeudor = new class ClienteA;
    }else if(tipo=='B'){
        Cdeudor = new class ClienteB;
    }else{
        Cdeudor = new class ClienteC;
    }
    Cdeudor->lee(arch);
}

int Deudor::activo(){
    return Cdeudor!=nullptr;
}


void Deudor::imprimir(ofstream &arch){
    Cdeudor->imprime(arch);
}


void Deudor::actualiza(Pedido *lpedido){
    int dni=Cdeudor->GetDni(),cantPed=0;
    double monto=0;
    for(int i=0;lpedido[i].GetDni();i++){
        if(lpedido[i].GetDni()==dni){
            monto+=lpedido[i].GetTotal();
            cantPed++;
        }
    }
    Cdeudor->actualiza(monto,cantPed);
}
