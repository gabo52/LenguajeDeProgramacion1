/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 13 de septiembre de 2022, 09:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "StPersona.h"
#include "sobreCargaFunc.h"

/*
 * 
 */
int main(int argc, char** argv) {
    struct Persona  persona1 {22334455, "Juan Pedro Lopez Quispe",3547.67},
                    persona2 {76766767, "Maria Rose Ruiz Castro",3547.67};
    cout<<persona1;
    ofstream arch("reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR, no se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    double s;
    bool b;
    // cin>>persona1;
    arch<<persona1<<endl;
    s = persona1 *= 20;
    arch<<persona1;
    cout<<s<<endl;
    b = !persona1;
    cout<<b<<endl;
    return 0;
}

