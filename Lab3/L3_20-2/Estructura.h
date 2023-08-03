
/* 
 * File:   Estructura.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 26 de abril de 2023, 07:44 PM
 */

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

struct StMedico{
    char codigo[10];
    char nombre[300];
    char especialidad[100];
    double tarifa;
    int fechas[100];
    int pacientes[100]; 
    double prima[100];
    char estado[100];
    int numPac;
    double ingresosP;
    double ingresosS;
};

struct StPaciente{
    int fecha;
    int codigo;
    char nombre[300];
    double prima;
    char estado; 
};


#endif /* ESTRUCTURA_H */

