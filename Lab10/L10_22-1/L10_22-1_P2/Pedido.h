/* 
 * File:   Pedido.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 04:51 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Pedido {
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch)=0;
    virtual void imprime(ofstream &arch)=0;
    void imprimeFecha(ofstream& arch,int fecha);
    virtual void actualizaFlete()=0;
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

//int operator < (class Pedido *ped1,class Pedido *ped2);
#endif /* PEDIDO_H */

