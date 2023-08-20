
/* 
 * File:   Estructura.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 04:16 PM
 */

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include "Estructura.h"

struct FaltaSt{
    char placa[25];
    int fecha;
    int codInf;
    double multa;
    char gravedad[25]; 
};

struct ConductorSt{
    int licencia;
    char nombre[300];
    struct FaltaSt faltas[20];
    int numFaltas;
    int numFaltasLeves;
    int numFaltasGraves;
    int numFaltasMuyGraves;
    double montoFaltasLeves;
    double montoFaltasGraves;
    double montoFaltasMuyGraves;
};

struct InfraccionSt{
    int licencia;
    char placa[25];
    int codInf;
    int fecha;
};

struct InfraccionEstabSt{
    int codigo;
    char gravedad[25];
    double multa; 
};

#endif /* ESTRUCTURA_H */

