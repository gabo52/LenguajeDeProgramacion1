/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: Gabo
 *
 * Created on 6 de octubre de 2022, 04:39 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ofstream &arch);
void AbrirArchivo(const char *nomb,ifstream &arch);
void CargarProductosPedidos(int **&pro_Informacion,char **&pro_Descripcion,
        int **&ped_Todo,const char *nomb);
void asignarPedido(int *&buffPed,int DNI,int fecha,int cant,int codigo);
int buscarProducto(int codigo,int **pro_Informacion);
int comparaProductos(int *Informacion,int codigo);

void asignarProducto(int *&auxInformacion,char *&auxDescripcion,int codigo,
                    int descuento,int precio,int stock,char *descrip);
void leerDatos(int &codigo,char *&descrip,int &descuento,int &cant,int &precio,
        int &stock,int &DNI,int &fecha,ifstream &arch);
char *leerCadena(ifstream &arch,char c);
void PruebaProductosPedidos(int **pro_Informacion,char **pro_Descripcion,
        int **ped_Todo,const char *nomb);
void imprimePedidos(int **ped_Todo,ofstream &arch);
void imprimePedido(int *ped_Todo,ofstream &arch);
void imprimeProductos(int **pro_Informacion,char **pro_Descripcion,ofstream &arch);
void imprimeProducto(int *informacion,char *descripcion,ofstream &arch);
void ordenarPedidos(int **&ped_Todo);
void asignarPedidos(int ***&cli_DniTelPed,int **&pro_Informacion,int **&ped_Todo);
void qSort(int **ped_Todo,int izq,int der);
void cambiar(int *&valor1, int *&valor2);
int enDesorden(int *ped1, int *ped2);
int hayStock(double cantidad,int codigo,int **&pro_Informacion);
void buscarProducto(int **pro_Informacion,int codigo,int *&puntero);
void insertarPedido(int **&cli_DniTelPed,int &capPed,int &numPed,int fecha, 
        int codigo, int cantidad);
void agregarPedido(int *&cli_DniTelPed,int i,
        int fecha,int codigo,int cantidad);
int obtieneDni(int *ped_Todo,int &codigo,double &cantidad,int &fecha);
int buscarDNI(int DNI,int ***cli_DniTelPed);
void incrementaRegistro(int *&cli_DniTelPed,int &capPed,int &numPed);
int obtieneDni(int **cli_DniTelPed);
#endif /* FUNCIONESAUX_H */

