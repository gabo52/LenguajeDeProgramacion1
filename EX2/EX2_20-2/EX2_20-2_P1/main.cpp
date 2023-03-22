/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 06:14 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Procesa.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    ifstream arch;
    arch.open("Parte01_AtencionMedicaP.csv");
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo Parte01_AtencionMedicaP.csv";
        exit(1);
    }
    pro.lee(arch);
    pro.ordena();
    pro.imprime();
    return 0;
}

