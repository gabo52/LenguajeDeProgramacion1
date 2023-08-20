
/* 
 * File:   MetodoPorIncrementos.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 8 de mayo de 2023, 05:59 PM
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

#include <fstream>
using namespace std;

char *leerCadena(ifstream &arch,char c);
void AbrirArchivoLectura(const char *nomb,ifstream &arch);
void AbrirArchivoEscritura(const char *nomb,ofstream &arch);
void CargaDePedidosYProductos(int **cli_DniTelefono, char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento, char ***&ped_Codigo,  int ***&ped_FechaCantidad, const char *nombre);
void agregarProducto(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento, char *codigo, char *descripcion, double descuento, double precio, int &, int &);
void agregarPedido(char **&ped_Codigo,  int **&ped_FechaCantidad, int &capCli, int &numCli, char *ped, int fecha, int cant);
void incrementarEspaciosPedidos(char **&ped_Codigo,  int **&ped_FechaCantidad, int &capCli, int &numCli);
int buscarCliente(int **cli_DniTelefono, int dniCli);
int buscarCodigo(char ***pro_CodigoDescripcion, char *cad);
void incrementarEspaciosProductos(char ***&pro_CodigoDescripcion, double **&pro_PrecioDescuento, int &cap, int &numProd);
void imprimeFecha(ofstream &arch, int fecha);
void imprimirProductos(ofstream &arch, char **ped_Codigo, int **ped_FechaCantidad, char ***pro_CodigoDescripcion, double **pro_PrecioDescuento);
void imprimirCabeceraReporte(ofstream &arch);
void ReporteRelacionDePedidos(int **cli_DniTelefono, char ***cli_NombreCategoria, 
        char ***pro_CodigoDescripcion, double **pro_PrecioDescuento, char ***ped_Codigo, 
        int ***ped_FechaCantidad, const char *nombre);
void imprimirLinea(ofstream &archRep, char car);
void ReporteDePedidosYProductos(int **cli_DniTelefono, char ***pro_CodigoDescripcion,double **pro_PrecioDescuento, char ***ped_Codigo, int ***ped_FechaCantidad,const char *nombre);
void imprimirPedidos(ofstream &arch, char **ped_Codigo, int **ped_FechaCantidad);

#endif /* METODOPORINCREMENTOS_H */

