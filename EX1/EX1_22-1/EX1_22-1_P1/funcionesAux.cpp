/* 
 * File:   funcionesAux.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de octubre de 2022, 04:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesAux.h"
#define INCREMENTO 5
using namespace std;
/*    char ***cli_NombreCategoria,**pro_Descripcion;
    int ***cli_DniTelPed,**pro_Informacion,**ped_Todo;*/


void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}
//412041,TORTILLAS DE MAIZ 1KG,7.91%,1.78,14.93,15.95,71378466,26/10/2020
//Codigo, descripcion, descuento(si tiene),cantidad,precio, stock,DNI,fecha
void CargarProductosPedidos(int **&pro_Informacion,char **&pro_Descripcion,
        int **&ped_Todo,const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    pro_Informacion=nullptr;
    int *buffInformacion[200]{},*buffPed[200]{},nPed=0,nProd=0,codigo,descuento,precio,stock,
            DNI,cant,fecha,pos;
    char *buffDescripcion[200]{},*descrip;
    while(1){
        leerDatos(codigo,descrip,descuento,cant,precio,stock,DNI,fecha,arch);
        if(arch.eof())break;
        pos=buscarProducto(codigo,buffInformacion);
        if(pos==-1){
            asignarProducto(buffInformacion[nProd],buffDescripcion[nProd],codigo,
                    descuento,precio,stock,descrip);
            nProd++;
        }else delete descrip;
        asignarPedido(buffPed[nPed],DNI,fecha,cant,codigo);
        nPed++;
    }
    pro_Informacion = new int *[nProd+1]{};
    pro_Descripcion = new char *[nProd+1]{};
    ped_Todo = new int *[nPed+1]{};
    
    for(int i=0;i<nPed;i++){
        ped_Todo[i]=buffPed[i];
    }
    
    for(int i=0;i<nProd;i++){
        pro_Descripcion[i]=buffDescripcion[i];
        pro_Informacion[i]=buffInformacion[i];
    }
    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos01.txt");
    cout<<nProd<<endl;
}


void asignarPedido(int *&buffPed,int DNI,int fecha,int cant,int codigo){
    buffPed = new int [4];
    buffPed[0]=DNI;
    buffPed[1]=fecha;
    buffPed[2]=cant;
    buffPed[3]=codigo;
}

int buscarProducto(int codigo,int **pro_Informacion){
    for(int i=0;pro_Informacion[i];i++){
        if(comparaProductos(pro_Informacion[i],codigo))return i;
    }
    return -1;
}

int comparaProductos(int *Informacion,int codigo){
    return Informacion[0]==codigo;
}

void asignarProducto(int *&auxInformacion,char *&auxDescripcion,int codigo,
                    int descuento,int precio,int stock,char *descrip){
    auxInformacion = new int [4];
    auxInformacion[0]=codigo;
    auxInformacion[1]=descuento;
    auxInformacion[2]=precio;
    auxInformacion[3]=stock;
    auxDescripcion=descrip;
}
void leerDatos(int &codigo,char *&descrip,int &descuento,int &cant,int &precio,
        int &stock,int &DNI,int &fecha,ifstream &arch){
    arch>>codigo;
    if(arch.eof())return;
    double auxCant,auxPrec,auxStock;
    
    char c;
    arch.get();
    descrip=leerCadena(arch,',');
    arch>>auxCant;
    if(arch.get()=='%'){
        descuento=auxCant*100;
        arch>>c>>auxCant;
    }else descuento=0;
    arch.get();
    arch>>auxPrec>>c>>auxStock>>c>>DNI>>c;
    int dd,mm,aa;
    arch>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
    cant=auxCant*100;
    precio=auxPrec*100;
    stock=auxStock*100;
}

char *leerCadena(ifstream &arch,char c){
    char buff[150],*aux;
    arch.getline(buff,150,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}


void PruebaProductosPedidos(int **pro_Informacion,char **pro_Descripcion,
        int **ped_Todo,const char *nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    imprimeProductos(pro_Informacion,pro_Descripcion,arch);
    arch<<endl;
    imprimePedidos(ped_Todo,arch);
}

void imprimePedidos(int **ped_Todo,ofstream &arch){
    arch<<setw(10)<<left<<"DNI"<<setw(10)<<left<<"FECHA"<<setw(10)<<left
            <<"CANTIDAD"<<setw(10)<<left<<"CODIGO"<<endl;
    for(int i=0;ped_Todo[i];i++){
        imprimePedido(ped_Todo[i],arch);
    }
}

void imprimePedido(int *ped_Todo,ofstream &arch){
    arch<<setw(10)<<left<<ped_Todo[0]<<setw(10)<<left<<ped_Todo[1]<<setw(10)<<left
            <<ped_Todo[2]<<setw(10)<<left<<ped_Todo[3]<<endl;
}

void imprimeProductos(int **pro_Informacion,char **pro_Descripcion,ofstream &arch){
    arch<<setw(10)<<left<<"CODIGO"<<setw(10)<<left<<"DESCUENTO"<<setw(10)<<left
            <<"PRECIO"<<setw(10)<<left<<"STOCK"<<endl;
    for(int i=0;pro_Informacion[i];i++){
        imprimeProducto(pro_Informacion[i],pro_Descripcion[i],arch);
    }
}

void imprimeProducto(int *informacion,char *descripcion,ofstream &arch){
    double aux1=(double)informacion[1]/100;
    double aux2=(double)informacion[2]/100;
    double aux3=(double)informacion[3]/100;
    arch<<setprecision(2);
    arch<<setw(10)<<left<<informacion[0]<<setw(10)<<left<<aux1<<setw(10)<<left
            <<aux2<<setw(10)<<left<<aux3<<endl;
}
    
void ordenarPedidos(int **&ped_Todo){
    int nd;
    for(nd=0 ; ped_Todo[nd]; nd++)
        qSort(ped_Todo,0,nd-1);
}

void qSort(int **ped_Todo,int izq,int der){
    int limite;
    if(izq >= der) return;
     // Ponemos el elemento "pivot" al inicio
    cambiar(ped_Todo[izq], ped_Todo[(izq+der)/2]);
    limite = izq;
    for(int i = izq+1; i<=der; i++)
        if(enDesorden(ped_Todo[i],ped_Todo[izq]))
            cambiar(ped_Todo[++limite], ped_Todo[i]);
    cambiar(ped_Todo[izq], ped_Todo[limite]);
    qSort(ped_Todo,izq,limite-1);
    qSort(ped_Todo,limite+1,der);
}

void cambiar(int *&valor1, int *&valor2){
    int *aux;
    aux=valor1;
    valor1=valor2;
    valor2=aux;
}

int enDesorden(int *ped1, int *ped2){
    return ped1[1]>ped2[1] || (ped1[1]==ped2[1] && ped1[0]>ped2[0]);
}
    
void asignarPedidos(int ***&cli_DniTelPed,int **&pro_Informacion,int **&ped_Todo){
    int DNI,i,pos,codigo,fecha;
    for(i=0;cli_DniTelPed[i];i++);
    int numPed[i+1]{},capPed[i+1]{};
    double cantidad,stock;
    for(int i=0;ped_Todo[i];i++){
        DNI=obtieneDni(ped_Todo[i],codigo,cantidad,fecha);
            cout<<"sali";
        pos=buscarDNI(DNI,cli_DniTelPed);
        if(pos!=-1&&hayStock(cantidad,codigo,pro_Informacion)){
                cout<<"hola";
            //insertarPedidos
            insertarPedido(cli_DniTelPed[pos],capPed[pos],numPed[pos],fecha,codigo,cantidad);
        }
    }
}

int hayStock(double cantidad,int codigo,int **&pro_Informacion){
    int pos,*puntero;
    double precio,descuento,stock;
    buscarProducto(pro_Informacion,codigo,puntero);
    if(puntero==nullptr)return 0;
    if(puntero[3]>=cantidad*100){
        puntero[3]-=(cantidad*100);
        return 1;
    }
}

void buscarProducto(int **pro_Informacion,int codigo,int *&puntero){
    for(int i=0;pro_Informacion[i];i++){
        if(comparaProductos(pro_Informacion[i],codigo)){
            puntero=pro_Informacion[i];
            return;
        }
    }
    puntero=nullptr;
}
void insertarPedido(int **&cli_DniTelPed,int &capPed,int &numPed,int fecha, 
        int codigo, int cantidad){
    if(capPed==numPed)incrementaRegistro(cli_DniTelPed[2],capPed,numPed);
    cout<<"hola";
    agregarPedido(cli_DniTelPed[2],numPed-1,fecha,codigo,cantidad);
    numPed++;
}

void agregarPedido(int *&cli_DniTelPed,int i,
        int fecha,int codigo,int cantidad){
    cli_DniTelPed[i*3]=fecha;
    cli_DniTelPed[i*3+1]=cantidad;
    cli_DniTelPed[i*3+2]=codigo;
}
int obtieneDni(int *ped_Todo,int &codigo,double &cantidad,int &fecha){
    fecha=ped_Todo[1];
    cantidad=ped_Todo[2];
    cantidad/=100;
    codigo=ped_Todo[3];
    return ped_Todo[0];
}

int obtieneDni(int **cli_DniTelPed){
    return *cli_DniTelPed[0];
}
int buscarDNI(int DNI,int ***cli_DniTelPed){
    for(int i=0;cli_DniTelPed[i];i++){
        if(DNI==obtieneDni(cli_DniTelPed[i])){
            cout<<"Llegue";
            return i;
        }
    }
    return -1;
}

//void incrementarEspacios(int **cli_DniTelPed,int &capPed,int &numPed){
//    incrementaRegistro(cli_DniTelPed[2],capPed,numPed);
//    numPed++;
//}

void incrementaRegistro(int *&cli_DniTelPed,int &capPed,int &numPed){
    capPed+=INCREMENTO;
    if(cli_DniTelPed==nullptr){
        cli_DniTelPed = new int [capPed*3]{};
        numPed=1;
    }else{
        int *auxPed;
        auxPed= new int [capPed*3]{};
        for(int i=0;i<numPed;i++){
            auxPed[i]=cli_DniTelPed[i];
        }
        delete cli_DniTelPed;
        cli_DniTelPed=auxPed;
    }
}