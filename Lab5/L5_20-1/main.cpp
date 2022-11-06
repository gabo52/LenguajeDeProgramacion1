/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 27 de septiembre de 2022, 04:55 PM
 */

#include <iostream>
#include <iomanip>
#include "funcionesAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **codMed,**nombMed,***nombPac;
    int **codPac,**veces;
    double *tarifas,**porcPac;
    leerMedicos(codMed,nombMed,tarifas);
    repMedicos(codMed,nombMed,tarifas);
    cout<<"hola";
    leerAtenciones(codMed,codPac,nombPac,porcPac,veces);
    repDeIngresos(codMed,nombMed,tarifas,codPac,nombPac,porcPac,veces);
    cout<<"adios";
    return 0;
}

