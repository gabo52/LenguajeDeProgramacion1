/* 
 * File:   Tienda.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de noviembre de 2022, 05:41 PM
 */


#include "Tienda.h"
#define MAXCANTLINEA 115

void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void imprimeLinea(ofstream& arch,int cant,char c);


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



//118050,8,79475585,16/12/2019
//codigo,cantSol, dni, fecha
void Tienda::carga(){
    ifstream arch;
    AbrirArchivo("pedidos3.csv",arch);
    Pedido ped;
    int n=0;
    while(1){
        leePedido(arch,ped);
        if(arch.eof())break;
        lpedidos[n]=ped;
        n++;
    }
    arch.close();
    AbrirArchivo("clientes2.csv",arch);
    n=0;
    Cliente clien;
    while(1){
        leeCliente(arch,clien);
        if(arch.eof())break;
        lclientes[n]=clien;
        n++;
    }
    
}

void Tienda::leePedido(ifstream &arch,Pedido &ped){
    int cod,cant,dni,dd,mm,aa;
    char c;
    arch>>cod>>c;
    if(arch.eof())return;
    arch>>cant>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    ped.SetCantidad(cant);
    ped.SetCodigo(cod);
    ped.SetFecha(dd+mm*100+aa*10000);
    ped.SetDni(dni);
    ped.SetCodprod(cod);
    char cad[100];
    double precio;
    int stock;
    buscaProducto(cod,cad,precio,stock);
    ped.SetPrecio(precio);
    ped.SetStock(stock);
    ped.SetNombre(cad);
    ped.SetTotal(precio*cant);
}


void Tienda::buscaProducto(int cod,char *cad,double &precio,int &stock){
    ifstream arch;
    AbrirArchivo("productos3.csv",arch);
    int codigo;
    char c,cadena[200];
    while(1){
        arch>>codigo>>c;
        if(arch.eof())break;
        if(codigo==cod){
            arch.getline(cad,80,',');
            arch>>precio>>c>>stock;
            return;
        }else arch.getline(cadena,200,'\n');
    }
    cout<<"Erro, no se encontro el producto "<<cod;
    exit(1);
}

void Tienda::leeCliente(ifstream &arch,Cliente &clien){
    int cod;
    char c,cad[80],tipo;
    arch>>cod>>c;
    if(arch.eof())return ;
    arch.getline(cad,80,',');
    arch>>tipo;
    clien.SetCategoria(tipo);
    clien.SetDni(cod);
    clien.SetNombre(cad);
}

void Tienda::actualiza(int d){
    
}

void imprimeLinea(ofstream& arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void Tienda::muestra(){
    ofstream arch;
    AbrirArchivo("Muestra.txt",arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(12)<<left<<"Fecha"<<setw(61)<<"Codigo    Descripcion del Prod."
            <<setw(50)<<left<<"Cant.   Precio     Total    Observaciones"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    for(int i=0;lpedidos[i].GetCodigo();i++){
        lpedidos[i].imprime(arch);
    }
}