/* 
 * File:   Promociones.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 05:06 PM
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "Lista.h"
class Promociones {
public:

    void leepedidos();
    void actualizapedidos();
    void imprimepedidos();
    Pedido *leePedido(ifstream &arch);
private:
    Lista lpedidos;
};

void imprimeLinea(ofstream &arch,int cant,char c);

#endif /* PROMOCIONES_H */

