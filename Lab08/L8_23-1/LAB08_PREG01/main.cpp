/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 29 de mayo de 2024, 06:02 PM
 */

#include "Tesoreria.hpp"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    return 0;
}