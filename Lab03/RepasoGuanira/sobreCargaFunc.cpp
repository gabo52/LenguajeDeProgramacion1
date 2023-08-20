/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "StPersona.h"

ostream & operator <<(ostream &out, const struct Persona &per){
    out.precision(2);
    out<<fixed;
    out<<"DNI:     "<<per.dni<<endl;
    out<<"Nombre:   "<<per.nombre<<endl;
    out<<"Sueldo:    "<<per.sueldo<<endl;
    return out;
}

ofstream & operator <<(ofstream &arch, const struct Persona &per){
    arch.precision(2);
    arch<<fixed;
    // out<<right<<setw(10)<<per.dni<<" "<<left<<setw(40)<<per.nombre<<right
    // <<setw(10)<<per.sueldo<<endl;
    arch<<"DNI: " <<per.dni<<endl;
    arch<<"Nombre: " <<per.nombre<<endl;
    arch<<"Sueldo: " <<per.sueldo<<endl;
    return arch;
}
istream & operator >>(istream &in, struct Persona &per){
    in>>per.dni>>per.nombre>>per.sueldo;
    return in;
}
double operator *= (struct Persona &per, double porcent){
    per.sueldo*=(1+porcent/100);
    return per.sueldo;
}
bool operator !(const struct Persona &per){
    return per.sueldo>10000;
}
