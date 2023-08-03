/* 
 * File:   FuncionesEx01_20202_Preg01.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de octubre de 2022, 11:02 PM
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20202_Preg01.h"
#define MAXCANTLINEA 100
using namespace std;

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void leerDatos(void *&pedidos,void *&stock){

    leeStock(stock);
    
    leePedidos(pedidos);
    
    imprimeStock(stock);
    imprimePedidos(pedidos);
}

void imprimeStock(void *st){
    ofstream arch;
    AbrirArchivo("ReporteStock.txt",arch);
    arch<<setw(10)<<left<<"CODIGO"<<setw(10)<<left<<"STOCK"<<endl;
    void **stock=(void**)st;
    for(int i=0;stock[i];i++){
        imprimeRegStock(stock[i],arch);
    }
}

void imprimeRegStock(void *st,ofstream &arch){
    void **stock=(void**)st;
    int *cod,*cantStock;
    cod = (int*)stock[0];
    cantStock = (int*)stock[1];
    arch<<setw(10)<<left<<*cod<<setw(10)<<left<<*cantStock<<endl;
}
void imprimePedidos(void *ped){
    ofstream arch;
    AbrirArchivo("ReportePedidos.txt",arch);
    arch<<setw(10)<<left<<"FECHA"<<setw(10)<<left<<"RUC"<<setw(10)<<left<<
            "CODIGO"<<setw(50)<<left<<"NOMBRE"<<setw(10)<<left<<"CANT SOL"
            <<setw(10)<<left<<"CANT ATEND"<<endl;
    void **pedidos=(void**)ped;
    for(int i=0;pedidos[i];i++){
        imprimeRegPedidos(pedidos[i],arch);
    }
}

void imprimeRegPedidos(void *ped,ofstream &arch){
    void **pedidos=(void**)ped;
    int *fecha,*ruc,*cod,*cantSol,*cantAtend;
    char *nomb;
    fecha = (int *)pedidos[0];
    ruc = (int *)pedidos[1];
    cod = (int *)pedidos[2];
    nomb = (char *)pedidos[3];
    cantSol = (int *)pedidos[4];
    cantAtend = (int *)pedidos[5];
    arch<<setw(10)<<left<<*fecha<<setw(10)<<left<<*ruc<<setw(10)<<left<<
            *cod<<setw(50)<<left<<nomb<<setw(10)<<left<<*cantSol
            <<setw(10)<<left<<*cantAtend<<endl;
}

void  leeStock(void *&stock){
    ifstream arch;
    AbrirArchivo("stock.csv",arch);
    
    void *buffStock[100],**aux;
    int nd=0;
    while(1){
        buffStock[nd]=leerRegStock(arch);
        if(arch.eof())break;
        nd++;
    }
    aux = new void *[nd+1]{};
    for(int i=0;i<nd;i++)aux[i]=buffStock[i];
    stock=aux;
}
//codProd,stock
void *leerRegStock(ifstream &arch){
    int *codP,*stockP,cod,stock;
    arch>>cod;
    if(arch.eof())return nullptr;
    arch.get();
    arch>>stock;
    void **reg;
    reg=new void *[2];
    codP=new int;
    stockP=new int;
    *codP=cod;
    *stockP=stock;
    reg[0]=codP;
    reg[1]=stockP;
    return reg;
}

void leePedidos(void *&pedidos){
    ifstream arch;
    void *buffReg[400],**aux;
    AbrirArchivo("pedidos.csv",arch);
    int nd=0;
    while(1){
        leePedidosLinea(buffReg,nd,arch);
        if(arch.eof())break;
    }
    
    aux = new void *[nd+1]{};
    for(int i=0;i<nd;i++)aux[i]=buffReg[i];
    pedidos=aux;
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>aa>>c>>mm>>c>>dd;
    return dd+mm*100+aa*10000;
}
//21034000,Para tu sed,2012/06/02,1233,Gaseosa Koka Kola,20,2012/07/04,2344,Gaseosa Koka Kola Zero,50,2012/08/04,2344,Gaseosa Koka Kola Zero,50
//RUC, nombreTienda,(fecha, codigo, nombre, cantSol)
void leePedidosLinea(void **buffReg,int &nd,ifstream &arch){
    char *nombreTienda,*nomb,c,buff[100];
    int *PRUC,RUC,fecha,*fechaP,cod,*codP,cant,*cantP,*cantAtend;
    PRUC=new int;
    cantAtend = new int;
    *cantAtend = 0;
    arch>>*PRUC>>c;
    void **aux;
    if(arch.eof())return;
    arch.getline(buff,150,',');
    while(1){
        cout<<"Hola owo";
        fecha=leerFecha(arch);
        arch>>c>>cod>>c;
        nomb=leerCadena(arch,',');
        arch>>cant;
        fechaP =  new int;
        codP = new int;
        cantP = new int;
        aux = new void *[6];
        *fechaP = fecha;
        *codP = cod;
        *cantP = cant;
        aux[0]=fechaP;
        aux[1]=PRUC;
        aux[2]=codP;
        aux[3]=nomb;
        aux[4]=cantP;
        aux[5]=cantAtend;
        buffReg[nd]=aux;
        nd++;
        if(arch.get()=='\n'||arch.eof())break;
    }
}

char *leerCadena(ifstream &arch,char c){
    char buff[150],*aux;
    arch.getline(buff,150,c);
    aux=new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
void atiende(void *&ped,void *&stock){
    ordenarPedidos(ped);
    void **pedidos=(void **)ped;
    for(int i=0;pedidos[i];i++){
        atenderPedido(pedidos[i],stock);
    }
    imprimePedidos(pedidos);
}

void atenderPedido(void *&ped,void *&stock){
    int *cantSol,*cantAtend,*codProd;
    obtieneDatosPedido(cantSol,cantAtend,codProd,ped);
    int *stockProd;
    buscaProd(*codProd,stock,stockProd);
    if(stockProd==nullptr)return;
    if(*cantSol<*stockProd){
        *cantAtend=*cantSol;
        (*stockProd)-=(*cantSol);
    }else{
        *cantAtend = (*cantSol)-(*stockProd);
        (*stockProd)=0;
    }
}

void buscaProd(int codProd,void *&st,int *&stockBuscado){
    void **stock=(void**)st;
    for(int i=0;stock[i];i++){
        if(comparaCod(codProd,stock[i],stockBuscado))return;
    }
    stockBuscado = nullptr;
}

int comparaCod(int codProd,void *stock,int *&stockBuscado){
    int *codigo;
    void **aux=(void **)stock;
    codigo=(int *)aux[0];
    if(codProd==(*codigo)){
        stockBuscado=(int *)aux[1];
        return 1;
    }
    return 0;
}
void obtieneDatosPedido(int *&cantSol,int *&cantAtend,int *&codProd,void *&ped){
    void **pedido=(void **)ped;
    codProd = (int *)pedido[2];
    cantSol = (int *)pedido[4];
    cantAtend = (int *)pedido[5];
}

void ordenarPedidos(void *&ped){
    void **pedidos=(void **)ped;
    int nd=0;
    for(int i=0;pedidos[i];i++)nd++;
    qSort(pedidos,0,nd-1);

}

void qSort(void **&pedidos,int izq,int der){
    int limite;
    if (izq>=der) return;
    // Ponemos el elemento pivot al inicio
    cambiar(pedidos[izq],pedidos[(izq+der)/2]);
    limite = izq;
    for(int i=izq+1; i<=der; i++){
        if(enDesorden(pedidos[i],pedidos[izq])){
            cambiar(pedidos[++limite], pedidos[i]);
             
        }
    }
    cambiar(pedidos[izq], pedidos[limite]);
    qSort(pedidos,izq, limite-1);
    qSort(pedidos,limite+1,der);
}

void cambiar(void *&dato1,void *&dato2){
    void *aux;
    aux=dato1;
    dato1=dato2;
    dato2=aux;
}

int enDesorden(void *&ped1,void *&ped2){
    void **aux1=(void**)ped1,**aux2=(void**)ped2;
    int *dat1,*dat2;
    dat1=(int *)aux1[0];
    dat2=(int *)aux2[0];
    return *dat1<=*dat2;
    
}

void imprimirDatos(void *&ped,void *stock){
    ordenarPedidosRUC(ped);
    void **pedidos=(void**)ped;
    ofstream arch;
    AbrirArchivo("ReporteDatos.txt",arch);
    arch<<setw(55)<<right<<"REPORTE DE ATENCION"<<endl;
    int RUC=0,aux,flag=1;
    for(int i=0;pedidos[i];i++){
        aux=obtenerRUC(pedidos[i]);
        if(aux!=RUC){
            if(!flag){
                arch<<endl;
            }
            flag=0;
            imprimeCabecera(arch,aux);
        }
        RUC=aux;
        imprimeRegReporteAtencion(pedidos[i],arch);
    }
}

void imprimeCabecera(ofstream &arch,int ruc){
    arch<<"RUC:   "<<ruc<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(10)<<left<<"  Fecha"<<setw(20)<<left<<"Cod.Producto"<<setw(20)
            <<left<<"Producto"<<setw(10)<<left<<"Cant. Solicitada"<<setw(20)
            <<left<<"Cant. Atendida"<<endl;
}
//pedido: fecha, ruc,codProd,nombre,cantSol,cantAtend
void imprimeRegReporteAtencion(void *ped,ofstream &arch){
    void **pedidos=(void**)ped;
    arch<< "  ";
    int *fecha,*codProd,*cantSol,*cantAtend;
    char *nomb;
    fecha = (int *)pedidos[0];
    codProd = (int *)pedidos[2];
    nomb = (char *)pedidos[3];
    cantSol = (int *)pedidos[4];
    cantAtend = (int *)pedidos[5];
    imprimeFecha(*fecha,arch);
    arch<<setw(10)<<right<<*codProd<<"     "<<setw(30)<<left<<nomb<<setw(10)
            <<right<<*cantSol<<setw(10)<<right<<*cantAtend<<endl;
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(4)<<right<<aa<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(2)<<right<<dd<<setfill(' ');
}
void imprimeLinea(ofstream &arch,int cantidad,char c){
    for(int i=0;i<cantidad;i++)arch<<c;
    arch<<endl;
}
int obtenerRUC(void *ped){
    void **pedidos=(void**)ped;
    int *ruc=(int *)pedidos[1];
    return *ruc;
}

void ordenarPedidosRUC(void *&ped){
    void **pedidos=(void **)ped;
    int nd=0;
    for(int i=0;pedidos[i];i++)nd++;
    qSortRUC(pedidos,0,nd-1);
}

void qSortRUC(void **&pedidos,int izq,int der){
    int limite;
    if (izq>=der) return;
    // Ponemos el elemento pivot al inicio
    cambiar(pedidos[izq],pedidos[(izq+der)/2]);
    limite = izq;
    for(int i=izq+1; i<=der; i++){
         if(enDesordenRUC(pedidos[i],pedidos[izq])){
            cambiar(pedidos[++limite], pedidos[i]);
            
         }
    }
    cambiar(pedidos[izq], pedidos[limite]);
    qSortRUC(pedidos,izq, limite-1);
    qSortRUC(pedidos,limite+1,der);
}
//PREGUNTAR RUC
int enDesordenRUC(void *&ped1,void *&ped2){
    void **aux1=(void**)ped1,**aux2=(void**)ped2;
    int *dat1,*dat2;
    dat1=(int *)aux1[1];
    dat2=(int *)aux2[1];
    return (*dat1)>=(*dat2);
}