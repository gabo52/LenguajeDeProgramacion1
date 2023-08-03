/* 
 * File:   funcionesAux.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de septiembre de 2022, 10:38 AM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
using namespace std;

void AbriArchivoLectura(ifstream &arch,const char *nombre);
void AbriArchivoEscritura(ofstream &arch,const char *nombre);
void arreglaNombre(char *nombre,char &cat);
void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria);
void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria);
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
        char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
        int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido);
void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,
        char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
        int **cli_CodigoProFechaPedido,double **cli_CantidadPedido);
void ReporteRelacionDePedidos(int *cli_DNI,char **cli_Nombre,char *cli_Categoria,
            int **cli_CodigoProFechaPedido,double **cli_CantidadPedido,
        int *pro_Codigo,char **pro_Descripcion,double *pro_Descuento,
        double *pro_Precio);
void leeValores(char *&cad,double &desc,double &cant,double &prec,int &DNI,
        int &fecha,ifstream &arch);
void  agregarDatosCliente(int *&codProFechaPed,int cod,int fecha,
        double *&cantPed,double cant,int &numDat);
char * leerCadena(ifstream &arch,char c);
//void agregarProducto(int *buffCod,int cod,char **pro_Descrip,char *cad,
//        double *prod_Desc,double desc,double *prod_prec,double prec,int &numDat);
void agregarProducto(int &codProd,int cod,char *&descripcion,char *cad
    ,double &descuento,double desc,double &precio,double prec,int &numDat);
int buscarDato(int *arr,int dato,int numDat);
int buscarDato(int *arr,int dato);
void asignarValoresCliente(int *&codProFecha,int *&buffCodProFecha,
            double *&cantPed, double  *&buffCantPed,int num);
void imprimeLinea(ofstream &arch,int cant,char c);
void imprimeCabeceraCliente(ofstream &arch,int dni,char *nombre,char cat);
void imprimeCabecera(ofstream &archRep);
void imprimirProductosCliente(int *arrCodFecha,
                    double *arrCant,ofstream &archRep,int *codProd,
        char **arrDescrip,double *arrPrecio,double *arrDesc);
void hallarDescripPrecio(int *codProd,char **arrDescrip,double *arrPrecio,
        double *arrDesc,char *&descripcion,double &precio,
        double &descuento,int codigo);
void imprimeFecha(int fecha,ofstream &arch);
void copiarArreglosDinamicos(int *&pro_Codigo,char **&pro_Descripcion,
        double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido,
        double **&cli_CantidadPedido,int numDat,int *buff_proCod,char **descripcion,
        double *descuento,double *precio,int *cli_DNI,int i,double **cantPed,
        int **buffCodProFecha,int *numPedidos);
void borrarValores(int **&buffCodProFecha,double **&cantPed);
#endif /* FUNCIONESAUX_H */

