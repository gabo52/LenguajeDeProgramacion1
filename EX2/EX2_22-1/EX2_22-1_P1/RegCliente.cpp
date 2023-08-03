/* 
 * File:   RegCliente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 02:57 PM
 */

#include "RegCliente.h"
//preguntar
//RegCliente::RegCliente() {
//}
//
//RegCliente::RegCliente(const RegCliente& orig) {
//}
//
//RegCliente::~RegCliente() {
//}

void imprimeLinea(ofstream &arch,int cant, char c);
void RegCliente::operator = (const Cliente &c){
    cliente=c;
}

ofstream &operator << (ofstream &arch, RegCliente &reg){
    reg.imprime(arch);
    return arch;
}

void imprimeLinea(ofstream &arch,int cant, char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void RegCliente::imprime(ofstream &arch){
    char cad[100];
    cliente.GetNombre(cad);
    imprimeLinea(arch,100,'=');
    arch<<setw(10)<<left<<"DNI"<<setw(40)<<left<<"NOMBRE"<<setw(10)<<left<<"TIPO"<<setw(10)<<left
            <<setw(10)<<left<<"DESCUENTO"<<left<<"TELEFONO"<<endl;
    imprimeLinea(arch,100,'=');
    cliente.imprimirDatos(arch);
    imprimeLinea(arch,100,'=');
    arch<<setw(10)<<left<<"CODIGO"<<setw(10)<<left<<"CANTIDAD"<<setw(12)
            <<left<<"FECHA"<<left<<"SubTotal"<<endl;
    imprimeLinea(arch,100,'=');
    for(list<class Pedido>::iterator it=pedidos.begin();it!=pedidos.end();it++){
        (*it).imprimirDatos(arch);
    }
}

int RegCliente::DNI(){
    return cliente.GetDni();
}


void RegCliente::agregaPedido( Pedido &c){
    c.setSubTotal(c.getSubTotal()*(1-cliente.GetDescuento()));
    pedidos.push_back(c);
}

void RegCliente::ordena(){
    pedidos.sort();
}
    

void RegCliente::leerDatosCliente(ifstream &arch){
    cliente.leerDatos(arch);
    if(arch.eof())return;
    if(cliente.GetTipo()=='A'){
        cliente.SetDescuento(0.235);
    }else if(cliente.GetTipo()=='B'){
        cliente.SetDescuento(0.168);        
    }else{
        cliente.SetDescuento(0.083);       
    }
    
}