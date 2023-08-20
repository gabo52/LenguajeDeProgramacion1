/* 
 * File:   Sobrecargas.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 7 de junio de 2023, 11:12 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Libro.h"
#include "Usuario.h"
using namespace std;

ifstream & operator >> (ifstream &arch, Usuario &f){
    char nombre[150], tipo, c;
    int carne;
    
    arch >> carne >> tipo >> c;
    if(arch.eof()) return arch; 
    arch.getline(nombre,150);
    f.SetCarne(carne); 
    f.SetTipo(tipo);
    f.SetNombre(nombre); 
}

ifstream & operator >> (ifstream &arch, Libro &f){
    char codigo[20], titulo[300], autor[150], c;
    int aa, stock;
    double precio; 
    
    arch.getline(codigo,20,',');
    if(arch.eof()) return arch;
    arch.getline(titulo,300,',');
    arch.getline(autor,150,',');
    arch >> aa >> c >> stock >> c >> precio; 
    arch.get();
    
    f.SetAutor(autor);
    f.SetPrecio(precio);
    f.SetStock(stock);
    f.SetTitulo(titulo);
    f.SetCodigo(codigo); 
}

ifstream & operator >> (ifstream &arch, LibroPrestado &f){
    char codigo[20], tipo, c;
    int carne, fecha, aa, mm, dd; 
    
    arch >> carne >> tipo >> c;
    if(arch.eof()) return arch;
    arch.getline(codigo,20,',');
    arch >> dd >> c >> mm >> c >> aa; 
    fecha = aa*10000 + mm*100 + dd; 
    
    f.SetCarne(carne);
    f.SetCodigoLib(codigo);
    f.SetFechaDeRetiro(fecha);
    f.SetTipo(tipo); 
}

ofstream & operator << (ofstream &arch, LibroPrestado &f){
    int aa, mm, dd, fecha = f.GetFechaDeRetiro(); 
    
    aa = fecha/10000;
    mm = (fecha%10000)/100; 
    dd = (fecha%10000)%100; 
    
    arch << f.GetCarne() << dd << "/" << mm << "/" << aa << endl;
}

ofstream & operator << (ofstream &arch, Usuario &u){
    int i, j, aa, mm, dd, fecha; 
    LibroPrestado *aux = u.GetLibPrest();
    
    arch << "Carne: " << u.GetCarne() << endl;
    arch << "Nombre: " << u.GetNombre() << endl;
    arch << "Tipo: " << u.GetTipo() << endl;
    if(u.GetCondicion() == 0) 
        arch << "INHABILITADO" << endl;
    else
        arch << "HABILITADO" << endl;
    
    for(i=0;i<aux[i].GetCarne();i++){
        fecha = aux[i].GetFechaDeRetiro();
        cout << fecha << endl;
        aa = fecha/10000;
        mm = (fecha%10000)/100; 
        dd = (fecha%10000)%100; 
        arch << left << setw(20) << aux[i].GetCodigoLib() << right << dd << "/" << mm << "/" << aa;
        if(aux[i].GetDeuda() == 1) arch << setw(10) << "Deuda";
        arch << endl; 
    }
    for(j=0;j<50;j++) arch << "="; 
    arch << endl; 
}

ofstream & operator << (ofstream &arch, Libro &l){
    int i; 
    arch << "Codigo: " << l.GetCodigo() << endl;
    arch << "Titulo: " << l.GetTitulo() << endl;
    arch << "Autor:  " << l.GetAutor() << endl; 
    arch << "Stock:  " << l.GetStock() << endl;
    for(i=0;i<50;i++) arch << "="; 
    arch << endl; 
    arch << "Prestamo a docentes:        " << l.GetCantDoc() << endl;
    arch << "Prestamo a alumnos:         " << l.GetCantEst() << endl;
    arch << "Prestamo a administrativos: " << l.GetCantAdm() << endl;
    for(i=0;i<50;i++) arch << "-"; 
    arch << endl; 
    arch << "Total de Prestamos:         " << l.GetPrestados() << endl;
    for(i=0;i<50;i++) arch << "="; 
    arch << endl; 
}