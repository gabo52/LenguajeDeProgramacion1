/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 21 de septiembre de 2022, 09:07 PM
 */

#include <iostream>
#include <iomanip>
#include "BibliotecaMemoriaDinamica.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **conductor,*gravedad;
    int *licencia,*infraccion;
    double *multa;
    cargarConductores(licencia,conductor);
    reporteConductores(licencia,conductor);
    cargaInfracciones(infraccion,gravedad,multa);
    reporteInfracciones(infraccion,gravedad,multa);
    reporteDeFaltas(licencia,conductor,infraccion,gravedad,multa);
    return 0;
}

