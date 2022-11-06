/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 13 de septiembre de 2022, 06:23 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncBiblioteca.h"
#include "Estructuras.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Libro libros[100];
    Usuario usuarios[100];
    int i=0,j=0;
    ifstream archLib=abrirArchivoL("Libros.txt",'T');
    ofstream archRepLib=abrirArchivoE("RepLib.txt",'T');
    ifstream archUsuario=abrirArchivoL("Usuarios.txt",'T');
    ofstream archRepUsuarios=abrirArchivoE("RepUsuarios.txt",'T');
    while(archLib>>libros[i]){
        i++;
    }
    for(j=0;j<i;j++)archRepLib<<libros[j];
    j=0;
    while(archUsuario>>usuarios[j]){
        j++;
    }
    for(int k=0;k<j;k++)archRepUsuarios<<usuarios[k];
    return 0;
}

