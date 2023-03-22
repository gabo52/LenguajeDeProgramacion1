/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEventual.h
 * Author: Gabo
 *
 * Created on 22 de noviembre de 2022, 04:59 PM
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H

#include "Pedido.h"


class PedidoEventual : public Pedido{
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void operator = (const PedidoEventual &c);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizaFlete();
private:
    double flete;
};

#endif /* PEDIDOEVENTUAL_H */

