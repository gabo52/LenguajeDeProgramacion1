/* 
 * File:   PedidoUsual.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 04:57 PM
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H

#include "Pedido.h"


class PedidoUsual : public Pedido{
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void operator = (const PedidoUsual &c);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    double descuento;
    double flete;
};

#endif /* PEDIDOUSUAL_H */

