/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabri
 *
 * Created on 24 de agosto de 2022, 11:25 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int dato,dd,mm,aa,tipo,cod;
    char nombre[100],unidades[10],c;
    double cant;
    
    ifstream arch("tiendas.txt",ios::in);
    if(!arch){
        cout<<"No se puede abrir tiendas.txt";
        exit(1);
    }
    
    ofstream reporte("reporte.txt",ios::out);
    if(!reporte){
        cout<<"No se puede abrir reporte.txt";
        exit(1);
    }
    
    while(1){
        arch>>dato;
        if(arch.eof())break;
        if(dato>31){
            arch<<nombre;
            reporte<<endl<<setw(20)<<dato<<setw(60)<<nombre;
        }
        reporte>>setfill(' ');
    }
    return 0;
}

