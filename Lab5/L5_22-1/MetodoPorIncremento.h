/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoPorIncremento.h
 * Author: Gabo
 *
 * Created on 29 de septiembre de 2022, 03:25 PM
 */

#ifndef METODOPORINCREMENTO_H
#define METODOPORINCREMENTO_H
#include <fstream>
using namespace std;

void AbrirArchivoEscritura(const char *nomb,ofstream &arch);
void AbrirArchivoLectura(const char *nomb,ifstream &arch);
void CargaDePedidosYProductos(int **cli_DniTelefono,char ***&pro_CodigoDescripcion,
        double **&pro_PrecioDescuento,char ***&ped_Codigo,
        int ***&ped_FechaCantidad,const char *nomb);
void agregarPedidoACliente(int **&ped_FechaCantidad,char **&pedCod,int fecha,
                int cant,char *&codProd,int &numDat,int &cap);
void agregarDatosCliente(int *&ped_FechaCantidad,char *&pedCod,int numDat,
        int fecha,int cant,char *&codProd);
void incrementarClientes(int **&ped_FechaCantidad,char **&pedCod,
        int &numDat,int &cap);
void agregarProducto(int &numDat,int &cap,char ***&pro_CodigoDescripcion,
                char *cod,char *descripcion,double **&pro_PrecioDescuento,
        double precio,double descuento);
void incrementarProducto(char ***&pro_CodigoDescripcion,
        double **&pro_PrecioDescuento,int &numDat,int &cap);
int buscarProducto(char *cod,char ***pro_CodigoDescripcion);
int buscarDNI(int DNI,int **arrDNI);
void leerDatos(ifstream &arch,char *&descripcion,double &descuento,double &precio,
        int &DNI,int &fecha,int &cant);
int leerFecha(ifstream &arch);
char *leerCadena(ifstream &arch,char c);
void ReporteDePedidosYProductos(int **cli_DniTelefono,char ***pro_CodigoDescripcion,
            double **pro_PrecioDescuento,char ***ped_Codigo,int ***&ped_FechaCantidad,
            const char *nomb);
void imprimirProducto(ofstream &arch,char **pro_CodigoDescripcion,
        double *pro_PrecioDescuento);
void imprimirLinea(ofstream &arch,int cant,char c);
void imprimeDatosCliente(int *cli_DniTelefono,int **ped_FechaCantidad,char **ped_Codigo,
                ofstream &arch);
void ReporteRelacionDePedidos(int **cli_DniTelefono,char *** cli_NombreCategoria,
            char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
        char ***ped_Codigo,int ***ped_FechaCantidad,const char *nomb);
#endif /* METODOPORINCREMENTO_H */

