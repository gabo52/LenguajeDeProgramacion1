/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de octubre de 2022, 08:11 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesE01_20211_Preg02.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *conductor,*falta,*consolidado;
    cargaDatos(conductor,falta);
    cout<<"Llegue";
    registrafaltas(consolidado,conductor,falta);
    cout<<"Llegue";
    imprime(consolidado);
    return 0;
}

