/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 13 de septiembre de 2022, 10:24 AM
 */

#include <cstdlib>
#include <cstring>
#include "Ventas_LP1.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    struct Estructura_ClienteRegistrado cliente[10];
    struct Estructura_ClienteRegistrado cliente2,cliente1;
    struct Estructura_ProductosEnAlmacen producto[10],prod1,prod2;
    struct Estructura_PedidoRealizado pedido;
    

    ifstream archclie;
    AperturaDeUnArchivoDeTextosParaLeer(archclie,"clientes.txt");
    
    archclie >>cliente2>>cliente1;
    cliente[0].dni=0;
    cliente+=cliente2;
    cliente+=cliente1;
    
    strcpy(prod1.codigo,"QBL949");
    strcpy(prod1.descripcion,"YOGHURT_NATURAL_LIGHT_LALA_1KG");
    prod1.descuento=4.7;
    prod1.precioUnitario = 25.86;
    
    strcpy(producto[0].codigo,"X");
    producto+=prod1;
    
    strcpy(pedido.codigo,"QBL949");
    pedido.fecha=20220914;
    pedido.cantidad=9;
    
    cliente[0]+=pedido;
    ofstream archRep("Reporte.txt",ios::out);
    archRep<<cliente[0];
    return 0;
}

