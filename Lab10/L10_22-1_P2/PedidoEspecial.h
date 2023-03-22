/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEspecial.h
 * Author: Gabo
 *
 * Created on 22 de noviembre de 2022, 04:54 PM
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedido.h"


class PedidoEspecial : public Pedido{
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void operator = (const PedidoEspecial &c);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizaFlete();
private:
    double descuento;
};

#endif /* PEDIDOESPECIAL_H */

