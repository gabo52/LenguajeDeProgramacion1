
/* 
 * File:   Funciones.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 11 de abril de 2023, 08:23 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>

using namespace std; 

void imprimeReporteClientes();
void generaclientebin();
char corrigeformato(char *);
void eliminaguiones(char *);
void generaproductosbin();
void generapedidosbin();
void imprimeReporteProductos(); 
void imprimeReportePedidos();
void imprimirLinea(char c, int n, ofstream &arch);
void imprimeReporteFinal();

#endif /* FUNCIONES_H */

