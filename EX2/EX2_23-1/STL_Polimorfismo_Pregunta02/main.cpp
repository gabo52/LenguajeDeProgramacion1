/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:45 PM
 */

#include "Registro.hpp"
using namespace std;

int main(int argc, char** argv) {
    Registro reg;
    reg.carga();
    reg.procesa();
    reg.muestra();
    return 0;
}

