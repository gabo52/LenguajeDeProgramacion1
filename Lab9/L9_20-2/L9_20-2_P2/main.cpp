/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 11:30 AM
 */

#include <iostream>
#include <iomanip>
#include "ListaDePacientes.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaDePacientes l;
    l.CreaLista("AtencionDeCitas.csv");
    l.imprimeLista("Reporte.txt");
    return 0;
}

