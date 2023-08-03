/* 
 * File:   Libro.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:33 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(char* autor);
    void GetAutor(char* cad) const;
    void SetTitulo(char* titulo);
    void GetTitulo(char* cad) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char* cad) const;
    void operator = (const Libro &c);
    int operator > (const Libro &c);
    void actualiza();
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int stock;
    int anho;
    double precio;
};
void operator >> (ifstream &arch,Libro &lib);
void operator << (ofstream &arch,Libro &lib);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* LIBRO_H */

