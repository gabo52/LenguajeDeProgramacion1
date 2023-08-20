/* 
 * File:   FuncionesAuxiliares.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 2 de noviembre de 2022, 12:18 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;
#include "Conductores.h"
#include "Falta.h"
#include "FaltaCond.h"
#include "Infraccion.h"


void cargaConductores(Conductores *arr,int &n);
void cargaFaltas(Conductores *arr,int n);
int buscarLicencia(Conductores *arr,int n,int licencia);
void asignarInfracciones(Conductores *arr,int n);
void imprimirReporte(Conductores *arr,int n);
#endif /* FUNCIONESAUXILIARES_H */

