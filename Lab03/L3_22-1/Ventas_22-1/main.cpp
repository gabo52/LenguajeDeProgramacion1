/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 14 de septiembre de 2022, 05:15 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archClientes;
    ofstream archRep;
    struct Estructura_ClienteRegistrado cliente[30];
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Prueba.txt");
    
    struct Estructura_ClienteRegistrado cliente1,cliente2;
    struct Estructura_PedidoRealizado ped,ped2,ped3;
    struct Estructura_ProductosEnAlmacen productos[30],prod1,prod2,prod3;
    archClientes>>cliente1>>cliente2;
    cout<<"Llegue";
    ped.cantidad=10;
    strcpy(ped.codigo,"DOB245");
    ped.fecha=20201111;
    cliente[0].dni=0;
    archRep<<cliente1<<cliente2;
    cliente+=cliente1;
    cliente[0]+=ped;
    cliente[0]+=ped2;
    cliente[0]+=ped3;
    
    ped2.cantidad=5.54;
    strcpy(ped2.codigo,"QBL949");
    ped2.fecha=20191015;   
    
    strcpy(prod1.codigo,"DOB245");
    strcpy(prod1.descripcion,"LECHE_LALA_SEMI_DESLACTOSADA_1LT");
    prod1.descuento=0;
    prod1.precioUnitario=16.98;
    
    strcpy(prod2.codigo,"QBL949");
    strcpy(prod2.descripcion,"YOGHURT_NATURAL_LIGHT_LALA_1KG");
    prod2.descuento=4.7;
    prod2.precioUnitario=25.86;
    
    strcpy(prod3.codigo,"DOB245");
    strcpy(prod3.descripcion,"LECHE_LALA_SEMI_DESLACTOSADA_1LT");
    prod3.descuento=0;
    prod3.precioUnitario=16.98;
    strcpy(productos[0].codigo,"X");
    productos+=prod1;
    productos+=prod2;
    productos+=prod3;
    cout<<"Llegue";
    archRep<<productos;
    return 0;
}

