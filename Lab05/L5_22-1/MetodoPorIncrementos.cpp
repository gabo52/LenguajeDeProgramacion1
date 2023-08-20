/* 
 * File:   MetodoPorIncrementos.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 8 de mayo de 2023, 05:59 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
#include "MetodoPorIncrementos.h"
using namespace std;

void AbrirArchivoLectura(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout << "ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivoEscritura(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout << "ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[100];
    arch.getline(buff,100,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void CargaDePedidosYProductos(int **cli_DniTelefono, char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento, char ***&ped_Codigo,  int ***&ped_FechaCantidad, const char *nombre){
    ifstream arch;
    AbrirArchivoLectura("Pedidos.csv",arch);
    
    int posProd, i, fecha, aa, mm, dd, cant, dni, numProd = 0, capProd = 0, posCli, numCli[1000]{}, capCli[1000]{};
    double descuento, precio; 
    char *cad1, *cad2, car;
    
    for(i=0;cli_DniTelefono[i];i++);
    
    ped_Codigo = new char **[i + 1];
    ped_FechaCantidad = new int **[i + 1];
    
    for(int j=0; j<i; j++){
        ped_Codigo[j] = nullptr;
        ped_FechaCantidad[j] = nullptr;
    }
    
    pro_CodigoDescripcion = nullptr;
    pro_PrecioDescuento = nullptr;
    
    while(1){
        descuento = 0; 
        cad1 = leerCadena(arch, ',');
        if(arch.eof()) break;
        cad2 = leerCadena(arch, ',');
        arch >> cant;
        if(arch.fail()){
            arch.clear(); 
            arch >> car >> descuento >> car >> cant; 
        }
        arch >> car >> precio >> car >> dni >> car >> dd >> car >> mm >> car >> dd; 
        arch.get(); 
        fecha = aa*10000 + mm*100 + dd;
        posCli = buscarCliente(cli_DniTelefono,dni); 
        if (posCli != -1) agregarPedido(ped_Codigo[posCli], ped_FechaCantidad[posCli], capCli[posCli], numCli[posCli], cad1, fecha, cant);
        posProd = buscarCodigo(pro_CodigoDescripcion,cad1); 
        if(posProd == -1) agregarProducto(pro_CodigoDescripcion,pro_PrecioDescuento,cad1,cad2,descuento,precio,numProd,capProd);
    }
}

void agregarPedido(char **&ped_Codigo,  int **&ped_FechaCantidad, int &capCli, int &numCli, char *ped, int fecha, int cant){
    int *aux1;
    aux1 = new int [2];
    aux1[0] = fecha;
    aux1[1] = cant;
    
    if (numCli == capCli) incrementarEspaciosPedidos(ped_Codigo, ped_FechaCantidad, capCli, numCli);
    ped_Codigo[numCli] = nullptr;
    ped_Codigo[numCli - 1] = ped;
    ped_FechaCantidad[numCli] = nullptr;
    ped_FechaCantidad[numCli - 1] = aux1;
    numCli++;
}

void incrementarEspaciosPedidos(char **&ped_Codigo,  int **&ped_FechaCantidad, int &capCli, int &numCli){
    char **auxC;
    int **auxF;
    
    capCli += INCREMENTO;
    if (ped_Codigo == nullptr) {
        ped_Codigo = new char *[capCli];
        ped_FechaCantidad = new int *[capCli];
        
        ped_Codigo[0] = nullptr;
        ped_FechaCantidad[0] = nullptr;
        
        numCli = 1;
    } else {
        auxC = new char *[capCli];
        auxF = new int *[capCli];
        
        for (int i = 0; i < numCli; i++){
            auxC[i] = ped_Codigo[i];
            auxF[i] = ped_FechaCantidad[i];
        }
        
        delete ped_Codigo;
        delete ped_FechaCantidad;
        ped_Codigo = auxC;
        ped_FechaCantidad = auxF;
    }
}

int buscarCliente(int **cli_DniTelefono, int dniCli){
    for(int i=0; cli_DniTelefono[i]; i++){
        if(cli_DniTelefono[i][0] == dniCli) return i;
    }
    return -1;
}

int buscarCodigo(char ***pro_CodigoDescripcion, char *cad){
    if(pro_CodigoDescripcion == nullptr) return -1;
    
    for(int i=0; pro_CodigoDescripcion[i]; i++){
        if(strcmp(pro_CodigoDescripcion[i][0], cad) == 0){
            return i;
        }
    }
    return -1;
}


void agregarProducto(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento, char *codigo, char *descripcion, double descuento, double precio, int &numProd, int &cap){
    double *aux1; 
    char **aux2; 
    
    aux1 = new double[2]{};
    aux2 = new char*[2]{}; 
    
    aux1[0] = precio;
    aux1[1] = descuento;
    
    aux2[0] = codigo;
    aux2[1] = descripcion;
    
    if (numProd == cap) incrementarEspaciosProductos(pro_CodigoDescripcion, pro_PrecioDescuento, cap, numProd);
    
    pro_CodigoDescripcion[numProd] = nullptr;
    pro_CodigoDescripcion[numProd-1] = aux2; 
    pro_PrecioDescuento[numProd] = nullptr;
    pro_PrecioDescuento[numProd-1] = aux1; 
    numProd++; 
}

void incrementarEspaciosProductos(char ***&pro_CodigoDescripcion, double **&pro_PrecioDescuento, int &cap, int &numProd){
    char ***auxC;
    double **auxP;
    
    cap += INCREMENTO;
    if (pro_CodigoDescripcion == nullptr) {
        pro_CodigoDescripcion = new char **[cap];
        pro_PrecioDescuento = new double *[cap];
        
        pro_CodigoDescripcion[0] = nullptr;
        pro_PrecioDescuento[0] = nullptr;
        
        numProd = 1;
    }else{
        auxC = new char **[cap];
        auxP = new double *[cap];
        for (int i = 0; i < numProd; i++){
            auxC[i] = pro_CodigoDescripcion[i];
            auxP[i] = pro_PrecioDescuento[i];
        }
        delete pro_CodigoDescripcion;
        delete pro_PrecioDescuento;
        pro_CodigoDescripcion = auxC;
        pro_PrecioDescuento = auxP;
    }
}


void ReporteDePedidosYProductos(int **cli_DniTelefono, char ***pro_CodigoDescripcion,
        double **pro_PrecioDescuento, char ***ped_Codigo, int ***ped_FechaCantidad,
        const char *nombre){
    ofstream arch;
    AbrirArchivoEscritura(nombre, arch);
    
    arch << left << "REPORTE PEDIDOS" << endl;
    imprimirLinea(arch, '=');
    for(int i=0; cli_DniTelefono[i]; i++){
        arch << setw(15) << "DNI COMPRADOR: " << setw(10) << cli_DniTelefono[i][0] << setw(10) << cli_DniTelefono[i][1] << endl;
        imprimirLinea(arch, '-');
        arch << right << setw(8) << "CODPROD" << setw(15) << "FECHA" << setw(15) << "CANTIDAD" << endl;
        if(ped_Codigo[i]){
            imprimirPedidos(arch, ped_Codigo[i], ped_FechaCantidad[i]);
        }
        arch << endl;
    }
    
    arch << endl << endl;
    imprimirLinea(arch, '*');
    arch << left << "REPORTE PRODUCTOS" << endl;
    imprimirLinea(arch, '*');
    arch << left << setw(75) << "COD PRODUCTO: " << setw(10) << "PRECIO" <<
            setw(15) << "DESCUENTO" << endl;
    for(int i=0; pro_CodigoDescripcion[i]; i++){
        arch << right << setw(3) << i + 1 << ")  ";
        arch << left << setw(15) << pro_CodigoDescripcion[i][0] << 
                setw(50) << pro_CodigoDescripcion[i][1] <<
                right << setw(10) << pro_PrecioDescuento[i][0] <<
                setw(10) << pro_PrecioDescuento[i][1] << endl;
    }
}

void imprimirPedidos(ofstream &arch, char **ped_Codigo, int **ped_FechaCantidad){
    if(ped_FechaCantidad){
        for(int i=0; ped_FechaCantidad[i]; i++){
            arch << right << setw(3) << i + 1 << ")  ";
            arch << setw(10) << ped_Codigo[i] << "  ";
//            arch << setw(10) << ped_FechaCantidad[i][0];
            imprimeFecha(arch, ped_FechaCantidad[i][0]);
            arch << "   " << setw(10) << ped_FechaCantidad[i][1];
            arch << endl;
        }
    }
}

void ReporteRelacionDePedidos(int **cli_DniTelefono, char ***cli_NombreCategoria, 
        char ***pro_CodigoDescripcion, double **pro_PrecioDescuento, char ***ped_Codigo, 
        int ***ped_FechaCantidad, const char *nombre){
    ofstream arch;
    AbrirArchivoEscritura(nombre, arch);
    imprimirCabeceraReporte(arch);
    for(int i=0; cli_DniTelefono[i]; i++){
        imprimirLinea(arch, '=');
        arch << left << setw(15) << "DNI" << setw(50) << "Nombre" << setw(15) <<
                "Categoria" << "Telefono" << endl;
        arch << setw(15) << cli_DniTelefono[i][0] << setw(50) << cli_NombreCategoria[i][0] << 
                setw(15) << cli_NombreCategoria[i][1] << cli_DniTelefono[i][1] << endl;
        imprimirLinea(arch, '-');
        arch << "PRODUCTOS ADQUIRIDOS" << endl;
        imprimirLinea(arch, '-');
        arch<<setw(5)<<"     " <<
                setw(10)<<"Codigo"<<
                setw(55)<<"Descripcion"<<
                setw(8)<<"P.U."<<
                setw(11)<<"Cantidad"<<
                setw(8)<<"Total"<<
                setw(12)<<"Descuento %"<<
                setw(10)<<"A Pagar"<<
                setw(13)<<"Descuento"<<
                setw(10)<<"Fecha"<<endl;
        imprimirLinea(arch, '-');
        imprimirProductos(arch, ped_Codigo[i], ped_FechaCantidad[i], pro_CodigoDescripcion, pro_PrecioDescuento);
        imprimirLinea(arch, '-');
    }
}

void imprimirProductos(ofstream &arch, char **ped_Codigo, 
        int **ped_FechaCantidad, char ***pro_CodigoDescripcion, double **pro_PrecioDescuento){
    if(ped_FechaCantidad){ // No null
        double total, pagar;
        double TOtalPagar = 0, totalDescuento=0;
        for(int i=0; ped_Codigo[i]; i++){
            arch << right << setw(3) << i + 1 << ")  ";
            arch << left << setw(10) << ped_Codigo[i];
            int pos = buscarCodigo(pro_CodigoDescripcion, ped_Codigo[i]);
            arch << setw(50) << pro_CodigoDescripcion[pos][1] << right <<
                    setw(10) << pro_PrecioDescuento[pos][0] << 
                    setw(10) << ped_FechaCantidad[i][1];
            total = pro_PrecioDescuento[pos][0] * ped_FechaCantidad[i][1];
            arch << setw(10) << total << 
                    setw(10) << pro_PrecioDescuento[pos][1];
            pagar = total * (1-pro_PrecioDescuento[pos][1]/100);
            arch << setw(10) << pagar <<
                    setw(10) << total * (pro_PrecioDescuento[pos][1]/100) << "  ";
            totalDescuento +=  total * (pro_PrecioDescuento[pos][1]/100);
//            arch << setw(10) << ped_FechaCantidad[i][0] << endl;
            imprimeFecha(arch, ped_FechaCantidad[i][0]);
            arch << endl;
            TOtalPagar += pagar;
        }
        imprimirLinea(arch, '-');
        arch << setw(106) << "TOTAL" << setw(10) << TOtalPagar << setw(10) << totalDescuento << endl;
    }
}

void imprimirCabeceraReporte(ofstream &arch){
    arch << left << setw(20) << " " << "EMPRESA COMERCIALIZADORA DE ABARROTES" << endl;
    imprimirLinea(arch, '=');
    arch << "GASTOS DE LOS CLIENTES REGISTRADOS:" << endl;
}

void imprimeFecha(ofstream &arch, int fecha){
    int dd, mm, aa;
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    aa = fecha/100;
    arch << right << setfill('0') << setw(2) << dd << "/" << 
            setw(2) << mm << "/" 
            << setw(4) << left << aa << setfill(' ');
}

void imprimirLinea(ofstream &archRep, char car){
    for (int i = 0; i < 150; i++) archRep << (car);
    archRep << endl;
}