/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 29 de septiembre de 2022, 03:23 PM
 */

#include <iostream>
#include <iomanip>
#include "MetodoPorIncremento.h"
#include "Clientes.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cli_NombreCategoria,***pro_CodigoDescripcion,***ped_Codigo;
    int **cli_DniTelefono,***ped_FechaCantidad;
    double **pro_PrecioDescuento;
    cout<<"Hola"<<endl;
    CargaDeClientes(cli_DniTelefono,cli_NombreCategoria,"Clientes.csv");
    ReporteDeClientes(cli_DniTelefono,cli_NombreCategoria,"PruebaClientes.txt");
    CargaDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,
            pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,"Pedidos.csv");
    ReporteDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,
              pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,
                "PruebaProductosPedidos.txt");
//    ReporteRelacionDePedidos(cli_DniTelefono,cli_NombreCategoria,
//           pro_CodigoDescripcion,pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,
//            "ReporteDeRelacionDePedidos.txt");
    cout<<"Adios";
    return 0;
}

