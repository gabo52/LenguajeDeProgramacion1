/* 
 * File:   funcionesAux.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 5 de octubre de 2022, 12:04 AM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
char *leerCadena(ifstream &arch,char c);
void cargaProductos(void *&prod);
void asignarValoresProd(void *&prod,int codProd,char *desc,double precio,int cantProd);
void cargaPedidos(void *&pedidos);
void procesaClientes(void *&productos,void *&pedidos,void *&clientes);
void imprimeReporte(void *&clientes);
void *leerDatos(ifstream &arch);
int comparaDni(int dni,void *&ped);
void *leerDatosClientes(ifstream &arch,void *&ped);
void  cargaClientes(void *&pedidos,void *&cli);
int comparaProducto(void *&prod,int cod,int &cant);
int buscarProducto(int cod,void **&prod,int &cant);
void cambiaEstadoActualizaStock(void *&ped,void *&prod,int cantSol);
void atenderPedido(void *&ped,void **&prod);
void actualizaPedidos(void *&prod,void *&ped);
void *obtienePedidoCliente(void *ped);
#endif /* FUNCIONESAUX_H */

