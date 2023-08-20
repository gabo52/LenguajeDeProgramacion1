/* 
 * File:   funcionesAux.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de septiembre de 2022, 10:38 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesAux.h"
#define MAXCANTLINEA 140
using namespace std;


void AbriArchivoLectura(ifstream &arch,const char *nombre){
    arch.open(nombre,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

void AbriArchivoEscritura(ofstream &arch,const char *nombre){
    arch.open(nombre,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

void arreglaNombre(char *nombre,char &cat){
    int largo=strlen(nombre);
    if(nombre[largo-2]==' '){
        cat=nombre[largo-1];
        nombre[largo-2]=0;
    }else cat='-';
}

void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    int dni,tele,i=0,buffCli[100],j;
    char nombre[150],cat,*buffNomb[100],buffCat[100];
    ifstream arch;
    AbriArchivoLectura(arch,"Clientes.csv");
    while(1){
        arch>>dni;
        if(arch.eof())break;
        arch.get();
        arch.getline(nombre,150,',');
        arreglaNombre(nombre,cat);
        arch>>tele;
        buffCli[i]=dni;
        buffCat[i]=cat;
        //No se olviden de separar espacio de memoria
        //Para lectura de char * usar tecnica Guanira  -> usar leer Cadena
        buffNomb[i]=new char [strlen(nombre)+1];
        strcpy(buffNomb[i],nombre);
        i++;
    }
    cli_DNI = new int [i+1];
    cli_Nombre = new char *[i+1];
    cli_Categoria = new char [i+1];
    for(j=0;j<i;j++){
        cli_DNI[j]=buffCli[j];
        cli_Categoria[j]=buffCat[j];
        cli_Nombre[j]=buffNomb[j];
    }
    cli_DNI[j]=0;
    cli_Categoria[j] = 0;
    cli_Nombre[j] = nullptr;
}
void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria){
    ofstream arch;
    AbriArchivoEscritura(arch,"ReporteClientes.txt");
    for(int i=0;cli_DNI[i];i++){
        arch<<setw(10)<<left<<cli_DNI[i]<<setw(50)<<left<<cli_Nombre[i]<<
                setw(4)<<left<<cli_Categoria[i]<<endl;
    }
}

int buscarDato(int *arr,int dato){
    for(int i=0;arr[i];i++)if(arr[i]==dato)return i;
    cout<<"Error, no se encontro el dato: "<<dato;
    exit(1);
}

int buscarDato(int *arr,int dato,int numDat){
    for(int i=0;i<numDat;i++)if(arr[i]==dato)return i;
    return -1;
}

//void agregarProducto(int *buffCod,int cod,char **pro_Descrip,char *cad,
//        double *prod_Desc,double desc,double *prod_prec,double prec,int &numDat){
//    buffCod[numDat]=cod;
//    pro_Descrip[numDat]=cad;
//    prod_Desc[numDat]=desc;//    prod_prec[numDat]=prec;
//    numDat++;
//}

void agregarProducto(int &codProd,int cod,char *&descripcion,char *cad
    ,double &descuento,double desc,double &precio,double prec,int &numDat){
    codProd=cod;
    descripcion=cad;
    descuento=desc;
    precio=prec;
    numDat++;
}
//397718,LECHE LALA SEMI DESLACTOSADA 1LT,1.78,16.98,71378466,26/10/2020
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
        char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
        int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido){
    ifstream arch;
    AbriArchivoLectura(arch,"Pedidos.csv");
    int buff_proCod[200],*buffCodProFecha[200],numDat=0,cod,DNI,fecha,pos1,pos2;
    double descuento[200],precio[200],*cantPed[200],desc,cant,prec;
    char *descripcion[200],*cad;
    int numPedidos[200]={},i;
    for(i=0;cli_DNI[i];i++){
        buffCodProFecha[i] =  new int [50];
        cantPed[i] = new double [25];
   }
    while(1){
        arch>>cod;
        if(arch.eof())break;
        leeValores(cad,desc,cant,prec,DNI,fecha,arch);
        pos1=buscarDato(cli_DNI,DNI);
        //agregar datos al cliente
        agregarDatosCliente(buffCodProFecha[pos1],cod,fecha,
                cantPed[pos1],cant,numPedidos[pos1]);
        pos2=buscarDato(buff_proCod,cod,numDat);
        if(pos2==-1){
            agregarProducto(buff_proCod[numDat],cod,descripcion[numDat],cad
                ,descuento[numDat],desc,precio[numDat],prec,numDat);
        }
    }
    copiarArreglosDinamicos(pro_Codigo,pro_Descripcion,pro_Descuento,pro_Precio,
        cli_CodigoProFechaPedido,cli_CantidadPedido,numDat,buff_proCod,
        descripcion,descuento,precio,cli_DNI,i,cantPed,buffCodProFecha,numPedidos);
    for(i=0;cli_DNI[i];i++){
        delete buffCodProFecha[i];
        delete cantPed[i];
   }
}

void copiarArreglosDinamicos(int *&pro_Codigo,char **&pro_Descripcion,
        double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido,
        double **&cli_CantidadPedido,int numDat,int *buff_proCod,char **descripcion,
        double *descuento,double *precio,int *cli_DNI,int i,double **cantPed,
        int **buffCodProFecha,int *numPedidos){
    pro_Codigo = new int [numDat+1];
    pro_Descripcion = new char *[numDat+1];
    pro_Descuento = new double [numDat+1];
    pro_Precio = new double [numDat+1];
    cli_CodigoProFechaPedido = new int *[i+1];
    cli_CantidadPedido = new double *[i+1];
    for(i=0;i<numDat;i++){
        pro_Codigo[i]=buff_proCod[i];
        pro_Descripcion[i]=descripcion[i];        
        pro_Descuento[i]=descuento[i];
        pro_Precio[i]=precio[i];
    }
    for(i=0;cli_DNI[i];i++){
        asignarValoresCliente(cli_CodigoProFechaPedido[i],buffCodProFecha[i],
                cli_CantidadPedido[i],cantPed[i],numPedidos[i]);
    }
    pro_Codigo[numDat]=0;
    pro_Descripcion[numDat]= nullptr;
    pro_Descuento[numDat]= 0;
    pro_Precio[numDat]= 0;
}



void asignarValoresCliente(int *&codProFecha,int *&buffCodProFecha,
            double *&cantPed, double  *&buffCantPed,int num){
    codProFecha = new int [2*num+2];
    cantPed = new double [num+1];
    for(int i=0;i<num;i++){
        codProFecha[2*i]=buffCodProFecha[2*i];
        codProFecha[(2*i)+1]=buffCodProFecha[(2*i)+1];
        cantPed[i]=buffCantPed[i];
    }
    codProFecha[2*num]=0;
    codProFecha[2*num+1]=0;
    cantPed[num]=0;

}
void  agregarDatosCliente(int *&codProFechaPed,int cod,int fecha,
        double *&cantPed,double cant,int &numDat){
    codProFechaPed[numDat*2]=cod;
    codProFechaPed[(numDat*2)+1]=fecha;
    cantPed[numDat]=cant;
    numDat++;
}
void leeValores(char *&cad,double &desc,double &cant,double &prec,int &DNI,
        int &fecha,ifstream &arch){
    int aa,dd,mm;
    char c;
    double aux;
    arch.get();
    cad=leerCadena(arch,',');
    arch>>cant;
    if(arch.fail()){
        arch.clear();
        arch.get();
        arch>>desc>>c>>cant;
    }
    arch>>c>>prec>>c>>DNI>>c>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}

char * leerCadena(ifstream &arch,char c){
    char buffer[100],*cadena;
    arch.getline(buffer,100,c);
    cadena = new char [strlen(buffer)+1];
    strcpy(cadena,buffer);    
    return cadena;
}

void imprimePedidos(int *codFecha,double *cant,ofstream &archRep2){
    for(int i=0;codFecha[2*i];i++){
        archRep2<<setw(10)<<left<<codFecha[2*i]<<setw(10)<<left<<codFecha[2*i+1]
                <<setw(10)<<right<<setprecision(2)<<fixed<<cant[i]<<endl;
    }
}

void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,
        char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
        int **cli_CodigoProFechaPedido,double **cli_CantidadPedido){
    ofstream archRep1,archRep2;
    AbriArchivoEscritura(archRep1,"ReporteProductos.txt");
    AbriArchivoEscritura(archRep2,"ReportePedidos.txt");
    for(int i=0;pro_Codigo[i];i++){
        archRep1<<setw(10)<<left<<pro_Codigo[i]<<setw(40)<<left
                <<pro_Descripcion[i]<<setw(12)<<right<<setprecision(2)<<fixed
                <<pro_Descuento[i]<<setw(12)<<right<<pro_Precio[i]<<endl;
    }
    
    for(int i=0;cli_DNI[i];i++){
        archRep2<<setw(10)<<left<<cli_DNI[i]<<endl;
        imprimePedidos(cli_CodigoProFechaPedido[i],cli_CantidadPedido[i],archRep2);
    }
}

void ReporteRelacionDePedidos(int *cli_DNI,char **cli_Nombre,char *cli_Categoria,
            int **cli_CodigoProFechaPedido,double **cli_CantidadPedido,
        int *pro_Codigo,char **pro_Descripcion,double *pro_Descuento,
        double *pro_Precio){
    ofstream archRep;
    AbriArchivoEscritura(archRep,"ReporteRelacionDePedidos.txt");
    imprimeCabecera(archRep);
    for(int i=0;cli_DNI[i];i++){
        imprimeCabeceraCliente(archRep,cli_DNI[i],cli_Nombre[i],cli_Categoria[i]);
        if(cli_CodigoProFechaPedido[i]){
            imprimirProductosCliente(cli_CodigoProFechaPedido[i],
                    cli_CantidadPedido[i],archRep,pro_Codigo,pro_Descripcion,
                    pro_Precio,pro_Descuento);
        }
    }
}

void hallarDescripPrecio(int *codProd,char **arrDescrip,double *arrPrecio,
        double *arrDesc,char *&descripcion,double &precio,
        double &descuento,int codigo){
    for(int i=0;codProd[i];i++){
        if(codProd[i]==codigo){
            descripcion=arrDescrip[i];
            precio=arrPrecio[i];
            descuento=arrDesc[i];
            return;
        }
    }
    cout<<"ERROR uwu no se encontro el codigo "<<codigo;
    exit(1);
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}
void imprimirProductosCliente(int *arrCodFecha,
                    double *arrCant,ofstream &archRep,int *codProd,
        char **arrDescrip,double *arrPrecio,double *arrDesc){
    char *descripcion;
    double precio,cantidad,descuento,tot;
    for(int i=0;arrCodFecha[i*2];i++){
        archRep<<setw(2)<<right<<i+1<<setw(10)<<right<<arrCodFecha[i*2];
        hallarDescripPrecio(codProd,arrDescrip,arrPrecio,arrDesc,
                descripcion,precio,descuento,arrCodFecha[i*2]);
        tot=arrCant[i]*precio;
        archRep<<"   "<<setw(40)<<left<<descripcion<<setw(12)<<right
                <<setprecision(2)<<fixed<<precio<<setw(10)<<right
                <<setprecision(2)<<fixed<<arrCant[i]<<setw(15)<<right
                <<setprecision(2)<<fixed<<tot;
        if(descuento>0){
            archRep<<setw(10)<<right<<setprecision(1)<<fixed<<descuento;
        }else{
            archRep<<setw(10)<<right<<"-.--";
        }
        archRep<<setw(8)<<right<<setprecision(1)<<fixed<<tot*(100-descuento)/100<<
                setw(8)<<right<<setprecision(1)<<fixed<<tot*descuento/100<<"       ";
        imprimeFecha(arrCodFecha[(i*2)+1],archRep);
        archRep<<endl;
    }
}

void imprimeCabecera(ofstream &archRep){
    archRep<<setw(92)<<right<<"EMPRESA COMERCIALIZADORA DE ABARROTES"<<endl;
    imprimeLinea(archRep,MAXCANTLINEA,'=');
    archRep<<left<<"GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeCabeceraCliente(ofstream &arch,int dni,char *nombre,char cat){
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(20)<<left<<"DNI"<<setw(60)<<left<<"Nombre"<<setw(20)<<left
            <<"Categoria"<<endl;
    arch<<setw(20)<<left<<dni<<setw(64)<<left<<nombre<<setw(20)<<left
            <<cat<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<"PRODUCTOS ADQUIRIDOS"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(12)<<right<<"Codigo"<<setw(12)<<right<<"  Descripcion"<<setw(38)
            <<right<<"P.U."<<setw(10)<<right<<"Cantidad"<<setw(10)<<right<<
            "Total"<<setw(14)<<right<<"Descuento %"<<
            "     A pagar    Descuento     Fecha"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
}