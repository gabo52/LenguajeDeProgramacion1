/* 
 * File:   FuncionesEx01_20202_Preg02.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de octubre de 2022, 01:21 AM
 */

#ifndef FUNCIONESEX01_20202_PREG02_H
#define FUNCIONESEX01_20202_PREG02_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void leerDatos(char **&clientes,int ***&intProductos,char ***&strProductos);
int leerFecha(ifstream &arch);
void agregaProductosACliente(int **&intProductos,char **&strProductos,
        ifstream &arch);
void agregaProductoAPedido(int *&intProductos,char *&strProductos,int codigo,
        int cantSol,char *nomb);
void incrementaEspacioProd(int **&intProductos,char **&strProductos,int &numProd,int &capProd);
void incrementaEspaciosCliente(char **&clientes,int ***&intProductos,char ***&strProductos,
        int &nd,int &cap);
char *leerCadena(ifstream &arch,char c);
void imprimirDatos(char **clientes,int ***intProductos,char ***strProductos);
void imprimirReporte(char *cliente,int **productos,char **nombProd,ofstream &arch);
void imprimeRegReporte(int *productos,char *nombProd,ofstream &arch);
void imprimeLinea(ofstream &arch,int cantidad,char c);
void ordenarProductos(int **&intProductos,char **&strProductos);
void qSort(int **&intProductos,char **&strProductos,int izq,int der);
int enDesorden(int *int1,int *int2);
void cambiar(int **&intProductos,char **&strProductos,int pos1,int pos2);


#endif /* FUNCIONESEX01_20202_PREG02_H */

