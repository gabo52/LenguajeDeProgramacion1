/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MetodoPorIncremento.h"
#define MAXCANTLINEA 100
#define INCREMENTO 5
using namespace std;
// char **cli_NombreCategoria,***pro_CodigoDescripcion,**ped_Codigo;
//    int **cli_DniTelefono,***ped_FechaCantidad;
//    double **pro_PrecioDescuento;


void AbrirArchivoEscritura(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo ",nomb;
        exit(1);
    }
}

void AbrirArchivoLectura(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo ",nomb;
        exit(1);
    }
}
//71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO B,935441620
//Dni, nombre, cat (opcional), telefono;

//FAY216,LECHE LALA SEMI DESLACTOSADA 1LT,19,16.98,71378466,26/10/2020
//codigo, descripcion,descuento,cant,precio,DNI,fecha
void CargaDePedidosYProductos(int **cli_DniTelefono,char ***&pro_CodigoDescripcion,
        double **&pro_PrecioDescuento,char ***&ped_Codigo,
        int ***&ped_FechaCantidad,const char *nomb){
    ifstream arch;
    AbrirArchivoLectura(nomb,arch);
    char *codProd,*descripcion,c;
    double descuento,precio;
    int cant,DNI,fecha,pos1,pos2,numDat1[200]{},cap1[200]{},numDat2=0,cap2=0,i;
    for(i=0;cli_DniTelefono[i];i++);
    cout<<i<<endl;
    pro_CodigoDescripcion = nullptr;
    ped_FechaCantidad = new int **[i+1]{};
    ped_Codigo = new char **[i+1]{};
    
    while(1){
        codProd=leerCadena(arch,',');
        if(arch.eof())break;
        leerDatos(arch,descripcion,descuento,precio,DNI,fecha,cant);
        pos1=buscarDNI(DNI,cli_DniTelefono);
        pos2=buscarProducto(codProd,pro_CodigoDescripcion);
        //inicializar con null ptr
        if(pos2==-1)agregarProducto(numDat2,cap2,pro_CodigoDescripcion,
                codProd,descripcion,pro_PrecioDescuento,precio,descuento);
        cout<<descripcion<<endl;
        agregarPedidoACliente(ped_FechaCantidad[pos1],ped_Codigo[pos1],fecha,
                cant,codProd,numDat1[pos1],cap1[pos1]);
    }
    cout<<"SALI";
}

void agregarPedidoACliente(int **&ped_FechaCantidad,char **&pedCod,int fecha,
                int cant,char *&codProd,int &numDat,int &cap){
    if(numDat==cap)incrementarClientes(ped_FechaCantidad,pedCod,numDat,cap);
    agregarDatosCliente(ped_FechaCantidad[numDat-1],pedCod[numDat-1],numDat,fecha,cant,codProd);
    numDat++;
}

void agregarDatosCliente(int *&ped_FechaCantidad,char *&pedCod,int numDat,
        int fecha,int cant,char *&codProd){
    ped_FechaCantidad = new int[2]{};
    ped_FechaCantidad[0]=fecha;
    ped_FechaCantidad[1]=cant;
    pedCod = codProd;
}


void incrementarClientes(int **&ped_FechaCantidad,char **&pedCod,
        int &numDat,int &cap){
    int **auxFecha;
    char **auxCod;
    
    cap+=INCREMENTO;
    if(ped_FechaCantidad == nullptr||numDat==0){
        ped_FechaCantidad = new int *[cap]{};
        pedCod = new char *[cap]{};
        numDat=1;
    }else{
        auxFecha = new int *[cap]{};
        auxCod = new char *[cap]{};
        for(int i=0;i<numDat;i++){
            auxFecha[i]=ped_FechaCantidad[i];
            auxCod[i]=pedCod[i];
        }
        delete ped_FechaCantidad;
        delete pedCod;
        ped_FechaCantidad=auxFecha;
        pedCod=auxCod;
    }
}

void agregarProducto(int &numDat,int &cap,char ***&pro_CodigoDescripcion,
                char *cod,char *descripcion,double **&pro_PrecioDescuento,
        double precio,double descuento){
    if(numDat==cap)incrementarProducto(pro_CodigoDescripcion,pro_PrecioDescuento,numDat,cap);
    pro_CodigoDescripcion[numDat-1] = new char*[2];
    pro_PrecioDescuento[numDat-1] = new double[2];
    pro_CodigoDescripcion[numDat-1][0] = cod;
    pro_CodigoDescripcion[numDat-1][1] = descripcion;
    pro_PrecioDescuento[numDat-1][0] = precio;
    pro_PrecioDescuento[numDat-1][1] = descuento;
    numDat++;
}

void incrementarProducto(char ***&pro_CodigoDescripcion,
        double **&pro_PrecioDescuento,int &numDat,int &cap){
    double **auxpro;
    char ***auxCodDesc;
    cap+=INCREMENTO;
    if(pro_CodigoDescripcion==nullptr){
        pro_CodigoDescripcion = new char **[cap]{};
        pro_PrecioDescuento = new double *[cap]{};
        numDat=1;
    }else{
        auxCodDesc = new char **[cap]{};
        auxpro = new double *[cap]{};
        for(int i=0;i<numDat;i++){
            auxCodDesc[i]=pro_CodigoDescripcion[i];
            auxpro[i]=pro_PrecioDescuento[i];
        }
        delete pro_CodigoDescripcion;
        delete pro_PrecioDescuento;
        pro_CodigoDescripcion=auxCodDesc;
        pro_PrecioDescuento=auxpro;
    }
}
int buscarProducto(char *cod,char ***pro_CodigoDescripcion){
    if(pro_CodigoDescripcion==nullptr)return -1;
    for(int i=0;pro_CodigoDescripcion[i];i++){
        if(strcmp(pro_CodigoDescripcion[i][0],cod)==0)return i;
    }
    return -1;
}

int buscarDNI(int DNI,int **arrDNI){
    for(int i=0;arrDNI[i];i++)if(DNI==arrDNI[i][0])return i;
    cout<<"ERROR, no se encontro el DNI "<<DNI;
    exit(1);
}


void leerDatos(ifstream &arch,char *&descripcion,double &descuento,double &precio,
        int &DNI,int &fecha,int &cant){
    char c,c2,c3;
    descripcion=leerCadena(arch,',');
    arch>>cant;
    double aux;
    if(arch.fail()){
        arch.clear();
        arch.get();
        arch>>descuento;
        arch>>c>>cant;
    }else descuento=0;
    arch.get();
    arch>>precio>>c>>DNI;
    arch.get();
    fecha=leerFecha(arch);
    arch.get();
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    return dd+mm*100+aa*10000;
}

char *leerCadena(ifstream &arch,char c){
    char buff[200]{},*aux;
    arch.getline(buff,200,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void ReporteDePedidosYProductos(int **cli_DniTelefono,char ***pro_CodigoDescripcion,
            double **pro_PrecioDescuento,char ***ped_Codigo,int ***&ped_FechaCantidad,
            const char *nomb){
    ofstream arch;
    AbrirArchivoEscritura(nomb,arch);
    arch<<setw(10)<<left<<"CODIGO"<<setw(60)<<left<<"DESCRIPCION"<<setw(10)
                    <<right<<setprecision(2)<<fixed<<"PRECIO"<<setw(10)<<right
                    <<setprecision(2)<<fixed<<"DESCUENTO"<<endl;  
    for(int i=0;pro_CodigoDescripcion[i];i++){
            imprimirProducto(arch,pro_CodigoDescripcion[i],pro_PrecioDescuento[i]);
    }
    
    imprimirLinea(arch,MAXCANTLINEA,'=');
    for(int i=0;cli_DniTelefono[i];i++){
        if(ped_Codigo[i]){
            imprimeDatosCliente(cli_DniTelefono[i],ped_FechaCantidad[i],ped_Codigo[i],
                arch);
        }
    }
}

void imprimirProducto(ofstream &arch,char **pro_CodigoDescripcion,
        double *pro_PrecioDescuento){
            arch<<setw(10)<<left<<pro_CodigoDescripcion[0]<<setw(60)<<left<<
            pro_CodigoDescripcion[1]<<setw(10)<<right<<setprecision(2)<<fixed<<
            pro_PrecioDescuento[0]<<setw(10)<<right<<setprecision(2)<<fixed<<
            pro_PrecioDescuento[1]<<endl;
}
void imprimirLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void imprimeDatosCliente(int *cli_DniTelefono,int **ped_FechaCantidad,char **ped_Codigo,
                ofstream &arch){
    arch<<setw(10)<<left<<"TELEFONO"<<setw(10)<<left<<"DNI"<<endl;
    arch<<setw(10)<<left<<cli_DniTelefono[0]<<setw(10)<<left<<cli_DniTelefono[1]<<endl;
    arch<<setw(10)<<left<<"CODIGO"<<setw(10)<<left<<"CANTIDAD"<<setw(10)<<left
            <<"FECHA"<<endl;
    for(int i=0;ped_Codigo[i];i++){
        cout<<"1";
        arch<<setw(10)<<left<<ped_Codigo[i]<<setw(10)<<left<<
                ped_FechaCantidad[i][0]<<setw(10)<<left
               <<ped_FechaCantidad[i][1]<<endl;
    }
    cout<<endl;
    imprimirLinea(arch,MAXCANTLINEA,'-');
}

void ReporteRelacionDePedidos(int **cli_DniTelefono,char *** cli_NombreCategoria,
            char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
        char ***ped_Codigo,int ***ped_FechaCantidad,const char *nomb){
    
}