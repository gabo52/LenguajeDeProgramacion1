/* 
 * File:   funcionesAux.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 5 de octubre de 2022, 12:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MuestraPunteros.h"
#include "funcionesAux.h"
using namespace std;


void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERRROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERRROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[200];
    arch.getline(buff,200,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void cargaProductos(void *&prod){
    void **productos,*buffProd[200];
    ifstream arch;
    AbrirArchivo("productos2.csv",arch);
    int codProd,cantProd=0,nd=0;
    char *desc,c;
    double precio;
    while(1){
        arch>>codProd;
        if(arch.eof())break;
        arch.get();
        desc=leerCadena(arch,',');
        arch>>precio>>c>>cantProd;
        asignarValoresProd(buffProd[nd],codProd,desc,precio,cantProd);
        nd++;
    }
    productos = new void *[nd+1]{};
    for(int i=0;i<nd;i++){
        productos[i]=buffProd[i];
    }
    prod=productos;
    imprimeproductos(prod);
}

void asignarValoresProd(void *&prod,int codProd,char *desc,double precio,int cantProd){
    void **aux;
    aux= new void *[4];
    double *auxPrecio;
    int *auxCodProd,*auxCantProd;
    auxPrecio = new double;
    *auxPrecio = precio;
    auxCodProd = new int;
    *auxCodProd = codProd;
    auxCantProd = new int;
    *auxCantProd = cantProd;
    aux[0]=auxCodProd;
    aux[1]=desc;
    aux[2]=auxPrecio;
    aux[3]=auxCantProd;
    prod=aux;
}
//422763,GALLETAS SUAVICREMAS FRESA 158GR,2,17913944,23/09/2019
//codigo,descrip,canti sol, dni, fecha


void *leerDatos(ifstream &arch){
    int cod,*codP,cant,*cantP,dni,*dniP,fecha,*fechaP,dd,mm,aa;
    char *desc,estado,*estadoP,c;
    arch>>cod;
    if(arch.eof())return nullptr;
    arch.get();
    desc=leerCadena(arch,',');
    arch>>cant>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    fecha = dd + mm*100 + aa*10000;
    codP = new int;
    cantP = new int;
    fechaP = new int;
    dniP = new int;
    estadoP = new char[2]{};
    
    *codP=cod;
    *cantP=cant;
    *dniP=dni;
    *fechaP=fecha;
    estado = 'N';
    estadoP[0] = estado;
    void **aux;
    aux = new void*[6];
    aux[0]=codP;
    aux[1]=desc;
    aux[2]=cantP;
    aux[3]=dniP;
    aux[4]=fechaP;
    aux[5]=estadoP;
    return aux;
}

void cargaPedidos(void *&ped){
    ifstream arch;
    AbrirArchivo("pedidos2.csv",arch);
    int nd=0;
    void *aux,**pedidos,*buffPed[200];
    pedidos=(void**)ped;
    while(1){
        aux=leerDatos(arch);
        if(arch.eof())break;
        buffPed[nd]=aux;
        nd++;
    }
    pedidos =  new void *[nd+1]{};
    for(int i=0;i<nd;i++){
        pedidos[i]=buffPed[i];
    }
    ped=pedidos;
    imprimepedidos(ped);
}



void procesaClientes(void *&productos,void *&pedidos,void *&clientes){
    actualizaPedidos(productos,pedidos);
    imprimepedidos(pedidos);
    imprimeproductos(productos);
    cargaClientes(pedidos,clientes);
    imprimerepfinal(clientes);
}

void actualizaPedidos(void *&prod,void *&ped){
    void **productos,**pedidos;
    productos = (void **)prod;
    pedidos = (void **)ped;
    for(int i=0;pedidos[i];i++){
        atenderPedido(pedidos[i],productos);
    }
}

void atenderPedido(void *&ped,void **&prod){
    void **productos,**pedidos;
    productos = (void **)prod;
    pedidos = (void **)ped;
    int pos,cod,*aux,cant,cantSol;
    aux=(int *)pedidos[0];
    cod = *aux;
    pos=buscarProducto(cod,productos,cant);
    if(pos!=-1){
        aux=(int *)pedidos[2];
        cantSol = *aux;
        if(cant>=cantSol)cambiaEstadoActualizaStock(ped,productos[pos],cantSol);
    }
}

void cambiaEstadoActualizaStock(void *&ped,void *&prod,int cantSol){
    void **productos,**pedidos;
    productos = (void **)prod;
    pedidos = (void **)ped;
    char *estado;
    int *cantidad;
    estado=(char*)pedidos[5];
    //preguntar esto, si es necesario reasignar
    estado[0]='A';
    pedidos[5]=estado;
    cantidad=(int*)productos[3];
    (*cantidad)-=cantSol;
    productos[3]=cantidad;
}
int buscarProducto(int cod,void **&prod,int &cant){
    void **productos;
    productos=prod;
    for(int i=0;productos[i];i++){
        if(comparaProducto(productos[i],cod,cant))return i;
    }
    return -1;
}
int comparaProducto(void *&prod,int cod,int &cant){
    void **productos;
    productos=(void **)prod;
    int *codigo;
    codigo=(int *)productos[0];
    if(*codigo==cod){
        int *cantidad;
        cantidad=(int *)productos[3];
        cant=*cantidad;
        return 1;
    }else return 0;
}

void  cargaClientes(void *&pedidos,void *&cli){
    ifstream arch;
    AbrirArchivo("clientes2.csv",arch);
    void *aux,**clientes,*buffClientes[100];
    int nd=0;
    while(1){
        aux=leerDatosClientes(arch,pedidos);
        if(arch.eof())break;
        buffClientes[nd]=aux;
        nd++;
    }
    clientes = new void *[nd+1]{};
    for(int i=0;i<nd;i++){
        clientes[i]=buffClientes[i];
    }
    cli=clientes;
}

void *leerDatosClientes(ifstream &arch,void *&ped){
    
    void **pedidos,*buffPedidos[100],**pedidosCliente;
    int *dniP,dni,nd=0;
    char *nomb;
    arch>>dni;
    if(arch.eof())return nullptr;
    pedidos = (void**)ped;
    arch.get();
    nomb=leerCadena(arch,'\n');
    
    for(int i=0;pedidos[i];i++){
        if(comparaDni(dni,pedidos[i])){
            buffPedidos[nd]=pedidos[i];
            nd++;
        }
    }
    pedidosCliente = new void *[nd+1]{};
    for(int i=0;i<nd;i++)pedidosCliente[i]=obtienePedidoCliente(buffPedidos[i]);
    dniP = new int;
    *dniP=dni;
    void **cliente;
    cliente = new void*[3];
    cliente[0]=dniP;
    cliente[1]=nomb;
    cliente[2]=pedidosCliente;
    return cliente;
}

void *obtienePedidoCliente(void *ped){
    void **pedido,**aux;
    pedido=(void**)ped;;
    aux = new void*[4];
    aux[0]=pedido[4];
    aux[1]=pedido[0];
    aux[2]=pedido[1];
    aux[3]=pedido[2];
    return aux;
}
int comparaDni(int dni,void *&ped){
    int *aux;
    void **pedidos;
    pedidos=(void **)ped;
    aux = (int *)pedidos[3];
    return dni == (*aux);
}
void imprimeReporte(void *&clientes){
    
}