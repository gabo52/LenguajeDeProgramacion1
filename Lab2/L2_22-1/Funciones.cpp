/* 
 * File:   Funciones.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 11 de abril de 2023, 08:23 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Funciones.h"
#define MAX_CAR 140
using namespace std;

void eliminaguiones(char *nombre){
    int i = 0, n;
    char c; 
    
    while(nombre[i] != '\0') i++;
    
    n = i; 
    
    for(i=0;i<n;i++){
        if(nombre[i] == '_') nombre[i] = ' ';
    }
}

char corrigeformato(char *nombre){
    int i = 0;
    char c; 
    
    while(nombre[i] != '\0') i++;
    
    if(nombre[i-2] == '-'){
        c = nombre[i-1];
        nombre[i-1] = ' '; 
    }else{
        c = 'D'; 
    }
    
    for(int j=0;j<i;j++){
        if(nombre[j] == '_' || nombre[j] == '-') nombre[j] = ' ';
    }
  
    return c; 
}

void generaclientebin(){
    int dni, telefono, codCliente, aa, mm, dd, fecha, cantidad;
    char nombre[100], codProducto[10], descripcion[100], car, categoria;
    double descuento, precioUnitario, montoGastado = 0;
   
    ifstream arch("ComprasClientes.txt", ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo CompraClientes.txt";
        exit(1); 
    }
    
    ofstream archBin("Clientes.bin", ios::out | ios::binary);
    if(!archBin){
        cout << "No se puede abrir el archivo Clientes.bin";
        exit(1); 
    }
    
    while(1){
        arch >> dni; 
        if(arch.eof()) break; 
        if(arch.fail()){
            arch.clear();
            arch >> codProducto >> descripcion >> descuento >> cantidad 
                    >> precioUnitario >> codCliente >> dd >> car >> mm >> car >> aa; 
        }else{
            arch >> nombre >> telefono; 
            categoria = corrigeformato(nombre); 
            
            archBin.write(reinterpret_cast<const char *>(&dni), sizeof(int));
            archBin.write(reinterpret_cast<const char *>(nombre), sizeof(char)*100);
            archBin.write(reinterpret_cast<const char *>(&categoria), sizeof(car));
            archBin.write(reinterpret_cast<const char *>(&telefono), sizeof(int));
            archBin.write(reinterpret_cast<const char *>(&montoGastado), sizeof(double));
        }
    }
}

void generaproductosbin(){
    int dni, telefono, codCliente, aa, mm, dd, fecha;
    char nombre[100], codProducto[10], descripcion[100], car, categoria;
    double descuento, precioUnitario, montoGastado = 0, cantidad;
   
    ifstream arch("ComprasClientes.txt", ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo CompraClientes.txt";
        exit(1); 
    }
    
    ofstream archBin("Productos.bin", ios::out | ios::binary);
    if(!archBin){
        cout << "No se puede abrir el archivo Productos.bin";
        exit(1); 
    }
    
    while(1){
        arch >> dni; 
        if(arch.eof()) break; 
        if(arch.fail()){
            arch.clear();
            arch >> codProducto >> descripcion;
            arch >> cantidad;
            
            if(arch.fail()){
                arch.clear();
                arch >> car >> descuento >> cantidad; 
            }else{
                descuento = 0; 
            }
                    
            arch >> precioUnitario >> codCliente >> dd >> car >> mm >> car >> aa;
            eliminaguiones(descripcion); 
            
            archBin.write(reinterpret_cast<const char *>(codProducto), sizeof(char)*10);
            archBin.write(reinterpret_cast<const char *>(descripcion), sizeof(char)*100);
            archBin.write(reinterpret_cast<const char *>(&descuento), sizeof(double));
            archBin.write(reinterpret_cast<const char *>(&precioUnitario), sizeof(double));
        }else{
            arch >> nombre >> telefono; 
            categoria = corrigeformato(nombre); 
        }
    }
}

void generapedidosbin(){
    int dni, telefono, codCliente, aa, mm, dd, fecha, aux;
    char nombre[100], codProducto[10], descripcion[100], car, categoria;
    double descuento, precioUnitario, montoGastado = 0, cantidad;
   
    ifstream arch("ComprasClientes.txt", ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo CompraClientes.txt";
        exit(1); 
    }
    
    ofstream archBin("Pedidos.bin", ios::out | ios::binary);
    if(!archBin){
        cout << "No se puede abrir el archivo Productos.bin";
        exit(1); 
    }
    
    while(1){
        arch >> dni; 
        if(arch.eof()) break; 
        if(arch.fail()){
            arch.clear();
            arch >> codProducto >> descripcion;
            arch >> cantidad;
            
            if(arch.fail()){
                arch.clear();
                arch >> car >> descuento >> cantidad; 
            }else{
                descuento = 0; 
            }
                    
            arch >> precioUnitario >> codCliente >> dd >> car >> mm >> car >> aa;
            fecha = aa * 10000 + mm*100 + dd; 
            eliminaguiones(descripcion); 
            
            archBin.write(reinterpret_cast<const char *>(&aux), sizeof(int));
            archBin.write(reinterpret_cast<const char *>(codProducto), sizeof(char)*10);
            archBin.write(reinterpret_cast<const char *>(&cantidad), sizeof(double));
            archBin.write(reinterpret_cast<const char *>(&fecha), sizeof(int));
        }else{
            aux = dni; 
            arch >> nombre >> telefono; 
            categoria = corrigeformato(nombre); 
        }
    }
}

void imprimeReporteClientes(){
    int dni, telefono, codCliente, aa, mm, dd, fecha, cantidad;
    char nombre[100], codProducto[10], descripcion[100], car, categoria;
    double descuento, precioUnitario, montoGastado = 0;
   
    ofstream archReporte("ReporteClientes.txt", ios::out);
    if(!archReporte){
        cout << "No se puede abrir el archivo ReporteClientes.txt";
        exit(1); 
    }
    
    ifstream archBin("Clientes.bin", ios::in | ios::binary);
    if(!archBin){
        cout << "No se puede abrir el archivo Clientes.bin";
        exit(1); 
    }
    
    archReporte.precision(2);
    archReporte << fixed;
    
    while(1){
        archBin.read(reinterpret_cast< char *>(&dni), sizeof(int));
        if(archBin.eof()) break; 
        archBin.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archBin.read(reinterpret_cast< char *>(&categoria), sizeof(car));
        archBin.read(reinterpret_cast< char *>(&telefono), sizeof(int));
        archBin.read(reinterpret_cast< char *>(&montoGastado), sizeof(double));
        
        archReporte << dni << "   " << left << setw(50) << nombre << "   " 
                << categoria << "   " << setw(11) << telefono << setw(8) << montoGastado << endl; 
    }
}

void imprimeReporteProductos(){
    int dni, telefono, codCliente, aa, mm, dd, fecha, cantidad;
    char nombre[100], codProducto[10], descripcion[100], car, categoria;
    double descuento, precioUnitario, montoGastado = 0;
   
    ofstream archReporte("ReporteProductos.txt", ios::out);
    if(!archReporte){
        cout << "No se puede abrir el archivo ReporteProductos.txt";
        exit(1); 
    }
    
    ifstream archBin("Productos.bin", ios::in | ios::binary);
    if(!archBin){
        cout << "No se puede abrir el archivo Productos.bin";
        exit(1); 
    }
    
    while(1){ 
        archBin.read(reinterpret_cast<char *>(codProducto), sizeof(char)*10);
        if(archBin.eof()) break; 
        archBin.read(reinterpret_cast<char *>(descripcion), sizeof(char)*100);
        archBin.read(reinterpret_cast<char *>(&descuento), sizeof(double));
        archBin.read(reinterpret_cast<char *>(&precioUnitario), sizeof(double));
        
        archReporte << codProducto << "   " << left << setw(75) << descripcion 
                << "   " << descuento << "   " << precioUnitario << endl; 
    }
}

void imprimeReportePedidos(){
    int dni, telefono, codCliente, aa, mm, dd, fecha, aux;
    char nombre[100], codProducto[10], descripcion[100], car, categoria;
    double descuento, precioUnitario, montoGastado = 0, cantidad;
   
    ofstream archReporte("ReportePedidos.txt", ios::out);
    if(!archReporte){
        cout << "No se puede abrir el archivo ReportePedidos.txt";
        exit(1); 
    }
    
    ifstream archBin("Pedidos.bin", ios::in | ios::binary);
    if(!archBin){
        cout << "No se puede abrir el archivo Pedidos.bin";
        exit(1); 
    }
    
    while(1){
        archBin.read(reinterpret_cast< char *>(&dni), sizeof(int));
        if(archBin.eof()) break; 
        archBin.read(reinterpret_cast< char *>(codProducto), sizeof(char)*10);
        archBin.read(reinterpret_cast< char *>(&cantidad), sizeof(double));
        archBin.read(reinterpret_cast< char *>(&fecha), sizeof(int));
        
        //archReporte << "DNI     COD. PRODUCTO        CANTIDAD        FECHA" << endl; 
        archReporte << dni << "   " << codProducto << "   " << setw(6) << cantidad 
                << "   " << fecha << endl;  
    }
}

void imprimeReporteFinal(){
    int dni, telefono, dni2, fecha, id, numReg1, numReg2, i, j, k, aa, mm, dd, numReg3;
    char categoria, nombre[100], car, codProducto[10], codProducto2[10], descripcion[100];
    double montoGastado, cantidad, descuento, precioUnitario, apagar, descTotal; 
            
    ifstream archPedidos("Pedidos.bin", ios::in | ios::binary);
    if(!archPedidos){
        cout << "No se puede abrir el archivo Pedidos.bin";
        exit(1); 
    }
    
    ifstream archProductos("Productos.bin", ios::in | ios::binary);
    if(!archProductos){
        cout << "No se puede abrir el archivo Productos.bin";
        exit(1); 
    }
    
    fstream archClientes("Clientes.bin", ios::in | ios::out | ios::binary);
    if(!archClientes){
        cout << "No se puede abrir el archivo Clientes.bin";
        exit(1); 
    }
    
    ofstream archReporte("ReporteFinal.txt", ios::out); 
    if(!archReporte){
        cout << "No se puede abrir el archivo Reporte.txt";
        exit(1); 
    }
    
    int tamReg1 = sizeof(int)*2 + sizeof(double)*1 + sizeof(char)*10;
    archPedidos.seekg(0,ios::end); 
    int tamArch1 = archPedidos.tellg(); 
    numReg1 = tamArch1/tamReg1; 
    
    int tamReg2 = sizeof(double)*2 + sizeof(char)*110;
    archProductos.seekg(0,ios::end); 
    int tamArch2 = archProductos.tellg(); 
    numReg2 = tamArch2/tamReg2;
    
    int tamReg3 = sizeof(double)*1 + sizeof(int)*2 + sizeof(char)*101;
    archClientes.seekg(0,ios::end); 
    int tamArch3 = archClientes.tellg(); 
    numReg3 = tamArch3/tamReg3;
    
    archReporte << setw(50) << " " << "EMPRESA COMERCIALIZADORA DE ABARROTES" << endl; 
    imprimirLinea('=', MAX_CAR, archReporte);
    archReporte << "GASTOS DE LOS CLIENTES REGISTRADOS:" << endl;
    imprimirLinea('=', MAX_CAR, archReporte);
    
    archReporte.precision(2);
    archReporte << fixed; 
    
    for(k=0;k<numReg3;k++){
        archClientes.seekg(k*tamReg3, ios::beg); 
        archClientes.read(reinterpret_cast< char *>(&dni), sizeof(int));
        if(archClientes.eof()) break; 
        archClientes.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archClientes.read(reinterpret_cast< char *>(&categoria), sizeof(car));
        archClientes.read(reinterpret_cast< char *>(&telefono), sizeof(int));
        archClientes.read(reinterpret_cast< char *>(&montoGastado), sizeof(double));
        
        archReporte << "DNI" << setw(15) << " " << "Nombre" << setw(44) << " " << "Telefono" << setw(22) << " " << "Categoria" << endl; 
        archReporte << dni << setw(10) << " " << left << setw(50) << nombre << telefono << setw(25) << " " << categoria << endl; 
        imprimirLinea('-', MAX_CAR, archReporte);
        archReporte << "PRODUCTOS ADQUIRIDOS: " << endl; 
        imprimirLinea('-', MAX_CAR, archReporte);
        archReporte << setw(7) << " " << "Codigo    Descripcion" << setw(34) << " " << "P.U      Cantidad     Total    Descuento %   A Pagar    Descuento     Fecha" << endl; 
        
        id = 0; 
        apagar = 0;
        descTotal = 0; 
        for(i=0;i<numReg1;i++){
            archPedidos.seekg(i*tamReg1, ios::beg); 
            archPedidos.read(reinterpret_cast< char *>(&dni2), sizeof(int));
            archPedidos.read(reinterpret_cast< char *>(codProducto), sizeof(char)*10);
            archPedidos.read(reinterpret_cast< char *>(&cantidad), sizeof(double));
            archPedidos.read(reinterpret_cast< char *>(&fecha), sizeof(int));
            
            aa = fecha/10000;
            mm = (fecha%10000)/100;
            dd = (fecha%10000)%100;
            
            if(dni == dni2){
                id++; 
                archReporte << right << "  " << setw(2) << id << "   " << codProducto << "    "; 
                
                for(j=0;j<numReg2;j++){
                    archProductos.seekg(j*tamReg2, ios::beg); 
                    archProductos.read(reinterpret_cast<char *>(codProducto2), sizeof(char)*10);
                    archProductos.read(reinterpret_cast<char *>(descripcion), sizeof(char)*100);
                    archProductos.read(reinterpret_cast<char *>(&descuento), sizeof(double));
                    archProductos.read(reinterpret_cast<char *>(&precioUnitario), sizeof(double));
                    
                    if(!strcmp(codProducto2, codProducto)){ 
                        archReporte << setfill(' '); 
                        archReporte << left << setw(40) << descripcion << "  " << right << setw(7) 
                                << precioUnitario << "    " << setw(7) << cantidad 
                                << "     " << setw(7) << cantidad*precioUnitario << "    " << setw(7) << descuento << "       " << setw(7)
                                << cantidad*precioUnitario - cantidad*precioUnitario*((double)descuento/100) << "    " 
                                << setw(7) << cantidad*precioUnitario*((double)descuento/100) << "     " << right << setfill('0') 
                                << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << endl;
                        apagar = apagar + cantidad*precioUnitario - cantidad*precioUnitario*((double)descuento/100); 
                        descTotal = descTotal + cantidad*precioUnitario*((double)descuento/100); 
                        archReporte << setfill(' '); 
                        break; 
                    }
                }
            }
        }
        imprimirLinea('-', MAX_CAR, archReporte);
        archReporte << setw(108) << "TOTAL:     " << apagar << "       " << descTotal << endl;  
        imprimirLinea('=', MAX_CAR, archReporte);
        archClientes.seekg(k*tamReg3, ios::beg); 
        archClientes.seekg(sizeof(int)*2+sizeof(char)*101, ios::cur);
        archClientes.write(reinterpret_cast< const char *>(&apagar), sizeof(double));
    }
}

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i=0;i<n;i++) arch << c; 
    arch << endl; 
}
