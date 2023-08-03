/* 
 * File:   Empresa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 02:58 PM
 */


#include "Empresa.h"
#include "RegCliente.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Producto.h"
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);

//Empresa::Empresa() {
//}
//
//Empresa::Empresa(const Empresa& orig) {
//}
//
//Empresa::~Empresa() {
//}

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

void Empresa::leerClientes(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    RegCliente reg;
    while(1){
        reg.leerDatosCliente(arch);
        if(arch.eof())break;
        lstClientes.push_back(reg);
    }
}

void Empresa::imprimirClientes(const char *nomb){
    ofstream arch;
    arch.precision(2);
    arch<<fixed;
    AbrirArchivo(nomb,arch);
    for(list<class RegCliente>::iterator it=lstClientes.begin();it!=lstClientes.end();it++ ){
        (*it).imprime(arch);
    }
}


void Empresa::leerPedidos(const char *nomb){
        ifstream arch;
    AbrirArchivo(nomb,arch);
    class Pedido ped;
    int cod,flag=0,dni;
    Producto prod,aux;
    while(1){
        prod.leerDatos(arch);
        if(arch.eof())break;
        agregarProducto(prod);
        dni=ped.leerDatos(arch);
        asignaValoresPedido(ped,dni,prod.GetCodigo());
        agregarPedido(dni,ped);
    }
}

void Empresa::asignaValoresPedido(Pedido &ped,int dni,int codProd){
    Producto prod;
    for(list<Producto>::iterator it=lstProducto.begin();it!=lstProducto.end();it++){
        if((*it).GetCodigo()==codProd){
            ped.setCodigo(codProd);
            ped.setSubTotal(ped.getCantidad()*((*it).GetPrecioUnitario())*
            (1-(*it).GetDescuento()/100));
            return;
        }
    }
    cout<<"Error, no se encontró el producto"<<codProd<<endl;
}

void Empresa::agregarProducto(Producto &prod){
    Producto aux;
    int flag=0;
    for(list<class Producto>::iterator it=lstProducto.begin();it!=lstProducto.end();it++){
        aux=*it;
        if(aux.GetCodigo()==prod.GetCodigo()){
            flag=1;
            return;
        }
    }
    if(!flag){
        lstProducto.push_back(prod);
    }
}

void Empresa::agregarPedido(int dni,Pedido &ped){
    RegCliente *aux;
    for(list<class RegCliente>::iterator it=lstClientes.begin();it!=lstClientes.end();it++){
        //aux=it;
        if((*it).DNI()==dni){
            (*it).agregaPedido(ped);
        }
    }    
}

void Empresa::ordenarPedidos(){
    RegCliente *aux;
    for(list<class RegCliente>::iterator it=lstClientes.begin();it!=lstClientes.end();it++){
        (*it).ordena();
    }    
}

void Empresa::imprimirProductos(const char *nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    arch.precision(2);
    arch<<fixed;
    Producto prod;
    for(list<class Producto>::iterator it=lstProducto.begin();it!=lstProducto.end();it++){
        prod=*it;
        prod.imprimirDatos(arch);
    }
}

