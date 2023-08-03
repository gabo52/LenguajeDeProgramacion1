/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 03:13 PM
 */

#include <iostream>
#include <iomanip>
#include "BibliotecaColaGenerica.h"
#include "FuncionesLaboratorio01.h"
#include "FuncionesLaboratorio02.h"
using namespace std;

int main(int argc, char** argv) {
    void *cola; 
    //creaCola(cola,leenumero); 
    //imprimir(cola,imprimenumero); 
    //atiendeNumero(cola); 
    
    creaCola(cola,leeregistro); 
    imprimir(cola,imprimeregistro); 
    atiendeNumero(cola); 
    
    return 0;
}

