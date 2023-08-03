/* 
 * File:   Pedido.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 02:56 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Pedido {
public:
    //Pedido();
    //Pedido(const Pedido& orig);
    int leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
    void setSubTotal(double subTotal);
    double getSubTotal() const;
    void setFecha(int fecha);
    int getFecha() const;
    void setCantidad(double cantidad);
    double getCantidad() const;
    void setCodigo(int codigo);
    int getCodigo() const;
    void imprimeFecha(ofstream &arch);
    void operator = (const Pedido &c);
    bool operator < (const Pedido &c);
    bool operator > (const Pedido &c);
private:
    int codigo;
    double cantidad;
    int fecha;
    double subTotal;
};

ofstream &operator <<(ofstream & arch, Pedido &c);
#endif /* PEDIDO_H */

