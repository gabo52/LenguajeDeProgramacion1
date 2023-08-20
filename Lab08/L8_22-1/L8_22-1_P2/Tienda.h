/* 
 * File:   Tienda.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de noviembre de 2022, 05:41 PM
 */

#ifndef TIENDA_H
#define TIENDA_H
#include "Pedido.h"
#include "Cliente.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Tienda {
public:
    void carga();
    void leePedido(ifstream &arch,Pedido &ped);
    void buscaProducto(int cod,char *cad,double &precio,int &stock);
    void leeCliente(ifstream &arch,Cliente &clien);
    void actualiza(int );
    void muestra();
    char obtieneTipo(int dni);
    void agregaDescuentoSegunTipo(char tipo,Pedido &ped);
private:
    Pedido lpedidos[200];
    Cliente lclientes[200];
};

#endif /* TIENDA_H */

