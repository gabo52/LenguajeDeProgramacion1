/* 
 * File:   PedidoEspecial.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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
private:
    double descuento;
};

#endif /* PEDIDOESPECIAL_H */

