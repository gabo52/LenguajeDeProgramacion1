/* 
 * File:   maina.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 8 de mayo de 2023, 05:59 PM
 */

#include <iostream>
#include <iomanip>
#include "MetodoPorIncrementos.h"
#include "Clientes.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cli_NombreCategoria,***pro_CodigoDescripcion,***ped_Codigo;
    int **cli_DniTelefono,***ped_FechaCantidad;
    double **pro_PrecioDescuento;
    CargaDeClientes(cli_DniTelefono,cli_NombreCategoria,"Clientes.csv");
    ReporteDeClientes(cli_DniTelefono,cli_NombreCategoria,"PruebaClientes.txt");
    CargaDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,"Pedidos.csv");
    ReporteDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,"PruebaProductosPedidos.txt");
    ReporteRelacionDePedidos(cli_DniTelefono,cli_NombreCategoria,pro_CodigoDescripcion,pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad, "ReporteDeRelacionDePedidos.txt");
    return 0;
}

