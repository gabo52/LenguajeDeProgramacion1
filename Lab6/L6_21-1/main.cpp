/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:14 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistro.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista1,*lista2;
//    creaLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv"); 
//    creaLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
//    uneLista(lista1,lista2);
//    imprimeLista(lista1,imprimenum,"Repnum.txt");
    
    creaLista(lista1,leeregistro,cmpregistro,"RegistroDeFaltas1.csv");
    creaLista(lista2,leeregistro,cmpregistro,"RegistroDeFaltas2.csv");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimeregistro,"Repfalta.txt");
    return 0;
}

