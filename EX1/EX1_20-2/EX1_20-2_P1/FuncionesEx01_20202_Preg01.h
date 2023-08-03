/* 
 * File:   FuncionesEx01_20202_Preg01.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de octubre de 2022, 11:02 PM
 */

#ifndef FUNCIONESEX01_20202_PREG01_H
#define FUNCIONESEX01_20202_PREG01_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void leerDatos(void *&pedidos,void *&stock);
void imprimeStock(void *st);
void imprimeRegStock(void *st,ofstream &arch);
void imprimePedidos(void *ped);
void imprimeRegPedidos(void *ped,ofstream &arch);
void  leeStock(void *&stock);
void *leerRegStock(ifstream &arch);
void leePedidos(void *&pedidos);
int leerFecha(ifstream &arch);
void leePedidosLinea(void **buffReg,int &nd,ifstream &arch);
char *leerCadena(ifstream &arch,char c);
void atiende(void *&pedidos,void *&stock);
void imprimirDatos(void *&pedidos,void *stock);
void atenderPedido(void *&ped,void *&stock);
void buscaProd(int codProd,void *&st,int *&stockBuscado);
int comparaCod(int codProd,void *stock,int *&stockBuscado);
void obtieneDatosPedido(int *&cantSol,int *&cantAtend,int *&codProd,void *&ped);
void ordenarPedidos(void *&ped);
void qSort(void **&pedidos,int izq,int der);
void cambiar(void *&dato1,void *&dato2);
int enDesorden(void *&ped1,void *&ped2);
void imprimeCabecera(ofstream &arch,int ruc);
void imprimeRegReporteAtencion(void *ped,ofstream &arch);
void imprimeFecha(int fecha,ofstream &arch);
void imprimeLinea(ofstream &arch,int cantidad,char c);
int obtenerRUC(void *ped);
void ordenarPedidosRUC(void *&ped);
void qSortRUC(void **&pedidos,int izq,int der);
int enDesordenRUC(void *&ped1,void *&ped2);

#endif /* FUNCIONESEX01_20202_PREG01_H */

