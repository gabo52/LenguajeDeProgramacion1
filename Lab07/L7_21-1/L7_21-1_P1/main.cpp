/* 
 * File:   main.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:20 PM
 */

#include <iostream>
#include <iomanip>
#include "Conductores.h"
#include "Falta.h"
#include "FaltaCond.h"
#include "SobrecargaEntradaSalida.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Conductores conduc1;
    char nombre[70]="ZAMORA ZAVALETA RONAL MANUEL";
    conduc1.SetLicencia(63736112);
    conduc1.SetNombre(nombre);
    Infraccion infrac1;
    char descripcion[300]="Detener el vehículo bruscamente sin motivo.";
    char gravedad[15]="Grave";
    infrac1.SetCodigo(103);
    infrac1.SetDescripcion(descripcion);
    infrac1.SetGravedad(gravedad);
    infrac1.SetMulta(316.00);
    FaltaCond falta1;
    Falta falta2;
    char placa[15]="C0P-895";
    int fecha = 20191210;
    falta2.SetCodInf(201);
    falta2.SetFecha(20191210);
    falta2.SetPlaca(placa);
    falta2.SetLicencia(15029228);
    FaltaCond faltaaa;
    double monto = ++conduc1;
    ifstream archImf,archConduct,archReg;
    AbrirArchivo("Infracciones.csv",archImf);
    AbrirArchivo("RegistroDeFaltas.csv",archReg);
    AbrirArchivo("Conductores.csv",archConduct);
    Conductores aux1;
    Infraccion aux2;
    Falta aux3;
    archReg>>aux3;
    archImf>>aux2;
    archConduct>>aux1;
    ofstream rep;
    AbrirArchivo("Rep.txt",rep);
    aux1+falta2;
    aux1+infrac1;
    rep<<aux1;
    return 0;
}

