/* 
 * File:   Promociones.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 05:06 PM
 */

#include "Promociones.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}


void Promociones::leepedidos(){
    ifstream arch;
    AbrirArchivo("pedidos5.csv",arch);
    Pedido *ped;
    while(1){
        ped=leePedido(arch);
        if(arch.eof())break;
        lpedidos.insertar(ped);
    }
}

Pedido *Promociones::leePedido(ifstream &arch){
    Pedido *ped;
    int codigo;
    char c;
    arch>>codigo>>c;
    if(arch.eof())return nullptr;
    if(codigo<400000){
        ped= new class PedidoEspecial;    
    }else if(codigo>40000&&codigo<600000){
        ped = new class PedidoUsual;   
    }   else ped = new class PedidoEventual;
    ped->SetCodigo(codigo);
    ped->lee(arch);
    return ped;
}



void Promociones::actualizapedidos(){
    ifstream arch;
    AbrirArchivo("promocion.csv",arch);
    int cod,dd,mm,aa,fec;
    char c;
    while(1){
        arch>>cod>>c>>dd>>c>>mm>>c>>aa;
        if(arch.eof())break;
        fec=dd+mm*100+aa*10000;
        lpedidos.actualizaLista(cod,fec);
    }
}



void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void Promociones::imprimepedidos(){
    ofstream arch;
    AbrirArchivo("Reporte.txt",arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(70)<<right<<"REPORTE DE PEDIDOS"<<endl;
    imprimeLinea(arch,100,'=');
    lpedidos.imprimir(arch);
}

