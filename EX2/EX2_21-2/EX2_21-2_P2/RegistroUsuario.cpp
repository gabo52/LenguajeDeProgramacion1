/* 
 * File:   RegistroUsuario.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 10:35 PM
 */

#include "RegistroUsuario.h"



void RegistroUsuario::leeDatos(ifstream &arch){
    usuario.leeDatos(arch);
}

void RegistroUsuario::imprimeDatos(ofstream &arch){
    imprimeUsuario(arch);
    imprimeRegistros(arch);
}

void RegistroUsuario::imprimeUsuario(ofstream &arch){
    usuario.imprimeDatos(arch);
}

void RegistroUsuario::imprimeRegistros(ofstream &arch){
    arch<<setw(14)<<left<<"CODIGO"<<left<<"FECHA"<<endl;
    for(list<RegistroPrestamo>::iterator it=prestamos.begin();it!=prestamos.end();it++){
        (*it).imprimeDatos(arch);
    }
}


bool RegistroUsuario::suspendido(int fecha){
    int contador=0,fec;
    for(list<RegistroPrestamo>::iterator it=prestamos.begin();it!=prestamos.end();it++){
        fec=(*it).GetFecha();
        if(fecha-fec>7)return true;
    }
    return false;
}

int RegistroUsuario::carne(){
    return usuario.GetCodigo();
}

void RegistroUsuario::agregaPrestamo(char *codLib,int fecha){
    RegistroPrestamo reg;
    reg.SetCodigoLibro(codLib);
    reg.SetFecha(fecha);
    prestamos.push_back(reg);
}