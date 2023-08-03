/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de octubre de 2022, 04:39 PM
 */

#include <iostream>
#include <iomanip>
#include "ClientesPreg1.h"
#include "funcionesAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cli_NombreCategoria,**pro_Descripcion;
    int ***cli_DniTelPed,**pro_Informacion,**ped_Todo;
    CargaDeClientes(cli_DniTelPed,cli_NombreCategoria,"ClientesPreg01.csv");
    PruebaDeClientes(cli_DniTelPed,cli_NombreCategoria,"PruebaClientes01.txt");
    
    CargarProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PedidosPreg01.csv");
    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos01.txt");
    cout<<"sali";
    ordenarPedidos(ped_Todo);
    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos02.txt");
    cout<<"sali";
    asignarPedidos(cli_DniTelPed,pro_Informacion,ped_Todo);

    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos03.txt");
    PruebaDeClientes(cli_DniTelPed,cli_NombreCategoria,"PruebaClientes02.txt");
    return 0;
}

